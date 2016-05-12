
#ifndef MAP_H
#define MAP_H

#include <map>
#include <vector>

#include <string>

#include "City.h"




class Map{

private:
	std::map<std::string, City*> vmap;

public:
	Map(std::string filename);
	City* findByName(std::string cityName);
	std::vector<City *> shortestPath(City * start, City * dest);

	unsigned int pathDistance(City * start, City * dest);

	/*
	
	The method should return the shortest path between two cities by returning
	 a list of the cities you will need to travel through

	*/

	 //unsigned int pathDistance(City* start, City* dest);
	 /*

	 The method should return the total distance (based on the path you must take) between the two cities.
	The method should return -1 if there is no path

	 */

};
#endif
