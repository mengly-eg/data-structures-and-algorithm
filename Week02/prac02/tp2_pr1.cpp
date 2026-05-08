#include <iostream>
using namespace std;

void display(int n) {
    if (n == 0) {
        return;
    }
    else {
        cout << n << " ";
        display(n - 1);
    }
}

int main() {
    display(10);
    return 0;
}