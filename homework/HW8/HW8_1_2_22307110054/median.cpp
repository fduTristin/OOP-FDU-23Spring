#include"median.h"
#include<algorithm>


double median(std::vector<double> vec)
{
	std::sort(vec.begin(), vec.end());
	typedef std::vector<double>::size_type vec_sz;
	vec_sz sz=vec.size();
	vec_sz mid=sz/2;
	return sz%2==0? (vec[mid]+vec[mid-1])/2 : vec[mid];
}
