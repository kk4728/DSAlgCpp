#include <iostream>

using namespace std;

void irregularArray()
{
	int numOfRows = 5;
	int length[5] = {6, 3, 4, 2, 7};

	int** p = new int* [numOfRows];
	for(int i=0; i<numOfRows; i++)
	{
		*(p+i) = new int[length[i]];
	}

	p[2][3] = 5;
	p[4][6] = p[2][3] + 2;
	p[1][1] = 3;

	cout << p[2][3] << endl;
	cout << p[4][6] << endl;
	cout << p[1][1] << endl;
	cout << endl;
	cout << *(p[2]+3) << endl;
	cout << *(*(p+2)+3) << endl;
	cout << p[4][6] << endl;
	cout << *(*(p+4)+6) << endl;
	cout << p[1][1] << endl;

	//delete
	for(int i=0; i<numOfRows; i++)
		delete [] *(p+i);

	delete [] p;
}

int main()
{
	irregularArray();
	return 0;
}
