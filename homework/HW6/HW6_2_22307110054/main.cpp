#include "Queue.h"
#include <iostream>

using std:: cout; using std::endl;

int main()
{
	Queue<int> q;
	int i = 1 , j = 1;
	for (int k = 0; !q.full(); k++)
	{
		if (k % 8 == 0) {
			q.enQueue(k);
			cout<<k<<"s: "<<"第"<<i<<"人进队."<<endl;
			i++;
		}
		if (k % 25 == 0 && k) {
			cout<<"                 "<<k<<"s: "<<"第"<<j<<"人出队."<<endl;
			q.deQueue();
			j++;
		}
	}

	if(q.full())
	{
		cout<<"                 该窗口排队人数已达到50人!请分流!"<<endl;
		q.print();
	}

    Queue<int> q1(q), q2; 
    q1.output();
    q2 = q1;
    q2.output();
    
    
	return 0;
}
