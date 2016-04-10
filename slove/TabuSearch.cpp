#include <iostream>
#include <utility>      // std::pair
#include <set>
#include <queue>

#include "TabuSearch.h"
#include "../map/Route.h"
#include "../map/Map.h"

using namespace std;

TabuSearch::TabuSearch()
{
}

TabuSearch::~TabuSearch()
{
}

void TabuSearch::tabuSearchSlove(Map& map)
{
	Route* current = new Route(map.NUM_OF_CITIES);
	Route* bestAccept = new Route(map.NUM_OF_CITIES);
	Route* bestTabu = new Route(map.NUM_OF_CITIES);

	queue< pair<int,int> > tabuThrowEdge;	//size 10
	queue< pair<int,int> > tabuNewEdge;	//size 5
	set< pair<int, int> > throwEdge;
	set< pair<int, int> > newEdge;
	
	initRoute(map);
	map.getTotalDistance();

	current->routeCopy(map.route, map.NUM_OF_CITIES);

	while(true)
	{
		iteration ++;
		
		for(int i = 0; i < (map.NUM_OF_CITIES); i++)
		{
			for(int j = (i + 1); j < map.NUM_OF_CITIES; j++)
			{
				bool tabu = false;
				int prevCity = current->getPrevCity(i, map.NUM_OF_CITIES);
				int nextCity = current->getNextCity(j, map.NUM_OF_CITIES);

				if( (throwEdge.find(make_pair(prevCity,i)) != throwEdge.end() ) || (throwEdge.find(make_pair(j,nextCity)) != throwEdge.end() ) || (throwEdge.find(make_pair(prevCity,j)) != throwEdge.end() ) || (throwEdge.find(make_pair(i,nextCity)) != throwEdge.end()) || (newEdge.find(make_pair(prevCity, i)) != newEdge.end()) || (newEdge.find(make_pair(j,nextCity)) != newEdge.end()) || ( newEdge.find(make_pair(prevCity,j)) != newEdge.end() ) || ( newEdge.find(make_pair(i,nextCity)) != newEdge.end() ) ) //in tabu					
					tabu = true;
				
				tabuThrowEdge.push( make_pair(prevCity, i) );
				throwEdge.insert(tabuThrowEdge.back());
				tabuThrowEdge.push( make_pair(j, nextCity) );
				throwEdge.insert(tabuThrowEdge.back());
				tabuNewEdge.push( make_pair(prevCity, j) );
				newEdge.insert(tabuNewEdge.back());
				tabuNewEdge.push( make_pair(i, nextCity) );
				newEdge.insert(tabuNewEdge.back());
	
				while(tabuThrowEdge.size() > 10)
				{
					throwEdge.erase(tabuThrowEdge.front());
					tabuThrowEdge.pop();
				}
				while(tabuNewEdge.size() > 5)
				{
					newEdge.erase(tabuNewEdge.front());
					tabuNewEdge.pop();
				}

				Route neighbor = this->twoOptSwap(*current, map, i, j);

				if(!tabu && (neighbor.totalDistance < bestAccept->totalDistance))//accept
					bestAccept->routeCopy(neighbor, map.NUM_OF_CITIES);

				if(tabu && (neighbor.totalDistance < current->totalDistance))//tabu but accept
					bestTabu->routeCopy(neighbor, map.NUM_OF_CITIES);				
			}//end for j
		}//end for i
		
		if( bestTabu->totalDistance < bestAccept->totalDistance )
		{
			current->routeCopy(*bestTabu, map.NUM_OF_CITIES);
		}
		else
		{
			if(bestAccept->totalDistance >= current->totalDistance)
			{
				map.updateRoute(*current);
				break;
			}
			current->routeCopy(*bestAccept, map.NUM_OF_CITIES);
		}
	}//end while
	
	delete current;
	delete bestTabu;
	delete bestAccept;
}//end TS slove()
