#ifndef GRADUATESTUDENT_H_
#define GRADUATESTUDENT_H_

#include "Student.h"

class GraduateStudent : public Student {
    public:
        void setThesisTitle(string t);
        string getThesisTitle();
        
    private:
        string thesisTitle;
};

#endif
