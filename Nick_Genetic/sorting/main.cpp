//example program that demonstrates sorting an stl::vector

#include <cmath>
#include <iostream>
#include <conio.h>
#include <vector>
#include <algorithm> //need this to use std::sort
#include <stdlib.h> //used for rand()
#include <random>
#include <time.h>
#include "Map.h"
#include "placement.h"

using namespace std;

#define POPSIZE 10
#define MUTATIONRATE 100

class WeightedPathNode
{
public:
	float x,y; //coordinates
	float fCost;
};

//function to sort pathnodes by fCost{    return (A.fCost < B.fCost);}
bool sortByF(PathNode *A, PathNode *B) 
{
   if( A->fCost < B->fCost ) return 1;

   return 0;
}

bool sortByH(placement *A, placement *B) 
{
   if( A->howclose < B->howclose ) return 1;

   return 0;
}

void PrintList(std::vector<WeightedPathNode *> *theList)
{
	for(int i = 0; i < theList->size(); ++i)
	{
		cout << i+1 << " - " << "X:" << (*theList)[i]->x << ", Y:" << (*theList)[i]->y << ", fCost:" << (*theList)[i]->fCost << endl;
	}
}

void main()
{
	int iterationcount = 0;
	srand (time(NULL)); //seed the random number generator

	std::vector<placement *> TheList;

	for(int i = 0; i < POPSIZE; i++)
	{
		TheList.push_back(new placement());

		for(int k = 0; k < 8; k++)
		{
			TheList.at(i)->positionlist.push_back(new position());
			TheList.at(i)->positionlist.at(k)->x = rand()%8;
			TheList.at(i)->positionlist.at(k)->y = rand()%8;
		}

		TheList.at(i)->howclose = TheList.at(i)->check();
	}

	std::sort(TheList.begin(), TheList.end(), sortByH);

	do
	{
		for(int i = 0; i < POPSIZE; i += 2)
		{
			int temp = rand()%6;
			temp += 1;
			int randmute = rand()%MUTATIONRATE;
			TheList.push_back(new placement());

			for(int k = 0; k < temp; k++)
			{
				TheList.at(TheList.size() - 1)->positionlist.push_back(new position());

				TheList.at(TheList.size() - 1)->positionlist.at(TheList.at(TheList.size() - 1)->positionlist.size() - 1)->x = TheList.at(i)->positionlist.at(k)->x;
				TheList.at(TheList.size() - 1)->positionlist.at(TheList.at(TheList.size() - 1)->positionlist.size() - 1)->y = TheList.at(i)->positionlist.at(k)->y;
			}

			for(int k = temp; k < 8; k++)
			{
				TheList.at(TheList.size() - 1)->positionlist.push_back(new position());

				TheList.at(TheList.size() - 1)->positionlist.at(TheList.at(TheList.size() - 1)->positionlist.size() - 1)->x = TheList.at(i+1)->positionlist.at(k)->x;
				TheList.at(TheList.size() - 1)->positionlist.at(TheList.at(TheList.size() - 1)->positionlist.size() - 1)->y = TheList.at(i+1)->positionlist.at(k)->y;
			}
			TheList.at(TheList.size()-1)->howclose = TheList.at(TheList.size()-1)->check();

			if(randmute == 1)
			{
				int postemp = rand()%8;
				placement *t = new placement();
				for(int i = 0; i < 8; i++)
				{
					t->positionlist.push_back(new position);
					t->positionlist.at(i)->x = TheList.at(TheList.size()-1)->positionlist.at(i)->x;
					t->positionlist.at(i)->y = TheList.at(TheList.size()-1)->positionlist.at(i)->y;
				}
				TheList.push_back(t);
				TheList.at(TheList.size()-1)->positionlist.at(postemp)->x = rand()%8;
				TheList.at(TheList.size()-1)->positionlist.at(postemp)->y = rand()%8;	
				TheList.at(TheList.size()-1)->howclose = TheList.at(TheList.size()-1)->check();
			}

			randmute = rand()%MUTATIONRATE;

			TheList.push_back(new placement());

			for(int k = 0; k < temp; k++)
			{
				TheList.at(TheList.size() - 1)->positionlist.push_back(new position());

				TheList.at(TheList.size() - 1)->positionlist.at(TheList.at(TheList.size() - 1)->positionlist.size() - 1)->x = TheList.at(i+1)->positionlist.at(k)->x;
				TheList.at(TheList.size() - 1)->positionlist.at(TheList.at(TheList.size() - 1)->positionlist.size() - 1)->y = TheList.at(i+1)->positionlist.at(k)->y;
			}

			for(int k = temp; k < 8; k++)
			{
				TheList.at(TheList.size() - 1)->positionlist.push_back(new position());

				TheList.at(TheList.size() - 1)->positionlist.at(TheList.at(TheList.size() - 1)->positionlist.size() - 1)->x = TheList.at(i)->positionlist.at(k)->x;
				TheList.at(TheList.size() - 1)->positionlist.at(TheList.at(TheList.size() - 1)->positionlist.size() - 1)->y = TheList.at(i)->positionlist.at(k)->y;
			}
			TheList.at(TheList.size()-1)->howclose = TheList.at(TheList.size()-1)->check();

			if(randmute == 1)
			{
				int postemp = rand()%8;
				placement *t = new placement();
				for(int i = 0; i < 8; i++)
				{
					t->positionlist.push_back(new position);
					t->positionlist.at(i)->x = TheList.at(TheList.size()-1)->positionlist.at(i)->x;
					t->positionlist.at(i)->y = TheList.at(TheList.size()-1)->positionlist.at(i)->y;
				}
				TheList.push_back(t);
				TheList.at(TheList.size()-1)->positionlist.at(postemp)->x = rand()%8;
				TheList.at(TheList.size()-1)->positionlist.at(postemp)->y = rand()%8;	
				TheList.at(TheList.size()-1)->howclose = TheList.at(TheList.size()-1)->check();
			}


		}

		std::sort(TheList.begin(), TheList.end(), sortByH);

		//delete any copies
		for(int i = TheList.size()-1; i > 0; --i)
		{
			for(int k = TheList.size()-1;k >=0; --k)
			{
				if(i!=k)
				{
					bool same = true;
					for(int n = 0; n < 8; ++n)
					{
						if(TheList.at(i)->positionlist.at(n)->x != TheList.at(k)->positionlist.at(n)->x ||
							TheList.at(i)->positionlist.at(n)->y != TheList.at(k)->positionlist.at(n)->y)
						{
							same = false;
							break;
						}
					}

					if(same)
					{
						int postemp = rand()%8;
				
						TheList.at(i)->positionlist.at(postemp)->x = rand()%8;
						TheList.at(i)->positionlist.at(postemp)->y = rand()%8;	
						TheList.at(i)->howclose = TheList.at(i)->check();
					}
				}
			}
		}


		for(int i = TheList.size()-1; i >= POPSIZE; --i)
		{
			delete TheList[i];
			TheList.erase(TheList.begin()+i);
		}
		
		iterationcount++;
	}while(TheList.at(0)->howclose != 0);

	cout << "After " << iterationcount << " breeding cycles, an answer to the 8 queens problem is:" << endl << endl;

	for(int i = 0; i < TheList.at(0)->positionlist.size(); i++)
	{
		cout << TheList.at(0)->positionlist.at(i)->x << " , " << TheList.at(0)->positionlist.at(i)->y << endl;
	}
	

	/*******
	//make a few nodes and add them to the list
	for(int i = 0; i < 5; ++i)
	{
		WeightedPathNode *newNode = new WeightedPathNode();
		newNode->x = rand() % 100;
		newNode->y = rand() % 100;
		//make up a randon fcost
		newNode->fCost = newNode->x + newNode->y;

		//add it to the open list
		OList.push_back(newNode);
	}

	//print the unsorted list
	cout << "Unsorted, the list looks like:" << endl;
	PrintList(&OList);

	//sort open list, using the sortByF() function
	std::sort(OList.begin(), OList.end(), sortByF); 

	//output the results
	cout << endl << "Sorted by fCost, the list looks like:" << endl;
	PrintList(&OList);
	*******/

	_getch();

	for(int i = TheList.size()-1; i >= 0; i--)
	{
		delete TheList.at(i);
	}
	TheList.clear();
	
}