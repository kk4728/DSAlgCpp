#include <algorithm>


class illegalParamterValue
{
public:
	illegalParamterValue(const char* pStr)
	{

	}

};

template<class T>
void changeLength1D(T* a, int oldLength, int newLength)
{
	if(newLength <0)
		throw illegalParamterValue("new length must be >=0");

	T* temp = new T[newLength];
	int number = oldLength < newLength ? oldLength : newLength;
	std::copy(a, a+number, temp);

	delete [] a;
	a = temp;



}


