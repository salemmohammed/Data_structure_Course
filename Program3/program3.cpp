#include <string>
#include <iostream>
#include <cassert>
#include <list>
#include "Map.h"
#include "Map.h"
#include "City.h"
#include "City.h"
using namespace std;

//*************Utility functions for debugging***************//

void printAdj(string city, list<City *> adjacency){
	cerr << "Adjacencies for:\t" << city << endl;
	for(auto ptr:adjacency) 
		cerr << ptr->getName() << " --- [x]: " << ptr->getXCoor() << " [y]: " << ptr->getYCoor() << endl;
}

void printPath(vector<City *> path){
	cerr << "Your path size is : " << path.size() << endl;
	if (!path.empty()) {
		auto it = path.begin();
		cout << "Your Starting City is:\t" << (*it)->getName() << endl;
		
		for (; it != path.end(); it++){
			City * c = (*it); 
			if (it+1 == path.end()) {
				cout << "Your Destination City is:\t" << c->getName() << endl;
				//cout << "\tDistance from the last node: " << step->distanceFromOptimalPrevious() << endl;
				cout << "\tThe (x,y) coordinates are: (" << c->getXCoor() << ", " << c->getYCoor() << ")" << endl;
			}else{
				cout << "The next city is: " << c->getName() << endl;
				cout << "\tThe (x,y) coordinates are: (" << c->getXCoor() << ", " << c->getYCoor() << ")" << endl;
			}
		}
	}	
}
//********************************************************************//

void checkAdjacencies(Map &map, string city, vector<string> &adjacents){
	list<City*> adj, test;
	test = map.findByName(city)->getAdjacent();
	assert(test.size() == adjacents.size());
	test.sort();
	for(auto a: adjacents){
		adj.push_back(map.findByName(a));
	}
	adj.sort();
	auto a = adj.begin();
	auto t = test.begin();
	for(; a != adj.end() && t != test.end(); a++, t++){
		assert((*a)->getName() == (*t)->getName());
	}
}

void checkPath(Map &map, vector<string> &cities, string start, string dest){
	City * startc = map.findByName(start);
	City * destc = map.findByName(dest);

	vector<City *> route = map.shortestPath(startc, destc);
	assert(route.size() == cities.size());
	int i = 0;
	for(auto r: route){
		assert(r->getName() == cities.at(i));
		i++;
	}
}

