#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Seed the random number generator
    srand(time(nullptr));

    int numRows, numCols;

    // Get the number of rows and columns from the user
    cout << "Enter the number of rows: ";
    cin >> numRows;
    cout << "Enter the number of columns: ";
    cin >> numCols;

    // Allocate memory for the 2D array using pointers
    int** matrix = new int*[numRows];
    for (int i = 0; i < numRows; ++i) {
        matrix[i] = new int[numCols];
    }

    // Populate the array with random integer values between 1 and 100
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            matrix[i][j] = rand() % 100 + 1;
        }
    }

    // Display the array
    cout << "\n2D Array:" << endl;
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }

    // Calculate the sum of all values in the array
    int sum = 0;
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            sum += matrix[i][j];
        }
    }

    // Display the sum
    cout << "\nSum of all values in the array: " << sum << endl;

    // Deallocate memory used by the array
    for (int i = 0; i < numRows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    cout << "\nMemory deallocated." << endl;

    return 0;
}
