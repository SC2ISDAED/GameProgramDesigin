#pragma once
#pragma once
#include "string"
#include "vector"
#include <windows.h>
#include "GameModeData.h"
#include "floor.h"
#include "Actor.h"
/*管理游戏窗体的控制以及游戏的逻辑进行*/
class MainWindows
{
private:
	void Draw();
	void ProcessInput();
	void UpdateMap();
	void SetPos(short X, short Y);
	void Prompt_info(short _x, short _y);
	void DrawInfomation(short _x, short _y, int color, const std::string & information);
	void GameLogic();
	void LoadMap(const std::string &source);
	unsigned int WindowsWidth;
	unsigned int WindowsHeigth;
	HANDLE sawpWindHandle[2];
	short sizeofSwapWind;
	short currentWindHandleNum;
	std::vector<std::string >screenData[2];

	std::vector<Floor> m_Map;
	const char * map[6] = {"■","□","◆","☆","●","★"};
	short mapNum=4;
	short mapCurrentNum=3;
	short mapWidhth = 0;
	short mapHeight = 0;
	Actor Player;
	int targetNum = 0;
	bool BWindowsShouldOver;
	GameModeData gameInstancedData;
	bool IsCharcterAtTarget = false;
	short latterFrame = false;
public:

	MainWindows(short _Width, short _Height, const std::string & nameOfWindows);
	bool BWindosOver() { return BWindowsShouldOver; }
	bool BGameOver() { return gameInstancedData.BisGameOver; }
	/*游戏初始化*/
	void Initial();
	void TickFrame();
	void ShowScore();
};

