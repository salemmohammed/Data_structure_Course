#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cassert>

template<typename T>
class LinkedList;

template<typename T>
class Node
{
private:
	Node* next;
	T data;
	friend class LinkedList<T>;

public:
	Node()
		: data(T())
	{
		this->next = NULL;
	}
};


template<typename T>
class LinkedList
{
private:
	Node<T>* head;
	Node<T>* current;
public:
	LinkedList()
	{
		this->head = NULL;
		this->current = NULL;
	}

	LinkedList(const LinkedList<T>& other)
	{
		this->head = NULL;
		this->current = NULL;

		*this = other;
	}

	~LinkedList(){
		ResetList();
	}

	LinkedList& operator=(const LinkedList& other)
	{
		ResetList();


		this->head = NULL;
		this->current = NULL;

		if (other.head == NULL)
			return *this;

		///create and copy the head node
		this->head = new Node<T>();
		this->head->next = NULL;
		this->head->data = other.head->data;


		const Node<T>* othercur = other.head;
		Node<T>* ourcur = this->head;

		while(othercur->next != NULL)
		{

			const Node<T>* source_node = othercur->next;
			///create the new node
			Node<T>* new_node = new Node<T>();
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

	void ResetList();
	void ResetCurrent();
	void MoveCurrentNext();

	///for list++
	void operator++(int);

	bool CurrentHasNext() const;
	bool CurrentIsValid() const;

	void CreateLast(T new_value);
	void operator<<(int new_value);

	///remove the last node
	void RemoveLast();

	///Removes the current node, and afterward, sets the current to point
	/// at the following node, if such a node exists (else, it will be null/invalid)
	void RemoveCurrent();
	void UpdateAll(T new_value);
	void UpdateCurrent(T new_value);
	T& ReadLast();
	T& ReadCurrent() const;
	void Find(T needle);

	bool operator==(const LinkedList<T>& other) const;

	LinkedList& operator<<(const LinkedList& other)
	{
		Node<T>* othercur = other.head;

		while (othercur != NULL)
		{
			this->CreateLast(othercur->data);
			othercur = othercur->next;
		}

		return *this;
	}
};

template<typename T>
void LinkedList<T>::CreateLast(T new_value)
{
	Node<T>* item = new Node<T>();
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
		current = item;
	}
}


/*void LinkedList::operator<<(T new_value)
{
	CreateLast(new_value);
}*/


template<typename T>
void LinkedList<T>::ResetCurrent()
{
	if(current == head)
		return;

	current = head;
}

template<typename T>
void LinkedList<T>::MoveCurrentNext()
{
	if(current == NULL)
		return;

	current = current->next;
}


///this is for list++
template<typename T>
void LinkedList<T>::operator++(int)
{
	MoveCurrentNext();
}



template<typename T>
bool LinkedList<T>::CurrentHasNext() const
{
	if(current == NULL)
		return false;

	return current->next != NULL;
}
template<typename T>
bool LinkedList<T>::CurrentIsValid() const
{
	return current != NULL;
}

template<typename T>
void LinkedList<T>::ResetList()
{
	Node<T>* cur = head;


	while(cur != NULL)
	{
		// std::cerr << "--------------" << std::endl;
		// std::cerr << "cur: " << cur << std::endl;
		// std::cerr << "cur->next: " << cur->next << std::endl;

		Node<T>* node_to_delete = cur;
		Node<T>* next_node = cur->next;
		// std::cerr << "next_node: " << next_node << std::endl;
		// std::cerr << "cur: " << cur << std::endl;

		cur = next_node;
		// std::cerr << "cur: " << cur << std::endl;


		delete node_to_delete;
		// std::cerr << "cur: " << cur << std::endl;
	}
	// std::cerr << "break: " << cur << std::endl;

	head = NULL;
	current = NULL;
}

template<typename T>
void LinkedList<T>::RemoveLast()
{

	if (head == NULL)
		return;
	if (head->next == NULL)
	{
		Node<T>* node_to_delete = head;
		head = NULL;
		delete node_to_delete;

		return;
	}


	current = head;

	while(current->next->next != NULL)
	{
		current = current->next;
	}

	Node<T>* node_to_delete = current->next;

	current->next = NULL;

	delete node_to_delete;

	ResetCurrent();
}



template<typename T>
void LinkedList<T>::RemoveCurrent()
{
	if (current == NULL)
		return;

	if (head == NULL)
		return;

	if (current == head)
	{
		delete head;
		head = NULL;
		current = NULL;

		return;
	}

	Node<T>* previous = head;
	assert(previous);

	while (previous->next != current)
	{
		assert(previous);
		previous = previous->next;
		assert(previous);
	}

	assert(previous->next == current);
	Node<T>* node_to_delete = current;


	///same things:
	// previous->next = previous->next->next;
	///same thing: ^
	previous->next = current->next;

	current = previous->next;


	delete node_to_delete;
}



template<typename T>
void LinkedList<T>::UpdateAll(T value)
{
	current = head;
	while(current != NULL)
	{
		current->data = value;

		current = current->next;
	}
}


template<typename T>
void LinkedList<T>::UpdateCurrent(T value)
{
	assert(current);
	current->data = value;
}

template<typename T>
T& LinkedList<T>::ReadLast()
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

template<typename T>
T& LinkedList<T>::ReadCurrent() const
{
	assert (current != NULL);

	return current->data;
}

template<typename T>
void LinkedList<T>::Find(T needle)
{

	current = head;

	while(current != NULL)
	{
		if (current->data == needle)
			return;
		current = current->next;
	}
}



template<typename T>
bool LinkedList<T>::operator==(const LinkedList<T>& other) const
{
	const Node<T>* cur = head;
	const Node<T>* othercur = other.head;

	while (cur != NULL && othercur != NULL)
	{
		if (cur->data != othercur->data)
			return false;


		///increment both node pointers
		othercur = othercur->next;
		cur = cur->next;
	}

	if (cur != NULL || othercur != NULL)
	{
		///this means that the lists are not the same length, because the while loop did not iterate the entirety of the lists
		/// and left one of the pointers non-null

		return false;
	}



	return true;
}

#endif
