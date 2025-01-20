
// Relevance to Data Structures:
// Understanding basic pointer operations is crucial for implementing dynamic data structures.
// Pointers allow direct memory access, enabling efficient manipulation of arrays, linked lists, and trees.
// Pointer arithmetic helps traverse arrays or allocate contiguous memory blocks dynamically.

#include <iostream>
using namespace std;
int main()
{
    int arr[] = {1,2,3,4,5};
    
    int *ptr = arr;

    cout << arr << endl; //arr is the address of the first element in the array which is index 0,
    cout << *arr << endl; // dereferencing arr pointer gives us value at the address
    
    cout << arr[0] << endl;
    cout << arr + 1 << endl; // since arr hold integer data type it adds 4 bytes to the base address
    cout << *(arr + 1);

    int A[] = {2,4,5,8,1};
    cout << A << endl;
    cout << &A[0] << endl;
    cout << A[0] << endl;
    cout << *A << endl;
    
    // loop thru to print elements in the array
    for (int i = 0; i < 5; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    // using pointers to interate thru the array we use pointer arithmetic
    // useful in low-level programming or embedded systems to directly access memory
    for (int i = 0; i < 5; ++i) {
        cout << *(A + i) << " ";
    }
    }

