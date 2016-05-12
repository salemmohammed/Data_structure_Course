#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <cassert>
#include <cmath>

#include "City.h"

#include <sstream>      // std::istringstream

using namespace std;

City::City(string cityName, int xCoor, int yCoor){
	
	this->cityName = cityName;
	this->xCoor = xCoor;
	this->yCoor = yCoor;
}

string City::getName(){
	return this->cityName;
}

int City::getXCoor(){
	return this->xCoor;
}

int City::getYCoor(){
	return this->yCoor;
}
list<City*> City::getAdjacent(){
    return adjacents;
}


int getCase(int xdelta, int ydelta)
{
    assert(xdelta == 0 || ydelta == 0);
    assert(xdelta != 0 || ydelta != 0);

    if (xdelta < 0)
    {
        return 0;
    } else if (xdelta > 0) {
        return 1;
    } else if (ydelta < 0) {
        return 2;
    } else if (ydelta > 0) {
        return 3;
    }

    ///this should never happen
    return 0;
}

int getDistance(int xdelta, int ydelta)
{
    return std::abs(xdelta + ydelta);
}

void City::addAdjacentCity(City* other){
    assert(other->getXCoor() == getXCoor() || other->getYCoor() == getYCoor());

    int otherxdelta = getXCoor() - other->getXCoor()
      , otherydelta = getYCoor() - other->getYCoor();

    for (std::list<City*>::iterator w = adjacents.begin(); w != adjacents.end(); ++w)
    {
        City* adjacent = *w;

        int xdelta = getXCoor() - adjacent->getXCoor()
          , ydelta = getYCoor() - adjacent->getYCoor();

        assert(xdelta == 0 || ydelta == 0);

        if (getCase(xdelta,ydelta) == getCase(otherxdelta,otherydelta))
        {
            if (getDistance(xdelta,ydelta) < getDistance(otherxdelta,otherydelta))
            {

                /*

                O     x Z
                
------------------------------

                O-----x

                O-------Z

                ignore Z

                */
                return;
            } else {
                /*

                O-----x

                O---Z

                keep Z, get rid of x
                */
                *w = other;
                return;
            }


        }

    }


    ///we didn't encounter any conflicting case inside the current adjaceny list.

    adjacents.push_back(other);
}

bool City::operator<(City& c){
	// Compares cities by name using the string operator< method
	if(getName() < c.getName())
		return true;
	else
		return false;
}

/*
unsigned int pathDistance(City* start, City* dest){


    return -1;

}
*/

int getAdjacentDistance(City* a, City* b)
{
    int xdelta = a->getXCoor() - b->getXCoor();
    int ydelta = a->getYCoor() - b->getYCoor();

    
    return std::abs(xdelta + ydelta);
}
