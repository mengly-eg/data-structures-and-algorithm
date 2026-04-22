#include <iostream>
#include <cmath>
using namespace std;

void solveEquation(int a, int b, int c, float *x1, float *x2, float *delta) {

    *delta = b * b - 4 * a * c;

    if (*delta >= 0) {
        *x1 = (-b + sqrt(*delta)) / (2 * a);
        *x2 = (-b - sqrt(*delta)) / (2 * a);
    } else {
        *x1 = 0;
        *x2 = 0;
    }
}

int main() {
    int a, b, c;
    float x1, x2, delta;
    
    cout << "Solve quadratic equation: ax^2 + bx + c = 0" << endl;
    cout << "Enter coefficient a (a != 0): ";
    cin >> a;
    
    if (a == 0) {
        cout << "Error: a cannot be 0 for quadratic equation!" << endl;
        return 1;
    }
    
    cout << "Enter coefficient b: ";
    cin >> b;
    
    cout << "Enter coefficient c: ";
    cin >> c;
    
    // Solve the equation using function with pointers
    solveEquation(a, b, c, &x1, &x2, &delta);

    cout << "\nResults:" << endl;
    cout << "Delta (Discriminant): " << delta << endl;
    
    if (delta < 0) {
        cout << "No real roots (discriminant is negative)" << endl;
    } else if (delta == 0) {
        cout << "One root: x = " << x1 << endl;
    } else {
        cout << "Two roots:" << endl;
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }
    
    return 0;
}
