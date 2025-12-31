#include<iostream>
# include<cstring>
using namespace std;

int main(){
    int num[3] = {3,46,6};
    // int x , y;
    // cin >> x >> y;
    // count << x << " " << y << endl;

    char name[20];
    cout << "Enter your name : " ;
    // $ is the delimiter (USED TO TREAT ENTER KEY AS an INPUT)
    // /n is better than endl ( it flushes the bios)   
    //cin.ignore() ---> INPUT BUFFER ----\r
    cin.get(name,20, '$'); // 19 strings uthaye as 20 character is the buffer
    cout << " Hello " << name << endl; 
    cout << "Length of name : " << strlen(name) << endl; // cpp cosiders spaces as spearrator 
    // eneter key is a separator, tab key, (limitation of cin)
    // space is counted as character
    // bound checking 

    // I WANT USER TO USE ENETR KEY AS PART OF INPUT FOR THE POEM
    return 0;
}

int my_strlen(char n[]){
    //for i=0 ; i < len(n) ; i++;
    // modify function os that it doesnt count spaces 
    int len = 0;
    int i = 0;
    while (n[i] != '\0'){
        i++;
        len++;
    }
    return len ;
}