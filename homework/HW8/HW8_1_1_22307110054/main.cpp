#include"core.h"
#include"median.h"
#include"grade.h"
#include<fstream>
#include<iomanip>
#include<algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::ifstream;


int main()
{
    vector<Core*> students;
    string::size_type maxlen = 0;
    Core* record;
    ifstream infile("grades2");
    char c;
    while(infile>>c)
    {
        if(c == 'U') record = new Core;
        if(c == 'G') record = new Grad;
        record->read(infile);
        maxlen = std::max(maxlen , record->name().size());
        students.push_back(record);
    }
    std::sort(students.begin(),students.end(),compare_Core_ptrs);
    
    for (vector<Core*>::size_type i = 0; i != students.size(); ++i) {
        cout << students[i]->name()
             << string(maxlen + 1 - students[i]->name().size(),' ');
        try{
            double final_grade = students[i]->grade();
            std::streamsize prec = cout.precision();
            cout << std::setprecision(3) << final_grade
                 << std::setprecision(prec) << endl;
        }catch(std::domain_error e){
            cout << e.what() << endl;
        }
        delete students[i];
    }
    return 0;
}
