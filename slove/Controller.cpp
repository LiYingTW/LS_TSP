#include <cstring>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <ctime>

#include <stdio.h>
#include <string.h>

#include "Controller.h"
#include "HillClimbing.h"
#include "../map/Map.h"

using namespace std;

Controller::Controller()
//: algorithm(), algArgs{argv[0], argv[1], argv[2]}
: eilMap(51, "./data/eil51.tsp"), linMap(105, "./data/lin105.tsp"), pcbMap(442, "./data/pcb442.tsp")
{
	for(int i = 0; i < FILE_NUM; i ++)
		this->slove(i, HC);
/*
	string fileName[3] = 	{"./data/eil51.tsp",
							"./data/lin105.tsp",
							"./data/pcb442.tsp"};
	int cityNum[3] = { 51, 105, 442}; 

	for( int i = 0; i < FILE_NUM; i++ )
	{
		tspFile[i] = open(fileName[i].c_str(), ios::in);
		tspMap[i] = new Map(cityNum[i], fileName[i]);

		this->slove(i, HC);
	}
*/
}//end constructor

Controller::~Controller()
{
	//delete eilMap;
//	delete linMap;
//	delete pcbMap;
}

void Controller::slove(const int fileIndex, const int algIndex)
{
	clock_t startTime;
	int iter = 0;
	Map* map;

	startTime = clock();
	
	switch(fileIndex)
	{
		case EIL:
			map = &this->eilMap;
			break;
		case LIN:
			map = &this->linMap;
			break;
		case PCB:
			map = &this->pcbMap;
			break;
		default:
			cout << "wrong file argument" << endl;
			break;
	}//end switch file

	switch(algIndex)
	{
		case HC:
		{
			HillClimbing* hc = new HillClimbing();
			hc->hillClimbingSlove(*map);
			iter = hc->iteration;
		}break;
		default:
			cout << "wrong algorithm argument" << endl;
			break;
	}//end switch
	
	timeUsed[algIndex][fileIndex] = ( clock() - startTime ) / (double) CLOCKS_PER_SEC;

	this->console(fileIndex, algIndex, iter);
}//end slove()

void Controller::console(const int fileIndex, const int algIndex, const int iteration)
{
	string alg, fileName;
	Map* map;

	switch(algIndex)
	{
		case HC:
			alg.assign("Hill Climbing");	
			break;
		default:
			cout << "wrong alg argument" <<endl;
		break;
	}//end alg switch

	switch(fileIndex)
	{
		case 0:
			fileName.assign("eil51");
			map = &eilMap;
			break;
		case 1:
			fileName.assign("lin105");
			map = &linMap;
			break;
		case 2:
			fileName.assign("pcb442");
			map = &pcbMap;
			break;
		default:
			cout << "wrong file argument" << endl;
			break;
	}//end file switch

	cout << "-------------------------------------------------------------------" << endl;
	cout << "Problem " << fileName << " using algorithm " << alg << " :" << endl;

	cout << "Distance : " << map->getTotalDistance() << endl;
	cout << "Iteration : " << iteration <<endl;
	cout << "Running time : " << timeUsed[algIndex][fileIndex] << "(sec)" << endl;
	cout << "===================================================================" << endl;

	return;
}//end console
