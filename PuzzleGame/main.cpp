#include <iostream>
#include <cstring>
#include "GameData.h"

/*
draw
input
updateGame - update player character position
		   - update map
           - isGameClear


		   플레이어가 이동 시
		   - 이동하려는 곳이 벽인가?
		   - 벽이면 이동 무효
		   - 블럭인가?
		   - 블럭이면 해당 블럭도 해당 방향으로 이동
		   - 벽인가?
		   - 불럭인가? 그렇다면 플레이어 이동 방향으로,
		   - 공 두개 이상은 이동 못하므로
		   이동 무효
		   - 일반 필드인가?
		   플레이어와 공 모두 이동
		   - 골인가 ?
		   둘다 이동 후 스코어 획득
		   - 블럭인 골 인가?
		   이동 무효
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

