#pragma once
#include "Actor.h"
#include "SFML/Graphics.hpp"
#include "string"
#include "Bullet.h"
class Helicopter:public Actor
{
private:

	sf::Texture m_Texture;
	sf::Sprite m_Sprite;
	
public:
	static const int shootDelay = 60;
	Helicopter(float locX, float locY, float speedX, float speedY, std::string path, int health, float _scale);
	Helicopter() {};
	void inilize(float locX, float locY, std::string path, int health, float _scale);
	void Update(int WindowsWidth, int WindowsHeight);
	void Draw(sf::RenderWindow &_renderWindow);

	
	Bullet Shoot(std::pair<float, float> _Target, float speed);
};