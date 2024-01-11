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
    string name;
    int age;
    double grade;

    Student(string n, int a, double g) : name(n), age(a), grade(g) {}

    void displayInfo() {
        cout << "Name: " << name << ", Age: " << age << ", Grade: " << grade << endl;
    }
};

int main() {
    // Declare and initialize an array of Student objects
    const int numStudents = 3;
    Student students[numStudents] = {
        {"Bill", 20, 85.5},
        {"Ted", 21, 92.0},
        {"Mary", 19, 78.5}
    };

    // Display student information
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
