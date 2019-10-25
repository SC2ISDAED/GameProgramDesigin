#pragma once
#include "utility"
#include "Actor.h"
#include "Collision.h"
#include <SFML/Graphics.hpp>
class NomalEnemy:public Actor
{
private:

	sf::Texture m_Texture;
	sf::Sprite m_Sprite;

public:
	 NomalEnemy(float locX, float locY,float speedX,float speedY, std::string path, int health, float _scale);
	 NomalEnemy() {};
	 void inilize(float locX, float locY, std::string path, int health, float _scale);
	 void Update(int WindowsWidth, int WindowsHeigth);
	 void Draw(sf::RenderWindow &_renderWindow);

};