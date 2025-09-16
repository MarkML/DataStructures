/*
binary search, checks the middle element of the list first. The list must be sorted first, then binary search checks the middle element in the list to match.
binary search will then search the first half and otherwise the last half. Each step reduces the "search space" that need to be searched by half.
*/

#include <iostream>
using namespace std;

int BinarySearch(const int* numbers, int numbersSize, int key) {
   int low = 0;
   int high = numbersSize - 1;
   
   while (high >= low) {
      int mid = (high + low) / 2;
      if (numbers[mid] < key) {
         low = mid + 1;
      }
      else if (numbers[mid] > key) {
         high = mid - 1;
      }
      else {
         return mid;
      }
   }
   
   return -1; // not found
}
   
int main() {
   int numbers[] = { 2, 4, 7, 10, 11, 32, 45, 87 };
   const int numbersSize = sizeof(numbers) / sizeof(numbers[0]);
   int key = 0;
      
   cout << "NUMBERS: ";
   for (int i = 0; i < numbersSize; i++) {
      cout << numbers[i] << " ";
   }
   cout << endl;
      
   cout << "Enter a value: ";
   cin >> key;
      
   int keyIndex = BinarySearch(numbers, numbersSize, key);
      
   if (keyIndex == -1) {
      cout << key << " was not found." << endl;
   }
   else {
      cout << "Found " << key << " at index " << keyIndex << "." << endl;
   }
   
   return 0;
}
