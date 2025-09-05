#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
#include <string>
using namespace std;

class Student {
    public:
        void setName(string n);
        void setGPA(double g);
        string getName();
        double getGPA();
        
    private:
        string name;
        double gpa;
};

#endif