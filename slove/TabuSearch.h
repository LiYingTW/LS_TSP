#ifndef TABUSEARCH_H
#define TABUSEARCH_H

#include "LocalSearch.h"

class TabuSearch: public LocalSearch
{
public:
	TabuSearch();
	~TabuSearch();

	void tabuSearchSlove(Map& map);
private:
};//end class TS

#endif
