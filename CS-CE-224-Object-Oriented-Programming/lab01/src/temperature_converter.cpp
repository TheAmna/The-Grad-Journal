#include<iostream>
using namespace std;

int main(){
    int temp, resultF, resultC;
    char  unit;
    cout << "Enter temperature : ";
    cin >> temp;
    cout << "Enter unit (C/F) : ";
    cin >> unit;
    if (unit == 'C')
    {
    resultF = ((160 + (9*temp))/5);
    cout << "Temperature in Farenheit: "<< resultF;
    }
    else if (unit == 'F')
    {
        resultC = (((5*temp) - 160)/ 9);
        cout << "Temperature in Celcius: "<< resultC;
    }
    
    return 0;
}