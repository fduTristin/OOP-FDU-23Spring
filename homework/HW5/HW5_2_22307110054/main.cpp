#include "Queue.h"
#include <iostream>

using std:: cout; using std::endl;

int main()
{
	Queue q;
	int i = 1 , j = 1;
	for (int k = 0; !q.full(); k++)
	{
		if (k % 8 == 0) {
			q.push(k);
			cout<<k<<"s: "<<"第"<<i<<"人进队."<<endl;
			i++;
		}
		if (k % 25 == 0 && k) {
			cout<<"                 "<<k<<"s: "<<"第"<<j<<"人出队."<<endl;
			q.pop();
			j++;
		}
	}

	if(q.full())
	{
		cout<<"                 该窗口排队人数已达到50人!请分流!"<<endl;
		q.print();
	}
	return 0;
}
