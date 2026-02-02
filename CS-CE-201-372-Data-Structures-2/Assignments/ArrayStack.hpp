#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H
#pragma once
#include "backing_array.hpp"

template<typename T>
class ArrayStack
{
protected:
	array<T> a;
	int n;
	 
public:
	ArrayStack( ) 
	{	 
	}

	~ArrayStack() 
	{
	}

	int size()
	{
		return n;
	}

	T get(int i)
	{
		return a[i];
	}

	T set(int i, T x)
	{
		T y = a[i];
		a[i] = x;
		return y;
	}

	virtual void add(int i, T x) 
	{
		if (n + 1 > a.length) 
			resize();
		for (int j = n; j > i; j--)
			a[j] = a[j - 1];
		a[i] = x;
		n++;
	}

	virtual T remove(int i) {
		T x = a[i];
		for (int j = i; j < n - 1; j++)
			a[j] = a[j + 1];
		n--;
		if (a.length >= 3 * n)
			resize();
		return x;
	}

	virtual void resize() 
	{
		array<T> b(std::max(2 * n, 1));
		for (int i = 0; i < n; i++)
			b[i] = a[i];
		a = b;
	}

};
#endif
