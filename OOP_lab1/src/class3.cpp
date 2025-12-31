// arrays are sequential (homogenous), static (dedicated stack), fixed size array
# include <iostream>
using namespace std;

int main(){

    int arr[5] = {22,34,45,23,12};
    cout << "first index value address : " <<  &arr[1]<< "    " << arr[1] << endl;
    cout << "second index value  address: " <<  &arr[2]<< "    " << arr[2] <<  endl;
    cout << "second index value  address: " <<  &arr[3]<<  "    " << arr[3] <<  endl;
    cout << "second index value  address: " <<  &arr[4]<<  "    " << arr[4] << endl;

    //int size = 3; //variable size array VLA (not allowed) -> affects storage;


    //cout << "address of size" << &size << endl;
    //cout << arr << endl;
    //cin >> size;
    // array out of bound 
    // for (int i = 0; i <10; i++)
    //     cout<< &arr[i] << " " << arr[i] << endl;
    
    print_array(arr, 5); // name of the array is the address of the array, arrays are dedicated pointers
    return 0;
}

int print_array(int array[], int size){
    for (int i =0; i <size; i++)
    {cout << array[i] << endl;}
    return 0;

}