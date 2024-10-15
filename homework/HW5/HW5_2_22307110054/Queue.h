#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
class Queue
{
private:
	struct queuenode
	{
		int data;
		queuenode *next;
		queuenode(const int &Newdata, queuenode *nextnode = nullptr) : data(Newdata), next(nextnode) {}
	};
	queuenode *head;
	queuenode *tail;
	int count;

public:
	Queue();
	~Queue();
	bool empty() const;
	bool full() const;
	int size() const;
	void clear();
	void pop();
	void push(const int &node);
	void print();
	int &front();
	int front() const;
};

Queue::Queue()
{
	head = tail = new queuenode(0, 0);
	count = 0;
}

Queue::~Queue()
{
	delete head, tail;
}

int Queue::size() const
{
	return count;
}

bool Queue::empty() const
{
	return size() == 0;
}

bool Queue::full() const
{
	return size() == 50;
}

void Queue::clear()
{
	queuenode *p;
	for (p = head; p != tail;)
	{
		queuenode *q = p->next;
		delete p;
		p = q;
	}
	delete p;
}

void Queue::pop()
{
	if (!empty())
	{
		queuenode *temp = head;
		head = head->next;
		delete temp;
		count--;
		if (empty())
		{
			tail = nullptr;
		}
	}
}

void Queue::push(const int &node)
{
	queuenode *temp = new queuenode(node,nullptr);
	if (empty())
	{
		head = tail = temp;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}
	count++;
}

void Queue::print()
{
	std::cout<<"        队首人员于"<<head->data<<"s入队"<<std::endl;
	std::cout<<"        队尾人员于"<<tail->data<<"s入队"<<std::endl;
}

int &Queue::front()
{
	return head->data;
}

int Queue::front() const
{
	return head->data;
}
#endif
