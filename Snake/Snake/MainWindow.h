#pragma once
#include "GameModeData.h"
#include "Snake.h"
#include "string"
#include "vector"
#include <windows.h>
/*������Ϸ����Ŀ����Լ���Ϸ���߼�����*/
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
	/*����������Ϸ���е��������*/
	GameModeData gameData;
	/*��Ϸ��ʼ��*/
	void Initial();
	void TickFrame();

};
