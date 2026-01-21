#include<iostream>
using namespace std;

long int fib(int n){
    static int count = 0;
    if (n==-1){
        return count;
    }
    count++ ;
    if ((n==0)|(n==1)){
        return 1;
    }
    return fib(n-1)+ fib(n-2);
}

int main(){
    int num;
    long int result;
    cout << "Please enter a number : ";
    cin >> num;
    result = fib(num);
    cout << "Fib(" << num << ") : " << result<< endl;
    cout << "No. of times fib(n) called : " << fib(-1) << endl;
    return 0;
}