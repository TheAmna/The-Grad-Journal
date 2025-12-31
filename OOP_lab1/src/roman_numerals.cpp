#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter integer between 1 and 3999 : ";
    cin >> num;
    cout << "The roman numeral is : " << RomanNum(num);
    return 0;
}

int RomanNum(int num) {
    if (num <= 0 || num > 3999) {
        cout << "invalid input";
        return 0;}
    
    int thousands = num / 1000;
    for (int i = 0; i < thousands; i++) {
        cout << "M";
    }
    num %= 1000;

    int hundreds = num / 100;
    if (hundreds == 9) {
        cout << "CM";}
    else if (hundreds >= 5) {
        cout << "D";
        for (int i = 0; i < hundreds - 5; i++) {
            cout << "C";
        }
    } 
    else if (hundreds == 4) {
        cout << "CD";}
    else {
        for (int i = 0; i < hundreds; i++) {
            cout << "C";
        }
    }
    num %= 100;
    
    int tens = num / 10;
    if (tens == 9) {
        cout << "XC";}
    else if (tens >= 5) {
        cout << "L";
        for (int i = 0; i < tens - 5; i++) {
            cout << "X";
        }}
    else if (tens == 4) {
        cout << "XL";} 
    else {
        for (int i = 0; i < tens; i++) {
            cout << "X";
        }
    }
    num %= 10;
    
    if (num == 9) {
        cout << "IX";} 
    else if (num >= 5) {
        cout << "V";
        for (int i = 0; i < num - 5; i++) {
            cout << "I";
        }
    } 
    else if (num == 4) {
        cout << "IV";
    } 
    else {
        for (int i = 0; i < num; i++) {
            cout << "I";
        }
    }
}

