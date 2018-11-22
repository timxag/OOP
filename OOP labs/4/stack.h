#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "stack_item.h"

template <class T>
class Stack
{
public:
	Stack();
	~Stack();

	void push(const std::shared_ptr<T>& item);
	void pop();
	unsigned int size() const;
	std::shared_ptr<T> front() const;

	template <class K>
	friend std::ostream& operator << (std::ostream& os, const Stack<K>& stack);

private:
	std::shared_ptr<StackItem<T>> m_front;
	std::shared_ptr<StackItem<T>> m_end;
	unsigned int m_size;
};

#include "stack_impl.cpp"

#endif
