#include "Stack.h"

Stack::Stack()
{
	m_size = 0;
}

Stack::~Stack()
{
	while (size() > 0)
		pop();
}

void Stack::push(const std::shared_ptr<Figure>& figure)
{
	std::shared_ptr<StackItem> itemPtr = std::make_shared<StackItem>(figure);

	if (m_size == 0)
	{
		m_end = itemPtr;
		m_front = m_end;
	}
	else
	{
		m_end->setNext(itemPtr);
		m_end = itemPtr;
	}

	++m_size;
}

void Stack::pop()
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

unsigned int Stack::size() const
{
	return m_size;
}

/*std::shared_ptr<Figure> Stack::front() const
{
	return m_front->getFigure();
}*/

std::ostream& operator << (std::ostream& os, const Stack& Stack)
{
	if (Stack.size() == 0)
	{
		os << "================" << std::endl;
		os << "Stack is empty" << std::endl;
	}
	else
	{
		std::shared_ptr<StackItem> item = Stack.m_front;

		while (item != nullptr)
		{
			item->getFigure()->print();
			item = item->getNext();
		}
	}

	return os;
}
