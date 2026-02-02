// TestArrayStack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//#include "ArrayStack.h"
#include "FastArrayStack.hpp"

int main()
{ 
    /*
    ArrayStack<int> stack;

    for(int i=0; i<50; ++i)
        stack.add(i, i + 1);

    for (int i = 0; i < stack.size(); ++i)
    {
        std::cout << stack.get(i) << std::endl;
    }
    */

    FastArrayStack<int> stack;
    for (int i = 0; i < 50; ++i)
        stack.add(i, i + 1);

    for (int i = 0; i < stack.size(); ++i)
    {
        std::cout << stack.get(i) << std::endl;
    }
    return 0;
}