#include <iostream>
using namespace std;

int Partition(int* numbers, int lowIndex, int highIndex) {
   // Pick middle element as pivot
   int midpoint = lowIndex + (highIndex - lowIndex) / 2;
   int pivot = numbers[midpoint];
   
   bool done = false;
   while (!done) {
      // Increment lowIndex while numbers[lowIndex] < pivot
      while (numbers[lowIndex] < pivot) {
         lowIndex += 1;
      }
      
      // Decrement highIndex while pivot < numbers[highIndex]
      while (pivot < numbers[highIndex]) {
         highIndex -= 1;
      }
      
      // If zero or one elements remain, then all numbers are 
      // partitioned. Return highIndex.
      if (lowIndex >= highIndex) {
         done = true;
      }
      else {
         // Swap numbers[lowIndex] and numbers[highIndex]
         int temp = numbers[lowIndex];
         numbers[lowIndex] = numbers[highIndex];
         numbers[highIndex] = temp;
         
         // Update lowIndex and highIndex
         lowIndex += 1;
         highIndex -= 1;
      }
   }
   
   return highIndex;
}

void Quicksort(int* numbers, int startIndex, int endIndex) {
   // Base case: If the partition size is 1 or zero 
   // elements, then the partition is already sorted
   if (startIndex >= endIndex) {
      return;
   }
   
   // Partition the data within the array. Value lowEndIndex 
   // returned from partitioning is the index of the low 
   // partition's last element.
   int lowEndIndex = Partition(numbers, startIndex, endIndex);
   
   // Recursively sort low partition (lowIndex to lowEndIndex) 
   // and high partition (lowEndIndex + 1 to highIndex)
   Quicksort(numbers, startIndex, lowEndIndex);
   Quicksort(numbers, lowEndIndex + 1, endIndex);
   
}

// String representation simplifies the process of showing the array's contents.
string ArrayToString(int* array, int arraySize) {
   // Special case for empty array
   if (0 == arraySize) {
      return string("[]");
   }
   
   // Start the string with the opening '[' and element 0
   string result = "[" + to_string(array[0]);
   
   // For each remaining element, append comma, space, and element
   for (int i = 1; i < arraySize; i++) {
      result += ", ";
      result += to_string(array[i]);
   }
   
   // Add closing ']' and return result
   result += "]";
   return result;
}

int main() {
   int numbers[] = { 10, 2, 78, 4, 45, 32, 7, 11 };
   int size = 8;
  
   
   cout << "UNSORTED: " << ArrayToString(numbers, size) << endl;
   
  
   // Initial call to quicksort
   Quicksort(numbers, 0, size - 1);
   
   cout << "SORTED: " << ArrayToString(numbers, size) << endl;
   
}