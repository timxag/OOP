#include "stack_item.h"

StackItem::StackItem(const Square& square)
{
	m_next = nullptr;
	m_square = square;
}

void StackItem::setNext(StackItem* next)
{
	m_next = next;
}

StackItem* StackItem::getNext()
{
	return m_next;
}

Square StackItem::getSquare() const
{
	return m_square;
}
