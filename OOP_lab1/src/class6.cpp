#include<iostream>
#include<cstring>
using namespace std;

char* my_strcpy(char* dest, char* src){
    char* ptr = dest;
    while (*src !='\0'){
        *ptr++ = *src++;
    }
    return dest;
}
int main (){
char dest_arr[] = "";
char src_arr[] = "Amna";
cout << my_strcpy(dest_arr, src_arr) <<endl;
return 0;
}
int main (){
    // int arr[2][3] ={{1,2,3},{4,5,6}};
    // cout << *(*(arr+1)+2);

    // int y = 888;
    // {
    //     int y = 99;
    //     cout << y << endl; // 99
    // }
    // return 0;

    // int y = 888;
    // {
    //     int yy = 99;
    //     cout << y << endl;
    // }
    // return 0;
    
    int y = 888;
    {
        int yy = 99;
        int * p = &yy;
        cout << "value of yy : " << yy << "address of P: "<< p << endl;
    }
    //cout << "value of yy : " << *p << endl;
    return 0;

    
}