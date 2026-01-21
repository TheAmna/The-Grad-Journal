#include<iostream>
using namespace std;

template <typename T>
class my_stack{
    private:
        int N;
        T* arr;
        int index;
    public:
        my_stack(){
            N=0;
            index=-1;
        }
        my_stack(T number){
            N=number;
            index=-1;
            arr=new T[N];
        }
        void push(T data){  
            if( isFull()==false){
                index++;
                arr[index]=data;
            }
        }
        T top(){
            return arr[index];
        }
        T pop(){
            if ( isEmpty()==false){
                return arr[index--];
            }
            else{
                cout<<"List is Empty"<<endl;
                return -1;
            }

        }
        bool isEmpty(){
            if (index!=-1){
                return false;
            }else{
                return true;
            }
        }
        bool isFull(){
            if (index==N){
                return true;
            }else{
                return false;
            }

        }
        ~ my_stack(){
            delete []arr;

        }

};


int main(){

    my_stack<int> s(10);
    for (int i =0; i<10; i++){
        s.push(i);
    }
    cout << s.isFull();
    while (!s.isEmpty()){
        cout << s.top();
        s.pop();
    }
    s.pop();
    return 0;
}


//     int input;
//     cout<<"Enter size of stack: ";
//     cin>>input;
//     stack call(input);
//     call.push(1);
//     call.push(5);
//     call.push(3);
//     call.push(4);
//     call.push(10);
//     cout<<"Is stack Full?:  "<< call.isFull() <<endl;
//     cout<<"top element that is removed: "<<call.pop()<<endl;
//     cout<<"top element is: "<<call.top()<<endl;
//     cout<<"Is stack empty?:  "<< call.isEmpty() <<endl;
