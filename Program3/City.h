#ifndef CITY_H
#define CITY_H

#include <list>
#include <string>

class City{
private:
	std::string cityName;
	int xCoor;
	int yCoor;

	std::list<City*> adjacents;

public:
	City(std::string cityName, int xCoor, int yCoor);
	std::string getName();
	int getXCoor();
	int getYCoor();
	std::list<City*> getAdjacent();
	bool operator<(City& c);
	void addAdjacentCity(City* other);


};


int getAdjacentDistance(City* a, City* b);

/*
			  x 
   x
		   x      x
	x
	  x    x  


*/

#endif