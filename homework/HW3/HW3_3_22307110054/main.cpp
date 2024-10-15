#include "function.h"
#include <iostream>
#include <list>
#include <cstdlib>
#include <random>
#include <ctime>
#include <string>
#include <vector>

using std::string;
using std::vector;

int main()
{
	// write your code here
	vector<int> v1;
	vector<double> v2;
	vector<string> v3;

	srand((unsigned)time(NULL));
	for (int i = 0; i != 10; ++i)
	{
		int a = rand() % 100;
		v1.push_back(a);
	}
	cout << "the integer list: " << endl;
	print(v1);

	int sum1 = accumulate(v1.begin(), v1.end(), 0);
	cout << "the sum of the integer list: " << sum1 << endl;

	vector<int>::iterator p1 = max_element(v1.begin(), v1.end());
	cout << "the max element in the integer list: " << *p1 << endl;

	p1 = min_element(v1.begin(), v1.end());
	cout << "the min element in the integer list: " << *p1 << endl
		 << endl;
	// int list

	for (int i = 0; i != 10; ++i)
	{
		double a = 1.0 * rand() / (RAND_MAX + 1u) * 10;
		v2.push_back(a);
	}
	cout << "the double list:" << endl;
	print(v2);

	double sum2 = accumulate(v2.begin(), v2.end(), 0.0);
	cout << "the sum of the double list: " << sum2 << endl;

	vector<double>::iterator p2 = max_element(v2.begin(), v2.end());
	;
	cout << "the max element in the double list: " << *p2 << endl;

	p2 = min_element(v2.begin(), v2.end());
	cout << "the min element in the double list: " << *p2 << endl
		 << endl;
	// double list

	
	for (int i = 0; i != 10; ++i)
	{
		int j = rand() % 5 + 1;
		string s = "";
		for (int k = 0; k != j; ++k)
		{
			char a='a'+rand()%25;
			s.push_back(a);
		}
		v3.push_back(s);
	}

	cout << "the string list: " << endl;
	print(v3);

	string a;
	string sum3 = accumulate(v3.begin(), v3.end(), a);
	cout << "the concatenation of the string list: " << sum3 << endl;

	vector<string>::iterator p3;
	p3 = max_element(v3.begin(), v3.end());
	cout << "the max element in the string list: " << *p3 << endl;

	p3 = min_element(v3.begin(), v3.end());
	cout << "the min element in the string list: " << *p3 << endl;
	// string list
	return 0;
}
