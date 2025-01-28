/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

class Node { 
    public:
        int value;
        Node* next;
        
        Node(int value) : data(value), next(nullptr) {}
    
};

class LinkedList {
    private:
        Node* head;
        Node* tail;
        int length;
    public:
        LinkedList(int value) : head(nullptr), tail(nullptr) {}
        
        //destructor function
        ~LinkedList();
        
        //helper methods
        void printList(){
            Node* temp;
            temp = head;
            while(temp != nullptr){
                cout << temp->value << endl;
                temp = temp->next;
            }
        }
        
        
        void append(int value) {
            Node* newNode = new Node(value);
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } 
            else {
                tail->next = newNode;
                tail = newNode;
            }
         
        }
        
        //remove an item from end of list
        void deleteLast() {
          if (head == nullptr)
            return;
          Node* temp = head;
          if (length == 1) {
              head = nullptr;
              tail = nullptr;
          } else {
              Node* pre = head;
              while(temp->next != nullptr){
                  pre = temp;
                  temp = temp->next;
              }
              tail = pre;
              tail->next = nullptr;
          }
          length--;
          delete temp;
        }
};

int main()
{
    LinkedList* myLinkedList = new LinkedList();
    
    myLinkedList->append(3);
    myLinkedList->append(4);
    myLinkedList->append(5);
    myLinkedList->printList();
    
    myLinkedList->deleteLast();
    myLinkedList->printList();
    
    myLinkedList->deleteLast();
    myLinkedList->printList();
    
    myLinkedList->deleteLast();
    myLinkedList->printList();

    return 0;
}