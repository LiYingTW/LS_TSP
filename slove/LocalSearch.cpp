#include "LocalSearch.h"
#include "Map.h"
#include "Route.h"



LocalSearch::LocalSearch()
{
} // end LS default constructor

LocalSearch::~LocalSearch()
{
}// end LS default deconstructor

Route& LocalSearch::twoOptSwap(const Route oldRoute, int cityA, int cityB)
{
	Route* newRoute = new Route(map->NUM_OF_CITIES)
	int prevCity, nextCity;
	
	if(cityA == -1 && cityB == -1 )
	{
		//get two random city
		srand( time(NULL) );
		cityA = rand() % map->NUM_OF_CITIES;
		cityB = rand() % map->MUM_OF_CITIES;
		while(cityA == cityB)
			cityB = rand() % map->NUM_OF_CITIES;
	}//end generate 2 random cities
	else if(cityA == cityB)
	{
		cout << "[ERROR 2-opt] the 2 cities cannot be the same." << endl;
		return NULL;
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
		prevCity = map->NUM_OF_CITIES - 1;
	
	if( cityB != ( map->NUM_OF_CITIES - 1 ) )
		nextCity = cityB + 1;
	else
		nextCity = 0;

	//get new route
	for( int i = 0; i < cityA; i++ )
		newRoute->path[i] = oldRoute->path[i];
	
	for( int i = 0; i <= (cityB - cityA); i++ )
		newRoute->path[i + cityA] = oldRoute->path[cityB - i];
	
	for( int i = (cityB + 1); i < map->NUM_OF_CITIES; i++ )
		newRoute->path[i] = oldRoute->path[i];

	//count the new distance
	//newRoute->totalDistance = oldRoute->totalDistance - get....	

	return *newRoute;
}//end 2-opt
