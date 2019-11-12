#pragma once
#include <SFML/Graphics.hpp>
#include "Collision.h"
#include "vector"

class Bullet
{
private:
	std::pair<float, float> m_Location;
	RectCollision m_Collision;
	std::pair<float, float> m_speed;
	int AminationDelay = 5;
	std::vector<sf::Texture> m_ImageArray;
	sf::Sprite m_Sprite;
	short currentImageNumber;
	float m_scale;
	int Damage=10;
	bool Remove=false;
public:
	Bullet(float locX, float locY,float speedX,float speedY,int damage, float scale, const std::vector<std::string> & ResourcePath);
	Bullet(float locX, float locY, const std::vector<std::string> & ResourcePath);
	void SetCenter(float locx, float locy);
	std::pair<float, float> GetCenter() { return m_Location; }

	const RectCollision & GetCollision() { return m_Collision; }
	bool ShouldRemove() { return Remove; }
	void Destory() { Remove = true; }
	void Update();
	void Draw(sf::RenderWindow & _renderWindow);
	bool Hit(RectCollision &rect);
	int GetDamage() { return Damage; }
};

