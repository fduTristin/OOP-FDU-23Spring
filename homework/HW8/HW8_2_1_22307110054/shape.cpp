#include "shape.h"
#include <stdexcept>
#include <cmath>

using std::istream;
using std::sqrt;

const double Circle::pi = 3.14;

istream &Triangle::read(istream &is)
{
    is >> a >> b >> c;
    _area();
    _perimeter();
    return is;
}

void Triangle::_area()
{
    if (a + b <= c || a + c <= b || b + c <= a)
    {
        throw std::domain_error("can't make a triangle.");
        ar = 0;
    }

    else
    {
        double p_ = (a + b + c) / 2;
        ar = sqrt(p_ * (p_ - a) * (p_ - b) * (p_ - c));
    }
}

void Triangle::_perimeter() 
{
    p = a + b + c;
}

istream &Rectangle::read(istream &is)
{
    is >> length >> width;
    _area();
    _perimeter();
    return is;
}

void Rectangle::_area() 
{
    ar = length * width;
}

void Rectangle::_perimeter() 
{
    p = 2 * length + 2 * width;
}

istream &Circle::read(istream &is)
{
    is >> r;
    _area();
    _perimeter();
    return is;
}

void Circle::_area()
{
    ar = pi * r * r;
}

void Circle::_perimeter() 
{
    p = 2 * pi * r;
}

bool compare(const Shape& x, const Shape& y)
{
    return x.area() < y.area();
}

bool compare_sp(const Shape *sp1, const Shape *sp2)
{
    return compare(*sp1,*sp2);
}