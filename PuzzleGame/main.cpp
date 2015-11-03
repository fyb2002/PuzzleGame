#include <iostream>
#include <cstring>
#include "GameData.h"

/*
draw
input
updateGame - update player character position
		   - update map
           - isGameClear


		   �÷��̾ �̵� ��
		   - �̵��Ϸ��� ���� ���ΰ�?
		   - ���̸� �̵� ��ȿ
		   - ���ΰ�?
		   - ���̸� �ش� ���� �ش� �������� �̵�
		   - ���ΰ�?
		   - �ҷ��ΰ�? �׷��ٸ� �÷��̾� �̵� ��������,
		   - �� �ΰ� �̻��� �̵� ���ϹǷ�
		   �̵� ��ȿ
		   - �Ϲ� �ʵ��ΰ�?
		   �÷��̾�� �� ��� �̵�
		   - ���ΰ� ?
		   �Ѵ� �̵� �� ���ھ� ȹ��
		   - ���� �� �ΰ�?
		   �̵� ��ȿ
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

