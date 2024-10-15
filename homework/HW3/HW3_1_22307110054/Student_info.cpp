#include "Student_info.h"
using std::istream;
using std::vector;

bool compare(const Student_info& x, const Student_info& y)
{
	if (x.final_grade != y.final_grade)
		return x.final_grade > y.final_grade;
	else
		return x.name < y.name;
}

std::istream& read_hw(std::istream& in, std::vector<double>& hw)
{
	if(in)
	{
		hw.clear();
		double x;
		while (in >> x)
			hw.push_back(x);
		in.clear();
	}
	return in;
}

std::istream& read(std::istream& is, Student_info& s)
{
	is >> s.name >> s.mid >> s.final;
	read_hw(is, s.homework);
	return is;
}
