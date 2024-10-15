#include "handle.h"
#include <fstream>
#include <iomanip>

using std::cout;
using std::endl;
using std::istream;
using std::ofstream;
using std::setprecision;
using std::streamsize;
using std::vector;

Handle &Handle::operator=(const Handle &s)
{
    if (this != &s)
    {
        delete sp;
        if (s.sp)
            sp = s.sp->clone();
        else
            sp = 0;
    }

    return *this;
}

istream &Handle::read(istream &is)
{
    if (sp)
        delete sp;
    char ch;
    is >> ch;

    if (ch == 'T')
        sp = new Triangle(is);
    else if (ch == 'R')
        sp = new Rectangle(is);
    else
        sp = new Circle(is);

    return is;
}

istream &readinfo(istream &is, vector<Handle> &h)
{

    if (is)
    {
        is.clear();
        Handle record;
        while (record.read(is))
            h.push_back(record);
    }

    return is;
}

bool compare(const Handle &x, const Handle &y)
{
    return x.area() < y.area();
}

ofstream outfile("results.csv");

void cal_output(const vector<Handle> &s)
{
    cout << endl;

    cout << "Area"
         << "    "
         << "Perimeter" << endl;
    outfile << "Area" << ',' << "Perimeter" << endl;

    for (vector<Handle>::size_type i = 0; i != s.size(); ++i)
    {
        if (s[i].area())
        {
            double a = s[i].area();
            double p = s[i].perimeter();
            streamsize prec = cout.precision();
            cout << setprecision(3) << s[i].area() << '\t' << s[i].perimeter() << setprecision(prec) << endl;
            outfile << setprecision(3) << s[i].area() << ',' << s[i].perimeter() << setprecision(prec) << endl;
        }
    }
}