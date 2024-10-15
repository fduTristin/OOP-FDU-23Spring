#ifndef FIND_H
#define FIND_H
#include<iostream>
#include<cstdlib>
#include<algorithm>
using std::cout;
using std::endl;
template <class container>
container find_same(container &input_0, container &input_1)
{
	container v;
	for(typename container::const_iterator it = input_0.begin(); it != input_0.end(); ++it)
	{
		if(find(input_1.begin() , input_1.end(), *it) != input_1.end())
		v.push_back(*it);
	}
	return v;
}
template <class container>
void print(container con) {
	for(typename container::const_iterator it = con.begin(); it!=con.end(); ++it)
		cout<<*it<<"  ";
	cout<<endl;
}
#endif
