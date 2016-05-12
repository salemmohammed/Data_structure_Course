
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdint>
#include <fstream>
#include <string>
#include <cassert>

#include "Map.h"
#include "City.h"

using namespace std;


Map::Map(string filename){

 	std::ifstream infile;

 	infile.open(filename.c_str());  
    // reading from file
    /*

    Get C string equivalent
    Returns a pointer to an array that contains a null-terminated sequence of characters 
    (i.e., a C-string) representing the current value of the string object.
    */

	while (infile)
	{
		std::string name;
		int x;
		int y;
		std::string dummy;


        infile >> name;
		
		if (name.size() == 0)
		//encountered an empty line, not allowed in middle of input, break and done.
		  break;

		infile >> x;   // cin >> input
		infile >> y;   // cin >> input

    	///get the extraneous newline character
    	std::getline(infile, dummy);

        this->vmap[name] = new City(name,x,y);

        // std::cerr << "name: " << name << ", x: " << x << ", y: " << y << std::endl;
        // std::cerr << "dummy: " << dummy << std::endl;

    }

    infile.close();


    for (auto left : vmap)
    {
        for (auto right : vmap)
        {
            City* left_city = left.second;
            City* right_city = right.second;

            int xdelta = right_city->getXCoor() - left_city->getXCoor();
            int ydelta = right_city->getYCoor() - left_city->getYCoor();
            if (xdelta == 0 && ydelta == 0)
                continue;
            if (xdelta != 0 && ydelta != 0)
                continue;

            left_city->addAdjacentCity(right_city);
            right_city->addAdjacentCity(left_city);
        }
    }
}

City* Map::findByName(string cityName){

    std::map<string,City*>::iterator it = vmap.find(cityName);

    if (it == vmap.end())
        return NULL;

    City* result = (it->second);
    return result;
}



vector<City*> Map::shortestPath(City* start, City* dest)
{



    ///"create vertex set Q" == a set of city names
    std::set<std::string> Q;

    std::map<std::string, uint32_t> dist;
    ///for each city, this map to the "Previous node in optimal path from source"
    std::map<std::string, std::string> prev;

    std::uint32_t INFDIST = -1;
    std::string UNDEFINED = "";

    ///"for each vertex v in Graph:"
    for(auto namecitypair : vmap)
    {
        City* v = namecitypair.second;
        //std::cout << "v->getName(): " << v->getName() << std::endl;

        ///"dist[v] ← INFINITY     // Unknown distance from source to v"
        dist[v->getName()] = INFDIST;

        ///"prev[v] ← UNDEFINED    // Previous node in optimal path from source"
        prev[v->getName()] = UNDEFINED;

        ///"add v to Q             // All nodes initially in Q (unvisited nodes)""
        Q.insert(v->getName());
    }



    ///"dist[source] ← 0"

    dist[start->getName()] = 0;

    ///"while Q is not empty:"
    while (Q.size() > 0)
    {
        auto find_min_q = [&Q, &dist, UNDEFINED, INFDIST](){
            uint32_t best_dist = INFDIST;
            std::string best_v = UNDEFINED;
            for (auto v : Q)
            {
                if (dist[v] <= best_dist)
                {
                    best_dist = dist[v];
                    best_v = v;
                }
            }
            return best_v;
        };

        ///"u ← vertex in Q with min dist[u]    // Source node will be selected first"
        std::string u = find_min_q();
        ///"remove u from Q"
        Q.erase(u);

        //std::cout << "u: " << u << std::endl;
        assert(vmap.count(u));

        ///"for each neighbor v of u:"
        City* ucity = vmap[u];

        assert(ucity);
        for (auto vcity : ucity->getAdjacent())
        {
            //std::cout << "vcity: " << vcity << std::endl;
            assert(vcity);
            std::string v = vcity->getName();

            ///"alt ← dist[u] + length(u, v)"
            uint32_t alt = dist[u] + getAdjacentDistance(ucity,vcity);

            ///"if alt < dist[v]:"
            if (alt < dist[v])
            {
                ///"dist[v] ← alt"
                dist[v] = alt;
                ///"prev[v] ← u"
                prev[v] = u;
            }
        }
    }


    ///this is the path from start to dest, it will be calculated in reverse.
    ///"S ← empty sequence"
    std::vector<City*> S;

    ///"u ← target"
    std::string u = dest->getName();

    if (prev[u] == UNDEFINED && u != start->getName())
    {
       // std::cerr << "target " << dest->getName() << " is not connected to the source " << start->getName() << std::endl;
        return S;
    }

    ///"while prev[u] is defined:  // Construct the shortest path with a stack S"
    while (prev[u] != UNDEFINED)
    {
        ///"insert u at the beginning of S         // Push the vertex onto the stack"
        ///we will put it at the end of S, and then reverse S at the end
        S.push_back(vmap[u]);
        u = prev[u];
    }

    ///"insert u at the beginning of S             // Push the source onto the stack"
    ///we will put it at the end of S, and then reverse S at the end
    S.push_back(vmap[u]);

    std::reverse(S.begin(), S.end());

    return S;




}


unsigned int Map::pathDistance(City * start, City * dest){

    auto S = shortestPath(start, dest);

    unsigned int result = 0;

    for (std::size_t i = 1; i < S.size(); ++i)
    {
        /// ----> ucity ------> vcity ----->

        City* ucity = S[i - 1];
        City* vcity = S[i];

        result += getAdjacentDistance(ucity,vcity);
    }
    return result;
    if (S.size() == 0 || S.size() == 1)
        return -1;

}

