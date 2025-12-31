#include<iostream>
using namespace std;

int main(){
    int a;
    cout << "Enter amount : ";
    cin >> a;
    int quotient, remainder,remainder1, quotient1, remainder2, quotient2,  remainder3, quotient3;
    int quotient4, remainder4,remainder5, quotient5, remainder6, quotient6;
    int quotient7, remainder7,remainder8, quotient8, remainder9, quotient9;

    remainder = a %  5000;
    quotient = a / 5000;
    cout << "5000 : " << quotient << "\n";

    remainder1 = remainder % 1000;
    quotient1 = remainder / 1000;
    cout << "1000 : " << quotient1 << "\n";

    remainder2 = remainder1 % 500;
    quotient2 = remainder1 / 500;
    cout << "500 : " << quotient2 << "\n";

    remainder3 = remainder2 % 100;
    quotient3 = remainder2 / 100;
    cout << "100 : " << quotient3 << "\n";

    remainder4 = remainder3 % 50;
    quotient4 = remainder3 / 50;
    cout << "50 : " << quotient4 << "\n";

    remainder5 = remainder4 % 20;
    quotient5 = remainder4 / 20;
    cout << "20 : " << quotient5 << "\n";

    remainder6= remainder5 % 10; 
    quotient6 = remainder5 /10;
    cout << "10 : " << quotient6 << "\n";

    remainder7 = remainder6 % 5;
    quotient7 = remainder6/ 5;
    cout << "5 : " << quotient7 << "\n";

    remainder8 = remainder7 % 2;
    quotient8 = remainder7 / 2;
    cout << "2 : " << quotient8 << "\n";

    remainder9 = remainder8 % 1;
    quotient9 = remainder8 / 1;
    cout << "1 : " << quotient9 << "\n";
    return 0;
}
