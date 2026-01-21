#include<iostream>
using namespace std;

int main(){
    int a;
    int b;
    cout << "Enter first number : " ;
       cin >> a ;
    cout << "Enter second number : ";
       cin >> b ;
    int sum, difference, product, quotient;
    sum = a + b;
    difference = a - b;
    product = a*b;
    quotient = a/b;
    cout << "Sum : " << sum;
    cout << "\nDifference : " << difference;
    cout << "\nProduct : " << product;
    cout << "\nQuotient : " << quotient;
    return 0;
}