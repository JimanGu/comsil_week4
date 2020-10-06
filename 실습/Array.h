#ifndef __ARRAY__
#define __ARRAY__
#include <iostream>
#include <cstdlib>
using namespace std;

template <class T>
class Array {
protected:
	T* data;
	int len;

public:

	Array(int size)
	{
		this->len = size;
		this->data = new T[size];
	}



	virtual T& operator[] (int index) {
		if (index < 0 || index >= len)
			cout << "Array bound Error!" << endl;

		return data[index];
	}

	virtual T operator[](int index) const {
		if (index < 0 || index >= len)
			cout << "Array bound Error!" << endl;

		return data[index];
	}



	int length()
	{
		return this->len;
	}



	void print()
	{
		cout << "[";
		for (int i = 0; i < len - 1; i++)
			cout << data[i] << " ";
		cout << data[len - 1];
		cout << "]" << endl;
	}

	~Array() {
		delete[] data;
	}

};
#endif	



