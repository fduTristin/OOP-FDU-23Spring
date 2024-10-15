#include <iostream>
#include "date.h"
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;

int inteval(const Date &x, const Date &y)
{
     return x.total_day() > y.total_day() ? x.total_day() - y.total_day() : y.total_day() - x.total_day();
}

int main()
{
     try
     {
          cout << "请输入两个日期(年月日，以空格分离):" << endl;
          Date dt1(cin);
          Date dt2(cin);
          cout << "日期一: ";
          dt1.print();
          cout << endl;
          cout << "日期二: ";
          dt2.print();
          cout << endl
               << "两个日期相隔天数为: " << inteval(dt1, dt2);
          cout << endl
               << "给日期一增加一天为: ";
          dt1.day_plus().print();
          cout << endl
               << "给日期一增加一月为: ";
          dt1.month_plus().print();
          cout << endl
               << "给日期一增加一年为: ";
          dt1.year_plus().print();
          return 0;
     } catch(std::domain_error e) {
          cout<<e.what();
     }
}