#ifndef DATE_H
#define DATE_H
#include <iostream>



class Date
{
public:
    Date() : y(0), m(0), d(0) {}
    Date(int, int, int);
    explicit Date(std::istream &);
    inline int year() const { return y; }
    inline int month() const { return m; }
    inline int day() const { return d; }
    void print();
    Date year_plus() const;
    Date month_plus() const;
    Date day_plus() const;
    bool year_special() const;
    int total_day() const;

private:
    int y, m, d;
};

#endif