#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char my_str[] = "Hello World";
    cout << my_str << endl;
    cout << my_str[1] << endl;
    char new_str[100] ;
    for (int i = 0; i < strlen(my_str) ; i++){
        if (my_str[i] != ' '){
            new_str[i]= my_str[i];
        }
        else {
            new_str[i] = '\0';
            cout << new_str << endl;
            break;
        }
    }
    return 0;
}
