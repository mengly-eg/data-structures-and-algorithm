#include <iostream>
using namespace std;

void exchange(float *a, float *b) {

    float temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    float num1, num2;
    
    cout << "Enter first number: ";
    cin >> num1;
    
    cout << "Enter second number: ";
    cin >> num2;
    
    cout << "\nBefore exchange:" << endl;
    cout << "num1 = " << num1 << ", num2 = " << num2 << endl;
    
    // Call exchange function with pointers
    exchange(&num1, &num2);

    cout << "\nAfter exchange:" << endl;
    cout << "num1 = " << num1 << ", num2 = " << num2 << endl;
    
    return 0;
}
