/******************************************************************************
Instructions:

Create a C++ program that finds the maximum value in an array of integers using pointers.
Use meaningful variable names and comments to make the code easy to understand.
Prompt the user to enter the number of elements in the array and the array elements.
Find the maximum value in the array using pointers and display it.


*******************************************************************************/
#include <iostream>

using namespace std;

int main() {
    int numElements;
    int* maxPtr = nullptr;

    cout << "Enter the number of elements in the array: ";
    cin >> numElements;

    int arr[numElements]; // Array allocated on the stack

    cout << "Enter " << numElements << " integers separated by spaces: ";
    for (int i = 0; i < numElements; i++) {
        cin >> arr[i];
    }

    maxPtr = &arr[0];

    for (int i = 1; i < numElements; i++) {
        if (arr[i] > *maxPtr) {
            maxPtr = &arr[i];
        }
    }

    cout << "\nThe maximum value in the array is: " << *maxPtr << endl;

    return 0;
}

