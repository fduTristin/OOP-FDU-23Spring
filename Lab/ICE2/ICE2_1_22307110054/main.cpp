#include "weather.h"
#include <stdexcept>
#include <algorithm>
#include<iomanip>

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::istream;
using std::ostream;
using std::vector;
using std::setprecision;

istream &read(istream &in, vector<city_temp> &s)
{

    if (in)
    {
        in.clear(),
            s.clear();
        city_temp x;
        while (in >> x.name >> x.temp)
            s.push_back(x);
    }
    return in;
}

double average(const vector<city_temp>& temp)
{
    if (temp.size() == 0)
        throw domain_error("No city and temperature input.");
    double count = 0;
    double sum = 0;
    for (vector<city_temp>::size_type i = 0; i != temp.size(); ++i)
    {
        count++;
        sum += temp[i].temp;
    }
    return sum / count;
}

bool cmp(const city_temp &x, const city_temp &y)
{
    return x.deviate < y.deviate;
}

void deviate(std::vector<city_temp> &s, double &avg)
{
    for (vector<city_temp>::size_type i = 0; i != s.size(); ++i)
    {
        s[i].deviate = s[i].temp > avg ? s[i].temp - avg : avg - s[i].temp;
    }
    std::sort(s.begin(), s.end(), cmp);
    return;
}

ostream &print(ostream &os, const std::vector<city_temp> &s, double& avg)
{
    if (os)
    {
        std::streamsize prec = os.precision();
        os << "The city with the largest deviation "
              "from the average temperature is: "
           << s[s.size() - 1].name << endl;
        os << "It's temperature is: " << s[s.size()-1].temp<<endl;
        os<<"The deviation is: "<<setprecision(3)<<s[s.size()-1].deviate<<setprecision(prec)<<endl;
        os << "The city with the smallest deviation "
              "from the average temperature is: "
           << s[0].name << endl;
        os << "It's temperature is: " << s[0].temp<<endl;
        os<<"The deviation is: "<<setprecision(3)<<s[0].deviate<<setprecision(prec)<<endl;
    }

    return os;
}

int main()
{
    vector<city_temp> cities;
    cout << "Enter city names and temperatures: " << endl;
    read(cin, cities); // 读入城市和温度数据
    try
    {
        double avg = average(cities); // 求平均温度(含抛出异常)
        deviate(cities, avg);         // 求温度偏差并按偏差排序
        print(cout, cities, avg);     // 按要求输出
    }
    catch (domain_error e)
    {
        cout << e.what() << endl;
    }
    return 0;
}