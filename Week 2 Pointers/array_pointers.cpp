#include <iostream>
using namespace std;

// Define the Animal class
class Animal {
public:
    Animal(string name, int age) : name(name), age(age) {}
    void printInfo() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }

private:
    string name;
    int age;
};

int main() {
    // Create an array of pointers to Animal objects
    const int numAnimals = 3;
    Animal* animalArray[numAnimals];

    // Create Animal objects and store pointers to them in the array
    animalArray[0] = new Animal("Lion", 5);
    animalArray[1] = new Animal("Elephant", 10);
    animalArray[2] = new Animal("Giraffe", 7);

    // Access and manipulate the objects through pointers
    cout << "Animals in the array:" << endl;
    for (int i = 0; i < numAnimals; i++) {
        animalArray[i]->printInfo(); // Access and print animal information
    }

    // Deallocate memory to prevent memory leaks
    for (int i = 0; i < numAnimals; i++) {
        delete animalArray[i];
    }

    return 0;
}
