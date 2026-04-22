#include <iostream>
using namespace std;

void findMaxMin(int* arr, int *max, int *min) {

    *max = arr[0];
    *min = arr[0];
    
    for (int i = 1; i < 7; i++) {
        if (arr[i] > *max) {
            *max = arr[i];
        }
        if (arr[i] < *min) {
            *min = arr[i];
        }
    }
}

int main() {
    int numbers[7];
    int maxValue, minValue;
    
    cout << "Enter 7 integer numbers:" << endl;
    for (int i = 0; i < 7; i++) {
        cout << "Number " << (i + 1) << ": ";
        cin >> numbers[i];
    }
    
    // Find max and min values using function with pointers
    findMaxMin(numbers, &maxValue, &minValue);

    cout << "\nArray contents: ";
    for (int i = 0; i < 7; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    
    cout << "\nMaximum value: " << maxValue << endl;
    cout << "Minimum value: " << minValue << endl;
    
    return 0;
}
