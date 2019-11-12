#pragma once
#include "Actor.h"
#include "SFML/Graphics.hpp"
#include "string"
#include "Bullet.h"
enum class MissleType
{
	Type1,
	Type2
};
class Missle :public Actor
{
private:
	MissleType misstype;
	sf::Sprite m_Sprite;
	std::vector<sf::Texture> m_Texture;
	int currentTexture = 0;
	int UpdateDelay = 10;
	int currentDelay = 10;

	sf::Sprite m_TrialSprite;
	std::vector<sf::Texture> m_TrialTexture;
	int currentTrailTexture = 0;
	int UpdateTrialDelay = 10;
	int currentUpdateTrialDelay = 10;
	int height;

public:


	Missle(float locX, float locY, float speedX, float speedY, int health, int _score, float _scale, MissleType _type);
	Missle() {};
	void inilize(float locX, float locY, std::string path, int health, float _scale);
	void Update(int WindowsWidth, int WindowsHeight, std::pair<float, float>_target);
	void Draw(sf::RenderWindow &_renderWindow);

};