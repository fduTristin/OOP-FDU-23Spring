#include"median.h"
#include"Student_info.h"
#include"grade.h"

double grade(double a, double b,const std::vector<double>& hw)
{
	if(hw.size()==0) throw std::domain_error("student has done no homework");
	return 0.2*a+0.4*b+0.4*median(hw);
}

double grade(const Student_info& s) 
{
	return grade(s.mid, s.final,s.homework);
}