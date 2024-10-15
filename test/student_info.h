#ifndef STUDENT
#define STUDENT

#include<string>
#include<vector>
#include<iostream>


struct  Student_info
{
    std::string name;
    double mid,final;
    std::vector<double> hw;
};

std::istream& read_hw(std::istream&, std::vector<double>& );
std::istream& read(std::istream&, Student_info&);
bool compare (const Student_info&, const Student_info&);
#endif