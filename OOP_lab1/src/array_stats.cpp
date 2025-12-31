#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int value, num, arr_val;
    double sum = 0, avg = 0, count = 0;
    int myarr[100];
    cout << "Enter number of values: " << "\n";
    cin >> value;

    for (int i =0; i<value; i++){
        cout << "Enter value " << i+1 << ": ";
        cin >> num;
        *(myarr+i) = num;
        sum = sum + num;
        count += 1;
    }

    int minimum = *(myarr), maximum = *(myarr);
    avg = sum/count;
    double sd_sum = 0;
    
    for (int i=0; i<value;i++){
        arr_val = *(myarr+i);
        cout << arr_val << endl;
        if (arr_val < minimum){
            minimum = arr_val;
        }
        if (arr_val > maximum){
            maximum = arr_val;
        }
        double diff = *(myarr + i) - avg;
        sd_sum += pow(diff, 2);
    }
    double std_deviation = sqrt(sd_sum / value);

    cout << "Minimum: " << minimum << endl;
    cout << "Maximum: " << maximum << endl;
    cout << "Average: " << avg << endl;
    cout << "Standard Deviation: " << std_deviation << endl;
    return 0;
}

