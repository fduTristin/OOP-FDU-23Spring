#ifndef FUNCTION_H
#define FUNCTION_H
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <iomanip>

using std::cout;
using std::endl;

template <class VEC, class type>
type accumulate(VEC &begin, VEC &end, type t)
{
    while (begin != end)
    {
        t += *begin;
        ++begin;
    }
    return t;
}

template <class container>
void print(container con)
{
    for (typename container::const_iterator it = con.begin(); it != con.end(); ++it){
        std::streamsize prec = cout.precision();
        cout << std::setprecision(6) << *it << std::setprecision(prec) << " ";
    }
    cout << endl;
}

template <class VEC, class type>
VEC max_element(VEC &begin, VEC &end)
{
    VEC max = begin;
    while (begin != end)
    {
        *max = *max > *begin ? max : begin;
        ++begin;
    }
    return max;
}

template <class VEC, class type>
VEC min_element(VEC &begin, VEC &end)
{
    VEC min = begin;
    while (begin != end)
    {
        min = *min < *begin ? min : begin;
        ++begin;
    }
    return min;
}
#endif
