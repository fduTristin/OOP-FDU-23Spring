#include <stdexcept>
#include <vector>
#include "grade.h"
#include "median.h"
#include "Student_info.h"

using std::domain_error;  using std::vector;


// compute a student"s overall grade from midterm and final exam grades and homework grade
double grade(double midterm, double final, double homework)
{
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// compute a student"s overall grade from midterm and final exam grades
// and vector of homework grades.
// this function does not copy its argument, because `median" does so for us.
double grade(double midterm, double final, const vector<double>& hw)
{
	if (hw.size() == 0)
		throw domain_error("student has done no homework");
	return grade(midterm, final, median(hw.begin(),hw.end()));
}

double Student_info::final_grade()const
{
	return grade(midterm, final, homework);
}

std::string letter_grade(const double& fnl) 
{
	if(fnl>=90) return "A";
	if(fnl<90 && fnl >= 85) return "A-";
	if(fnl<85 && fnl >= 82) return "B+";
	if(fnl<82 && fnl >= 78) return "B";
	if(fnl<78 && fnl >= 75) return "B-";
	if(fnl<75 && fnl >= 71) return "C+";
	if(fnl<71 && fnl >= 66) return "C";
	if(fnl<66 && fnl >= 62) return "C-";
	if(fnl<62 && fnl >= 60) return "D";
	else return "F";
}
