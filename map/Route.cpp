#include "Route.h"
#include "Map.h"

Route::Route(const int numOfCities)
{
	this->path = (int*)malloc(sizeof(int)*numOfCities);
	this->totalDistance = Map::INF();
}

Route::~Route()
{
	free(this->path);
}

/*Route::Route(const Route &oldRoute)
//copy constructor
{
	this.path = copy()

}*/
