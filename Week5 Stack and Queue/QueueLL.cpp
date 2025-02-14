#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) : data(d), next(nullptr) {}
};

class LinkedListQueue {
private:
    Node* head;
    Node* tail;

public:
    LinkedListQueue() : head(nullptr), tail(nullptr) {}

    void enqueue(int item) {
        Node* newNode = new Node(item);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Error: Queue is empty!" << endl;
            return -1; // Return a default value or throw an exception
        }

        int dequeuedData = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        if (head == nullptr) {
            tail = nullptr; // Update tail if the queue becomes empty
        }
        return dequeuedData;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void printQueue() {
        Node* current = head;
        cout << "Queue: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedListQueue queue;

    // Enqueue some elements into the queue
    queue.enqueue(5);
    queue.enqueue(10);
    queue.enqueue(15);
    queue.enqueue(20);

    // Print the queue
    queue.printQueue(); // Output: Queue: 5 10 15 20

    // Dequeue elements from the queue
    cout << "Dequeued: " << queue.dequeue() << endl; // Output: Dequeued: 5
    cout << "Dequeued: " << queue.dequeue() << endl; // Output: Dequeued: 10

    // Print the queue after dequeuing
    queue.printQueue(); // Output: Queue: 15 20

    return 0;
}
