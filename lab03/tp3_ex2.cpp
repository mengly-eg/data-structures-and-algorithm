#include <iostream>
using namespace std;

int main() {
    int n;
    
    cout << "Enter a number: ";
    cin >> n;
    
    // Create pointer to n
    int *p = &n;
    
    cout << "Original value of n: " << n << endl;
    
    // Modify n to n+7 using pointer operation
    *p = *p + 7;
    
    // Display the modified value
    cout << "Modified value of n: " << n << endl;
    
    return 0;
}
