#include<algorithm>
#include<iomanip>
#include<ios>
#include<iostream>
#include<stdexcept>
#include<string>
#include<list>
#include"grade.h"
#include"Student_info.h"

using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::string;

int main() {
	std::vector<double> homework;
    std::list<Student_info> students;
    std::list<Student_info> fail;
    Student_info record;
    std::string::size_type maxlen=0;

    while(read(cin,record)) 
        students.push_back(record);

    for(list<Student_info>::iterator it=students.begin();it!=students.end();++it)
    {
        try{
            (*it).final_grade = grade(*it);
        } catch (const std::domain_error) {
            (*it).final_grade=999;
        }
        maxlen = std::max((*it).name.size(),maxlen);
    }

    fail=extract_fails(students);
   
    students.sort(compare);
    fail.sort(compare);
    
    bool flg=1;
    
    for(list<Student_info>::iterator it=students.begin();it!=students.end();++it)
    {
        if ((*it).final_grade == 999)
			cout << (*it).name << string(maxlen + 1 - (*it).name.size(), ' ') << "student has done no homework\n";
		else 
        {
            if(flg) 
            {
                cout<<endl<<"Passing students:"<<endl,flg=0;
            }
			cout << (*it).name << string(maxlen + 1 - (*it).name.size(), ' ') <<std::setprecision(3)<< (*it).final_grade << endl;
        }
    }

    cout<<endl<<"Failing students:"<<endl;

    for(list<Student_info>::iterator it=fail.begin();it!=fail.end();++it)
        cout << (*it).name << string(maxlen + 1 - (*it).name.size(), ' ') <<std::setprecision(3)<< (*it).final_grade << endl;
	return 0;
}
