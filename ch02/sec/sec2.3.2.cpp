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
