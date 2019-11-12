#pragma once
#include <SFML/Graphics.hpp>
#include "GameModeData.h"
#include "string"
#include "array"
#include "floor.h"


/*������Ϸ����Ŀ����Լ���Ϸ���߼�����*/
class MainWindows
{
private:
	void showScore();
	
	void Draw();
	void DrawGrid();
	void DrawButton();
	void DrawScore();
	void DrawTimer();
	void DrawGameEnd();

	void ProcessInput();
	void Prompt_info(short _x, short _y);
	void DrawInfomation(short _x, short _y);
	void GameLogic();
	unsigned int WindowsWidth;
	unsigned int WindowsHeigth;
	/*����������Ϸ���е��������*/
	GameModeData gameData;
	bool BWindowsShouldOver;
	std::array<std::array<Floor, LVL3_WIDTH>,LVL3_HEIGHT>floors;

	int imgSkinNo=1;
	int imgBGno=1;

	sf::Texture tBackground, tTiles, tButtons, tNum, tTimer, tCounter, tGameOver;		//�����������
	sf::Sprite	sBackground, sTiles, sButtons, sNum, sTimer, sCounter, sGameOver;		//�����������
	sf::IntRect ButtonRectEasy, ButtonRectNormal, ButtonRectHard, ButtonRectBG, ButtonRectSkin, ButtonRectRestart, ButtonRectQuit;

	short UintSize = 25;
	int delay = 10;

	sf::Sprite m_SpriteBackground;
	sf::Texture m_BackgroundTexture;

	sf::RenderWindow renderWindow;
	sf::Font sfFont;

	short textAnFrame = 3;
	short textAnDelay = 5;
public:

	MainWindows(short _Width, short _Height, const std::string& nameOfWindows);
	bool BGameOver() { return gameData.BisGameOver; }
	bool BWindosOver() {return BWindowsShouldOver;}
	/*��Ϸ��ʼ��*/
	void Initial();
	void TickFrame();
	void LoadResource();
};
