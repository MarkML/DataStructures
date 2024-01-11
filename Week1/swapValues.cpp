/******************************************************************************
Instructions:

Create a C++ program that swaps the values of two integers using pointers.
Use meaningful variable names to make the code easy to understand.
Prompt the user to enter two integers.
Swap the values of the two integers using pointers and display the swapped values.

*******************************************************************************/
#include <iostream>
using namespace std;

int main() {
    // Declare variables and pointers
    int firstInt, secondInt;
    int* firstPtr = nullptr;
    int* secondPtr = nullptr;

    // Get user input for two integers
    cout << "Enter the first integer: ";
    cin >> firstInt;
    cout << "Enter the second integer: ";
    cin >> secondInt;
    // Display the values before the SWAP
    cout << "begin first integer is: " << firstInt << endl;
    cout << "begin second integer is: " << secondInt << endl;
    
    // Initialize pointers to point to the variables
    firstPtr = &firstInt;
    secondPtr = &secondInt;

    // Swap the values using pointers
    int temp = *firstPtr;
    *firstPtr = *secondPtr;
    *secondPtr = temp;
    

    // Display the swapped values BEFORE the swap and AFTER the swap

    cout << "after swap" << endl;
    cout << "firstInt is: " << firstInt << endl;
    cout << "secondInt is: " << secondInt << endl;
    
    return 0;
}



