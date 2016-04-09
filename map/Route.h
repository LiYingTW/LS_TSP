#ifndef ROUTE_H
#define ROUTE_H

class Route
{
public:
	int* path;	//index of cities
	unsigned int totalDistance;

	Route(const int numOfCities);
	~Route();

	void routeCopy(const Route& newRoute, const int numOfCities);
//	Route& twoOptSwap(const int A, const int B, const Map& map);
};//end class Route

#endif
