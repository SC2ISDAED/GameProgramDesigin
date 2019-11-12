#pragma once
#include "Actor.h"
#include "string"
#include "SFML/Graphics.hpp"
#include "Bullet.h"
#include "BulletList.h"
class BigEnemy :public Actor
{
private:
	std::vector<sf::Texture>m_Texture;
	sf::Sprite m_Sprite;
	int stage = 0;
	int MaxHP;

	int shootDelay = 25;
	int currentDelay = 0;
	int changeGun = 0;
	int changeGunTotalNum = 16;
	int cicleGun = 0;
	int bulletSpeed = 10;
public:
	BigEnemy(float locX, float locY, float speedX, float speedY, std::vector<std::string> path, int health, int _score, float _scale);
	BigEnemy() {};
	void inilize(float locX, float locY, float speedX, float speedY, std::vector<std::string> &path, int health, float _scale);
	void Update(int WindowsWidth, int WindowsHeight, BulletList &_BulletList, std::pair<float, float> _Target);
	void Draw(sf::RenderWindow &_renderWindow);
	void Damage(int damage)override;
	virtual Animation SpawnDeathAnimation(int locxOffset, int locYoffset, int delay, float _scale)override;
	void ShootStage1(BulletList &_BulletList,std::pair<float, float> _Target, float speed);
	void ShootStage2(BulletList &_BulletList, std::pair<float, float> _Target, float speed);
};
