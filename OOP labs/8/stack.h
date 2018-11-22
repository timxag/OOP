#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <thread>
#include <future>
#include <functional>
#include "stack_item.h"
#include "iterator.h"

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

	Iterator<StackItem<T>, T> begin() const;
	Iterator<StackItem<T>, T> end() const;

	void sort();
	void sortParallel();

	template <class K>
	friend std::ostream& operator << (std::ostream& os, const Stack<K>& stack);

private:
	std::shared_ptr<StackItem<T>> m_front;
	std::shared_ptr<StackItem<T>> m_end;
	unsigned int m_size;

	void sortHelper(Stack<T>& q, bool isParallel);
	std::future<void> sortParallelHelper(Stack<T>& q);
};

#include "stack_impl.cpp"

#endif
