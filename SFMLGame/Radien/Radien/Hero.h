#pragma once
#include "utility"
#include "Actor.h"
#include "Collision.h"
#include <SFML/Graphics.hpp>
class Bullet;
class Hero :public Actor
{
private:
	int m_Heath;
	TAG tag;
	sf::IntRect imageRect;
	Direction direction;
	sf::Sprite m_Sprite;
	sf::Sprite m_TrailSprite1;
	sf::Sprite m_TrailSprite2;
	sf::Texture m_Texture;
	sf::Texture m_TrailTexture;
	//用来对轨迹做相对偏移
	int trailOffsetX = 13;
	bool trialTransalte = true;
	float speed=2;
	float m_sacle = 0.5;
	
	std::string BulletResourcePath;
	int weaponDelay = 20;

	int m_width;
	int m_height;
public:
	 void inilize(float locX, float locY, std::string path, std::string TrailPath, std::string, int health, float _scale);
	 void Draw(sf::RenderWindow &_renderWindow);
	 std::pair<float, float> GetLocation() { return m_Location; }
	 int GetWeaponDelay() { return weaponDelay; }
	 void Damage(int _damage) { m_Heath -= _damage; }
	 bool Death() { return m_Heath <= 0; }

	 void ProcessInput(int WinWidth,int WinHeight);
	 Bullet Shoot();
	 void Fly();
};
