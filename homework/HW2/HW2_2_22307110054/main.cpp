#include<algorithm>
#include<iomanip>
#include<ios>
#include<iostream>
#include<stdexcept>
#include<string>
#include<vector>
#include"grade.h"
#include"Student_info.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    std::vector<double> homework;
    std::vector<Student_info> students;
    Student_info record;
    std::string::size_type maxlen=0;

    while(read(cin,record)) 
        students.push_back(record);

    for(int i=0;i!=students.size();++i)
    {
        try{
            students[i].final_grade = grade(students[i]);
        } catch (const std::domain_error) {
            students[i].final_grade=999;
        }
        maxlen = std::max(maxlen,students[i].name.size());
    }

    sort(students.begin(),students.end(),compare);
    
    for(int i=0;i!=students.size();++i)
    {
        if (students[i].final_grade == 999)
			cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ') << "student has done no homework\n";
		else
			cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ') <<std::setprecision(3)<< students[i].final_grade << endl;
	
    }
    return 0;
}