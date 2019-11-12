#pragma once
#include "utility"
#include "Collision.h"
#include "SFML/Graphics.hpp"
#include "Actor.h"
class BulletList;
enum class BossState
{
	State1,
	Stage2,
	State3,
	Dead
};
class BossEnemy
{
private:

protected:
	int m_Health;
	std::pair<float, float> m_Location;
	std::pair<float, float> m_Speed;
	bool ShouldRemove = false;
	float m_scale;
	int score = 10;
	bool death = false;

	BossState m_bossState;
	
	sf::Sprite sp_Heart;
	sf::Texture tex_Heart;
	int firstHeartoffsetX = 67;
	int firstHeartoffsetY = 100;
	int firstHeartGunDelay = 100;
	int currentFirstHeartGunDelay = 100;

	int firstHeartGgun2Delay = 20;
	int currentfirstHeartGgun2Delay = 0;

	int currentGun = 12;
	int currentGunTime = 0;
	int currentCicleGun = 12;

	int CicleGunNum = 12;
	int CicleGunDelay = 10;
	bool CilcleChangeGun = true;
	sf::Sprite sp_SecondHeart;
	sf::Texture tex_SecondHeart;
	int secondHeartGunDelay = 50;
	int currentSecondHeartGunDelay = 0;
	bool changeGun = true;
	int SecondHeartoffsetX = 67;
	int SecondHeartoffsetY = 160;

	
	int gunDelay = 25;
	int currentGunDelay = 0;

	int slotDelay = 25;
	int currentSlotDelay = 0;

	sf::Sprite sp_LeftGun;
	sf::Texture tex_LeftGun;
	int leftGunoffetX = -35;
	int leftGunoffetY = 60;


	sf::Sprite sp_RightGun;
	sf::Texture tex_RightGun;
	int rightGunGoffetX = 180;
	int rightGunGoffetY = 60;

	sf::Sprite sp_LeftShield;
	sf::Texture tex_LeftShield;
	int leftShiledoffetX = 40;
	int leftShiledoffetY = 0;
	
	sf::Sprite sp_RightShield;
	sf::Texture tex_RightShield;
	int rightShiledoffetX = 125;
	int rightShiledoffetY = 0;
	void Stage1(BulletList &_bulletList, std::pair<float, float> _Target);

	void Stage2(BulletList &_bulletList, std::pair<float, float> _Target);

	void Stage3(BulletList &_bulletList, std::pair<float, float> _Target);
	void DeadAmination();

public:
	Actor leftGun;
	Actor rightGun;
	Actor leftShiled;
	Actor rightShiled;
	Actor secondHeart;
	Actor firstheart;
	BossEnemy() {};
	void inilize();
	void Draw(sf::RenderWindow &_renderWindows);
	
	BossState GetBossState() { return m_bossState; }
	void Update(BulletList &_bulletList, std::pair<float, float> _Target);
	void UpdateLocation(int _locx, int _locy);

	void Detory() { ShouldRemove = true; }
	bool IsRemove() { return ShouldRemove; }
	bool IsDead() { return death; }

	int GetScore() { return score; }
	void SetScore(int _score) { score = _score; }



	void  Damage(int damage);
	bool Hit(RectCollision  _temp);
};