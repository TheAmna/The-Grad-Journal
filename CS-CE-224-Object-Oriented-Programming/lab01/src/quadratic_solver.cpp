#include<iostream>
using namespace std;
# include <cmath>

int main(){
    float a,b,c;
    float x1, x2;
    cout << "Enter coefficient a: ";
    cin >> a;
    cout << "Enter coefficient b: ";
    cin >> b;
    cout << "Enter coefficient c: ";
    cin >> c;
    int discriminant =  (pow(b,2)- ((4*a)*c));
    if (discriminant >= 0)
    {
        x1 = -((b+ sqrt(discriminant))/(2*a));
        x2 = -((b- sqrt(discriminant))/(2*a));
        cout << "Solutions : x1 = " << x2 << " , x2 = " << x1;
    }

    else {
        float pt1,pt2;
        pt1 = -(b/(2*a));
        pt2 = sqrt((4*a*c)- pow(b,2)/ (2*a));
        cout << "Solutions : x1 = " << pt1 << '+' << pt2 << "i x2 = " << pt1 << '-' << pt2; 
    }
    return 0;
}