#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

class Shape
{
protected:
double ar,p;

public:
    Shape() : ar(0), p(0) {}
    Shape(std::istream) {}
    virtual ~Shape() {}
    virtual std::istream &read(std::istream & is ) {return is;}
    double area() const {return ar;}
    double perimeter() const {return p;}
    virtual void _area() {}
    virtual void _perimeter() {}
    virtual void print() const {}
};

class Triangle : public Shape
{
private:
    double a, b, c;

public:
    Triangle() : a(0), b(0), c(0) {}
    Triangle(std::istream &is) { read(is); }
    std::istream &read(std::istream &);
    void _area();
    void _perimeter();
    void print() const {std::cout<<a<<", "<<b<<", "<<c<<' ';}
};

class Rectangle : public Shape
{
private:
    double length, width;

public:
    Rectangle() : length(0), width(0) {}
    Rectangle(std::istream &is) { read(is); }
    std::istream &read(std::istream &);
    void _area();
    void _perimeter();
};

class Circle : public Shape
{
private:
    static const double pi;
    double r;

public:
    Circle() : r(0) {}
    Circle(std::istream &is) { read(is); }
    std::istream &read(std::istream &);
    void _area();
    void _perimeter();
};

bool compare(const Shape& x, const Shape& y);
bool compare_sp(const Shape *sp1, const Shape *sp2);
#endif