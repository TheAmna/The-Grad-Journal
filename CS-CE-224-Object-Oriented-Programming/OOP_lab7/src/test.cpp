// #include <iostream>
// using namespace std;

// class Node{
//     public:
//         int data;
//         Node * next;

//     Node(int value){
//         data = value;
//         next = nullptr;
//     }
// };

// class LinkedList{
//     private:
//         Node* head;

//     public:

//     void insertAtEnd(int value){
//         Node* newNode = new Node(value);
//         if (head == 0){
//             newNode = head;   
//         }
//         else {
//             Node * temp = head;
//         while (temp-> next != nullptr){
//                 temp = temp->next;
//             temp->next = newNode;
//             }
//         }

//     }

//     void print(){
//         Node* temp = head;
//         if (head == 0){
//             cout << "list is empty "<< endl;
//             return;
//         }
//         while (temp-> next != nullptr){
//             cout << temp->data<<endl;
//             temp = temp->next;
//         }
//         cout << "nullptr" << endl;
//     }
// };
class base{
    public: int x;
    protected : int y;
    private: int y;
};

class publicDerived: public base{
    // x is public 
    // y is protected for objects of this class
    // z is not accessible for publicDerived
};

class protectedDerived: protected base{

};