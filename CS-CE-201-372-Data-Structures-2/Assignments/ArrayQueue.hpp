#ifndef ARRAY_QUEUE_HPP
#define ARRAY_QUEUE_HPP
#pragma once
#include "backing_array.hpp"

template<typename T>

class ArrayQueue{
    protected:
        array<T> a;
        int n;
        
    public:
        ArrayQueue(){

        }

        ~ArrayQueue(){

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
