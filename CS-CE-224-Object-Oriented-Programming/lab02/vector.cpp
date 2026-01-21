#include<iostream>
using namespace std;

int print_vector(int size,int vector[]){
    for(int i = 0; i < size; i++){
        cout << vector[i] << " ";
    return 0;}
    }

int input_vector(int size, int vector[]){
    for (int i = 0; i < size; i++){
        cin >> vector[i];
    return 0; }
    }

int add_vectors(int size, int vector1[], int vector2[], int vector3[]){
    for (int i = 0; i < size; i++){
        vector3[i] = vector1[i] + vector2[i];
    return 0;}
    }

int subtract_vectors(int size, int vector1[], int vector2[], int vector3[]){
    for (int i = 0; i < size; i++){
        vector3[i] = vector1[i] - vector2[i];
    return 0;}
    }

bool compare_vectors(int size, int vector1[], int vector2[]){
    bool value = true;
    for (int i = 0; i < size; i++){
        if (vector1[i] != vector2[i]) {
            value = false; 
            break;}
        }
    return value;
    }

int main(){
    // cin acts like a buffer so input is 5483 , enter 5 4 8 3 , press enter cin is automatically gonna strip
    // run for loop, inside for loop cin array in the correct index 
    // cout the message, the user will enter nos in a line, inside for loop,c hanging value of i 
    int size; 
    cin >> size;
    int vector1[size], vector2[size], vector3[size];
    input_vector(size, vector1); input_vector(size, vector2);
    char sign; 
    cin >> sign;
    bool value;
    switch(sign){
        case '+':
            add_vectors(size, vector1, vector2, vector3);
            print_vector(size, vector3);
            break;
        case '-':
            subtract_vectors(size, vector1, vector2, vector3);
            print_vector(size, vector3);
            break;
        case '=':
            value = compare_vectors(size, vector1, vector2);
            if(value == true){
                cout << "Vectors Equal";}
            else 
            {cout << "Vectors Not Equal";}}    
    return 0;
}