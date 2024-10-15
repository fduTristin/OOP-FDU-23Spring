#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

class Shape
{
    friend class Handle;

protected:
    double ar, p;
    virtual Shape *clone() const { return new Shape(*this); }

public:
    Shape() : ar(0), p(0) {}
    Shape(std::istream) {}
    virtual ~Shape() {}
    virtual std::istream &read(std::istream &is) { return is; }
    double area() const { return ar; }
    double perimeter() const { return p; }
    virtual void _area() {}
    virtual void _perimeter() {}
};

class Triangle : public Shape
{
private:
    double a, b, c;

protected:
    Triangle *clone() const { return new Triangle(*this); }

public:
    Triangle() : a(0), b(0), c(0) {}
    Triangle(std::istream &is) { read(is); }
    std::istream &read(std::istream &);
    void _area();
    void _perimeter();
};

class Rectangle : public Shape
{
private:
    double length, width;

protected:
    Rectangle *clone() const { return new Rectangle(*this); }

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

protected:
    Circle *clone() const { return new Circle(*this); }

public:
    Circle() : r(0) {}
    Circle(std::istream &is) { read(is); }
    std::istream &read(std::istream &);
    void _area();
    void _perimeter();
};

#endif