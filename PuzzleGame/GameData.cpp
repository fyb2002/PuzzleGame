#include "GameData.h"
#include <cstring>
#include <iostream>

GameData::GameData(const char* mapData)
	: mStateMap(nullptr), mHeight(0)
{
	// get mapData's height
	// TODO:first '\n' , many '\n's,  no player, many player, no goal, no block, goals != blocks
	using namespace std;

	if (mapData == nullptr)
		return;

	char* tok;
	char* context;
	char* copyMap = new char[strlen(mapData) + 1];

	strcpy_s(copyMap, strlen(mapData) + 1, mapData);


	tok = strtok_s(copyMap, "\n", &context);
	while (tok) {
		mHeight++;
		tok = strtok_s(nullptr, "\n", &context);
	}

	cout << "Height = " << mHeight << endl;
	context = nullptr;
	delete[] copyMap;

	if (mHeight == 0)
		return;

	mStateMap = new Object*[mHeight];
	copyMap = new char[strlen(mapData) + 1];
	strcpy_s(copyMap, strlen(mapData) + 1, mapData);
	
	tok = strtok_s(copyMap, "\n", &context);
	int i = 0;
	while (tok) {
		int j = 0;
		mStateMap[i] = new Object[strlen(tok) + 1];
		char* cur = tok;
		while (*cur != '\0') {
			Object obj;
			switch (*cur)
			{
			case '#': obj = OBJ_WALL; break;
			case ' ': obj = OBJ_SPACE; break;
			case 'p': obj = OBJ_PLAYER; break;
			case 'P': obj = OBJ_PLAYERONGOAL; break;
			case '.': obj = OBJ_GOAL; break;
			case 'o': obj = OBJ_BLOCK; break;
			case 'O': obj = OBJ_BLOCKONGOAL; break;
							
			default: obj = OBJ_UNKNOWN;  break; // for anything else...

			}
			if (obj != OBJ_UNKNOWN)
				mStateMap[i][j++] = obj;
			cur++;
		} //while(*cur != '\0')
		mStateMap[i][j] = OBJ_END_LINE;
		i++;

		tok = strtok_s(nullptr, "\n", &context);
	} // while (tok)
	
	delete[] copyMap;

}

GameData::~GameData()
{
	for (int i = 0; i < mHeight; i++)
		delete[] mStateMap[i];

	if(mStateMap != nullptr)
		delete[] mStateMap;
}

void GameData::draw()
{
	using namespace std;
	
	for (int i = 0; i < mHeight ; i++)
	{
		int j = 0;
		bool isEndLine = false;
		while(isEndLine != true) {
			switch (mStateMap[i][j]) {
				case OBJ_WALL:cout << '#'; break;
				case OBJ_SPACE: cout << ' '; break;
				case OBJ_PLAYER: cout << 'p'; break;
				case OBJ_PLAYERONGOAL: cout << 'P'; break;
				case OBJ_GOAL: cout << '.'; break;
				case OBJ_BLOCK: cout << 'o'; break;
				case OBJ_BLOCKONGOAL: cout << 'O';  break;

				case OBJ_END_LINE: isEndLine = true; cout << endl; break;
			}
			j++;
		}
	}
}