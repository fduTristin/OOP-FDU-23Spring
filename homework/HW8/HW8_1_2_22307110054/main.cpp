#include "core.h"
#include "median.h"
#include "grade.h"
#include "handle.h"
#include <fstream>
#include <iomanip>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;

int main()
{
    vector<Student_info> students;
    string::size_type maxlen = 0;
    Student_info record;
    ifstream infile("grades2");
    while (record.read(infile))
    {
        maxlen = std::max(maxlen, record.name().size());
        students.push_back(record);
    }
    std::sort(students.begin(), students.end(), Student_info::compare);

    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i)
    {
        cout << students[i].name()
             << string(maxlen + 1 - students[i].name().size(), ' ');
        try
        {
            double final_grade = students[i].grade();
            std::streamsize prec = cout.precision();
            cout << std::setprecision(3) << final_grade
                 << std::setprecision(prec) << endl;
        }
        catch (std::domain_error e)
        {
            cout << e.what() << endl;
        }
    }
    return 0;
}
