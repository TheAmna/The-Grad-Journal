#include<iostream>
using namespace std;

class Complex{
    private:
        double real, real_sum;
        double imaginary, imaginary_sum;

    public:
        Complex(){ // ctor1
            real = 0;
            imaginary = 0;
            real_sum =0;
            imaginary_sum = 0;
        }
        Complex(double r, double i){ //ctor
            real = r;
            imaginary = i;
            real_sum =0;
            imaginary_sum = 0;
        }

    Complex add(Complex c){
        real_sum = real + c.real;
        imaginary_sum = imaginary + c.imaginary;
        Complex final_result(real_sum,  imaginary_sum);
        return final_result;
    }

    Complex add(double d){
        real_sum = real +d;
        imaginary_sum = imaginary;
        Complex final_result(real_sum,  imaginary_sum);
        return final_result;
    }

    Complex subtract(Complex c){
        real_sum = real - c.real;
        imaginary_sum = imaginary - c.imaginary;
        Complex final_result(real_sum,  imaginary_sum);
        return final_result;
    }
    
    Complex subtract(double d){
        real_sum = real - d;
        imaginary_sum = imaginary;
        Complex final_result(real_sum,  imaginary_sum);
        return final_result;
    }

    Complex multiply(Complex c){
        real_sum = (real * c.real) - (imaginary*c.real);
        imaginary_sum = (real * c.imaginary) + (imaginary*c.real);
        Complex final_result(real_sum,  imaginary_sum);
        return final_result;
    }

    Complex multiply(double d){
        real_sum = real * d;
        imaginary_sum = imaginary *d;
        Complex final_result(real_sum,  imaginary_sum);
        return final_result;
    }


   void show(){
    cout << real << " + " << imaginary << "i" << endl;
   }

};


int main(){
    double real , imag ;
    cin >> real>> imag;
    Complex c1 = {real , imag };
    cin >>real >> imag ;
    Complex c2 = {real , imag };
    double d1;
    cin >>d1;
    Complex result;
    // showing the numbers :
    cout <<"c1: "; c1. show () ;
    cout <<"c2: "; c2. show () ;
    cout <<"d1: " <<d1 << endl ;
    // Check the opertions where both operands are complex
    result = c1. add (c2) ;
    cout <<"c1+c2: "; result . show () ;
    result = c1. subtract (c2);
    cout <<"c1-c2: "; result . show () ;
    result = c1. multiply (c2);
    cout <<"c1*c2: "; result . show () ;
    // Check the opertions where one operator is complex , other is double
    result = c1. add (d1) ;
    cout <<"c1+d1: "; result . show () ;
    result = c1. subtract (d1);
    cout <<"c1-d1: "; result . show () ;
    result = c1. multiply (d1);
    cout <<"c1*d1: "; result . show () ;

    return 0;
}