#include <iostream>	//cout error msg

//#include <stdlib.h> //srand, rand
//#include <time.h>	//time

#include "Route.h"
#include "Map.h"

Route::Route(const int numOfCities)
{
	this->path = (int*)malloc(sizeof(int)*numOfCities);
	this->totalDistance = Map::INF();
}

int Route::getPrevCity(const int city, const int numOfCities)
{
	if(city != 0)
		return (city - 1);
	else
		return (numOfCities - 1);
}

int Route::getNextCity(const int city, const int numOfCities)
{
	if(city != (numOfCities - 1))
		return (city + 1);
	else
		return 0;
}
void Route::routeCopy(const Route& copyRoute, const int numOfCities)
{
	for(int i = 0; i < numOfCities; i++)
		this->path[i] = copyRoute.path[i];
	this->totalDistance = copyRoute.totalDistance;
}//copy constructor

Route::~Route()
{
	free(this->path);
}

/*Route& Route::twoOptSwap(int A, int B, const Map& map)
{
	Route* newRoute = new Route(numOfCities);
	int cityA, cityB;
	int prevCity, nextCity;

	int numOfCities = map.NUM_OF_CITIES;

	if(A == -1 && B == -1)
	{
		//get 2 eandom city
		srand (time(NULL));
		cityA = rand() % numOfCities;
		cityB = rand() % numOfCities;

		while(cityA == cityB)
			cityB = rand() % numOfCities;
	}else if(A == B)
	{
		cout << "[ERROR 2-opt]The 2 cities cannot be the same." << endl;
		return *newRoute;
	}else if(A < 0 || B < 0 || A >= numOfCities || B >= numOfCities)
	{
		cout << "[ERROR 2-opt]Incorrect cities : " << cityA << " ," << cityB << endl;
		return *newRoute;
	}else
	{
		cityA = A;
		cityB = B;
	}

	if(cityB < cityA)
	{
		int tmp = cityA;
		cityA = cityB;
		cityB = tmp;
	}

	if(cityA != 0)
		prevCity = cityA - 1;
	else
		prevCity = numOfCities - 1;
	
	if(cityB != (numOfCities - 1))
		nextCity = cityB + 1;
	else
		nextCity = 0;
	
	//get new route
	for(int i = 0; i < cityA; i++)
		newRoute->path[i] = this->path[i];
	for(int i = 0; i <= (cityB - cityA); i++)
		newRoute->path[i + cityA] = this->path[cityB - i];
	for(int i = (cityB + 1); i < numOfCities; i++)
		newRoute->path[i] = this->path[i];

	//count the new distance
	newRoute->totalDistance = this->totalDistance - map.getDistance(prevCity, cityA) - map.getDistance(cityB, nextCity) + map.getDistance(prevCity, cityB) + map.getDistance(cityA, nextCity);

}//end 2-opt
*/

/*Route::Route(const Route &oldRoute)
//copy constructor
{
	this.path = copy()

}*/
