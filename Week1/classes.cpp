#include <iostream>
#include <string>

using namespace std;

// Define the Animal class
class Animal {
private:
    string name;
    string species;
    int age;

public:
    // Constructor to initialize attributes
    Animal(string n, string s, int a) {
        name = n;
        species = s;
        age = a;
    }

    // Public member functions to access private members
    string getName() const {
        return name;
    }

    string getSpecies() const {
        return species;
    }

    int getAge() const {
        return age;
    }

    void setName(string n) {
        name = n;
    }

    void setSpecies(string s) {
        species = s;
    }

    void setAge(int a) {
        age = a;
    }

    // Function to display information about the animal
    void displayInfo() const {
        cout << "Name: " << name << endl;
        cout << "Species: " << species << endl;
        cout << "Age: " << age << " years" << endl;
    }
};

int main() {
    // Create objects of the Animal class
    Animal lion("Simba", "Lion", 5);
    Animal dog("Buddy", "Dog", 2);
    Animal parrot("Polly", "Parrot", 3);

    // Display information about the animals
    cout << "Animal 1:" << endl;
    lion.displayInfo();
    cout << endl;

    cout << "Animal 2:" << endl;
    dog.displayInfo();
    cout << endl;

    cout << "Animal 3:" << endl;
    parrot.displayInfo();
    cout << endl;

    // Modify private members using public member functions
    lion.setName("Mufasa");
    dog.setAge(3);

    // Display updated information
    cout << "Updated Animal 1:" << endl;
    lion.displayInfo();
    cout << endl;

    cout << "Updated Animal 2:" << endl;
    dog.displayInfo();
    cout << endl;

    return 0;
}
