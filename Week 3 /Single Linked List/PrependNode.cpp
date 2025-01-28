#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node* next;
        
        Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    Node* tail;
public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    // member function to prepend a node    
    void prepend(int value){
        Node* newNode = new Node(value);  // call Node constructor and save node in Heap memory
        
        if(head == nullptr){ // check if List is empty
            head = newNode;
            tail = newNode;
        } else {             // list is not empty
            newNode->next = head;  // new node points to 1st node in list
            head = newNode;       // update head pointer to point to new Node which is now 1st node in list
        }
    }

    void printList() {
        Node* temp = head;
        while (temp != nullptr){
            cout << temp->data << " ";  
            temp = temp->next;
        }
        cout << endl;   // Optional, just to print a newline after list is printed
    }
};

int main() {
    LinkedList* myLinkedList = new LinkedList();   //use the default constructor
    myLinkedList->prepend(5);  // Prepend a node
    myLinkedList->prepend(6);
    myLinkedList->printList(); // Corrected function name to 'printList'
    
    return 0;
}
