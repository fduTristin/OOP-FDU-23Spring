#ifndef GUARD_Student_info
#define GUARD_Student_info

// 'Student_info.h' header file
#include <iostream>
#include <string>
#include <vector>

class Student_info{
	public:
	std::string name() const {return n;}
	std::istream& read (std::istream&);
	Student_info():midterm(0),final(0) {};
	double final_grade() const;

	private:
	std::string n;
	double midterm;
	double final;
	std::vector<double> homework;
};

bool compare(const Student_info&, const Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);
#endif

