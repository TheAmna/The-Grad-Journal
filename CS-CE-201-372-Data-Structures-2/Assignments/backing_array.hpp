#ifndef ARRAY_HPP
#define ARRAY_HPP
#pragma once
#include <cassert>

template <typename T>
class array 
{
public:

	T* a;
	int length;

	array(int len=10)
	{
		length = len;
		a = new T[len];
	}
    
	virtual ~array() {
		delete[] a;
		a = nullptr;
	}

	T& operator[](int i)
	{
		assert(i >= 0 && i < length);

		return a[i];
	}

	//required to get a pointer when passed to std::copy* functions
	//in FastArrayStack
	T* operator+(int i) {
		return &a[i];
	}

	array<T>& operator=(array<T>& b) {
		if (a != nullptr) 
			delete[] a;
		a = b.a;
		b.a = nullptr;
		length = b.length;
		return *this;
	}

};
#endif
