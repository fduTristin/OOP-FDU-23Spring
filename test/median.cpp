#include"median.h"
#include<algorithm>

using std::vector;

double median(vector<double> vec)
{
    std::sort(vec.begin(),vec.end());
    typedef vector<double>::size_type size;
    size sz = vec.size();
    size mid = sz/2;
    return sz % 2 == 0 ? (vec[mid]+vec[mid - 1])/2  : vec[mid]; 
}