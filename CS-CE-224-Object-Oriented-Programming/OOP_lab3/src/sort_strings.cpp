#include<iostream>
#include<cstring>
using namespace std;

int my_strcmp(char *str1, char *str2) {
    while (*str1 && *str2 && *str1 == *str2) { 
        str1++; 
        str2++; 
    }
    return *str1 - *str2;
}

/* strcmp compares the two string character by charater using their 
ASCII values. if the result is <0 , there is need for swap like
U > T, so 96-85 > 0 so swap, otherwise 
B < A, so 66-65 < 0 so no swap 
HOWEVER THIS WILL ONLY WORK IF ALL LETTERS ARE UPPERCASE OR LOWER*/

void sort( char myarr[][100], int n){
    for (int i = 0; i<n-1; i++){
        for (int j = 0; j<n-i-1; j++){
        char temp[100];
            if (my_strcmp(*(myarr + j), *(myarr + j + 1)) > 0) {
                strcpy(temp , (*(myarr + j)));
                strcpy((*(myarr + j)), (*(myarr + j +1)));
                strcpy((*(myarr + j +1)), temp);
            }
        }
    }    
}

int main(){
    int n;
    cout << "Enter size of the array: " ;
    cin >> n;
    char mystr[n][100];
    cin.ignore();

    for (int i = 0; i<n; i++){
        cin.getline(mystr[i], sizeof(mystr)); 
    }
    cout << endl;
    sort(mystr, n);
    for (int i = 0; i<n; i++){
        cout << mystr[i] << endl; 
    }
    return 0;
}