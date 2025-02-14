#include <iostream>

using namespace std;
void B();  //let's the compiler know about these 2 functions before they are called.
void C();

void A(){
    cout << "A() is called" << endl;
    B();
    cout << "A() is returning" << endl;
}

void B(){
    cout << "B() is called" << endl; 
    C();
    cout << "B() is returning" << endl;
}

void C(){
    cout << "C() is called" << endl;
    cout << "C() is returning" << endl;
}

int main(){
    A();
    return 0;
}