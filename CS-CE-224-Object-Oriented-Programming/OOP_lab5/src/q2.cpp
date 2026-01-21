#include<iostream>
using namespace std;

class MyStack{
    private:
        int topOfStack;
        int stack_size, popped_item;
        int * mystack;
    
    public:
        MyStack(int size){   // ctor
            topOfStack = 0;
            mystack = new int[size];
            stack_size = size;
        }
        
        ~MyStack(){ //destructor
            delete[] mystack;
            mystack = nullptr;
        }
    void push(int num){
        if (topOfStack < stack_size){
            mystack[topOfStack] = num;
            topOfStack++;
           }
        else {cout << "Stack is full !";}
    }

    int pop(){
        if (!(isempty())){
            popped_item = mystack[topOfStack-1]; 
            topOfStack = topOfStack-1; 
            return popped_item;
        }
        cout << "No element to pop";
    }

    int top(){
        if (topOfStack != 0)
            return mystack[topOfStack-1];
        else {return -1;}
    }

    bool isempty(){
        if (topOfStack == 0){
            return true;}
        else {return false;}
    }

    void display(){
        if (topOfStack !=0){
            for (int i=0; i < topOfStack ; i++){
                cout << "Stack index " << i << " : " << mystack[i] << endl;
            }
        }
        else {cout << "Stack is empty, nothing to display!";}
    }
};


int main(){
    int pop_result;
    MyStack s1(5);
    s1.push(1);
    s1.push(5);
    s1.push(3);
    s1.push(4);
    s1. display();
    cout << "After pushing 10 : " << endl;
    s1.push(10);
    s1.display();
    pop_result = s1.pop();
    cout << "popped item is : " << pop_result << endl ;
    cout << "Result after popping : " << endl;
    s1.display();
    cout << endl;
    
    cout << "The top of stack is : " << s1.top() << endl;
    cout << "Is stack empty ? : " << s1.isempty() << endl;
    return 0;
}