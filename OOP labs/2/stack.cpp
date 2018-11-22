#include "stack.h"

Stack::Stack()
{
	m_front = nullptr;
	m_end = nullptr;
	m_size = 0;
}

Stack::~Stack()
{
	while (size() > 0)
		pop();
}

void Stack::push(const Square& square)
{
	StackItem* item = new StackItem(square);

	if (m_size == 0)
	{
		m_front = item;
		m_end = m_front;
	}
	else
	{
		m_end->setNext(item);
		m_end = item;
	}

	++m_size;
}

void Stack::pop()
{
	if (m_size == 1)
	{
		delete m_front;

		m_front = nullptr;
		m_end = nullptr;
	}
	else
	{
		StackItem* next = m_end->getNext();

		delete m_end;

		m_end = next;
	}

	--m_size;
}

unsigned int Stack::size() const
{
	return m_size;
}

Square Stack::front() const
{
	return m_front->getSquare();
}

std::ostream& operator << (std::ostream& os, const Stack& stack)
{
	if (stack.size() == 0)
	{
		os << "================" << std::endl;
		os << "Stack is empty" << std::endl;
	}
	else
	{
		StackItem* item = stack.m_front;

		while (item != nullptr)
		{
			os << item->getSquare();
			item = item->getNext();
		}
	}

	return os;
}
