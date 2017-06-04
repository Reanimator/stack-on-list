#pragma once
#include "LinkedList.h"
#include <iostream>
#include <fstream>

template<class E>
class ListStack
{
private:
	LinkedList<E> *list;

public:
	ListStack()
	{
		list = new LinkedList<E>;
	}
	~ListStack()
	{
		delete list;
	}

	void add(E elem)
	{
		list->addEnd(elem);
	}

	E get()
	{
		if (list->size() == 0)
			throw 2;
		E tmp = list->get(list->getEnd());
		list->removeEnd();
		return tmp;
	}

	void write_to_file()
	{
		LinkedList<E> *tmp = new LinkedList<E>;
		std::ofstream file("stack.txt");
		try
		{
			while (true)
			{
				tmp->addStart(get());
				file << tmp->get(tmp->getStart()) << std::endl;
			}
		}
		catch (...)
		{
			delete list;
			list = tmp;
		}
		file.close();
	}

	size_t size()
	{
		return list->size();
	}

	E operator[](size_t index)
	{
		int counter = 0;
		for (node<E>* i = list->getStart(); !list->isEnd(i); i = list->getNext(i), counter++)
		{
			if (counter == index)
				return list->get(i);
		}
	}
};