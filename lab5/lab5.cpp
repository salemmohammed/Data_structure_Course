#include <iostream>
#include <map>
#include <string>

#include "Card.h"
#include "Deck.h"


int main()
{
	Deck deck;

	while (deck.size() > 0)
	{
		Card c = deck.draw();

		c.print();
		std::cout << std::endl;
	}

	std::cout << std::endl;
	
	Deck deck2;
	deck2.shuffle();

	while (deck2.size() > 0)
	{
		Card c = deck2.draw();

		c.print();
		std::cout << std::endl;
	}


	return 0;
}
