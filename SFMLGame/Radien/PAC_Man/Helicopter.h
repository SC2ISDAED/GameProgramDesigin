#pragma once
#include "Actor.h"
#include "SFML/Graphics.hpp"
#include "string"
#include "Bullet.h"
class BulletList;
/*
	直升机类，能够发射子弹，子弹的产生需要到Shoot函数里去设置
*/
class Helicopter:public Actor
{
private:

	sf::Texture m_Texture;
	sf::Sprite m_Sprite;
	int currentDelay = shootDelay;
	
public:
	static const int shootDelay = 60;
	int weaponSpeed = 5;

	Helicopter(float locX, float locY, float speedX, float speedY, std::string path, int health, int _score, float _scale);
	Helicopter() {};
	void inilize(float locX, float locY, std::string path, int health, float _scale);
	void Update(int WindowsWidth, int WindowsHeight, std::pair<float, float>_target, BulletList& _bulletList);
	void Draw(sf::RenderWindow &_renderWindow);

	
	Bullet Shoot(std::pair<float, float> _Target, float speed);
};