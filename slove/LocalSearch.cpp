#include <vector>
#include <algorithm>
#include <iostream>
//#include <random>

#include <stdlib.h>	//srand, rand
#include <time.h>	//time

#include "LocalSearch.h"
#include "../map/Map.h"
#include "../map/Route.h"

using namespace std;


void LocalSearch::initRoute(Map& map)
{
	vector<int> sequence;

	srand( time(NULL) );
	for(int i = 0; i < map.NUM_OF_CITIES; i++)
		sequence.push_back(i);
	
	random_shuffle(sequence.begin(), sequence.end());
//	auto engine = std::default_random_engine{};
//	std::shuffle(std::begin(sequence), std::end(sequence), engine);
//	mt19937 g(static_cast<uint32_t>(time(0)));
//  	shuffle(sequence.begin(), sequence.end(), g);

	for(int i = 0; i < map.NUM_OF_CITIES; i++)
		map.route.path[i] = sequence[i];
	
//	delete sequence;
}

LocalSearch::LocalSearch()
{
	iteration = 0;
} // end LS default constructor

LocalSearch::~LocalSearch()
{
}// end LS default deconstructor


Route& LocalSearch::twoOptSwap(const Route& oldRoute, const Map& map,const int A, const int B)
{
	Route* newRoute = new Route(map.NUM_OF_CITIES);
	int cityA, cityB;
	int prevCity, nextCity;
	
	if(A == -1 && B == -1 )
	{
		//get two random city
		srand( time(NULL) );
		cityA = rand() % map.NUM_OF_CITIES;
		cityB = rand() % map.NUM_OF_CITIES;
		while(cityA == cityB)
			cityB = rand() % map.NUM_OF_CITIES;
	}//end generate 2 random cities
	else if(A == B)
	{
		cerr << "[ERROR 2-opt] the 2 cities cannot be the same." << endl;
		return *newRoute;
	}else if (A < 0 || B < 0 || A >= map.NUM_OF_CITIES || B >= map.NUM_OF_CITIES)
	{
		cerr << "[ERROR]Incorrect cities: " << cityA << " ," << cityB << endl;
		return *newRoute;
	}else
	{
		cityA = A;
		cityB = B;
	}

	//make cityA less than cityB
	if(cityB < cityA)
	{
		int tmp = cityA;
		cityA = cityB;
		cityB = tmp;
	}

	//set prev and next
	if( cityA != 0 )
		prevCity = cityA - 1;
	else
		prevCity = map.NUM_OF_CITIES - 1;
	
	if( cityB != ( map.NUM_OF_CITIES - 1 ) )
		nextCity = cityB + 1;
	else
		nextCity = 0;

	//get new route
	for( int i = 0; i < cityA; i++ )
		newRoute->path[i] = oldRoute.path[i];
	
	for( int i = 0; i <= (cityB - cityA); i++ )
		newRoute->path[i + cityA] = oldRoute.path[cityB - i];
	
	for( int i = (cityB + 1); i < map.NUM_OF_CITIES; i++ )
		newRoute->path[i] = oldRoute.path[i];

	//count the new distance
	map.recomputeTotalDistance(*newRoute);
//	newRoute->totalDistance = oldRoute.totalDistance - map.getDistance(prevCity, cityA) - map.getDistance(cityB, nextCity) + map.getDistance(prevCity, cityB) + map.getDistance(cityA, nextCity);

	return *newRoute;
}//end 2-opt*/
