#ifndef QUEUE_ITEM_H
#define QUEUE_ITEM_H

#include <memory>
#include "figure.h"

class StackItem
{
public:
	StackItem(const std::shared_ptr<Figure>& figure);

	void setNext(std::shared_ptr<StackItem> next);
	std::shared_ptr<StackItem> getNext();
	std::shared_ptr<Figure> getFigure() const;

private:
	std::shared_ptr<Figure> m_figure;
	std::shared_ptr<StackItem> m_next;
};

#endif
