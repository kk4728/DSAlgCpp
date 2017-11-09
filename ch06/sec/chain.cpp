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

template< class T>
chain<T> :: chain(int initCapacity)
{
	firstNode = NULL;
	listSize = 0;
}

template<class T>
chain<T>::chain(const chain<T>& theList)
{
	listSize = theList.listSize;

	if(listSize ==0 )
	{
		firstNode = NULL;
		listSize = 0;
	}

	// chain not empty
	// just for lookup int theList 
	chainNode<T>* sourceNode = theList.firstNode;

	//deep copy
	firstNode = new chainNode<T> (sourceNode->element); //point to fist element
	sourceNode = sourceNode->next;

	// just for lookup int chain
	chainNode<T>* targetNode = firstNode;

	while( sourceNode != NULL) //deep copy all the elements
	{
		targetNode->next = new chainNode<T>(sourceNode->element);
		targetNode = targetNode->next;
		sourceNode = sourceNode->next;
	}
	targetNode->next = NULL;
}

template<class T>
chain<T>::~chain()
{
	while(firstNode != NULL)
	{
		chainNode<T>* nextNode = firstNode->next;
		delete nextNode;
		firstNode = nextNode;
	}
}

template<class T>
void chain<T>::checkIndex(int theIndex) const
{
	if(theIndex<0 || theIndex>=listSize)
	{
		//throw exception
	}
}

template<class T>
T& chain<T>::get(int index) const
{
	checkIndex(index);

	chainNode<T>* curNode = firstNode;
	for(int i=0; i<index; i++)
		curNode = curNode->next;

	return curNode->element;
}

template<class T>
int chain<T>::indexOf(const T& element) const
{
	chainNode<T>* curNode = firstNode;
	int index = 0;
	while(curNode != NULL)
	{
		index++;
		if(element == curNode->element)
		{
			return index;
		}
		curNode = curNode->next;
	}
	return -1;
}

template<class T>
void chain<T>::erase(int index)
{
	checkIndex(index);

	chainNode<T>* deleteNode = NULL;
	if(index ==0)
	{
		deleteNode = firstNode;
		firstNode = firstNode->next;
	}
	else
	{
		chainNode<T>* p = firstNode;
		for(int i=0; i<index-1; i++)
		{
			p = p->next; // find the index th element
		}

		deleteNode = p->next;
		p->next = p->next->next;
	}

	listSize--;
	delete deleteNode;
}

template<class T>
void chain<T>::insert(int index, const T& theElement)
{
	if(index<0 || index>listSize)
	{
		//throw exception
	}
	
	if(index==0)
	{
		//after firstNode
		firstNode = new chainNode<T>(theElement, firstNode);
	}
	else
	{
		chainNode<T>* p = firstNode;
		for(int i=0; i<index-1; i++)
			p = p->next;

		//after p for insert
		p->next = new chainNode<T>(theElement, p->next);

	}
	listSize++;
}

template<class T>
void chain<T>::output(std::ostream& out) const
{
	chainNode<T>* p = firstNode;
	while(p != NULL)
	{
		out << p->element << " " ;
		p = p->next;
	}
}

template<class T>
std::ostream& operator<<(std::ostream& out, const chain<T> & x)
{
	x.output(out);
	return out;
}




int main()
{
	chain<int> c;

	c.insert(0, 1);
	c.insert(1, 22);
	c.insert(2, 3);
	
	std::cout <<"size: "<< c.size() <<std::endl;

 	std::cout << " index of" << c.indexOf(33)<< std::endl;
 	std::cout << " index of" << c.indexOf(3)<< std::endl;

	std::cout << c;

	return 0;
}


/////////////////////////////////////////////////
template <class T>
class extendedLinearList : public linearList<T>
{
public:
	virtual ~extendedLinearList() {}

	virtual void clear() = 0;

	virtual void push_back(const T& theElement) = 0;

};










