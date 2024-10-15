#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept>

template <class T>
class Queue
{
public:
	
	typedef size_t size_type;
	Queue();			   // default constructor
	Queue(const Queue &q); // copy constructor
	~Queue();			   // destructor

	Queue &operator=(const Queue &); 

	bool enQueue(T); 
	bool deQueue();	 

	T front() const; 
	T back() const;	 

	size_type size() const; 
	bool empty() const;		
	bool full() const;		

	void output() const; 
	void print() const;
private:
	struct node
	{
		T val;
		node *next;
		node(const T &Newval, node *next_ = nullptr) : val(Newval), next(next_) {}
	} *head, *rear; 

	size_type count;

	
	void copyLink(node *); 
	void freeLink();	  
};

template <class T>
Queue<T>::Queue()
{
	head = rear = new node(0, 0);
	count = 0;
	std::cout<<"default constructor called."<<std::endl;
}

template<class T>
Queue<T>::Queue(const Queue& q) {
	std::cout<<"copy constructor called."<<std::endl;
	head = rear = nullptr;
	count = 0;
	copyLink(q.head);
	
}

template <class T>
Queue<T>::~Queue()
{
	freeLink();
	std::cout<<"destructor called."<<std::endl;
}

template <class T>
Queue<T> &Queue<T>::operator=(const Queue &q)
{
	std::cout<<"operator=() called."<<std::endl;
	if (this == &q) {
        return *this;
    }
    freeLink();
    head = rear = nullptr;
    count = 0;
    copyLink(q.head);
    return *this;
	
}

template <class T>
bool Queue<T>::enQueue(T t)
{
	node* temp = new node(t, nullptr);

	if (empty())
	{
		head = rear = temp;
		count++;
		return true;
	}

	else
	{
		rear->next = temp;
		rear = temp;
		count++;
		return true;
	}
}

template <class T>
bool Queue<T>::deQueue()
{
	if (empty())
		return false;
	if(!empty()) {
		node* temp = head;
		head = head->next;
		delete temp;
		count--;
		if(empty()) rear = nullptr;
		
	}
	return true;
}

template <class T>
void Queue<T>::copyLink(node *src)
{
	while (src != nullptr)
	{
		enQueue(src->val);
		src = src->next;
	}
	
}

template <class T>
void Queue<T>::freeLink()
{
	while (head != nullptr)
	{
		node *p = head;
		head = head->next;
		delete p;
	}
	count = 0;
}

template <class T>
T Queue<T>::front() const
{
	if (head == nullptr)
	{
		throw std::domain_error("Queue is empty.");
	}
	return head->val;
}

template <class T>
T Queue<T>::back() const
{
	if (rear == nullptr)
	{
		throw std::domain_error("Queue is empty.");
	}
	return rear->val;
}

template <class T>
typename Queue<T>::size_type Queue<T>::size() const
{
	return count;
}

template <class T>
bool Queue<T>::full() const
{
	return count == 50;
}

template <class T>
bool Queue<T>::empty() const
{
	return count == 0;
}

template <class T>
void Queue<T>::output() const
{
	node *p = head;
	int i = 0;
	for (p = head; p != rear->next; p = p->next)
	{
		if (i % 10 == 0 && i) std::cout<<std::endl;
		std::cout<<p->val<<" ";
		i++;
	}
	std::cout<<std::endl<<std::endl;
}

template<class T>
void Queue<T>::print() const
{
	std::cout<<"        队首人员于"<<head->val<<"s入队"<<std::endl;
	std::cout<<"        队尾人员于"<<rear->val<<"s入队"<<std::endl;
}
#endif
