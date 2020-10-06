#include "Array.h"
//#ifndef __GROWABLEARRAY__
//#define __GROWABLEARRAY__

template <class T>

class GrowableArray: public Array<T>
{
public:

	GrowableArray(int size) :Array<T>(size) {};

	virtual T&operator[](int index) {
		
		if (index >= this->len) {

			this->data = (T*)realloc(this->data, (2*index) * sizeof(T));

			for (int i = this->len ; i < 2* index ; i++) {
				(this->data)[i] = 0;
			}
			this->len = index * 2;
		}
		if (index < 0 || index>=this->len)
			cout << "Array bound Error!" << endl;
		else	return (this->data)[index];
	}

	
	virtual T operator[](int index) const {
		if (index < 0 || index >= this->len)
			cout << "Array bound Error!" << endl;

		else	return (this->data)[index];
	}
};
//#endif

