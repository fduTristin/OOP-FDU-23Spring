#include"median.h"
#include"grade.h"
#include"student_info.h"

using std::cout;
using std::vector;
using std::string;
using std::cin;
using std::endl;

int main()
{
    Student_info record;
    vector<Student_info> students;
    string::size_type maxlen  = 0;
    while(read(cin,record))
    {
        students.push_back(record);
        maxlen = std::max(maxlen,record.name.size());
    }
    for(vector<Student_info>::size_type i = 0; i != students.size();++i)
    {
        try{
            double final_grade = grade(students[i]);
            cout<<students[i].name<<string(maxlen+1-students[i].name.size(),' ')<<final_grade<<endl;
        } catch(std::domain_error e) {cout<<e.what();}
    }
    return 0;
}
