#ifndef STACK_ITEM_H
#define STACK_ITEM_H

#include "square.h"

class StackItem
{
public:
	StackItem(const Square& square);

	void setNext(StackItem* next);
	StackItem* getNext();
	Square getSquare() const;

private:
	Square m_square;
	StackItem* m_next;
};

#endif
