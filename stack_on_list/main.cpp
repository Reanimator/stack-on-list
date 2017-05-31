#include "ListStack.h"
#include "ListQueue.h"
#include <iostream>


void main()
{
	ListStack<int> lt;
	ListQueue<int> lq;

	lt.add(15);
	lt.add(25);
	lt.add(35);
	lt.add(45);
	lt.add(75);

	lq.add(15);
	lq.add(25);
	lq.add(35);
	lq.add(45);
	lq.add(75);

	std::cout << std::endl;
	try
	{
		for (;;)
			std::cout << lt.get() << "|";
	}
	catch (int ee)
	{
		std::cout << std::endl << "stack is empty"<<std::endl;
	}
	try
	{
		for (;;)
			std::cout << lq.get() << "|";
	}
	catch (int ee)
	{
		std::cout << std::endl << "quoue is empty";
	}


	std::cin.get();


}