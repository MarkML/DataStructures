#include "Student.h"

void Student::setName(string n) {
    name = n;
}

void Student::setGPA(double g) {
    gpa = g;
}

string Student::getName() {
    return name;
}

double Student::getGPA() {
    return gpa;
}
