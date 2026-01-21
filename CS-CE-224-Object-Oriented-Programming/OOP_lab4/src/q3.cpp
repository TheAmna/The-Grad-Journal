#include<iostream>
using namespace std;

int countHoles(char* str_arr){
    if (*str_arr =='\0'){
        return 0;
    }
    if ((*str_arr=='A')|(*str_arr=='D')|(*str_arr=='O')|(*str_arr=='P')|(*str_arr=='Q')|(*str_arr=='R')){
        return 1 + countHoles(str_arr+1);
    }
    else if (*str_arr=='B'){
        return 2 + countHoles(str_arr+1);
    }
    else {return 0 + countHoles(str_arr+1);}
}

int countHoles(int a){
    if (a == 0){
        return 0;
    }
    int digit = a % 10, total_holes;
    if ((digit == 1)|(digit ==2)|(digit==3)|(digit ==5)|(digit==7)){
        return 0 + countHoles(a/10);
    }
    else if ((digit==0)|(digit ==4)|(digit ==6)|(digit ==9)){
        return 1 + countHoles(a/10);
    }
    else {return 2 + countHoles(a/10);}
}

int main(){
    char letter;
    int num, result;
    cout << "Press \'d\'  to enter a number or \'s' to enter string. ";
    cin >> letter;

    if (letter =='s'){
        char sentence[50];
        cin.ignore();
        cin.getline(sentence,50);
        result = countHoles(sentence);
        if (result==1){
            cout << result << " hole.";
        } 
        else {
            cout << result << " holes.";
        }
    }
    else if (letter =='d'){
        cin >> num;
        result = countHoles(num);
        if (result==1){
            cout << result << " hole.";
        } 
        else {
            cout << result << " holes.";
        }
    }
    else {cout << "Please enter valid letters.";}
    return 0;
}