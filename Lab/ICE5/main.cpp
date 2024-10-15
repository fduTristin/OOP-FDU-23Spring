#include"countif.h"
#include<vector>
#include<string>
#include<fstream>


using std:: vector; using std::cout; using std::string; using std::ifstream;
using std::ofstream; using std::endl;

bool pred1(int a) {
    return a > 0;
}

bool pred2(string s) {
    return s=="A";
}
int main()
{
    vector<int> v = {1,2,-1,-2};
    cout<<countif(v.begin(),v.end(),pred1)<<endl;
    vector<string> s;
    string record;
    ifstream infile("grades.txt");
    while(infile>>record){
        s.push_back(record);
    }
    cout<<countif(s.begin(),s.end(),pred2);
}