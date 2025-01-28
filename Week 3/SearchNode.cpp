#include <iostream>

using namespace std;

// Node class definition
class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int value) : data(value), next(nullptr) {}
};

// List class definition
class List {
public:
    Node* head;
    Node* tail;

    // Constructor
    List() : head(nullptr), tail(nullptr) {}

    // Function to search for a key in the list
    Node* ListSearch(int key) {
        Node* curNode = head;
        while (curNode != nullptr) {
            if (curNode->data == key) {
                return curNode;
            }
            curNode = curNode->next;
        }
        return nullptr;
    }

    // Function to append a node to the end of the list
    void ListAppend(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) { // Check if the list is empty
            head = newNode; // If empty, set both head and tail to the new node
            tail = newNode;
        } else {
            tail->next = newNode; // If not empty, append the new node after the current tail
            tail = newNode; // Update the tail pointer to the new node
        }
    }
};

int main() {
    // Create a list
    List myList;

    // Append six elements to the list
    myList.ListAppend(10);
    myList.ListAppend(20);
    myList.ListAppend(30);
    myList.ListAppend(40);
    myList.ListAppend(50);
    myList.ListAppend(60);

    // Search for a key in the list
    int key = 40;
    Node* result = myList.ListSearch(key);

    // Display the search result
    if (result != nullptr) {
        cout << "Key " << key << " found in the list." << endl;
    } else {
        cout << "Key " << key << " not found in the list." << endl;
    }

    return 0;
}
