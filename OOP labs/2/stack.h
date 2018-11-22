#ifndef STACK_H
#define STACK_H

#include "stack_item.h"

class Stack
{
public:
	Stack();
	~Stack();

	void push(const Square& square);
	void pop();
	unsigned int size() const;
	Square front() const;

	friend std::ostream& operator << (std::ostream& os, const Stack& stack);

private:
	StackItem* m_front;
	StackItem* m_end;
	unsigned int m_size;
};

#endif
