/******************************************************************************


*******************************************************************************/
#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node* next;
        
        //constructor
        Node(int value) : data(value), next(nullptr) {}
        //destructor
        ~Node() {}
        
};


class LinkedList {
    private:
        Node* head;
        Node* tail;
        
    public:   //create a empty list
        LinkedList() : head(nullptr), tail(nullptr) {}
        
        ~LinkedList() {
            Node* temp = head;
            while(head) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }
        
       
        void printList() {
            Node* temp = head;
            while (temp != nullptr){
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
        
        void append(int value){
            Node* newNode = new Node(value);
            //check if LL is empty
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
                
            }
        }
        
       
};

using namespace std;

int main()
{
 
    LinkedList* myLinkedList = new LinkedList();
    
    myLinkedList->append(3);
    myLinkedList->printList();
    cout << endl;
    
    myLinkedList->append(1);
    myLinkedList->printList();
    cout << endl;

    myLinkedList->append(100);
    myLinkedList->printList();
    
    return 0;
}