#ifndef MAP_H
#define MAP_H

#include <string>
#include <climits>	//INT_MAX
#include <cstdlib>

#include "Route.h"


class Map
{
public:
	static const int INF()
		{ return INT_MAX; }
	static const int UNDEFINED()
		{ return -1; }
	int NUM_OF_CITIES;
	Route route;

	Map(const int numOfCities, const std::string file);	//constructor
	~Map();
	
	unsigned int getTotalDistance();
	unsigned int recomputeTotalDistance(Route& targetRoute)const;
//	Route& twoOptSwap(int A, int B);	//return an new route
	unsigned int getDistance(const int cityA, const int cityB)const;
	void updateRoute(const Route &newRoute);
	
private:
	double* posX, *posY;	//posX[city-i] = coord x of city i 	
//	Route route;
	unsigned int** dis ;	//2D array, record the distance between every two city
	std::string fileName;

	unsigned int roundDistance(const int cityA, const int cityB)const;
	bool parse();
};//end class Map 

#endif
