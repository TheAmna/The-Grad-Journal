#include<iostream>
using namespace std;

template <typename T>
class my_array{
    private:
        T* a;
        int length;

    public:
        //ctor
        my_array(int len){
            length = len;
            a = new T[length];
        }

        //copy ctor
        my_array(const my_array& other){
            length = other.length;
            a = new T[length];
            for(int i = 0; i < length; i++){
                a[i] = other.a[i];
            }
        }

        //dtor
        ~my_array(){
            delete[] a;
        }

        //overloading [] operator
        T& operator[](int index){
            if ( index >= 0 && index < length){
                return a[index];
            }
        }

        //overloading = operator (assignment)
        my_array& operator=(const my_array& other){
            if(this != &other){
                delete[] a;
                length = other.length;
                a = new T[length];
                for(int i = 0; i < length; i++){
                    a[i] = other.a[i];
                }
            }
            return *this;
        }
};