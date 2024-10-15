#include"grade.h"
#include<stdexcept>

double grade(const double& a, const double& b, const std::vector<double>& hw )

{
    if(hw.size() == 0) throw std::domain_error ("students has done no homework.");
    return 0.2*a+0.4*b+0.4*median(hw);
}

double grade(Student_info& s)
{
    return grade(s.mid,s.final, s.hw);
}