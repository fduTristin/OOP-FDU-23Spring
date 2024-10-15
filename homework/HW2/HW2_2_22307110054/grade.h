#ifndef GRADE_H
#define GRADE_H
#include <vector>
#include "Student_info.h"


inline double grade(double a, double b,const std::vector<double>& hw);

double grade(const Student_info& s);

#endif