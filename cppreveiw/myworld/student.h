#pragma once

#include "human.h"
#include "classroom.h"
using namespace std;

enum grade : int {
    grade1,
    grade2,
    grade3,
    grade4,
    grade5,
    grade6,
};

class student : public Human {
    public:
        student(classroom cls, string nm, grade grd) {}

    private:
        classroom clsr;
        string    st_name;
        grade     st_grd;
};