#ifndef LOCAL_SEARCH_H
#define LOCAL_SEARCH_H

#include "../map/Map.h"
#include "../map/Route.h"

//abstract class, inherited by HC,SA and TS
class LocalSearch
{
public:
	LocalSearch();
	~LocalSearch();

	int iteration;

	void initRoute(Map& map);
	//set a random route
	Route& twoOptSwap(const Route& oldRoute, const Map& map, const int A, const int B);	

private:
	
};//end class LS

#endif
