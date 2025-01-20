
//Simple Swap with Single Pointers

/* Swap function pass by reference ("var a and b are alias for variables")
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
*/

#include <iostream>
using namespace std;

void swap(int* a, int* b) {
    int temp = *a;  // Swap values using pointers.  we dereference
    *a = *b;
    *b = temp;
}

int main() {
    int x = 5, y = 10;
    cout << "Before swap: x = " << x << ", y = " << y << endl;
    swap(&x, &y);
    cout << "After swap: x = " << x << ", y = " << y << endl;

    return 0;
}
