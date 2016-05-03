#include "placement.h"

using namespace std;

placement::~placement()
{
	for(int i = positionlist.size()-1; i >= 0; --i)
	{
		delete positionlist[i];
	}
	positionlist.clear();
}

int placement::check()
{
	int count = 0;
	for(int i = 0; i < positionlist.size(); i++)
	{
		for(int k = 1; k < positionlist.size(); k++)
		{
			if(i != k)
			{
				if(positionlist.at(i)->x == positionlist.at(k)->x)
				{
					count++;
				}
				else if(positionlist.at(i)->y == positionlist.at(k)->y)
				{
					count++;
				}
				else
				{
					//int tempx = 7-positionlist.at(i)->x;
					//int tempy = 7-positionlist.at(i)->y;
					//bool found = false;

					//check up right and down right at same time
					int yinc = 1;
					for(int x = positionlist.at(i)->x + 1; x < 8; ++x)
					{
						if(positionlist.at(k)->x == x) 
						{
							if(positionlist.at(k)->y == positionlist.at(i)->y + yinc ||
								positionlist.at(k)->y == positionlist.at(i)->y - yinc)
							{
								count++;
								break;
							}
						}
						yinc++;
					}

					//up and down left
					yinc = 1;
					for(int x = positionlist.at(i)->x - 1; x >= 0; --x)
					{
						if(positionlist.at(k)->x == x) 
						{
							if(positionlist.at(k)->y == positionlist.at(i)->y + yinc ||
								positionlist.at(k)->y == positionlist.at(i)->y - yinc)
							{
								count++;
								break;
							}
						}
						yinc++;
					}

					/*for(int A = 1; A <= tempx; A++)
					{
						if(found == true)
						{
							break;
						}
						else if((positionlist.at(k)->x == positionlist.at(i)->x + A) && (positionlist.at(k)->y == positionlist.at(i)->y + A))
						{
							count++;
							found = true;
							break;
						}
						else if((positionlist.at(k)->x == positionlist.at(i)->x + A) && (positionlist.at(k)->y == positionlist.at(i)->y - A))
						{
							count++;
							found = true;
							break;
						}
					}
					for(int A = 1; A <= positionlist.at(i)->x; A++)
					{
						if(found == true)
						{
							found = false;
							break;
						}
						else if((positionlist.at(k)->x == positionlist.at(i)->x - A) && (positionlist.at(k)->y == positionlist.at(i)->y + A))
						{
							count++;
							found = true;
							break;
						}
						else if((positionlist.at(k)->x == positionlist.at(i)->x - A) && (positionlist.at(k)->y == positionlist.at(i)->y - A))
						{
							count++;
							found = true;
							break;
						}
					}*/
				}
			}
		}
	}

	return count;
}