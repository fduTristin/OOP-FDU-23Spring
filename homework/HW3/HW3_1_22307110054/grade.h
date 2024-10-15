#ifndef GUARD_H
#define GUARD_H 
#include<vector>
#include<list> 
#include"Student_info.h"

double grade(double mid,double final,double homework);
double grade(double mid,double final,const std::vector<double>& hw);
double grade(const Student_info & s);
std::list<Student_info> extract_fails(std::list<Student_info>& students);
#endif