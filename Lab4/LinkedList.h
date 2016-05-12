#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cassert>

class LinkedList;

class Node
{
private:
	Node* next;
	std::string data;
	friend class LinkedList;
	
	public:
		Node()
		{
			this->next = NULL;
			this->data = "";

			ifstream infile;
			infile.open(name);

			if(!infile.good())
			{
			cout << "File is not open";
			}

			else
			{
				string line;
				while(getline(infile,line))
					text = text + line + '\n';
			}

}
};



class LinkedList
{
	private:
		Node* head;
		Node* current;
	public:		
		LinkedList()
		{
			this->head = NULL;
			this->current = NULL;
		}
		LinkedList(const LinkedList& other)
		{
		
			this->head = NULL;
			this->current = NULL;

			if (other.head == NULL)
				return;
		
		///create and copy the head node
			this->head = new Node();
			this->head->next = NULL;
			this->head->data = other.head->data;
		
		
			const Node* othercur = other.head;
			Node* ourcur = this->head;
		
			while(othercur->next != NULL)
			{

				const Node* source_node = othercur->next;			
				///create the new node
				Node* new_node = new Node;
				new_node->next = NULL;
				new_node->data = source_node->data;
			
				///point the current node to the new node as the next
				ourcur->next = new_node;
				///increment both node cursors
				othercur = othercur->next;
				ourcur = ourcur->next;
			}
		
			this->current = this->head;
		}

		~LinkedList(){
			ResetList();
		}

	void ResetList();
	void ResetCurrent();
	void MoveCurrentNext();
	
	///for list++
	void operator++(int);
	
	bool CurrentHasNext() const;
	
	void CreateLast(std::string new_value);
	void operator<<(int new_value);
	
	///remove the last node
	void RemoveLast();
	void RemoveCurrent();
	void UpdateAll(int new_value);
	void UpdateCurrent(std::string new_value);
	std::string ReadLast();
	std::string ReadCurrent() const;
	void Find(std::string needle);
};

#endif 