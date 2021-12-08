#pragma once

#include "teacher.h"
using namespace std;

class classroom {
    public:
        classroom(string nm, string desc, int number, teacher t) : 
        class_name(nm), class_desc(desc), num_of_student(number), class_teacher(t) {}

    private:
        string class_name;
        string class_desc;
        int    num_of_student;
        teacher class_teacher;
};