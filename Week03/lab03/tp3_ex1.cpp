#include <iostream>
using namespace std;

int main() {

    int n1 = 7;
    int n2 = 3;
    int n3 = 15;
    
    int *p1 = &n1;
    int *p2 = &n2;
    int *p3 = &n3;
    
    // Part a: Display address and value of n1, n2, n3 using pointers
    cout << "Part a: Display address and value using pointers" << endl;
    cout << "n1 - Address: " << p1 << ", Value: " << *p1 << endl;
    cout << "n2 - Address: " << p2 << ", Value: " << *p2 << endl;
    cout << "n3 - Address: " << p3 << ", Value: " << *p3 << endl;
    
    cout << endl;
    
    // Part b: Update n3 using p3 to be the sum of n1 and n2
    cout << "Part b: Update n3 using p3" << endl;
    cout << "Before: n3 = " << n3 << endl;
    *p3 = *p1 + *p2;  // n3 = n1 + n2 using pointers
    cout << "After: n3 = " << n3 << endl;
    
    return 0;
}
