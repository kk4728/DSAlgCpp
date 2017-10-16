#include <iostream>

using namespace std;

template <class T>
T f1(T n)
{
	if(n ==0) return 2;

	return (2 + f1(n-1));
}


template <class T>
T f5(T n)
{
	if(n ==0) return 2;

	return (3 * f5(n-1));
}




int main()
{
	int a = 0;
	std::cout << "please enter an inter for arguement: ";
	std::cin >>  a;
	std::cout <<f1(a) <<std::endl;

	std::cout <<f5(a) <<std::endl;
		
	return 0;
}
