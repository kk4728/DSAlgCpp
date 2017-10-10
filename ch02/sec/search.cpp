// Ch02.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>

template <class T>
int SequentialSearch(T a[], int n, const T& x)
{
	for (size_t i = 0; i < n; i++)
	{
		if (x == a[i]) return i;
	}
	return -1;
}

template<class T>
int rSequentialSearch(T a[], int n, const T& x)
{
	if (n < 1) return -1;
	if (a[n - 1] == x) return n - 1;
	return rSequentialSearch(a, n - 1, x);
}

using namespace std;




int main()
{
	unsigned char ch[100] = {0};

	for (unsigned char i = 0; i < 100; i++)
	{
		ch[i] = i + 1;
	}

	//int n = SequentialSearch(ch, 100, (unsigned char)67);
	int n = rSequentialSearch(ch, 100, (unsigned char)67);


	std::cout << n << endl;

//	getchar();

    return 0;
}