int main(int argc, char *argv[]){

	cerr << "\n\tTEST #1: Read file a list of Cities and their locations" << endl;	
	Map map("townlist.txt");
	
	assert(map.findByName("binghamton") != NULL);
	assert(map.findByName("fairbanks") != NULL);
	assert(map.findByName("cypress") != NULL);
	assert(map.findByName("victorville") != NULL);
	assert(map.findByName("laguna") != NULL);
	assert(map.findByName("anaheim") != NULL);
	assert(map.findByName("bend") != NULL);
	assert(map.findByName("rialto") != NULL);
	assert(map.findByName("kathmandu") == NULL);
	assert(map.findByName("bend")->getXCoor() == 6 && map.findByName("bend")->getYCoor() == 7);
	assert(map.findByName("rialto")->getXCoor() == 4 && map.findByName("rialto")->getYCoor() == 7);

	cerr << "\n\t========================PASS========================\n" << endl;


	cerr << "\n\tTEST #2: Test Adjacencies" << endl;	

	string city = "bend";
	vector<string> adjacents = {"victorville", "rialto"};
	checkAdjacencies(map, city, adjacents);

	city = "rialto";
	adjacents = {"bend", "anaheim"};
	checkAdjacencies(map, city, adjacents);

	city = "fairbanks";
	adjacents = {"binghamton", "anaheim"};
	checkAdjacencies(map, city, adjacents);

	city = "cypress";
	adjacents = {"binghamton", "anaheim", "victorville"};
	checkAdjacencies(map, city, adjacents);

	city = "anaheim";
	adjacents = {"rialto", "cypress", "fairbanks"};
	checkAdjacencies(map, city, adjacents);

	city = "victorville";
	adjacents = {"bend", "laguna", "cypress"};
	checkAdjacencies(map, city, adjacents);

	city = "laguna";
	adjacents = {"victorville"};
	checkAdjacencies(map, city, adjacents);

	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #3: Simple Shortest Path" << endl;
	vector<string> path = {"bend","rialto"};
	checkPath(map, path, "bend", "rialto");

	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #4: Less Simple Shortest Path" << endl;

	path = {"rialto","anaheim", "fairbanks"};
	checkPath(map, path, "rialto", "fairbanks");

	cerr << "\n\t========================PASS========================\n" << endl;
	
	cerr << "\n\tTEST #5: Shortest Path between a single point" << endl;
	path = {"fairbanks"};
	checkPath(map, path, "fairbanks", "fairbanks");

	cerr << "\n\t========================PASS========================\n" << endl;


	cerr << "\n\tTEST #6: Shortest Path on Map 2" << endl;
	Map map2("townlist2.txt");
	path = {"doomstadt", "attilan", "smallville", "gotham"};
	checkPath(map2, path, "doomstadt", "gotham");

	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #7: Shortest Path on Map 2" << endl;
	path = {"gotham", "smallville", "metropolis", "kun-lun", "genosha", "asgard", "madripoor"};
	checkPath(map2, path, "gotham", "madripoor");

	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #8: No Path" << endl;
	path.clear();
	checkPath(map2, path, "attilan", "nyc");

	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #9: Distance from a single city (should be 0)" << endl;
	City * start = map2.findByName("nyc");
	City * stop = map2.findByName("nyc");
	assert(map.pathDistance(start, stop) == 0);

	cerr << "\n\t========================PASS========================\n" << endl;
	cerr << "\n\tTEST #10: Distance between two cities" << endl;
	start = map2.findByName("attilan");
	stop = map2.findByName("madripoor");
	assert(map2.pathDistance(start, stop) == 8);
	
	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #11: Distance with two equal paths" << endl;
	start = map2.findByName("metropolis");
	stop = map2.findByName("doomstadt");
	assert(map2.pathDistance(start, stop) == 8);
	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\t========================PASS========================\n" << endl;
	cerr << "\n\t=                       MYTEST                     =\n" << endl;
	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #12: Read my file which is a list of Cities and their locations" << endl;	
	Map map1("Mytest.txt");

	assert(map1.findByName("EPHESUS") != NULL);
	assert(map1.findByName("DAHAB") != NULL);
	assert(map1.findByName("JERUSALEM") != NULL);
	assert(map1.findByName("MAAN") != NULL);
	assert(map1.findByName("FEZ") != NULL);
	assert(map1.findByName("HAIFA") != NULL);
	assert(map1.findByName("DUBAI") != NULL);
	assert(map1.findByName("ISTANBUL") != NULL);
	assert(map1.findByName("SYDNEY") != NULL);
	assert(map1.findByName("Jeddah") != NULL);
	assert(map1.findByName("Riyadh") != NULL);
	assert(map1.findByName("ADO") != NULL);
	assert(map1.findByName("Abha") == NULL);

	assert(map1.findByName("MAAN")->getXCoor() == 8 && map1.findByName("MAAN")->getYCoor() == 9);
	assert(map1.findByName("SYDNEY")->getXCoor() == 25 && map1.findByName("SYDNEY")->getYCoor() == 25);
	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #13: Test myAdjacencies" << endl;	
	string mycity = "MAAN";
	vector<string> myadjacents = {"JERUSALEM", "FEZ"};
	checkAdjacencies(map1, mycity, myadjacents);

	mycity = "EPHESUS";
	myadjacents = {"DAHAB"};

	checkAdjacencies(map1, mycity, myadjacents);
	

	mycity = "HAIFA";
	myadjacents = {"Jeddah", "ADO","DAHAB"};
	checkAdjacencies(map1, mycity, myadjacents);
	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #14: Find on myPath a short route between cities" << endl;
	vector<string> path1 = {"EPHESUS","DAHAB"};
	checkPath(map1, path1, "EPHESUS", "DAHAB");
	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #15: Also Shortest Path" << endl;
	path1 = {"EPHESUS","DAHAB", "HAIFA"};
	checkPath(map1, path1, "EPHESUS", "HAIFA");
	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #17: A single point between cities" << endl;
	path1 = {"EPHESUS"};
	checkPath(map1, path1, "EPHESUS", "EPHESUS");
	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #18: Shortest Path on Map 3" << endl;
	Map map3("Mytest.txt");

	vector<string> path2 = {"EPHESUS", "DAHAB", "HAIFA", "Jeddah"};
	checkPath(map3, path2, "EPHESUS", "Jeddah");
	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #19: Shortest Path on Map 3" << endl;
	path2 = {"EPHESUS", "DAHAB", "HAIFA", "ADO","DUBAI", "Riyadh"};
	checkPath(map3, path2, "EPHESUS", "Riyadh");
	cerr << "\n\t========================PASS========================\n" << endl;

	return 0;
	
}