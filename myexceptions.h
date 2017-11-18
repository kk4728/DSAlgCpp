#ifndef myExceptions_
#define myExceptions_

#include <string>
#include <iostream>

using namespace std;

class illegalParamterValue
{
public:
	illegalParamterValue(const string& theMsg = "illegal Paramter Value")
	{
		message = theMsg;
	}

	void outputMessage() 
	{
		cout << message << endl;
	}
private:
	string message;
};

class illegalInputData
{
public:
	illegalInputData(string theMsg="illegal input data")
	{
		message = theMsg;
	}

	void outputMessage() 
	{
		cout << message << endl;
	}
private:
	string message;

};


class illegalIndex
{
public:
	illegalIndex(string theMsg="illegal index")
	{
		message = theMsg;
	}

	void outputMessage() 
	{
		cout << message << endl;
	}
private:
	string message;

};


class matrixIndexOutOfBounds
{
public:
	matrixIndexOutOfBounds(string theMsg="matrixIndexOutOfBounds")
	{
		message = theMsg;
	}

	void outputMessage() 
	{
		cout << message << endl;
	}
private:
	string message;

};

class matrixSizeMismatch
{
public:
	matrixSizeMismatch(string theMsg="matrixSizeMismatch")
	{
		message = theMsg;
	}

	void outputMessage() 
	{
		cout << message << endl;
	}
private:
	string message;

};

class stackEmpty
{
public:
	stackEmpty(string theMsg="stackEmpty")
	{
		message = theMsg;
	}

	void outputMessage() 
	{
		cout << message << endl;
	}
private:
	string message;

};

class queueEmpty
{
public:
	queueEmpty(string theMsg="Invalid operation on empty queue")
	{
		message = theMsg;
	}

	void outputMessage() 
	{
		cout << message << endl;
	}
private:
	string message;

};

class hashTableFull
{
public:
	hashTableFull(string theMsg="The hash table is full")
	{
		message = theMsg;
	}

	void outputMessage() 
	{
		cout << message << endl;
	}
private:
	string message;

};


class undefinedEdgeWeight
{
public:
	undefinedEdgeWeight(string theMsg="No edge weights defined")
	{
		message = theMsg;
	}

	void outputMessage() 
	{
		cout << message << endl;
	}
private:
	string message;

};


class undefinedMethod
{
public:
	undefinedMethod(string theMsg="This method is undefined")
	{
		message = theMsg;
	}

	void outputMessage() 
	{
		cout << message << endl;
	}
private:
	string message;

};


#endif //myExceptions_

