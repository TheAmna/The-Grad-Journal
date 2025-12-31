#include<iostream>
using namespace std;

void  greetings(string str)
{
    cout  << "Hello, " << str;
    return;
    cout << "C++";
}


int main()
{
    long long unsigned int a = 42;
    cout << "Value of a = " << a << endl;
    cout << "Address of a = " << &a <<endl;
    cout << "Char of a = " << char(a) <<endl;
    cout << "float of a = " << float(a) <<endl;
    cout << "bool of a = " << bool(a) <<endl;
    float b = 3.24565677899080; 
    cout << b;
    cout << "int a * float b = " << a*b <<endl;
    cout << "int a * float b (int) = " << int(a*b) <<endl;
    cout << "int a * float b (float) = " << float(a*b) <<endl;
    cout << "int a * float b (double) = " << double(a*b) <<endl;
    cout << "precision : " << float(1.234567890) << endl;
    cout << "precision : " << float(12345678.90) << endl;

    int arr[5] = {4,3,6,7,1}; // array of 5 int
    //total bytes of arr = 4*5 20 bytes

    for (int i =0 ; i < 5 ; i++) // i++ = i = i+1 , i+= 2 --> i = i +2 
    {
        cout << arr[i]  << " " << &arr[i] << endl;
    }

    cout << sizeof(a) << endl;
    cout << sizeof(arr) << endl;

    greetings("Nadia");
    return 0;
}

