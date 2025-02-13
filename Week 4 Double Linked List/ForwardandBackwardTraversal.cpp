#include <iostream>

using namespace std;

// Node class for a Doubly Linked List
class DNode {
public:
    int data;
    DNode* next;
    DNode* prev;

    // Constructor with list initialization
    DNode(int value) : data(value), next(nullptr), prev(nullptr) {}
};

// Doubly Linked List class
class DoublyLinkedList {
private:
    DNode* head;
    DNode* tail;

public:
    // Constructor with list initialization
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Function to insert a new node at the end
    void insert(int value) {
        DNode* newNode = new DNode(value);
        if (!head) {  // If the list is empty, new node becomes head and tail
            head = tail = newNode;
        } else {  // Otherwise, add to the end
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Function to traverse and print the list in forward direction
    void traverseForward() const {
        cout << "Forward Traversal (Head to Tail): ";
        DNode* curNode = head;
        while (curNode) {
            cout << curNode->data << " ";
            curNode = curNode->next;
        }
        cout << endl;
    }

    // Function to traverse and print the list in backward direction
    void traverseBackward() const {
        cout << "Backward Traversal (Tail to Head): ";
        DNode* curNode = tail;
        while (curNode) {
            cout << curNode->data << " ";
            curNode = curNode->prev;
        }
        cout << endl;
    }
};

// Main function
int main() {
    DoublyLinkedList studentScores;

    // Insert sample student scores
    studentScores.insert(87);
    studentScores.insert(92);
    studentScores.insert(78);
    studentScores.insert(95);
    studentScores.insert(88);

    // Forward traversal (Head to Tail)
    studentScores.traverseForward();

    // Backward traversal (Tail to Head)
    studentScores.traverseBackward();

    return 0;
}
