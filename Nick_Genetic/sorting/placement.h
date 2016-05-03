#include <fstream>
#include <iostream>
#include <conio.h>
#include <string>
#include <vector>

#ifndef PLACEMENT_H
#define PLACEMENT_H

using namespace std;

class position
{
public:
	int x;
	int y;
};

class placement
{
public:
	std::vector<position*> positionlist;
	int howclose;
	int check();
	~placement();
};

#endif