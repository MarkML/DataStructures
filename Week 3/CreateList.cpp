#include <iostream>
using namespace std;

//individual nodes in the linked list
class Node {
public:
    int data;    // data of the node: age, student id, membership id, etc
    Node* next;  // Pointer to the next node
    
    //Constructor to initialize the node with data
    Node(int value) : data(value), next(nullptr) {}
};

// numList class will manage the entire linked list
class Linked_list {
private:
    Node* head;
    Node* tail;
public:
    Linked_list() : head(nullptr), tail(nullptr) {}
};

int main(){
    
    Linked_list numList;  //create empty list
    return 0;
}
