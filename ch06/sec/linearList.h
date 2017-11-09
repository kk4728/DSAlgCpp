#ifndef linearList_
#define linearList_

#include <iostream>

template <class T>
class linearList
{
public:
	virtual ~linearList() {}

	virtual bool empty() const = 0;

	virtual int size() const = 0;

	virtual T& get(int index) const = 0;

	virtual int indexOf(const T& element) const = 0;

	virtual void erase(int index) = 0;

	virtual void insert(int index, const T& element) = 0;

	virtual void output(std::ostream& out) const = 0;

};

#endif

