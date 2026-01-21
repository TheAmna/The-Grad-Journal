#include<iostream>
#include<cstring>
using namespace std;

int main(){
    cout << "Enter a string: ";
    int count = 0;
    char mystr[30];
    cin.getline(mystr, sizeof(mystr)); //read max of 29 chars
    char a;
    cout << "Enter a character to search: ";
    cin >> a;
    for (int i=0; i<strlen(mystr); i++){
        if (*(mystr + i) == a){
            count++;
        } 
    }
    cout << "Number of occurences of "<< "\'" << a << "\' " << ": " << count; 
    return 0;
}