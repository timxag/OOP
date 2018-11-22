#ifndef CONTAINTER_H
#define CONTAINTER_H

#include <memory>
#include <cstring>
#include "stack.h"
#include "list.h"
#include "criteria.h"

template <class T>
class Container
{
public:
	void add(const std::shared_ptr<T>& item);
	void erase(const Criteria<T>& criteria);
	//void print() const;

	template <class K>
	friend std::ostream& operator << (std::ostream& os, const Container<K>& container);

private:
	Stack<List<T>> m_container;
};

#include "container_impl.cpp"

#endif
