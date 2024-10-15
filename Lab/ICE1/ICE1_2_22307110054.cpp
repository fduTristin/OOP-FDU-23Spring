#include <iostream>

using std::cin;
using std::cout;

int main () {
	long a0,n,m,x,d,p;
	cin>>a0>>n>>m>>x;

	int a[n],b[n];
	a[0]=a0;
	b[0]=0;
	b[n-1]=m;
	//a[k]-b[k]=a[k-2] (k>=2) m=a+0+a[0]+...+a[n-4] a[0]=a a[1]=d a[2]=a+d a[3]=a+2d a[4]=2a+3d a、d的系数为Fibonacci数列 记录a、d的系数

	int ca[n],cd[n],SUMa,SUMd;
	ca[0]=1,ca[1]=0,cd[0]=0,cd[1]=1;
	SUMa=ca[0]+ca[1],SUMd=cd[0]+cd[1];

	for(int i=2; i!=n-3; ++i) {
		ca[i]=ca[i-1]+ca[i-2];
		cd[i]=cd[i-1]+cd[i-2];
		SUMa+=ca[i];
		SUMd+=cd[i];
	}

	d=(m-a0-SUMa*a0)/SUMd;

	p=a0;
	if(x==1||x==2) cout<<p;
	else {
		for (int i=2; i!=x; ++i) {
			p+=ca[i-2]*a0+cd[i-2]*d;
		}
		cout<<p;
	}
	return 0;
}
