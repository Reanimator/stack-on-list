#pragma once

template<class E>
struct node
{
	E data;
	node<E> *next;
};
template<class E>
class LinkedList 
{
private:
	

	node<E> *head, *tail;
	size_t count;
public:
	
	LinkedList():count(0)
	{
	}

	~LinkedList()
	{
		if (head == 0)
			return;
		node<E> *tmp ;
		node<E> *next = head;
		do {

			tmp = next->next;
			delete next;
			next = tmp;
		} while (next != head);
	}

	void addEnd(E e);

	E get(node<E>*);
	
	bool isEmpty();
	void removeEnd();
	void removeStart();
	size_t size();
	void clear();
	node<E>* getStart()
	{
		return head;
	}
	node<E>* getEnd()
	{
		return tail;
	}
	node<E>* getNext(node<E>*);
	bool isEnd(node<E>* tmp)
	{
		if (tmp->next == head)
			return true;

	}
	//*/

};

template<class E>
void LinkedList<E>::addEnd(E e)
{
	node<E> *tmp = new node<E>;
	tmp->data = e;
	if (head == 0)
	{
		head = tail = tmp;
	}
	else
	{
		tail->next = tmp;
		tail = tmp;
	}
	tmp->next = head;
	++count;
}

template<class E>
E LinkedList<E>::get(node<E>* tmp)
{
	if (tmp == nullptr)
		throw 1;
	return tmp->data;
}


template<class E>
inline bool LinkedList<E>::isEmpty()
{
	return count == 0;
}

template<class E>
inline void LinkedList<E>::removeEnd()
{
	if (count == 1)
	{
		delete head;
		head = tail = 0;
		count = 0;
		return;
	}

	node<E> *prev = head;
	for (node<E> *i = head; isEnd(i); i = i->next)
	{
		if (i == tail)
		{
			tail = prev;
			delete tail->next;
			tail->next = head;
			break;
		}
		prev = i;
	}
	--count;
}
template<class E>
inline void LinkedList<E>::removeStart()
{
	if (count == 1)
	{
		delete head;
		head = tail = 0;
		count = 0;
		return;
	}

	node<E> *prev = head;
	for (node<E> *i = head; isEnd(i); i = i->next)
	{
		if (i == head)
		{
			head = head->next;
			delete tail->next;
			tail->next = head;
			break;
		}
		prev = i;
	}
	--count;
}

/*template<class E>
void LinkedList<E>::remove(size_t index)
{
	if (index > count)
		throw INDEX_ERROR_EXCEPTION;

	if (count == 1)
	{
		delete head;
		head = tail = 0;
		count = 0;
		return;
	}

	node<E> *prev = head;
	size_t counter = 0;
	for (node<E> *i = head; counter < count; i = i->next, counter++)
	{
		if (counter == index)
		{
			if (i == head)
			{
				head = head->next;
				delete tail->next;
				tail->next = head;
				break;
			}
			if (i == tail)
			{
				tail = prev;
				delete tail->next;
				tail->next = head;
				break;
			}
			if (i != tail && i != head)
			{
				prev->next = i->next;
				delete i;
			}
			break;
		}
		prev = i;
	}
	--count;
}*/

template<class E>
inline size_t LinkedList<E>::size()
{
	return count;
}

template<class E>
inline void LinkedList<E>::clear()
{
	node<E> *tmp;
	node<E> *next = head;
	do
	{
		tmp = next->next;
		delete next;
		next = tmp;

	} while (next != head);
	head = tail = 0;
	count = 0;
}

template<class E>
inline node<E>* LinkedList<E>::getNext(node<E>* tmp)
{
	return tmp->next;
}
