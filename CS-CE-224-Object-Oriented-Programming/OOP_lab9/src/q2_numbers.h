#include <iostream>
using namespace std;

class NumInterface {
    public:
        virtual void display() const = 0;
        virtual void increment() = 0;
};

class NumWhole : public NumInterface{
    private:
        int val;
    public:
        NumWhole(){}
        NumWhole(int value){
            val = value;}
            
        int getVal() const {
            return val;}
        void setVal(int value){
            val = value;}
        void display() const {
            cout << val;}
        void increment(){
            val++;}
        NumWhole operator+(const NumWhole n) const {
            NumWhole res; 
            res.val = val + n.val;
            return res;
        }
};

class NumComplex: public NumInterface{
    private:
        int real, imag;
    public:
        NumComplex(){}
        NumComplex(int r, int i){real = r; imag = i;}
        int getReal() const {return real;}
        int getImag() const {return imag;}
        void setReal(int r){real = r;}
        void setImag(int i){imag = i;}
        void display() const {
            cout << "(" << real;
        if (imag >= 0)
            cout << "+" << imag << "i";
        else
            cout << imag << "i";  // imag is negative, so -5i
        cout << ")";
        }
        void increment(){real++; imag++;}
        NumComplex operator+(const NumComplex& n) const {
            return NumComplex(real + n.real, imag + n.imag);
        }
};
