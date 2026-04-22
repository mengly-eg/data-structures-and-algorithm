#include <iostream>
using namespace std;

int main() {
    float numbers[7];
    float *ptr = numbers;

    cout << "Enter 7 float numbers:" << endl;
    for (int i = 0; i < 7; i++) {
        cout << "Number " << (i + 1) << ": ";
        cin >> *(ptr + i);
    }
    
    cout << endl;
    
    // Part a: Display all numbers using pointer variable
    cout << "Part a: Display all numbers using pointer operation:" << endl;
    float *displayPtr = numbers;
    for (int i = 0; i < 7; i++) {
        cout << *(displayPtr + i) << " ";
    }
    cout << endl << endl;
    
    // Part b: Compute summation and multiplication
    cout << "Part b: Compute summation and multiplication:" << endl;
    
    float sum = 0;
    float product = 1;
    
    for (int i = 0; i < 7; i++) {
        sum += *(ptr + i);
        product *= *(ptr + i);
    }
    
    cout << "Summation of all numbers: " << sum << endl;
    cout << "Multiplication of all numbers: " << product << endl;
    
    return 0;
}
