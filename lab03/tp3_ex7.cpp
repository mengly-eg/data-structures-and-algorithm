#include <iostream>
using namespace std;

void sum1(double *sum, int n) {
    // Calculate sum of 1/1^2 + 1/2^2 + 1/3^2 + ... + 1/n^2
    *sum = 0;
    
    for (int i = 1; i <= n; i++) {
        *sum += 1.0 / (i * i);
    }
}

int main() {
    int n;
    double result;
    
    cout << "Enter a positive integer n: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Error: n must be a positive integer!" << endl;
        return 1;
    }
    
    // Call sum1 function to calculate the sum
    sum1(&result, n);
    
    cout << "Sum of 1/1^2 + 1/2^2 + 1/3^2 + ... + 1/" << n << "^2 = " << result << endl;
    
    return 0;
}
