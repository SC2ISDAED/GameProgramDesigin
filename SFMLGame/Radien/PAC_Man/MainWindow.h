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
#include "Animation.h"
#include "Boss.h"
#include "Missle.h"
#include "SFML/Audio.hpp"
/*管理游戏窗体的控制以及游戏的逻辑进行*/
class MainWindows
{
private:
	void DrawScore();

	void DrawGaming();
	void Drawinitialize();
	void DrawGameOver();
	void DrawGamePause();
	void DrawGameWin();

	void ProcessInput();
	void Prompt_info(short _x, short _y);
	void DrawInfomation(short _x, short _y);
	void GameLogic();
	void SpawnNormalEnemy();
	void SpawnnHelicopter();
	void SpawnBigEnemy();
	void SpawnMissleEnemy(MissleType _type);

	void GameStage1();
	void GameStage2();
	void GameStage3();
	void GameStage4();
	void GameStage5();
	void Boss();

	unsigned int WindowsWidth;
	unsigned int WindowsHeigth;
	

	sf::Texture m_backGround;
	sf::Sprite m_bgSprite;
	sf::IntRect m_currentRect;
	
	sf::Texture m_HPofHeroImage;
	sf::Sprite m_HPofHeroSprite;
	/*管理整个游戏进行的相关数据*/

	GameModeData gameData;
	unsigned int currentShowScore = 0;
	bool BWindowsShouldOver;
	GameState gameState = GameState::GameInitialize;
	GameStage gameStage = GameStage::Stage1;

	BossEnemy boss;
	bool State2SpawnMissle=false;
	bool State3SpawnMissle=false;
	int SpawnNumber = 20;
	
	std::list<Actor*> bossList;
	//存放Hero产生子弹的数据结构
	BulletList HeroBulletList;
	//存放敌军产生的子弹
	BulletList EnemyBulletList;

	std::list<NomalEnemy> normalEnemyList;
	std::list<Helicopter> helicopterList;
	std::list<BigEnemy> bigEnemyList;
	std::list<Missle> missleEnemyList;
	std::list<Animation> DeathAnimation;

	short UintSize = 25;
	int delay = 10;
	Hero m_Player;
	int player_MaxHP = 200;

	int weaponDelay;

	int helicopterWeaponDelay;

	sf::RenderWindow renderWindow;
	sf::Font sfFont;
	
	int SpawnNormalEnemyDelay = 120;
	int currentNormalEnemyDealy = 60;

	int SpawnHelicopterDelay = 120;
	int currentHelicopterDelay = 120;
	short textAnFrame = 3;
	short textAnDelay = 5;

	sf::Music mapBG;
	sf::Music GamingBG;
	sf::Music WarningBG;
	sf::Music BossBG;
	sf::Music MissleTimeBG;
	sf::SoundBuffer gamingBG;
public:

	MainWindows(short _Width, short _Height, const std::string& nameOfWindows);
	bool BGameOver() { return gameData.BisGameOver; }
	bool BWindosOver() {return BWindowsShouldOver;}
	/*游戏初始化*/
	void Initial();
	void TickFrame();

	void UpdateBGandUI();
	void LoadResource();


};
