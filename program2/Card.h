#ifndef CARDS_H
#define CARDS_H
#include <map>


std::string getSuitName(int suit);

class Card
{
private:
	int value;
	int suit;
public:
	Card(int suit,  int value);
	int getValue() const;
	int getSuit() const;
	std::string getSuitName() const;
	void print() const;
};

#endif
