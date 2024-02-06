#include <iostream>

using namespace std;

// Function to merge two subarrays into one sorted subarray
void Merge(int* numbers, int i, int j, int k) {
    int mergedSize = k - i + 1;
    int mergePos = 0;
    int leftPos = 0;
    int rightPos = 0;
    int* mergedNumbers = new int[mergedSize];

    leftPos = i;
    rightPos = j + 1;

    // Merge elements from left and right subarrays into mergedNumbers
    while (leftPos <= j && rightPos <= k) {
        if (numbers[leftPos] <= numbers[rightPos]) {
            mergedNumbers[mergePos] = numbers[leftPos];
            ++leftPos;
        } else {
            mergedNumbers[mergePos] = numbers[rightPos];
            ++rightPos;
        }
        ++mergePos;
    }

    // If any elements are remaining in the left subarray, add them to mergedNumbers
    while (leftPos <= j) {
        mergedNumbers[mergePos] = numbers[leftPos];
        ++leftPos;
        ++mergePos;
    }

    // If any elements are remaining in the right subarray, add them to mergedNumbers
    while (rightPos <= k) {
        mergedNumbers[mergePos] = numbers[rightPos];
        ++rightPos;
        ++mergePos;
    }

    // Copy mergedNumbers back to the original array 'numbers'
    for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
        numbers[i + mergePos] = mergedNumbers[mergePos];
    }

    delete[] mergedNumbers;
}

// Recursive function to perform Merge Sort
void MergeSort(int* numbers, int i, int k) {
    int j = 0;

    if (i < k) {
        j = (i + k) / 2; // Find the midpoint of the array

        // Recursively sort the left and right subarrays
        MergeSort(numbers, i, j);
        MergeSort(numbers, j + 1, k);

        // Merge the sorted subarrays
        Merge(numbers, i, j, k);
    }
}

int main() {
    int numbers[] = {10, 2, 78, 4, 45, 32, 7, 11};
    int NUMBERS_SIZE = 8;

    cout << "UNSORTED: ";
    for (int i = 0; i < NUMBERS_SIZE; ++i) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    MergeSort(numbers, 0, NUMBERS_SIZE - 1); // Sort the array

    cout << "SORTED: ";
    for (int i = 0; i < NUMBERS_SIZE; ++i) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}
