#include <iostream>
using namespace std;

void funct(int n) {
    if (n == 0) {
        return;
    }
    funct(n/2);
    cout << n << " ";
}

int main() {
    funct(5);
    return 0;
}