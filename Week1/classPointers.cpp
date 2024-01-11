/******************************************************************************
Instructions:

Create a C++ program that defines a Student class with the following attributes: name (a string), age (an integer), and grade (a double).
Use meaningful variable names and comments to make the code easy to understand.
Create an array of Student objects on the stack to store information for multiple students (e.g., an array of size 3).
Prompt the user to enter information for each student (name, age, and grade).
Use pointers to access and display the information for each student.
Calculate and display the average grade of the students.


*******************************************************************************/
#include <iostream>
#include <string>

using namespace std;

class Student {
public:
    // Define the Student class with name, age, and grade as attributes
    string name;
    int age;
    double grade;

    // Constructor to initialize the attributes
    Student(string n, int a, double g) : name(n), age(a), grade(g) {}

    // Function to display student information
    void displayInfo() {
        cout << "Name: " << name << ", Age: " << age << ", Grade: " << grade << endl;
    }
};

int main() {
    // Declare an array of Student objects on the stack
    const int numStudents = 3;
    Student students[numStudents];

    // Prompt the user to enter information for each student
    for (int i = 0; i < numStudents; i++) {
        cout << "Enter information for Student " << i + 1 << ":" << endl;
        cout << "Name: ";
        cin >> students[i].name;
        cout << "Age: ";
        cin >> students[i].age;
        cout << "Grade: ";
        cin >> students[i].grade;
    }

    // Use pointers to display the student information
    cout << "\nStudent Information:" << endl;
    for (int i = 0; i < numStudents; i++) {
        cout << "Student " << i + 1 << " - ";
        students[i].displayInfo();
    }

    // Calculate and display the average grade
    double totalGrade = 0.0;
    for (int i = 0; i < numStudents; i++) {
        totalGrade += students[i].grade;
    }
    double averageGrade = totalGrade / numStudents;
    cout << "\nAverage Grade: " << averageGrade << endl;

    return 0;
}

