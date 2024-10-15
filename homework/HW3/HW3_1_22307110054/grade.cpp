#include"median.h"
#include"Student_info.h"
#include"grade.h"
#include<stdexcept>
#include<vector>

using std::domain_error;
using std::vector;

double grade(double mid,double final,double homework) {
    return 0.2*mid+0.4*final+0.4*homework;
}
double grade(double mid,double final,const vector<double>& hw) {
    if(hw.size()==0) throw std::domain_error("student has done no homework");
    double homework=median(hw);
    return grade(mid,final,homework);
}
double grade(const Student_info & s) {
    return grade(s.mid, s.final,s.homework);
}

