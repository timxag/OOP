#include "stack_item.h"

StackItem::StackItem(const std::shared_ptr<Figure>& figure)
{
	m_next = nullptr;
	m_figure = figure;
}

void StackItem::setNext(std::shared_ptr<StackItem> next)
{
	m_next = next;
}

std::shared_ptr<StackItem> StackItem::getNext()
{
	return m_next;
}

std::shared_ptr<Figure> StackItem::getFigure() const
{
	return m_figure;
}
