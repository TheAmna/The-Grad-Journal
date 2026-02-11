#include <iostream>
using namespace std;

template <typename T>
class my_stack{

    private:
        int len;
        int top = -1;
        T* arr;

    public:

        my_stack(int length=5){
            len = length;
            arr = new T[len];
        }
        
        ~my_stack(){
            delete[] arr;
             arr = nullptr;
        }

        void push(T x){
            if ( top + 1 == len){
                cout << "Stack is full" << endl;
                return ;
            }
            arr[++top] = x;
        }

        // returns item on top of stack w/out removing it
        T peek(){
            if (top < 0) {
            cout << "Stack is empty" << endl;
            return T();   
        }
            return arr[top];
        }

        T pop(){
            if (top < 0){
                cout << "Stack is empty" << endl;
                return T();   
            }
            return arr[top--];
        }

        bool is_empty(){
            return top == -1;
        }

        T stop_max_pop(){
            if (is_empty()){
                return T();
            }      
            T item = pop();
            while (item <= peek() && !is_empty()){
                item = pop();
                // if (is_empty()){
                //     return item;
                // }
            }
            return item;
        }

        void display_stack(){
            for (int i = 0; i <= top; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    };


int main(){
    my_stack<int> s(5);
    s.push(9);
    s.push(4);
    s.push(5);
    s.push(3);
    s.push(2);
    s.display_stack();
    cout << s.stop_max_pop() << endl;
    s.display_stack();
    return 0;
}
