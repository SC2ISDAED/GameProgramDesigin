#pragma once
#include <SFML/Graphics.hpp>
#include "GameModeData.h"
#include "Snake.h"
#include "string"
#include "vector"
#include "Fruit.h"


/*管理游戏窗体的控制以及游戏的逻辑进行*/
class MainWindows
{
private:
	void showScore();
	void Draw();
	void ProcessInput();
	void Prompt_info(short _x, short _y);
	void DrawInfomation(short _x, short _y);
	void GameLogic();
	void initalFruits();
	unsigned int WindowsWidth;
	unsigned int WindowsHeigth;
	Snake m_Snake;
	/*管理整个游戏进行的相关数据*/
	Fruit m_fruits;
	GameModeData gameData;
	bool BWindowsShouldOver;
	

	short UintSize = 25;
	int delay = 10;

	sf::Sprite m_SnakeHeadSprite;
	sf::Texture m_SnakeHeadTexture;

	sf::Sprite m_SnakeTailSprite;
	sf::Texture m_SnakeTailTexture;

	sf::Sprite m_SpriteFruit;
	sf::Texture m_FruitTexture;

	sf::Sprite m_SpriteBackground;
	sf::Texture m_BackgroundTexture;

	sf::RenderWindow renderWindow;
	sf::Font sfFont;

	short textAnFrame = 3;
	short textAnDelay = 5;
public:

	MainWindows(short _Width, short _Height, short _uintSize, const std::string& nameOfWindows);
	bool BGameOver() { return gameData.BisGameOver; }
	bool BWindosOver() {return BWindowsShouldOver;}
	/*游戏初始化*/
	void Initial();
	void TickFrame();

};
