#include <iostream>

using std::cin;  using std::cout;

int main()
{
	int year,month,day;
	
	cout<<"Enter the baby's birthday: ";
	cin>>year>>month>>day;
	
	int m[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	
	for(int i=1;i != 100;++i)
	{
		if(month == 12 && day == 31)	
		{
			month=1,day=1,year+=1;
		}
		
		else
		{
			if((year%4 == 0 && year%100 != 0) || year%400 == 0) 
				m[1]=29;
			else 
				m[1]=28;
			if(day < m[month - 1]) 
				day+=1;
			else 
			{
				day=1;month+=1;
			}	
		}
	}
	
	cout<<"The baby's 100-day date is: "<<year<<' '<<month<<' '<<day;
	
	return 0;
} 
