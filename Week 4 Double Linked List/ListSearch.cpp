#include <iostream>

using namespace std;

// Node class representing a single element in the doubly linked list
class Node {
public:
    int data;   // Data stored in the node
    Node* next; // Pointer to the next node
    Node* prev; // Pointer to the previous node

    // Constructor to initialize a new node with given data
    Node(int item) : data(item), next(nullptr), prev(nullptr) {}
};

// DoublyLinkedList class to manage the list
class DoublyLinkedList {
public:
    Node* head; // Pointer to the first node in the list
    Node* tail; // Pointer to the last node in the list

    // Constructor to initialize an empty list
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Member function to search for a node with a specific value
    Node* ListSearch(int dataValue) {
        // Step 1: Start from the head of the list
        Node* currentNode = head;

        // Step 2: Traverse the list to find the node with the given data
        while (currentNode) {
            if (currentNode->data == dataValue) {
                return currentNode;  // Return the node if found
            }
            currentNode = currentNode->next;  // Move to the next node
        }

        // Step 3: If the node was not found, return nullptr
        return nullptr;
    }

    // Member function to append a new node at the end of the list (for testing purposes)
    void ListAppend(int item) {
        Node* newNode = new Node(item);

        if (!tail) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Display the list from head to tail
    void displayForward() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    // Step 1: Create an empty doubly linked list
    DoublyLinkedList myList;

    // Step 2: Append values to the list to create sample data
    cout << "Appending values: 10, 20, 30, 40, 50" << endl;
    myList.ListAppend(10);
    myList.ListAppend(20);
    myList.ListAppend(30);
    myList.ListAppend(40);
    myList.ListAppend(50);

    // Step 3: Display the list before searching
    cout << "Current List: ";
    myList.displayForward();

    // Step 4: Search for an existing value
    int searchValue = 30;
    Node* foundNode = myList.ListSearch(searchValue);
    if (foundNode) {
        cout << "Node with value " << searchValue << " found!" << endl;
    } else {
        cout << "Node with value " << searchValue << " not found!" << endl;
    }

    // Step 5: Search for a non-existing value
    searchValue = 100;
    foundNode = myList.ListSearch(searchValue);
    if (foundNode) {
        cout << "Node with value " << searchValue << " found!" << endl;
    } else {
        cout << "Node with value " << searchValue << " not found!" << endl;
    }

    return 0;
}
