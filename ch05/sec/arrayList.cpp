#include <iostream>
#include <iterator>
#include <string>
#include <ostream>
#include <algorithm>


class illegalParamterValue
{
public:
	illegalParamterValue(const char* pStr) {}
	illegalParamterValue(std::string str) {}


};

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
class arrayList : public linearList<T>
{
public:
	arrayList(int initCapacity = 10);
	arrayList(const arrayList<T>& );
	~arrayList() { delete [] element; }


	bool empty() const { return listSize == 0; }
	
	int size() const { return listSize; }

	T& get(int index) const ;

	int indexOf(const T& theElement) const ;

	void erase(int index);

	void insert(int index, const T& theElement); 

	void output(std::ostream& out) const;

	int capacity() const { return arrayLength; }


protected:
	T* element;
	int arrayLength;
	int listSize;

	void checkIndex(int index) const;
};

template <class T>
arrayList<T> :: arrayList(int initCapacity)
{
	if(initCapacity <0)
	{
		//std::ostringstream s;
		//s << "Init Capacity = " << initCapacity << "Must be > 0 ";
		//throw illegalParamterValue(s.c_str());
		throw illegalParamterValue("111");
	}
	arrayLength = initCapacity;
	element = new T[arrayLength];
	listSize = 0;
}

template <class T>
arrayList<T> :: arrayList(const arrayList<T>& theList)
{
	arrayLength = theList.arrayLength;
	listSize = theList.listSize;
	element = new T[arrayLength];
	std::copy(theList.element, theList.element + listSize, element);
}

template<class T>
void arrayList<T>::checkIndex(int index) const
{
	if(index <0 || index>=listSize)
	{
		//throw
	}
}

template<class T>
T& arrayList<T>::get(int index) const
{
	checkIndex(index);
	return element[index];
}

template<class T>
int arrayList<T>::indexOf(const T& theElement) const
{
	int theIndex = (int) (std::find(element, element+listSize, theElement) - element);
	if(theIndex == listSize)
		return -1;
	else
		return theIndex;
}

template<class T>
void arrayList<T>::erase(int index)
{
	checkIndex(index);

	std::copy(element+index+1, element+listSize, element+index);

	element[--listSize].~T(); // delete ? deconstrution 将末尾处的T元素类型进行析构掉
}

template<class T>
void arrayList<T>::insert(int index, const T& theElement)
{
	if(index<0 || index>listSize)
	{
		//throw
	}

	//索引有效，确认数组是否已满
	if(listSize == arrayLength)
	{
		//数组空间已满，倍增数组长度
		//...

		arrayLength *= 2;
	}

	std::copy_backward(element+index, element+listSize, element+listSize+1);
	
	element[index] = theElement;

	listSize++;
}

template<class T>
void arrayList<T>::output(std::ostream& out) const
{
	std::copy(element, element+listSize, std::ostream_iterator<T>(std::cout, " "));	
}

//overload
template<class T>
std::ostream& operator<<(std::ostream& out, const arrayList<T>& x)
{
	x.output(out);
	return out;
}

class iterator
{
public:
	typedef bidirectional_iterator_tag interator_category;
protected:
	
};


void f_test()
{
	linearList<int>* x = (linearList<int>*)new arrayList<int>(100);
//	linearList y = (linearList)new arrayList<int>(100);//error

	arrayList<double> y(100);

	arrayList<char> z;

	arrayList<double> w(y);


	y.output(std::cout);
	std::cout <<std::endl;
}


int main()
{
	f_test();

	return 0;
}























