#include <iostream>

using std::cin; using std::cout;
using std::endl;

int main()
{
	int sidelength,length,width,baselength;
	int i,j;
	
	cout<<"Enter the side length of a square:";
	cin>>sidelength;
	
	for(i=0;i != sidelength;++i)
	{
		for(j=0;j != sidelength;++j) cout<<"* ";
		cout<<endl;
	}

	
	cout<<"Enter the length and width of a rectangle:";
	cin>>length>>width;
	
	for(i=0;i!=width;++i)
	{
		for(j=0;j != length;++j) cout<<"* ";
		cout<<endl;
	}

	
	cout<<"Enter the base length of an isosceles triangle(odd number):";
	cin>>baselength;
	int height=( 1+ baselength)/2;
	
	for(i=0;i != height;++i)
	{
		std::string space(2 * height - 2 * i - 2,' ');
		cout<<space;
		for(j=0;j != 2 * i + 1;++j) cout<<"* ";
		cout<<endl;
	}
	
	return 0; 
}
