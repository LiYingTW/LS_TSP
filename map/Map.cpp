#include <iostream>	//cout
#include <sstream>	//string stream
#include <fstream>	//file
#include <cmath>	//for round(), sqrt(), pow()

#include <stdlib.h>	// srand, rand 
#include <time.h>	// time 

#include "Map.h"
//#include "Route.h"

using namespace std;

class Route;
class Node;

Map::Map(const int numOfCities, const string file)
: route(numOfCities),
  fileName(file)
{
	this->NUM_OF_CITIES = numOfCities;
	
	this->posX = (double*) malloc( sizeof(double) * this->NUM_OF_CITIES );
	this->posY = (double*) malloc( sizeof(double) * this->NUM_OF_CITIES );

	this->dis = (unsigned int**) malloc( sizeof(unsigned int*)*this->NUM_OF_CITIES );
	for(int i = 0; i < this->NUM_OF_CITIES; i++)
		this->dis[i] = (unsigned int*)malloc(sizeof(unsigned int)*this->NUM_OF_CITIES);

	for(int i = 0; i < this->NUM_OF_CITIES; i++)
	{
		for(int j = 0; j < this->NUM_OF_CITIES; j++)
		{
			if(i == j)
				this->dis[i][j] = 0;
			else
				this->dis[i][j] = UNDEFINED();
		}
	}//end init dis[][]

	parse();
}//end constructor

Map::~Map()
{
	free(posX);
	free(posY);
	for(int i = 0; i < this->NUM_OF_CITIES; i++)
		free(dis[i]);
	free(dis);
}

unsigned int Map::getTotalDistance()
{
	if(this->route.totalDistance == INF())
	{
		this->route.totalDistance = 0;
		for(int i = 0; i < (this->NUM_OF_CITIES - 1); i++)
			this->route.totalDistance += getDistance( i, i+1 );
			//this->route.totalDistance += getDistance(this->route.path[i], this->route.path[i+1]);
		this->route.totalDistance += getDistance( 0, (this->NUM_OF_CITIES - 1));	//return to the origin city
	}
	return this->route.totalDistance;
}//end getTotalDistance

Route& Map::twoOptSwap(int A, int B)
{
	Route* newRoute = new Route(this->NUM_OF_CITIES);
	int cityA, cityB;
	int prevCity, nextCity;
	
	if(A == -1 && B == -1)
	{
		//get two random city
		srand (time(NULL));
		cityA = rand() % this->NUM_OF_CITIES;
		cityB = rand() % this->NUM_OF_CITIES;
		while(cityA == cityB)
			cityB = rand() % this->NUM_OF_CITIES;
	}
	else if(A == B)
	{
		cout << "[ERROR 2-opt] the 2 city cannot be the same." << endl;
		return *newRoute;
	}
	else if(A < 0 || B < 0 || A >= this->NUM_OF_CITIES || B >= this->NUM_OF_CITIES)
	{
		cout << "[ERROR 2-opt] incorrect cities:" << cityA << " ," << cityB << endl;
		return *newRoute;
	}
	else
	{
		cityA = A;
		cityB = B;
	}

	if(cityB < cityA)
	{
		int tmp = cityA;
		cityA = cityB;
		cityB = tmp;
	}

	if(cityA != 0)
		prevCity = cityA - 1;
	else
		prevCity = this->NUM_OF_CITIES - 1;

	if(cityB != (this->NUM_OF_CITIES - 1))
		nextCity = cityB + 1;
	else
		nextCity = 0;

	//get new route
	for(int i = 0; i < cityA; i++)
		newRoute->path[i] = this->route.path[i];
	
	for(int i = 0; i <= (cityB - cityA); i++)
		newRoute->path[i + cityA] = this->route.path[cityB - i];

	for(int i = (cityB + 1); i < this->NUM_OF_CITIES; i++)
		newRoute->path[i] = this->route.path[i];
	
	//count the new distance
	newRoute->totalDistance = this->route.totalDistance - getDistance(prevCity, cityA) - getDistance(cityB, nextCity) + getDistance(prevCity, cityB) + getDistance(cityA, nextCity);
		
	return *newRoute;
}//end twoOptSwap

unsigned int Map::getDistance(const int cityA, const int cityB)
{
	if(cityA == cityB)
		return 0;
	
	if(this->dis[cityA][cityB] == UNDEFINED())
	{
		this->dis[cityA][cityB] = roundDistance(cityA, cityB);
		this->dis[cityB][cityA] = this->dis[cityA][cityB];
	}

	return this->dis[cityA][cityB];
}//end getDistance

void Map::updateRoute(const Route &newRoute)
{
	this->route.totalDistance = newRoute.totalDistance;

	for(int i = 0; i < this->NUM_OF_CITIES; i++)
		this->route.path[i] = newRoute.path[i];
	
	return;
}//end updateRoute

unsigned int Map::roundDistance(const int cityA, const int cityB)
{
	return (unsigned int) round( sqrt( pow( posX[cityA] - posX[cityB] , 2) + pow( posY[cityA] - posY[cityB] , 2) ) );
}

bool Map::parse()
{
	if(this->fileName == "test")
	{
		for(int i = 0; i < this->NUM_OF_CITIES; i++)
			this->route.path[i] = i;
		
		cout << "Before 2-opt:" << endl;
		for(int i = 0; i < this->NUM_OF_CITIES ; i++)
			cout << this->route.path[i] << ", ";
		cout << endl;
		
		cout << "/nAfter 2-opt:" << endl;
		Route newRoute = twoOptSwap(-1, -1);
		for(int i = 0; i < this->NUM_OF_CITIES; i++)
			cout << newRoute.path[i] << ", ";
		cout << endl;
		return true;
	}//end test
	
	ifstream tspFile;
	string line;

	tspFile.open( this->fileName.c_str(), ios::in );
	if( tspFile.is_open() == false )
	{
		cout << "Cannot open the file:" << this->fileName << endl;
		return false;
	}
	
	while( getline(tspFile,line) && !tspFile.fail() )
	{
		stringstream ss(line);
		string entryKey;

		ss >> entryKey;
	
		if(entryKey.empty())
			continue;
		if(entryKey == "EOF")
			break;

		if(entryKey[entryKey.length() - 1] == ':' )
		{
			entryKey = entryKey.substr(0, entryKey.length() - 1);
		}
		else
		{
			string colon;
			ss >> colon;

			if(!ss.fail() && colon != ":")
			{
				cout << "Reading file error: colon" << endl;
				return false;
			}
		}//colon

		if(entryKey == "DIMENSION")
			ss >> this->NUM_OF_CITIES;
		else if (entryKey == "NODE_COORD_SECTION")
		{
			for( int i = 0; i < this-> NUM_OF_CITIES; i++)
			{
				int index;
				double x,y;
				
				tspFile >> index >> x >> y;

				this->posX[ index ] = x;
				this->posY[ index ] = y;

//[DEBUG]output origin map				cout << index <<": "<< x << ", " << y <<endl;
			}//end for loop
		}//coord
	}//end while (getline)

	tspFile.close();
	return true;	
}//end parse
