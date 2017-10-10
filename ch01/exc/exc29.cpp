#include <iostream>
#include <iterator>
#include <algorithm>


using namespace std;

int main()
{

	int a[] = {1, 2, 3 ,4, 5};
	int b[5] = {0};

	copy(a, a+5, b);

	for(int i=0; i<5; i++)
		std::cout << b[i] << ",";

	std::cout << std::endl;
	

		
	return 0;
}


