#include<iostream>
using namespace std;

int main(){
    // char str[] = "Print a message";
    // cout << &str[8]; // meesage 
    // str[5] = '\0';
    // cout<< str <<endl; // print
    cout << "Enter a string: "<< endl;
    int count = 0;
    char mystr[30];
    cin.ignore();
    cin.getline(mystr, sizeof(mystr)); //read max of 29 chars
    char a;
    cout << "Enter a character to search: ";
    cin >> a;
    for (int i=0; i<sizeof(mystr); i++){
        if (*(mystr + i) == a){
            count++;
        } 
    }
    cout << "Number of occurences of "<< "\'" << a << "\' " << ": " << count; 
    return 0;
}