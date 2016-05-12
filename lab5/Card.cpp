
#include <iostream>
#include "Card.h"
using namespace std;



std::map< int,std::string> getSuitNameMap()
{
	std::map<int,std::string> name_map;
	name_map.insert (std::pair<int,std::string>(1,"Heart"));
	name_map.insert (std::pair<int,std::string>(2,"Spade"));
	name_map.insert (std::pair<int,std::string>(3,"Diamond"));
	name_map.insert (std::pair<int,std::string>(4,"Club"));
	return name_map;
}

std::string getSuitName(int suit)
{
	static std::map<int,std::string> name_map = getSuitNameMap();

	std::map<int,std::string>::iterator w = name_map.find(suit);

	if (w == name_map.end())
		///Error: suit was not found inside the map
		return "";

	std::pair<int,std::string> pair = *w;

	return pair.second;
}


Card::Card(int suit, int value)
{
  this->suit = suit;
  this->value = value;
}

int Card::getSuit() const
{
  return this->suit;
}

int Card::getValue() const
{
  return this->value;
}

std::string Card::getSuitName() const
{
  return ::getSuitName(this->suit);
}

void Card::print() const{
  std::cout << getSuitName()<<" "<< getValue();
}
