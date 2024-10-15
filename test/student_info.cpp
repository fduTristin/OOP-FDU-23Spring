#include "student_info.h"

using std::istream;
using std::string;
using std::vector;

istream &read_hw(istream &is, vector<double> &hw)
{
    if (is)
    {
        hw.clear();
        double x;
        while (is >> x)
            hw.push_back(x);
        is.clear();
    }
    return is;
}

istream &read(istream &is, Student_info &s)
{
    is >> s.name >> s.mid >> s.final;
    read_hw(is, s.hw);
    return is;
}

bool compare(const Student_info &x, const Student_info &y)
{
    return x.name < y.name;
}