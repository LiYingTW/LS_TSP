#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <fstream>	//file I/O
//#include <cstdio>
//#include <ctime>

#include <stdio.h>	//printf
//#include <time.h>	//timer


#include "../map/Map.h"

#include "LocalSearch.h"
//#include "HillClimbing.h"
//#include "SimulatedAnnealing.h"
//#include "TabuSearch.h"

//class Console;	//forward declaration

class Controller
{
public:
	const static int HC = 0; //Hill Climbing
	const static int SA = 1; //Simulated Annealing
	const static int TS = 2; //Tabu Search
	const static int EIL = 0;
	const static int LIN = 1;
	const static int PCB = 2;

	const static int ALG_NUM = 3;
	const static int FILE_NUM = 3;

	// some const args (read from main and assigned in constructor)
	//const int algorithm;	//the value is HC, SA or TS
	//const int algArgs[3];
	
	//variable
	double timeUsed[3][3];	//time[ALG_NUM][FILE_NUM], in sec

	std::ofstream tspFile[3];	//tspFile[FILE_NUM]

	Map eilMap, linMap, pcbMap;	//map[FILE_NUM]
	
	//functions
	Controller( const int alg);
	~Controller();
	//Controller(int argc, char *argv[]);	//constructor, init the const vars and create the map
	//call: Slove() -> Analysis() -> Console() / write result into a file

private:	
	void slove(const int fileIndex,const int algIndex);	//call the alg, record the time used.

	void result(const int fileIndex, const int algIndex, const int iteration);
	//void Analysis();




};//end class Controller


#endif
