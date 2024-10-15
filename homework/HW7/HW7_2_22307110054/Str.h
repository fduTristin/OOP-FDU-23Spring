#ifndef STR_H
#define STR_H

#include "Vec.h"
#include <algorithm>
#include <cstring>
#include <iterator>
#include <iostream>

int ascii (char c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 32;
    else
        return c;
}

class Str
{
    friend std::istream &operator>>(std::istream &, Str &);

public:
    typedef Vec<char>::size_type size_type;
    Str() {}
    Str(size_type n, char c) : data(n, c) {}
    Str(const char *cp)
    {
        std::copy(cp, cp + std::strlen(cp), std::back_inserter(data));
    }
    template <class In>
    Str(In i, In j)
    {
        std::copy(i, j, std::back_inserter(data));
    }
    size_type size() const { return data.size(); }

    char &operator[](size_type i) { return data[i]; }
    const char &operator[](size_type i) const { return data[i]; }

    Str &operator+=(const Str &s);
    bool operator<(const Str &s);

    void transfer() 
    {
        for(Str::size_type k = 0; k != size(); ++k)
            data[k] = ascii(data[k]);
    }

private:
    Vec<char> data;
};

std::istream &operator>>(std::istream &is, Str &s)
{
    s.data.clear();
    char c;
    while (is.get(c) && isspace(c))
        ;
    if (is)
    {
        do
            s.data.push_back(c);
        while (is.get(c) && !isspace(c));
        if (is)
            is.unget();
    }
    return is;
}

std::ostream &operator<<(std::ostream &os, const Str &s)
{
    for (Str::size_type i = 0; i != s.size(); ++i)
        os << s[i];
    return os;
}

Str &Str::operator+=(const Str &s)
{
    std::copy(s.data.begin(), s.data.end(), std::back_inserter(data));
    return *this;
}

Str operator+(const Str &s, const Str &t)
{
    Str r = s;
    r += t;
    return r;
}

bool Str::operator<(const Str &s)
{
    bool flg1 = 1, flg2 = 1;

    for (Str::size_type i = 0; i != size() && i != s.size(); ++i)
    {
        if ((data[i]) < (s[i]))
            break;
        if ((data[i]) > (s[i]))
            flg1 = 0;
    }
    for (Str::size_type i = 0; i != size() && i != s.size(); ++i)
    {
        if ((data[i]) != (s[i]))
            flg2 = 0;
    }

    if (flg2 && size() > s.size())
        flg1 = 0;

    return flg1;
}

#endif