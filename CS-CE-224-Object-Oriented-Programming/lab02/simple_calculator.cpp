#include<iostream>
#include <cmath>
using namespace std;

int main(){
    int a,b, operation;
    char operand;
    cout << "Enter first number: " ;
    cin >> a;
    cout << "Enter second number: " ;
    cin >> b;
    cout << "Enter operation: ";
    cin >> operand;
    switch(operand){
        case '+':
            operation = a + b;
            cout << a << " + " << b << " = " << operation << endl;
            break;
        case '-':
            operation = a - b;
            cout << a << " - " << b << " = " << operation << endl;
            break;
        case '*':
            operation = a * b;
            cout << a << " * " << b << " = " << operation << endl;
            break;
        case '/':
            operation = a / b;
            cout << a << " / " << b << " = " << operation << endl;
            break;
        case '^':
            operation = pow(a,b);
            cout << a << " ^ " << b << " = " << operation << endl;
            break;
        default:
            cout << "Error! The operator is not correct";}
    return 0;
}