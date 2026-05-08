#include <iostream>
using namespace std;

void display(int n) {
    if (n == 0) {
        return;
    }
    else {
        display(n-1);
        cout << n << " ";
    }
}

int main() {
    display(10);
    return 0;
}