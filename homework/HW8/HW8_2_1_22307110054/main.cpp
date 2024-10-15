#include"shape.h"
#include<fstream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<string>

using std::cout;
using std::endl;
using std::vector;
using std::setprecision;
using std::streamsize;

int main()
{
    vector<Shape*> s;
    std::ifstream infile("shapes");
    std::ofstream outfile("results.csv");
    Shape* record;
    char c;
    while(infile>>c)
    {
        if(c == 'T') record = new Triangle;
        if(c == 'R') record = new Rectangle;
        if(c == 'C') record = new Circle;
        try{
            record->read(infile);
            
        } 
        catch(std::domain_error e)
        {
            record->print();
            cout<<e.what()<<endl;
        }
        s.push_back(record);
        
    }
    
    std::sort(s.begin(), s.end(),compare_sp);

    cout<<endl;

    cout<<"Area"<<"    "<<"Perimeter"<<endl;
    outfile<<"Area"<<','<<"Perimeter"<<endl;



    for(vector<Shape*>::size_type i = 0; i!=s.size(); ++i)
    {
        if(s[i]->area())
        {
            double a = s[i]->area();
            double p = s[i]->perimeter();
            streamsize prec = cout.precision();
            cout<<setprecision(3)<<s[i]->area()<<'\t'<<s[i]->perimeter()<<setprecision(prec)<<endl;
            outfile<<setprecision(3)<<s[i]->area()<<','<<s[i]->perimeter()<<setprecision(prec)<<endl;
        }
        
        delete s[i];
    }
}