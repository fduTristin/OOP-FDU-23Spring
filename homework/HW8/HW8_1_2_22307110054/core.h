#ifndef CORE_H
#define CORE_H

#include<string>
#include<vector>
#include<iostream>

class Core{
    friend class Student_info;
    private:
    std::string n;

    protected:
    std::istream& read_common(std::istream&);
    double mid,final;
    std::vector<double> hw;
    virtual Core* clone() const {return new Core(*this);} 

    public:
    Core() : mid(0),final(0) {}
    Core(std::istream& is) {read(is);}
    virtual ~Core() {}
    std::string name() const {return n;}
    virtual std::istream& read(std::istream&);
    virtual double grade() const;

};

class Grad : public Core
{
    public:
    Grad():thesis(0) {}
    Grad(std::istream& is) {read(is);}
    std::istream& read(std::istream&);
    double grade() const;

    protected:
    Grad* clone() const {return new Grad(*this);}

    private:
    double thesis;
};

std::istream& read_hw(std::istream& , std::vector<double>& hw);
#endif