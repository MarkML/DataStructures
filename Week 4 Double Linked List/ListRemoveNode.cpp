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

    // Member function to remove a specific node from the list
    void ListRemoveNode(Node* currentNode) {
        if (!currentNode) {
            cout << "Error: Given node is NULL. Cannot remove a NULL node." << endl;
            return;
        }

        // Step 1: Get the successor and predecessor of the node to be removed
        Node* successor = currentNode->next;
        Node* predecessor = currentNode->prev;

        // Step 2: Update the pointers to remove the node from the chain
        if (successor) {
            successor->prev = predecessor; // Set successor's previous to predecessor
        }
        if (predecessor) {
            predecessor->next = successor; // Set predecessor's next to successor
        }

        // Step 3: Update head or tail if needed
        if (currentNode == head) {
            head = successor; // If removing the head, move it to the next node
        }
        if (currentNode == tail) {
            tail = predecessor; // If removing the tail, move it to the previous node
        }

        // Step 4: Free memory of the removed node
        delete currentNode;
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

    // Member function to search for a node with a specific value (for finding removal target)
    Node* ListSearch(int dataValue) {
        Node* currentNode = head;
        while (currentNode) {
            if (currentNode->data == dataValue) {
                return currentNode;  // Return the node if found
            }
            currentNode = currentNode->next;
        }
        return nullptr;
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

    // Step 3: Display the list before removal
    cout << "Current List: ";
    myList.displayForward();

    // Step 4: Remove a node with a specific value
    int removeValue = 30;
    Node* nodeToRemove = myList.ListSearch(removeValue);
    if (nodeToRemove) {
        cout << "Removing " << removeValue << endl;
        myList.ListRemoveNode(nodeToRemove);
    } else {
        cout << "Node with value " << removeValue << " not found. Cannot remove." << endl;
    }

    // Step 5: Display the list after removal
    cout << "List after Remove (Forward): ";
    myList.displayForward();

    return 0;
}
