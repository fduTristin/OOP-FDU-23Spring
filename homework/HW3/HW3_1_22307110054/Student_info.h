#ifndef STUDENT_INFO
#define STUDENT_INFO
#include <iostream>
#include <vector>
#include <string>
struct Student_info
{
  std::string name;
  std::vector<double> homework;
  double mid;
  double final;
  double final_grade;
};

bool compare(const Student_info &x, const Student_info &y);
std::istream &read_hw(std::istream &in, std::vector<double> &hw);
std::istream &read(std::istream &is, Student_info &s);

#endif
