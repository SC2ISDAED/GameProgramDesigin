#pragma once
#include <SFML/Graphics.hpp>
#include "GameModeData.h"
#include "Bullet.h"
#include "Hero.h"
#include "string"
#include "vector"
#include "list"
#include "BulletList.h"
#include "NormalEnemy.h"
#include "Helicopter.h"
#include "BigEnemy.h"
/*������Ϸ����Ŀ����Լ���Ϸ���߼�����*/
class MainWindows
{
private:
	void showScore();
	void Draw();
	void ProcessInput();
	void Prompt_info(short _x, short _y);
	void DrawInfomation(short _x, short _y);
	void GameLogic();
	void SpawnNormalEnemy();
	void SpawnnHelicopter();
	void SpawnBigEnemy();
	unsigned int WindowsWidth;
	unsigned int WindowsHeigth;

	sf::Texture m_backGround;
	sf::Sprite m_bgSprite;
	sf::IntRect m_currentRect;
	
	/*����������Ϸ���е��������*/

	GameModeData gameData;
	bool BWindowsShouldOver;
	
	BulletList HeroBulletList;
	//��ŵо��������ӵ�
	BulletList EnemyBulletList;

	std::list<NomalEnemy> normalEnemyList;
	std::list<Helicopter> helicopterList;
	std::list<BigEnemy> bigEnemyList;

	short UintSize = 25;
	int delay = 10;
	Hero m_Player;
	int weaponDelay;

	int helicopterWeaponDelay;

	sf::RenderWindow renderWindow;
	sf::Font sfFont;
	
	int SpawnNormalEnemyDelay = 60;
	int SpawnHelicopterDelay = 120;

	short textAnFrame = 3;
	short textAnDelay = 5;
public:

	MainWindows(short _Width, short _Height, const std::string& nameOfWindows);
	bool BGameOver() { return gameData.BisGameOver; }
	bool BWindosOver() {return BWindowsShouldOver;}
	/*��Ϸ��ʼ��*/
	void Initial();
	void TickFrame();

	void UpdateBackGround();
	void LoadResource();


};
