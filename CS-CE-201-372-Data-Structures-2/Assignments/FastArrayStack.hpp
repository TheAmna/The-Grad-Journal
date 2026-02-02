#ifndef FAST_ARRAY_STACK
#define FAST_ARRAY_STACK
#pragma once
#include "ArrayStack.hpp"
#include <algorithm> //for std::copy/std::copy_backward

template <typename T>
class FastArrayStack :public ArrayStack<T>
{
	using ArrayStack<T>::a; //get the parent's reference to array a
	using ArrayStack<T>::n;	//get the parent's reference to n

protected:
	virtual void resize() override
	{
		array<T> b(std::max(2 * n, 1));
		//for (int i = 0; i < n; i++)
		//	b[i] = a[i];
		std::copy(a+0, a+n, b+0);
		a = b;
	}
public:
	virtual void add(int i, T x) override
	{
		
		if (n + 1 > a.length)
			resize();
		//for (int j = n; j > i; j--)
		//a[j] = a[j - 1];
		std::copy_backward(a + i, a + n, a + n + 1);

		a[i] = x;
		n++;
	}

	virtual T remove(int i) override 
	{
		T x = a[i];
		//for (int j = i; j < n - 1; j++)
		//	a[j] = a[j + 1];
		std::copy(a+i+1, a + n, a + i);
		n--;
		if (a.length >= 3 * n)
			resize();
		return x;
	}

	
};
#endif
