#include <iostream>


using namespace std;


template<class T>
T polyEval(T coeff[], int n, const T& x)
{
	T y = 1;
	T value = coeff[0];
	for(int i=0; i<n+1; i++)
	{
		y *= x;
		value += y*coeff[i];
	}

	return value;
}

template<class T>
T horner(T coeff[], int n, const T& x)
{
	T value = coeff[n];
	for(int i=1; i<n; i++)
		value = x * value + coeff[n-i];

	return value;
}


template<class T>
void rank(T a[], int n, int r[])
{
	for(int i=0; i<n; i++)
		r[i] = 0;

	for(int i=1; i<n; i++)
		for(int j=0; j<i; j++)
		{
			if(a[j]<a[i]) r[i]++;
			else r[j]++;
		}
}

template<class T>
void rearrange(T a[], int n, int r[])
{
	T* u = new T[n];

	//将a中元素按名词排序移到u中合适的位置
	for(int i = 0; i<n; i++)
		u[r[i]] = a[i];

	for(int i=0; i<n; i++)
		a[i] = u[i];

	delete [] u;
}


template<class T>
int indexOfMax(T a[], int size)
{
	int i = 0;
	T max = a[0];
	int maxIndex = 0;
	for(i = 1; i<size; i++)
	{
		if(max<a[i]) 
		{
			max = a[i];
			maxIndex = i;
		}
	}

	return maxIndex;
}

template <class T>
void swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<class T>
void selectionSort(T a[], int n)
{
	for(int size=n; size>1; size--)
	{
		int j = indexOfMax(a, size);
		::swap(a[j], a[size-1]);
	}
}

template<class T>
void bubbleSort(T a[], int n)
{
	for(int i=n; i>1; i--)
	{
		for(int j=0; j<n-1; j++)
		{
			if(a[j]>a[j+1]) ::swap(a[j], a[j+1]);
		}
	}

}

////////////////////////////////////////////////////////////////////////////

//原地重新排序，减小占用内存占用内容空间
template<class T>
void rearrange_inplace(T a[], int n, int r[])
{
	for(int i=0; i<n; i++)
	{
		while(r[i] != i)
		{
			int t = r[i];
			::swap(a[i], a[t]);
			::swap(r[i], r[t]);
		}
	}
}

template <class T>
void selectionSort_abortInTime(T a[], int n)
{
	bool sorted = false;	
	for(int size=n; !sorted && (sorted>1); size--)
	{
		int indexOfMax = 0;
		sorted = true;
		for(int i=1; i<size; i++)
		{
			if(a[indexOfMax] <= a[i]) indexOfMax = i;
			else sorted = false;
		}
		::swap(a[indexOfMax], a[size-1]);
	}
}

template<class T>
bool bubble(T a[], int n)
{
	bool swapped = false;
	for(int i=0; i<n-1; i++)
	{
		if(a[i] > a[i+1])
		{
			swap(a[i], a[i+1]);
			swapped = true;
		}
	}

	return swapped;
}

template <class T>
void bubbleSort_AbortInTime(T a[], int n)
{
	for(int i=n; n>1 && bubble(a, i); i--);
}

template <class T>
void insert(T a[], int n, const T& x)
{
	int i=0;
	for(i = n-1; i>=0 && (a<a[i]); i--)
	{
		a[i+1] = a[i];
	}
	a[i+1] = x;
}

template <class T>
void insertionSort(T a[], int n)
{
	for(int i=1; i<n; i++)
	{
		T t = a[i];
		::insert(a, i, t);
	}
}

int main()
{
	std::cout<<"==================名次/计数排序==============="<<std::endl;
	int a[] = {4,3,9,3,7};
	int r[5];

	::rank(a, 5, r);
	for(int i=0; i<5; i++)
		std::cout<<r[i]<<' ' ;
	std::cout <<endl;

	::rearrange(a, 5, r);
	for(int i=0; i<5; i++)
		std::cout<<a[i]<<' ' ;
	std::cout <<endl;
	
	std::cout<<"==================原地计数排序==============="<<std::endl;
	int aa[] = {4,5,9,3,7};
	int rr[5];
	::rank(aa, 5, rr);
	::rearrange_inplace(aa, 5, rr);
	for(int i=0; i<5; i++)
		std::cout<<aa[i]<<' ' ;
	std::cout <<endl;

	std::cout<<"==================选择排序==============="<<std::endl;
	int a2[] = {6,5,8,4,3,1};
	::selectionSort(a2, 6);
	for(int i=0; i<6; i++)
		std::cout<<a2[i]<<' ' ;
	std::cout <<endl;

	std::cout<<"==================冒泡排序==============="<<std::endl;
	int a3[] = {6,5,8,4,3,1};
	::bubbleSort(a3, 6);
	for(int i=0; i<6; i++)
		std::cout<<a3[i]<<' ' ;
	std::cout <<endl;

	
	
	
	
	return 0;
}
