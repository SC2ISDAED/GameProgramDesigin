#pragma once
#include "string"
#include "vector"
#include "SFML/Graphics.hpp"
class Animation
{
private:
	int m_delay;
	int current_Time;
	float m_scale;
	sf::Sprite m_Sprite;
	sf::Text text;
	std::vector<sf::Texture> m_TextureArray;
	int currentImage = 0;
	int printScore = 0;
	bool Remove = false;
public:
	Animation(float locX,float locY, int delay, std::vector<std::string >& pathArray, float _Texturescale,int score);
	Animation() = default;
	void inlize(float locX, float locY, int delay,std::vector<std::string >& pathArray, float _Texturescale);
	void Play(sf::RenderWindow &renderWindow, sf::Font &font);
	bool ShouldRemove() { return Remove; }
};