// #include <iostream>
// #include <iomanip>
// using namespace std;

// int main() {
//     int size, maxCount=0, mode=0, arr[100];
//     cout << "Enter number of values: ";
//     cin >> size;
//     double sum = 0, mean=0, median= 0;

//     for (int i = 0; i < size; i++) {
//         cout << "Enter value " << (i + 1) << ": ";
//         cin >> *(arr + i);
//         sum += *(arr + i);
//     }
//     mean = sum / size;
//     // flag to check if median is present 
//     bool mean_flag = false;
//     for (int i = 0; i < size; i++) {
//         if (*(arr + i) == mean) {
//             mean_flag = true;
//             break;
//         }
//     }
//     int sort_arr[100];
//     for (int i = 0; i < size; i++) {
//         *(sort_arr + i) = *(arr + i);}
//     //bubblesort with pointer
//     for (int i = 0; i < size - 1; i++) {
//         for (int j = 0; j < size - i - 1; j++) {
//             if (*(sort_arr + j) > *(sort_arr + j + 1)) {
//                 int temp = *(sort_arr + j);
//                 *(sort_arr + j) = *(sort_arr + j + 1);
//                 *(sort_arr + j + 1) = temp;
//             }
//         }
//     }
//     if (size % 2 == 1) {
//         median = *(sort_arr + size / 2);
//     } 
//     else {
//         median = (*(sort_arr + size / 2 - 1) + *(sort_arr + size / 2)) / 2.0;
//     }
//     bool median_flag = false;
//     for (int i = 0; i < size; i++) {
//         if (*(arr + i) == median) {
//             median_flag = true;
//             break;
//         }
//     }
//     //mode flag to check if mode is present
//     bool mode_flag = false;
//     for (int i = 0; i < size; i++) {
//         int count = 0;
//         int current = *(arr + i);
//         for (int j = 0; j < size; j++) {
//             if (*(arr + j) == current) {
//                 count++;
//             }
//         }
//         if (count > maxCount) {
//             maxCount = count;
//             mode = current;
//             mode_flag = true;
//         }
//         else if (count == maxCount && count > 1) {
//             if (current > mode) {
//                 mode = current;
//                 mode_flag = true;
//             }
//         }
//     }
//     if (maxCount == 1) {
//         mode_flag = false;
//     }
//     cout << "Mean: " << mean;
//     if (mean_flag) {
//         cout << " (present)"<< endl;
//     } else {
//         cout << " (not present)"<< endl;
//     }
    
//     cout << "Median: " << median;
//     if (median_flag) {
//         cout << " (present)" << endl;
//     } else {
//         cout << " (not present)" << endl;
//     }
    
//     cout << "Mode: ";
//     if (mode_flag) {
//         cout << mode << " (present)"<< endl;
//     } else {
//         cout << "None (not present)" << endl;
//     }
//     return 0;
// }

#include <iostream>
#include <iomanip>
using namespace std;

void computeStatistics(int* arr, int size, double* mean, double* median, int* mode, 
                      bool* meanPresent, bool* medianPresent, bool* modePresent) {
    // Calculate mean
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += *(arr + i);
    }
    *mean = sum / size;
    
    // Check if mean is present in array
    *meanPresent = false;
    for (int i = 0; i < size; i++) {
        if (*(arr + i) == *mean) {
            *meanPresent = true;
            break;
        }
    }
    
    // Create a copy and sort the array for median calculation
    int* sortedArr = new int[size];
    for (int i = 0; i < size; i++) {
        *(sortedArr + i) = *(arr + i);
    }
    
    // Bubble sort using pointer notation
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (*(sortedArr + j) > *(sortedArr + j + 1)) {
                int temp = *(sortedArr + j);
                *(sortedArr + j) = *(sortedArr + j + 1);
                *(sortedArr + j + 1) = temp;
            }
        }
    }
    
    // Calculate median
    if (size % 2 == 1) {
        *median = *(sortedArr + size / 2);
    } else {
        *median = (*(sortedArr + size / 2 - 1) + *(sortedArr + size / 2)) / 2.0;
    }
    
    // Check if median is present in original array
    *medianPresent = false;
    for (int i = 0; i < size; i++) {
        if (*(arr + i) == *median) {
            *medianPresent = true;
            break;
        }
    }
    
    // Calculate mode
    int maxCount = 0;
    *mode = 0;
    *modePresent = false;
    
    for (int i = 0; i < size; i++) {
        int count = 0;
        int current = *(arr + i);
        
        // Count frequency of current element
        for (int j = 0; j < size; j++) {
            if (*(arr + j) == current) {
                count++;
            }
        }
        
        // Update mode based on rules
        if (count > maxCount) {
            maxCount = count;
            *mode = current;
            *modePresent = true;
        } else if (count == maxCount && count > 1) {
            // If tie, choose the largest value
            if (current > *mode) {
                *mode = current;
                *modePresent = true;
            }
        }
    }
    
    // If all values occur only once, no mode exists
    if (maxCount == 1) {
        *modePresent = false;
    }
    
    // Clean up dynamic memory
    delete[] sortedArr;
}

int main() {
    int size;
    cout << "Enter number of values: ";
    cin >> size;
    
    int* arr = new int[size];
    
    cout << "Enter " << size << " values:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Value " << (i + 1) << ": ";
        cin >> *(arr + i);
    }
    
    // Variables to store results
    double mean, median;
    int mode;
    bool meanPresent, medianPresent, modePresent;
    
    // Compute statistics
    computeStatistics(arr, size, &mean, &median, &mode, 
                     &meanPresent, &medianPresent, &modePresent);
    
    // Display results
    cout << fixed << setprecision(2);
    cout << "\nResults:" << endl;
    cout << "Mean: " << mean << " (" << (meanPresent ? "present" : "not present") << ")" << endl;
    cout << "Median: " << median << " (" << (medianPresent ? "present" : "not present") << ")" << endl;
    cout << "Mode: ";
    if (modePresent) {
        cout << mode << " (present)" << endl;
    } else {
        cout << "None (not present)" << endl;
    }
    
    // Clean up
    delete[] arr;
    return 0;
}