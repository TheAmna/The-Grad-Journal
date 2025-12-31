#include<iostream>
#include<cstring>
using namespace std;


char* my_strcpy(char* dest, char* src){
    char* ptr = dest;
    while (src !='\0'){
        *ptr++ = *src++;
    }
    return dest;
}
int main (){
char dest_arr[] = "\0";
char src_arr[] = "Amna";
cout << my_strcpy(dest_arr, src_arr) <<endl;
}

int my_strlen(char n[]){
    //for i=0 ; i < len(n) ; i++;
    // modify function os that it doesnt count spaces 
    int len = 0;
    int i = 0;
    while (n[i] != '\0'){
        i++;
        len++;
    }
    return len ;
}

int my_strcmp(char* str1, char* str2) {
    while (*str1 != '\0' && *str2 != '\0') { 
        if (*str1 != *str2) {             
            return *str1 - *str2;            
        }
        str1++; 
        str2++; 
    }
    return *str1 - *str2;
}

int my_strcmp(char* str1, char* str2) {
    int i;
    for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++) {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
    }
    return str1[i] - str2[i];
}


/* strcmp compares the two string character by charater using their 
ASCII values. if the result is <0 , there is need for swap like
U > T, so 96-85 > 0 so swap, otherwise 
B < A, so 66-65 < 0 so no swap 
HOWEVER THIS WILL ONLY WORK IF ALL LETTERS ARE UPPERCASE OR LOWER*/

int sort( char myarr[][100], int n){
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
    return 0;
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