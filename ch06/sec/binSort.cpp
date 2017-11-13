#include <iostream>

#include "binSort.h"

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

template <class T>
void chain<T>::binSort(int range)
{
	chainNode<T>** bottom;
	chainNode<T>** top;
	bottom = new chainNode<T>* [range + 1];
	top = new chainNode<T>* [range];
	for(int i = 0; i <= range; i++)
		bottom[i] = NULL;

	for(; firstNode != NULL; firstNode = first->next)
	{
		int theBin = firstNode->element;
		if(bottom[theBin] == NULL)
		{
			bottom[theBin] = top[theBin] = firstNode;	
		}
		else
		{//box not empty
			top[theBin]->next = firstNode;
			top[theBin] = firstNode;
		}
	}

	//
	chainNode<T>* y = NULL;
	for(int theBin = 0; theBin <= range; theBin++)
	{
		if(bottom[theBin] != NULL)
			firstNode = bottom[theBin];
		else
			y->next = bottom[theBin];
		y = top[theBin];
	}

	if(y != NULL)
		y->next = NULL;

	delete [] bottom;
	delete [] top;
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













