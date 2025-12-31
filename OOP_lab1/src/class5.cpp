# include<iostream>
using namespace std;
// pointer needed for read and write purposes
// variable name, address, value, storage in bytes
int main(){
    int x = 3;
    int* ptr = &x; // ptr is a pointer that will hold teh address of an int as we initilaized with int ( insert memory address)
    // * tells that address can be assigned only no constants or variables 
    // int is the data type of the element that it is pointing to 
    // ptr, value : 0x61ff08, 
    cout<< "Value of x: " <<x << endl;
    cout << "Address of x : " << &x << endl;
    cout << "Address of x (ptr): " << ptr << endl;
    // * tells it is a pointer , data type tis defined by user 
    return 0;
}
// (*p_d) == *(&d)
// every pointer takes 4/8 bytes 


// Example : Array and Pointer Notation
# include <iostream>
int main () {
    int i, arr [5] = {10 ,20 ,30 ,40 ,50};
    std :: cout << " ***** Using array notation ***** \n";
    for (i=0;i <5; i++)
        std :: cout << " Addr : " << &arr[i] << " Val: " << arr[i] << "\n";
        
        std :: cout << "\n ***** Using pointer notation *****\n";
    for (i=0;i <5; i++)
        std :: cout << " Addr : " << arr+i << " Val: " << *( arr+i) << "\n";
    return 0;
}