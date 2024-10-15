#include"median.h"
#include<algorithm>


double median(std::vector<double> hw)
{
	std::sort(hw.begin(), hw.end());
	typedef std::vector<double>::size_type vec_sz;
	vec_sz sz=hw.size();
	vec_sz mid=sz/2;
	return sz%2==0? (hw[mid]+hw[mid-1])/2 : hw[mid];
}

