#include <iostream>
#include "LinkedList.h"
using namespace std;

void print_ll(LinkedList& list)
{
	
	list.ResetCurrent();
	
	while (list.CurrentHasNext())
	{
		std::cout << "," << list.ReadCurrent();
		
		list++;
	}
	std::cout << "," << list.ReadCurrent();
	
	std::cout << std::endl;
}


int main()
{
	LinkedList obj;
	
	obj.CreateLast("");
	obj.CreateLast("");
	obj.CreateLast("");
	obj.CreateLast("");
	obj.CreateLast("");


	obj.ResetList();

	obj.CreateLast("");
	obj.CreateLast("egss");
	obj.CreateLast("milk");
	obj.CreateLast("sugar");
	obj.CreateLast("chocolate");
	obj.CreateLast("flour");

	print_ll(obj);
	
	obj.RemoveLast();
	obj.CreateLast("Coffee");

	obj.Find("sugar");
	obj.RemoveCurrent();
	obj.UpdateCurrent("Honey");
	obj.Find("milk");
	obj.RemoveCurrent();
	print_ll(obj);



	/*
	obj.RemoveLast();
	obj.ResetCurrent();
	obj++;
	obj++;
	///should get rid of 12
	obj.RemoveCurrent();
	///now current should point at 11
	
	std::cout << "expecting 11, got " << obj.ReadCurrent() << std::endl;
	
	print_ll(obj);
	
	obj.CreateLast(20);
	obj.CreateLast(21);
	obj.CreateLast(22);
	obj.CreateLast(23);
	obj.CreateLast(24);
	
	obj.ResetCurrent();
	//obj.Find(21);
	///should get rid of 21
	obj.RemoveCurrent();
	std::cout << "expecting 20, got " << obj.ReadCurrent() << std::endl;

	//print_ll1(obj);

	obj.UpdateCurrent(25);

	print_ll(obj);

	*/
	return 0;
}