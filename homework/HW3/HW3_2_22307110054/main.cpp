#include"find.h"
#include<iostream>
#include<list>
#include<cstdlib>
#include<ctime>
#include<string>
#include<vector>

using std::vector;
using std::string;
using std::list;
using std::cin;


int main() {
	// write your code here
	vector<int> vec_0;
	vector<int> vec_1;
	list<string> lis_0;
	list<string> lis_1;
	cout << "Random integer vector 1:" << endl;
	srand((unsigned)time(NULL));
	for(int i=0;i!=13;++i)
	{
    	int a = rand()%20;
    	vec_0.push_back(a);
		cout<<a<<"  ";
	}
	cout<<endl;

	cout << "Random integer vector 2:" << endl;
	for(int i=0;i!=13;++i)
	{
    	int a = rand()%20;
    	vec_1.push_back(a);
		cout<<a<<"  ";
	}
	cout<<endl;

	cout<<"Vector in common:"<<endl;
	print(find_same(vec_0,vec_1));

	string s;
	cout<<"Enter some words for string list 1:"<<endl;
	while(cin>>s) lis_0.push_back(s);
	cin.clear();

	cout<<"Enter some words for string list 2:"<<endl;
	while(cin>>s) lis_1.push_back(s);
	cin.clear();

	cout<<"List in common:"<<endl;
	print(find_same(lis_0,lis_1));
	return 0;
}
