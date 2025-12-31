#include<iostream>
using namespace std;
# include <cmath>

int main(){
    float h = (19*18)/3.28084;
    float g = 9.81;
    float t;
    t = sqrt((2*h)/g);
    cout << "time to reach ground is : " << t;
    return 0;
}