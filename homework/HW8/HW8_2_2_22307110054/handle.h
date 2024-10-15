#ifndef HANDLE_H
#define HANDLE_H

#include "shape.h"
#include <vector>

class Handle
{
private:
    Shape *sp;

public:
    Handle() : sp(0) {}
    Handle(const Handle &h) : sp(0)
    {
        if (h.sp)
            sp = h.sp->clone();
    }
    Handle(std::istream &is) : sp(0) { read(is); }
    ~Handle() { delete sp; }
    Handle &operator=(const Handle &s);
    std::istream &read(std::istream &);

    double area() const
    {
        if (sp)
            return sp->area();
        else
            throw std::runtime_error("uninitialized shape.");
    }

    double perimeter() const
    {
        if (sp)
            return sp->perimeter();
        else
            throw std::runtime_error("uninitialized shape.");
    }

};

std::istream &readinfo(std::istream &, std::vector<Handle> &);

bool compare(const Handle &, const Handle &);
void cal_output(const std::vector<Handle>& vec);

#endif