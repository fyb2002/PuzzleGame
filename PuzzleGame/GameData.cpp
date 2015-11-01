#include "GameData.h"
#include <cstring>
#include <iostream>

GameData::GameData(const char* mapData)
	: mStateMap(nullptr)
{
	using namespace std;
	const char* reader = mapData;
	mSize = strlen(mapData);
	cout << "mSize = " << mSize << endl;
	mStateMap = new Object[mSize];

	int x = -1;
	int y = 0;

	while(*reader != '\0')
	{
		Object obj;
		switch (*reader)
		{
			case '#': obj = OBJ_WALL; x++;  break;
			case ' ': obj = OBJ_SPACE; x++; break;
			case 'p': obj = OBJ_PLAYER; x++; break;
			case 'P': obj = OBJ_PLAYERONGOAL; x++; break;
			case '.': obj = OBJ_GOAL; x++; break;
			case 'o': obj = OBJ_BLOCK; x++; break;
			case 'O': obj = OBJ_BLAOCKONGOAL; x++; break;

			case '\n': 
				obj = OBJ_NEXTFLOOR;
				x++; 
				y += x;
				x = 0;
				break;

			default: obj = OBJ_UNKNOWN;  break; // for anything else...
			
		}
		if(obj != OBJ_UNKNOWN)
			mStateMap[y + x] = obj;

		++reader;
	} //while(*reader != '\0')
}

GameData::~GameData()
{
	if(mStateMap != nullptr)
		delete mStateMap;
}

void GameData::draw()
{
	using namespace std;
	
	for (int i = 0; i < mSize; i++)
	{
		switch (mStateMap[i]) {
		case OBJ_WALL:cout << '#'; break;
		case OBJ_SPACE: cout << ' '; break;
		case OBJ_PLAYER: cout << 'p'; break;
		case OBJ_PLAYERONGOAL: cout << 'P'; break;
		case OBJ_GOAL : cout << '.'; break;
		case OBJ_BLOCK : cout << 'o'; break;
		case OBJ_BLAOCKONGOAL: cout << 'O';  break;
		case OBJ_NEXTFLOOR: cout << '\n'; break;
		}
	}
	cout << endl;
}