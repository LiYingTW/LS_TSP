#include <cstring>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <ctime>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>	//srand, rand
#include <time.h>	//time


#include "Controller.h"
#include "HillClimbing.h"
#include "TabuSearch.h"
#include "../map/Map.h"

using namespace std;

Controller::Controller(const int alg)
//: algorithm(), algArgs{argv[0], argv[1], argv[2]}
: eilMap(51, "./data/eil51.tsp"), linMap(105, "./data/lin105.tsp"), pcbMap(442, "./data/pcb442.tsp")
{
	srand( time(NULL) );
	for(int i = 0; i < FILE_NUM; i ++)
		this->slove(i, alg);
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
		case TS:
		{
			TabuSearch* ts = new TabuSearch();
			ts->tabuSearchSlove(*map);
			iter = ts->iteration;
		}break;
		default:
			cout << "wrong algorithm argument" << endl;
			break;
	}//end switch
	
	timeUsed[algIndex][fileIndex] = ( clock() - startTime ) / (double) CLOCKS_PER_SEC;

	this->result(fileIndex, algIndex, iter);
}//end slove()

void Controller::result(const int fileIndex, const int algIndex, const int iteration)
{
	string alg, fileName;
	Map* map;
	fstream resultFile;

	switch(algIndex)
	{
		case HC:
			alg.assign("Hill Climbing");	
			resultFile.open("./result/hc.csv", ios::out | ios::app);
			if(resultFile.fail())
				cerr << "[ERROR]Cannot open hc.csv" << endl;
			break;
		case TS:
			alg.assign("Tabu Search");
			resultFile.open("./result/ts.csv", ios::out | ios::app);
			if(resultFile.fail())
				cerr << "[ERROR]Cannot open ts.csv" << endl;
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

	resultFile << fileName << "," << map->getTotalDistance() << "," << iteration << "," << timeUsed[algIndex][fileIndex] << endl;

	resultFile.close();
	
	return;
}//end console
