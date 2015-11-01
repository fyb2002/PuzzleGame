#include <iostream>
#include <cstring>
#include "GameData.h"

/*
draw
input
updateGame - update player character position
		   - update map
           - isGameClear

*/

using namespace std;

static const char gStageData[] = "\
########\n\
#  ..p #\n\
#  oo  #\n\
#      #\n\
########";

void main(void)
{
	GameData *gd = new GameData(gStageData);
	gd->draw();

#if 0
	while (true)
	{
		// getInput()

		// updateGame()

		// draw()
	}
#endif
}

