#include<iostream>
using namespace std ;

double* add(double* c1, double* c2) {
    double* result = new double[2];
    result[0] = c1[0] + c2[0];  
    result[1] = c1[1] + c2[1]; 
    return result;
}

double* add(double* c1, int real) {
    double* result = new double[2];
    result[0] = c1[0] + real;  
    result[1] = c1[1];    
    return result;        
}

double* subtract(double* c1, double* c2) {
    double*result = new double[2];
    result[0] = c1[0] - c2[0];  
    result[1] = c1[1] - c2[1];  
    return result;
}

double* subtract(double* c1, int real) {
    double* result = new double[2];
    result[0] = c1[0] - real; 
    result[1] = c1[1];      
    return result;      
}

double* multiply(double* c1, double* c2) {
    double* result = new double[2];
    result[0] = c1[0] * c2[0] - c1[1] * c2[1];  
    result[1] = c1[0] * c2[1] + c1[1] * c2[0]; 
    return result; 
}

double* multiply(double* c1, int real) {
    double* result = new double[2];
    result[0] = c1[0] * real;  
    result[1] = c1[1] * real;
    return result; 
}

void show(double* complex) {
    cout << complex[0];
    if (complex[1] >= 0) {
        cout << " + " << complex[1] << "i";
    } else {
        cout << " - " << -complex[1] << "i";
    }
}

int main(){
    double  c1[2], c2[2], d1;
    double* result;
    cout << "Enter c1:" ;
    cin >> c1[0] >> c1[1];
    cout << "Enter c2:" ;
    cin >> c2[0] >> c2[1];
    cout << "Enter d1:" ;
    cin >> d1;

    cout << "c1+c2: ";
    result = add(c1, c2);
    show(result);
    
    cout << "\nc1-c2: ";
    result = subtract(c1, c2);
    show(result) ;
    
    cout << "\nc1*c2: ";
    result = multiply(c1, c2);
    show(result);
  
    cout << "\nc1+d1: ";
    result = add(c1, d1);
    show(result);
 
    cout << "\nc1-d1: ";
    result = subtract(c1, d1);
    show(result);
    
    cout << "\nc1*d1: ";
    result = multiply(c1, d1);
    show(result);
    return 0;

}