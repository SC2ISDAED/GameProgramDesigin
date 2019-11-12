#pragma once
#include "utility"
#include "Actor.h"
#include "Collision.h"
#include <SFML/Graphics.hpp>
#include "SFML/Audio.hpp"
class Bullet;
class BulletList;
enum class  WeaponType
{
	Normal=0,
	SlotGun,
	Count
};
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
	WeaponType weapon=WeaponType::Normal;
	std::string BulletResourcePath;
	int weaponDelay = 20;

	sf::Sound bulletSound1;
	sf::Sound bulletSound2;
	sf::SoundBuffer bullet1Soundbuffer;
	sf::SoundBuffer bullet2Soundbuffer;
	int weaponChangeDelay = 20;
	short currentweaponChangeTime = 20;
	int m_width;
	int m_height;
public:
	 void inilize(float locX, float locY, std::string path, std::string TrailPath, std::string, int health, float _scale);
	 void Draw(sf::RenderWindow &_renderWindow);
	 std::pair<float, float> GetLocation() { return m_Location; }
	 int GetWeaponDelay() { return weaponDelay; }
	 void Damage(int _damage) { m_Heath -= _damage; }
	 bool Death() { return m_Heath <= 0; }
	 int GetHealth() { return m_Heath; }
	 void ProcessInput(int WinWidth,int WinHeight);
	 void Shoot(BulletList & bulletList);
	 virtual Animation SpawnDeathAnimation(int locxOffset, int locYoffset, int delay, float _scale)override;
	 void Fly();
};
