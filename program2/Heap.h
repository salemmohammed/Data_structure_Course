#ifndef HEAP_H
#define HEAP_H

#include <string>
#include <vector>
#include "Player.h"

class Heap{
private:
	///this will internally represent our heap
	std::vector<Player> internal_heap;
public:
	Heap(std::string filename);// read the name and budget 
	Heap(const Heap &copy);
	void addPlayer(Player newPlayer); // add player to the heap
	Player getPlayer();
	bool empty();
	unsigned int size(); // return number of nodes in heap
	// you still need heap
	std::vector<Player> getArray();
};

#endif 