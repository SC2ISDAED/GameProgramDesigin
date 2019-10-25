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

public:
	static const int shootDelay = 240;
	BigEnemy(float locX, float locY, float speedX, float speedY, std::vector<std::string> path, int health, float _scale);
	BigEnemy() {};
	void inilize(float locX, float locY, float speedX, float speedY, std::vector<std::string> &path, int health, float _scale);
	void Update(int WindowsWidth, int WindowsHeight);
	void Draw(sf::RenderWindow &_renderWindow);
	void Damage(int damage)override;

	void Shoot(BulletList &_BulletList,std::pair<float, float> _Target, float speed);
};
