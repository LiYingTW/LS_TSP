#include "HillClimbing.h"
#include "../map/Route.h"
#include "../map/Map.h"

HillClimbing::HillClimbing()
{
	iteration = 0;
}

HillClimbing::~HillClimbing()
{
}

void HillClimbing::hillClimbingSlove(Map& map)
{
	Route* current = new Route(map.NUM_OF_CITIES);
	Route* bestNeighbor = new Route(map.NUM_OF_CITIES);

	initRoute(map);
	current->routeCopy(map.route, map.NUM_OF_CITIES);

	while(true)
	{
		iteration ++;

		for(int i = 0; i < (map.NUM_OF_CITIES - 1); i++)
		{
			for(int j = (i + 1); j < map.NUM_OF_CITIES; j++)
			{
				Route neighbor = this->twoOptSwap(*current, map, i, j);
				if(neighbor.totalDistance < bestNeighbor->totalDistance)
					bestNeighbor->routeCopy(neighbor, map.NUM_OF_CITIES);
			}
		}//end for
		
		if(bestNeighbor->totalDistance >= current->totalDistance)
		{
			map.updateRoute(*current);
			break;
		}//return
		
		current->routeCopy(*bestNeighbor, map.NUM_OF_CITIES);
	}//end while

	return;
}//end HC sloving

