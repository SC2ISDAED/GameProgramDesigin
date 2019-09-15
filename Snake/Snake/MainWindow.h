#pragma once
#include "GameModeData.h"
#include "Snake.h"
#include "string"
#include "vector"
#include <windows.h>
#include "Fruit.h"
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
	void initalFruits();
	unsigned int WindowsWidth;
	unsigned int WindowsHeigth;
	HANDLE sawpWindHandle[2];
	short sizeofSwapWind;
	short currentWindHandleNum;
	std::vector<std::string >screenData[2];
	Snake m_Snake;
	/*����������Ϸ���е��������*/
	Fruit m_fruits;
	GameModeData gameData;
	bool BWindowsShouldOver;
public:

	MainWindows(short _Width, short _Height, const std::string & nameOfWindows);
	bool BGameOver() { return gameData.BisGameOver; }
	bool BWindosOver() {return BWindowsShouldOver;}
	/*��Ϸ��ʼ��*/
	void Initial();
	void TickFrame();

};
