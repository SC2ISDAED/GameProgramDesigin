#pragma once
#include "GameModeData.h"
#include "Snake.h"
#include "string"
#include "vector"
#include <windows.h>
/*管理游戏窗体的控制以及游戏的逻辑进行*/
class MainWindows
{
private:
	void showScore();
	void Draw();
	void ProcessInput();
	void SetPos(short X, short Y);
	void Prompt_info(short _x, short _y);
	void DrawInfomation(short _x, short _y, int color, const std::string & information);
	void GameLogic();
public:
	MainWindows(short _Width, short _Height,const std::string & nameOfWindows);
	unsigned int WindowsWidth;
	unsigned int WindowsHeigth;
	HANDLE sawpWindHandle[2];
	short sizeofSwapWind;
	short currentWindHandleNum;
	std::vector<std::string >screenData[2];
	Snake m_Snake;
	/*管理整个游戏进行的相关数据*/
	GameModeData gameData;
	/*游戏初始化*/
	void Initial();
	void TickFrame();

};
