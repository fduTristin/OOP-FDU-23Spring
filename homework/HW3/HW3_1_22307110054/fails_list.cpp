#include "Student_info.h"
#include "grade.h"
#include <list>

using std::list;

list<Student_info> extract_fails(list<Student_info> &students)
{
    list<Student_info> fails;
    std::list<Student_info>::iterator iter = students.begin();
    while (iter != students.end())
    {
        if (iter->final_grade < 60)
        {
            fails.push_back(*iter);
            iter = students.erase(iter);
        }
        else
            ++iter;
    }
    return fails;
}
