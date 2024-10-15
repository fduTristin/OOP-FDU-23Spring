#include "date.h"
#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;
using std::istream;

Date::Date(int y_, int m_, int d_) : y(y_), m(m_), d(d_) {}

Date::Date(istream &in)
{
    int day_of_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    in >> y >> m >> d;
    if(year_special()) day_of_month[1]=29;
    if(m<=0||m>12||d>day_of_month[m-1]||d<1) throw std::domain_error("invalid day");
}

void Date::print()
{
    cout << year() << "年" << month() << "月" << day() << "日";
}

Date Date::year_plus() const
{
    int y1 = year() + 1;
    int m1 = month();
    int d1 = m1 == 2 && day() == 29 && year_special() ? 28 : day();
    Date date(y1, m1, d1);
    return date;
}
Date Date::month_plus() const
{
    int day_of_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int y2 = month() == 12 ? year() + 1 : year();
    int m2 = month() == 12 ? 1 : month() + 1;
    int d2 = day();
    day_of_month[1] = year_special() ? 29 : 28;
    d2 = d2 > day_of_month[m2 - 1] ? day_of_month[m2 - 1] : d2;
    Date date(y2, m2, d2);
    return date;
}
Date Date::day_plus() const
{
    int day_of_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int y3 = (month() == 12 && day() == 31) ? 1 : year();
    int m3 = month();
    day_of_month[1] = year_special() ? 29 : 28;
    m3 = day() == day_of_month[month() - 1] ? (month() == 12 ? 1 : month() + 1) : month();
    int d3 = day() == day_of_month[month() - 1] ? 1 : day() + 1;
    Date date(y3, m3, d3);
    return date;
}

bool Date::year_special() const
{
    return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
}

int Date::total_day() const
{
    int day_of_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int d = day();
    day_of_month[1] = year_special() ? 29 : 28;
    for (int i = 0; i != month() - 1; ++i)
        d += day_of_month[i];
    for (int j = 1; j != year(); ++j){
        int plus = j % 400 == 0 || (j % 4 == 0 && j % 100 != 0) ? 366 : 365;
        d += plus;
    }
    return d;
}