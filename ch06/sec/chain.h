#include <iostream>
#include "linearList.h"

template <class T>
struct chainNode
{
	T element;
	chainNode<T>* next;

	chainNode() {}
	chainNode(const T& element)
	{
		this->element = element;
	}

	chainNode(const T& element, chainNode<T>* next)
	{
		this->element = element;
		this->next = next;
	}
};

template <class T>
class chain : public linearList<T>
{
public:
	chain(int initCapacity = 10);
	chain(const chain<T>&);
	~chain();

	virtual bool empty() const { return (listSize == 0);}

	virtual int size() const { return listSize; }

	virtual T& get(int index) const ;

	virtual int indexOf(const T& element) const ;

	virtual void erase(int index) ;

	virtual void insert(int index, const T& element) ;

	virtual void output(std::ostream& out) const ;

	class iterator;
	iterator begin() const { return iterator(firstNode); }
	iterator end() const { return iterator(NULL); }

	class iterator
	{
	public:
		typedef std::bidirectional_iterator_tag iterator_category;
		typedef T value;
		typedef std::ptrdiff_t difference_type;
		typedef T* pointer;
		typedef T& reference;

		iterator(chainNode<T>* theNode = NULL)
		{
			node = theNode;
		}

		T& operator*() const { return node->element; }
		T* operator->() const { return &node->element; }

		iterator& operator++() 
		{
			node = node->element;
			return *this;
		}

		iterator& operator++(int)
		{
			//chainNode<T>* old = node;
			iterator old = *this;
			node = node->next;
			return old;
		}

	protected:
		chainNode<T>* node;
	};

protected:
	void checkIndex(int theIndex) const;

	chainNode<T>* firstNode;
	int listSize;

};


template<class T>
std::ostream& operator<<(std::ostream& out, const chain<T> & x);












