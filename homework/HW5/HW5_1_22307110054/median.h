#ifndef GUARD_median_h
#define GUARD_median_h
// source file for the 'median' function
#include <algorithm>    // to get the declaration of 'sort'
#include <stdexcept>    // to get the declaration of 'domain_error'
#include <vector>       // to get the declaration of 'vector'

using std::domain_error;  
using std::sort;
using std::vector;

// compute the median of a 'vector<double>'
// note that calling this function copies the entire argument 'vector'

template<typename Iterator>
typename std::iterator_traits<Iterator>::value_type median(Iterator begin, Iterator end)
{
    using T = typename std::iterator_traits<Iterator>::value_type;
    vector<T> tempVector(begin, end);
    std::sort(tempVector.begin(), tempVector.end());
    typedef typename vector<T>::size_type size;
    size sz = tempVector.size();
    size mid = sz/2;
    
    return sz % 2 == 0 ? (tempVector[mid] + tempVector[mid-1]) / 2 : tempVector[mid];
}
#endif

