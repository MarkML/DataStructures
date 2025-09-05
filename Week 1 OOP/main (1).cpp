#include "GraduateStudent.h"

int main() {
    // Create a GraduateStudent object
    GraduateStudent gradStudent;

    // Set values using inherited methods
    gradStudent.setName("Alice");
    gradStudent.setGPA(3.8);

    // Set thesis title specific to GraduateStudent
    gradStudent.setThesisTitle("Machine Learning in Healthcare");

    // Display information
    cout << "Graduate Student Details:" << endl;
    cout << "Name: " << gradStudent.getName() << endl;
    cout << "GPA: " << gradStudent.getGPA() << endl;
    cout << "Thesis Title: " << gradStudent.getThesisTitle() << endl;

    return 0;
}
