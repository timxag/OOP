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
		std::shared_ptr<StackItem<K>> item = stack.m_front;

		while (item != nullptr)
		{
			item->getItem()->print();
			item = item->getNext();
		}
	}

	return os;
}
