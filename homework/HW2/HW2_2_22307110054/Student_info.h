#ifndef STUDENT_INFO_H
#define STUDENT_INFO_H
#include<iostream>
#include<vector>
#include<string>

struct Student_info
{
    std::string name;
	double mid, final;
	std::vector<double> homework;
	double final_grade;
};

std::istream& read_hw(std::istream& in , std::vector<double>& hw);
std::istream& read(std::istream& is , Student_info& s);
bool compare(const Student_info& x, const Student_info& y);
#endif
