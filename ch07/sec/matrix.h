#include <iostream>

template<class T>
class matrix
{
	friend std::ostream& operator<< (std::ostream& , const matrix<T>& );

public:
	matrix(int rows = 0, int cols = 0);
	matrix(const matrix<T>& );
	~matrix() { delete [] element; };

	int rows() const { return m_rows; }
	int cols() const { return m_cols; }

	T& operator() (int i, int j) const;
	matrix<T>& operator=(const matrix<T>& );
	matrix<T> operator+() const;
	matrix<T> operator+(const matrix<T>& ) const;
	matrix<T> operator-() const;
	matrix<T> operator-(const matrix<T>&) const;
	matrix<T> operator*(const matrix<T>& ) const;
	matrix<T> operator += (const T&);


private:
	int m_rows;
	int m_cols;

	T* element;


};

