#ifndef CORE_H
#define CORE_H

#include <iostream>
#include <string>
#include <vector>

class Core
{
private:
    std::string n;

protected:
    double mid, final;
    std::vector<double> hw;
    std::istream &read_common(std::istream &);

public:
    Core() : mid(0), final(0) {}
    Core(std::istream &is) { read(is); }
    virtual ~Core() {}
    virtual std::istream &read(std::istream &);
    virtual double grade() const;
    std::string name() const {return n;}
};

class Grad : public Core
{
public:
    Grad() : thesis(0) {}
    Grad(std::istream &is) { read(is); }
    double grade() const;
    std::istream &read(std::istream &);

private:
    double thesis;
};

std::istream &read_hw(std::istream &, std::vector<double> &);
bool compare(const Core &, const Core &);
bool compare_Core_ptrs(const Core *cp1, const Core *cp2);

#endif