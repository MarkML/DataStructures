#include <iostream>

using namespace std; 

class GenericQueue {
private:
    static const int maxSize = 100; // Maximum size of the queue (static and constant)
    int elements[maxSize]; // Array to store elements
    int frontIndex; // Index of the front element
    int rearIndex; // Index of the rear element

public:
    // Constructor: Initialize an empty queue
    GenericQueue() {
        frontIndex = -1; // Initialize frontIndex to -1 to indicate an empty queue
        rearIndex = -1; // Initialize rearIndex to -1 to indicate an empty queue
    }

    // Enqueue operation: Adds an item to the rear of the queue
    void enqueue(int item) {
        if (!isFull()) {
            if (isEmpty()) {
                frontIndex = 0; // Set frontIndex to 0 for the first element
            }
            rearIndex++; // Increment rearIndex to insert the item
            elements[rearIndex] = item;
        } else {
            cout << "Queue is full! Cannot enqueue " << item << "." << endl;
        }
    }

    // Dequeue operation: Removes the item from the front of the queue
    void dequeue() {
        if (!isEmpty()) {
            // Increment frontIndex to remove the front element
            frontIndex++;
            if (frontIndex > rearIndex) {
                // If frontIndex crosses rearIndex, reset both to indicate an empty queue
                frontIndex = -1;
                rearIndex = -1;
            }
        } else {
            cout << "Queue is empty! Cannot dequeue." << endl;
        }
    }

    // Peek method: Return the element at the front of the queue without removing it
    int Peek() {
        if (!isEmpty()) {
            return elements[frontIndex];
        }
        cout << "Queue is empty! No front element." << endl;
        return -1; // Return a default value to indicate an empty queue
    }

    // isEmpty operation: Check if the queue is empty
    bool isEmpty() {
        return frontIndex == -1 && rearIndex == -1;
    }

    // isFull operation: Check if the queue is full (compares to maxSize)
    bool isFull() {
        return rearIndex == maxSize - 1;
    }
};

int main() {
    GenericQueue queue;

    // Enqueue elements to the rear of the queue
    
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    
    
    // Use Peek method to retrieve the front element without removing it
    // Print the front element of the queue
    cout << "Front element of the queue: " << queue.Peek() << endl;

    // Dequeue elements from the front of the queue
    cout << "Dequeuing elements from the queue:" << endl;
    queue.dequeue();
    queue.dequeue();

    // Check if the queue is empty after each operation and print the result
    cout << "Is the queue empty? " << (queue.isEmpty() ? "Yes" : "No") << endl;


    // Print the front element of the queue
    cout << "Front element of the queue: " << queue.Peek() << endl;
    return 0;
}


