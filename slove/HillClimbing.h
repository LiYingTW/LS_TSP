#ifndef HILL_CLIMBING_H
#define HILL_CLIMBING_H

#include "LocalSearch.h"

class HillClimbing: public LocalSearch
{
public:
	HillClimbing();
	~HillClimbing();

	void hillClimbingSlove(Map& map);	
private:

};//end class HC

#endif

