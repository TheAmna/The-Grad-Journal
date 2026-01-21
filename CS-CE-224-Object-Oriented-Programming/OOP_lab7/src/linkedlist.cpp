#include <iostream>
using namespace std;

// Node class representing each element in the linked list
class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data =value;
        next = nullptr; }
};

// LinkedList class managing the linked list operations
class LinkedList {
private:
    Node* head;

public:
    LinkedList(){
        head =nullptr;}

    // Function to insert a node at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == 0)
            head = newNode;
        else {
            Node* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    // Function to print all elements in the linked list
    void print() {
        // TODO: Traverse and print all elements
        if (!head){
            cout << "List is empty " << endl;
            return ;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }

    // Function to calculate the length of the linked list
    int length() {
        // TODO: Traverse and count all nodes
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Function to insert before a specific value
    void insertBefore(int target, int newValue) {
        // TODO: Insert newValue before target node
        if (head==0) {
            cout << "List is empty. Cannot insert before " << target << endl;
            return;
        }
        if (head->data == target) {
            Node* newNode = new Node(newValue);
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != target) {
            temp = temp->next;
        }
        if (temp->next == nullptr) {
            cout << "Target value " << target << " not found in the list." << endl;
        } 
        else {
            Node* newNode = new Node(newValue);
            newNode->next = temp->next;
            //temp->next = newNode;
        }
    }

    // Function to insert after a specific value
    void insertAfter(int target, int newValue) {
        // TODO: Insert newValue after target node
        if (!head) {
            cout << "List is empty " << target << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr && temp->data != target) {
            temp = temp->next;
        } 
        if (temp == nullptr) {
            cout << "Target value " << target << " not found in the list." << endl;
        } 
        else {
            Node* newNode = new Node(newValue);
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // Function to insert into sorted list using two pointers
    void insertIntoSorted(int value) {
        Node* newNode = new Node(value);
        
        // Case 1: Empty list
        if (head == nullptr) {
            head = newNode;
            cout << "Inserted " << value << " as first element" << endl;
            return;
        }
        
        // Case 2: Insert at beginning (value is smaller than head)
        if (value < head->data) {
            newNode->next = head;
            head = newNode;
            cout << "Inserted " << value << " at beginning" << endl;
            return;
        }
        
        // Case 3: Insert in middle or end using two pointers
        Node* p = head->next;  // p traverses ahead
        Node* q = head;        // q follows p (one step behind)
        
        // Traverse until we find where to insert
        while (p != nullptr && p->data < value) {
            q = p;
            p = p->next;
        }
        
        // Insert between q and p
        newNode->next = p;  // New node points to p
        q->next = newNode;  // q points to new node
        
        cout << "Inserted " << value << " between " << q->data;
        if (p != nullptr) {
            cout << " and " << p->data;
        } else {
        cout << " and nullptr (at end)";
        }
        cout << endl;
    }

    // Function to delete node before a specific value
    void deleteBefore(int target) {
        // TODO: Delete node before target node
        if (!head || !head->next) {
            cout << "Not enough nodes to delete before " << target << endl;
            return;
        }
        if (head->next->data == target) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr && temp->next->next->data != target) {
            temp = temp->next;
        }
        if (temp->next->next == nullptr) {
            cout << "Target value " << target << " not found or no node before it." << endl;
        } 
        else {
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
        }
    }
    ////////////////////////////////////////
    bool isSorted() {
        if (head == nullptr || head->next == nullptr) {
            return true; // Empty or single node list is always sorted
        }
        
        int prevValue = -2147483648; // Lowest negative value for int (INT_MIN)
        Node* p = head;
        
        while (p != nullptr) {
            if (p->data < prevValue) {
                return false; // Found violation - not sorted
            }
            prevValue = p->data;
            p = p->next;
        }
        return true; // All elements in non-decreasing order
    }

    // Function to sort the list using bubble sort
    void sortList() {
        if (head == nullptr || head->next == nullptr) {
            return; // Empty or single node list is already sorted
        }
        
        bool swapped;
        do {
            swapped = false;
            Node* p = head;
            Node* prev = nullptr;
            
            while (p != nullptr && p->next != nullptr) {
                if (p->data > p->next->data) {
                    // Swap the nodes
                    if (prev == nullptr) {
                        // Swapping head and second node
                        Node* second = p->next;
                        p->next = second->next;
                        second->next = p;
                        head = second;
                    } else {
                        // Swapping middle nodes
                        Node* second = p->next;
                        p->next = second->next;
                        second->next = p;
                        prev->next = second;
                    }
                    swapped = true;
                }
                prev = p;
                p = p->next;
            }
        } while (swapped);
    }

    // Function to check and sort if needed
    void checkAndSort() {
        cout << "Current list: ";
        print();
        
        if (isSorted()) {
            cout << "List is already sorted!" << endl;
        } else {
            cout << "List is NOT sorted. Sorting now..." << endl;
            sortList();
            cout << "Sorted list: ";
            print();
        }
        cout << endl;
    }

    // Function to delete node after a specific value
    void deleteAfter(int target) {
        // TODO: Delete node after target node
        if (!head) {
            cout << "List is empty " << target << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr && temp->data != target) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Target value " << target << " not found in the list." << endl;
        } 
        else if (temp->next == nullptr) {
            cout << "No node after " << target << " to delete." << endl;
        } 
        else {
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
        }
    }
};

// Main function for testing
int main() {
    LinkedList list;
    int n, value;

    cout << "Enter number of elements to insert: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        list.insertAtEnd(value);
    }

    cout << "Initial List: ";
    list.print();

    cout << "Length of list: " << list.length() << endl;

    // Demonstration of insertBefore, insertAfter, deleteBefore, deleteAfter
    cout << "\nInsert a value before a given element:\n";
    list.insertBefore(20, 15); // Example
    list.print();

    cout << "\nInsert a value after a given element:\n";
    list.insertAfter(30, 35); // Example
    list.print();

    cout << "\nDelete node before a given element:\n";
    list.deleteBefore(20);
    list.print();

    cout << "\nDelete node after a given element:\n";
    list.deleteAfter(30);
    list.print();

    return 0;
}
