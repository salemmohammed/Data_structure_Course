#ifndef DOCK_H
#define DOCK_H
#include <map>
#include <deque>

#include "Card.h"

class Deck
{
private:
	std::deque<Card> mCards;
public:
	Deck();
	~Deck();

	int size() const;
	void print();
	void shuffle();
	Card draw();
};


#endif
