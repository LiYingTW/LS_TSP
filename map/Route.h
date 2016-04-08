#ifndef ROUTE_H
#define ROUTE_H

class Route
{
public:
	int* path;	//index of cities
	unsigned int totalDistance;

	Route(const int numOfCities);
	~Route();
};//end class Route

#endif
