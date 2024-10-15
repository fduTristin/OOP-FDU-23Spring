#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

int main() {
	string s1,s2,s3,s;
	cin>>s1>>s2>>s3;

	for(int i=0; i!=2; ++i) {
		if(s1>s2) {
			s=s1,s1=s2,s2=s;
		}
		if(s2>s3) {
			s=s2,s2=s3,s3=s;
		}
	}

	cout<<s1<<' '<<s2<<' '<<s3;

	return 0;
}
