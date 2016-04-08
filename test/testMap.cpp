#include <iostream>
#include <string>

#include <stdlib.h>
#include <stdio.h>

#include "../map/Map.h"

using namespace std;
int main()
{
	/***	test 001	***
	int numOfTown = 10;
	string fileName = "test";

	Map* map = new Map(numOfTown, fileName);
	*/

	Map* map = new Map(51, "./data/eil51.tsp");
	return 0;
}
