#include <iostream>

#include "HillClimbing.h"
#include "../map/Route.h"
#include "../map/Map.h"

using namespace std;

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
//	Route* neighbor = new Route(map.NUM_OF_CITIES);

	initRoute(map);
	cout << "init dis: " << map.getTotalDistance() << endl;

	current->routeCopy(map.route, map.NUM_OF_CITIES);

	while(true)
	{
//		cout << "iteration " << iteration <<endl;
		iteration ++;

		for(int i = 0; i < (map.NUM_OF_CITIES - 1); i++)
		{
			for(int j = (i + 1); j < map.NUM_OF_CITIES; j++)
			{
				Route neighbor = this->twoOptSwap(*current, map, i, j);
				if(neighbor.totalDistance < bestNeighbor->totalDistance)
					bestNeighbor->routeCopy(neighbor, map.NUM_OF_CITIES);
//				delete neighbor;
			}
		}//end for
		
//		cout << "(Best, current) = (" <<bestNeighbor->totalDistance <<" ," <<current->totalDistance << ")" <<endl;
		if(bestNeighbor->totalDistance >= current->totalDistance)
		{
			map.updateRoute(*current);
			break;
		}//return
		current->routeCopy(*bestNeighbor, map.NUM_OF_CITIES);
	}//end while

	delete current;
	delete bestNeighbor;
	return;
}//end HC sloving

