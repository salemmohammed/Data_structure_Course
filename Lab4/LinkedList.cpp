#include <iostream>
#include "LinkedList.h"
using namespace std;

void LinkedList::CreateLast(string new_value)
{
	Node* item = new Node();
	item->next = NULL;
	item->data = new_value;
	
	if(head == NULL)
	{
		head = item;
		current = item;

	}
	else
	{
		current = head;
		while(current -> next != NULL)
		{
			current = current->next;
		}
		current->next = item;
	}
}


/*void LinkedList::operator<<(string new_value)
{
	CreateLast(new_value);
}*/


void LinkedList::ResetCurrent()
{
	if(current == head)
		return;
	
	current = head;
}

void LinkedList::MoveCurrentNext()
{
	if(current == NULL)
		return;
	
	current = current->next;
}


///this is for list++
void LinkedList::operator++(int)
{
	MoveCurrentNext();
}



bool LinkedList::CurrentHasNext() const
{
	if(current == NULL)
		return false;
	
	return current->next != NULL;
}

void LinkedList::ResetList()
{
	current = head;
	while(current != NULL)
	{
		Node* next_node = current->next;
		delete current;
		
		current = next_node;
	}
	
	head = NULL;
	current = NULL;
}

void LinkedList::RemoveLast()
{
	
	if (head == NULL)
		return;
	if (head->next == NULL)
	{
		head = NULL;
		return;
	}
	
	current = head;
	
	while(current->next->next != NULL)
	{
		current = current->next;
	}
	
	current->next = NULL;
	ResetCurrent();
}



void LinkedList::RemoveCurrent()
{
	if (current == NULL)
		return;
	
	if (head == NULL)
		return;
	
	Node* previous = head;
	
	while (previous->next != current)
	{
		previous = previous->next;
	}
	
	
	///same things:
	// previous->next = previous->next->next;
	///same thing: ^
	previous->next = current->next;
	
	current = previous;
}



void LinkedList::UpdateAll(int value)
{
	current = head;
	while(current != NULL)
	{
		current->data = value;
		
		current = current->next;
	}
}


void LinkedList::UpdateCurrent(string value)
{
	current->data = value;
}

string LinkedList::ReadLast()
{
	if (head == NULL)
		return 0;
	
	current = head;
	while(current->next != NULL)
	{
		current = current->next;
	}

	return current->data;
}

string LinkedList::ReadCurrent() const
{
	if (current == NULL)
		return 0;
	return current->data;
}

void LinkedList::Find(string needle)
{
	
	if (head == NULL)
		current = NULL;
	
	current = head;
	
	while(current != NULL)
	{
		if (current->data == needle)
			return;
		current = current->next;
	}
}