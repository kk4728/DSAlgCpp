#include <iostream>
#include <iterator>
#include <algorithm>
#include <numeric>

using namespace std;

template<class T>
T sum(T a[], int n)
{
	T theSum = 0;
	return accumulate(a, a+n, theSum);
	
}

template <class T>
T product(T a[], int n)
{
	T res = 1;
	return accumulate(a, a+n, res, multiplies<T>() );
}

template <class T>
void permutation(T list[], int k, int m)
{
	do
	{
		copy(list, list+m+1, ostream_iterator<T>(std::cout, ""));
		std::cout<< std::endl;
	}while(next_permutation(list, list+m+1));
}


int main()
{
	int a[100] = {0};

	for(int i=1; i<101; i++)
	{
		a[i-1] = i;
	}

	int s = sum(a, 100);
	int p = product(a, 9);
	
	std::cout<<s << std::endl;
	std::cout<< p << std::endl;

	char ch[3] = {'x','y','z'};

	permutation(ch, 0,2);


	return 0;
}
