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

    // Member function to insert a new node after a specific node
    void ListInsertNodeAfter(Node* currentNode, int newItem) {
        if (!currentNode) {
            cout << "Error: Given node is NULL. Cannot insert after a NULL node." << endl;
            return;
        }

        // Step 1: Create a new node with the given data
        Node* newNode = new Node(newItem);

        // Step 2: Check if the given node is the last node (tail)
        if (currentNode == tail) {
            tail->next = newNode;  // Set tail's next to new node
            newNode->prev = tail;  // Set new node's previous to current tail
            tail = newNode;        // Update tail to the new node
        } else { // Insert in the middle
            Node* successor = currentNode->next;
            newNode->next = successor;
            newNode->prev = currentNode;
            currentNode->next = newNode;
            if (successor) {
                successor->prev = newNode;
            }
        }
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

    // Member function to search for a node with a specific value (for finding insertion point)
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

    // Step 3: Display the list before insertion
    cout << "Current List: ";
    myList.displayForward();

    // Step 4: Insert a node after a specific value
    int searchValue = 30;
    int insertValue = 35;
    Node* foundNode = myList.ListSearch(searchValue);
    if (foundNode) {
        cout << "Inserting " << insertValue << " after " << searchValue << endl;
        myList.ListInsertNodeAfter(foundNode, insertValue);
    } else {
        cout << "Node with value " << searchValue << " not found. Cannot insert." << endl;
    }

    // Step 5: Display the list after insertion
    cout << "List after Insert (Forward): ";
    myList.displayForward();

    return 0;
}
