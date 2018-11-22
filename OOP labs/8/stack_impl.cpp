template <class T>
Stack<T>::Stack()
{
	m_size = 0;
}

template <class T>
Stack<T>::~Stack()
{
	while (size() > 0)
		pop();
}

template <class T>
void Stack<T>::push(const std::shared_ptr<T>& item)
{
	std::shared_ptr<StackItem<T>> itemPtr = std::make_shared<StackItem<T>>(item);

	if (m_size == 0)
	{
		m_front = itemPtr;
		m_end = m_front;
	}
	else
	{
		m_end->setNext(itemPtr);
		m_end = itemPtr;
	}

	++m_size;
}

template <class T>
void Stack<T>::pop()
{
	if (m_size == 1)
	{
		m_front = nullptr;
		m_end = nullptr;
	}
	else
		m_end = m_end->getNext();

	--m_size;
}

template <class T>
unsigned int Stack<T>::size() const
{
	return m_size;
}

template <class T>
std::shared_ptr<T> Stack<T>::front() const
{
	return m_front->getItem();
}

template <class T>
Iterator<StackItem<T>, T> Stack<T>::begin() const
{
	return Iterator<StackItem<T>, T>(m_front);
}

template <class T>
Iterator<StackItem<T>, T> Stack<T>::end() const
{
	return Iterator<StackItem<T>, T>(nullptr);
}

template <class T>
void Stack<T>::sort()
{
	sortHelper(*this, false);
}

template <class T>
void Stack<T>::sortParallel()
{
	sortHelper(*this, true);
}

template <class T>
void Stack<T>::sortHelper(Stack<T>& q, bool isParallel)
{
	if (q.size() <= 1)
		return;

	Stack<T> left;
	Stack<T> right;
	std::shared_ptr<T> mid = q.front();

	q.pop();

	while (q.size() > 0)
	{
		std::shared_ptr<T> item = q.front();

		q.pop();

		if (item->area() < mid->area())
			left.push(item);
		else
			right.push(item);
	}
	
	if (isParallel)
	{
		std::future<void> leftFu = sortParallelHelper(left);
		std::future<void> rightFu = sortParallelHelper(right);

		leftFu.get();
		rightFu.get();
	}
	else
	{
		sortHelper(left, isParallel);
		sortHelper(right, isParallel);
	}
	
	while (left.size() > 0)
	{
		q.push(left.front());
		left.pop();
	}

	q.push(mid);

	while (right.size() > 0)
	{
		q.push(right.front());
		right.pop();
	}
}

template <class T>
std::future<void> Stack<T>::sortParallelHelper(Stack<T>& q)
{
	auto funcObj = std::bind(&Stack<T>::sortHelper, this, std::ref(q), true);
	std::packaged_task<void()> task(funcObj);
	std::future<void> res(task.get_future());
	std::thread th(std::move(task));

	th.detach();

	return res;
}

template <class K>
std::ostream& operator << (std::ostream& os, const Stack<K>& stack)
{
	if (stack.size() == 0)
	{
		os << "================" << std::endl;
		os << "Stack is empty" << std::endl;
	}
	else
	{
		for (std::shared_ptr<K> item : stack)
		{
			item->print();

			std::cout << "Area: " << item->area() << std::endl;
		}
	}

	return os;
}
