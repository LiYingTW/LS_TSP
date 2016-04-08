#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <fstream>	//file I/O

#include <stdio.h>	//printf
#include <time.h>	//timer


#include "Map.h"

#include "LocalSearch.h"
#include "HillClimbing.h"
#include "SimulatedAnnealing.h"
#include "TabuSearch.h"

//class Console;	//forward declaration

class Controller
{
public:
	const static int HC = 0; //Hill Climbing
	const static int SA = 1; //Simulated Annealing
	const static int TS = 2; //Tabu Search

	// some const args (read from main and assigned in constructor)
	const int algorithm;	//the value is HC, SA or TS
	const int algArgs[3];
	
	//variables
	time_t timer[3];

	ofstream tspFile[2];
	
	//functions

	Controller(int argc, char *argv[]);	//constructor, init the const vars and create the map
	//call: Slove() -> Analysis() -> Console() / write result into a file

private:	
	void Slove();	//call the alg, record the time used.

	void Analysis();




}//end class Controller


#endif
