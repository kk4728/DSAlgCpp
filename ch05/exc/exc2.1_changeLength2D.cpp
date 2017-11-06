#include <algorithm>
#include <iostream>


template <class T>
void changeLength2D(T** a, int oldRLen, int oldCLen, int rLen, int cLen)
{
	T** p = new T*[rLen];	
	for(int i=0; i<rLen; i++)
		*(p+i) = new T[cLen];


	int r = oldRLen > rLen ? rLen : oldRLen;
	int c = oldCLen > cLen ? cLen : oldCLen;	

	for(int i=0; i<r; i++)
	{
		//std::copy(*(a+i), *(a+i+c), *(p+i));
		//std::copy(&a[i], &a[i][2], &p[i]);
	}

	for(int i=0; i<oldRLen; i++)
		delete [] *(a+i);
	delete [] a;
}

int main()
{
	int** a = new int*[2];
	for(int i=0; i<2; i++)
		*(a+i) = new int[3];

	a[0][0]= 1;
	a[0][1]= 2;
	a[0][2]= 3;
	a[1][0]= 4;
	a[1][1]= 5;
	a[1][2]= 6;

	for(int i=0; i<2; i++)
	{
		for(int j=0; j<3; j++)
			//std::cout <<* ((*a+i*3) + j) << " ";
			std::cout << a[i][j]<< " ";

		std::cout <<std:: endl;
	}

	std::cout <<std::endl;




	changeLength2D (a, 2,3, 4,5);

	return 0;
}
