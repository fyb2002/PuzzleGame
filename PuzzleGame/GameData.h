enum Object 
{
	OBJ_WALL,
	OBJ_SPACE,
	OBJ_GOAL,
	OBJ_BLOCK,
	OBJ_BLOCKONGOAL,
	OBJ_PLAYER,
	OBJ_PLAYERONGOAL,
	OBJ_END_LINE,

	OBJ_UNKNOWN
};

struct GameData {
	Object **mStateMap;
	int mHeight;
	
	GameData(const char* mapData);
	~GameData();

	void draw();
	
	//int mWidth;
	//int mHeight;
	//GameData(const char* mapData, int width, int height);
	
};
