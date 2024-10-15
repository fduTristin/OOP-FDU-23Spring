#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iomanip>
#include <string>
#include "core.h"
#include"grade.h"
#include"median.h"


using std::istream;
using std::domain_error;
using std::vector;
using std::min;
using std::string;



istream& read_hw(istream& in, vector<double>& hw){
    if(in){
        hw.clear();
        double x;
        while(in >> x){
            hw.push_back(x);
        }
        in.clear();
    }
    return  in;
}

istream& Core::read_common(istream& in){
    in >> n >> mid >> final;
    return in;
}

istream& Core::read(istream& in){
    read_common(in);
    read_hw(in, hw);
    return in;
}

istream& Grad::read(istream& in){
    read_common(in);
    in >> thesis;
    read_hw(in, hw);
    return in;
}

bool compare(const Core& c1, const Core& c2){
    return c1.name() < c2.name();
}

bool compare_Core_ptrs(const Core* cp1, const Core* cp2){
    return compare(*cp1, *cp2);
}

double Core::grade() const{
    return ::grade(mid, final, hw);
}


double Grad::grade() const {
    return  min(Core::grade(), thesis);
}








