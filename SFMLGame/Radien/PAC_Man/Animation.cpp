#include "Animation.h"

Animation::Animation(float locX, float locY, int delay, std::vector<std::string >& pathArray, float _Texturescale, int score)
{
	printScore = score;
	m_delay = delay;
	current_Time = delay;
	for (auto path:pathArray)
	{
		sf::Texture texture;
		texture.loadFromFile(path);
		m_TextureArray.push_back(std::move(texture));
	}
	m_Sprite.setTexture(m_TextureArray[0]);
	m_Sprite.setPosition(locX, locY);
	text.setPosition(locX+30, locY);
	m_Sprite.setScale(_Texturescale,_Texturescale);
}

void Animation::inlize(float locX, float locY, int delay, std::vector<std::string >& pathArray, float _Texturescale)
{
	m_delay = delay;
	current_Time = delay;
	for (auto path : pathArray)
	{
		sf::Texture texture;
		texture.loadFromFile(path);
		m_TextureArray.push_back(std::move(texture));
	}
	m_Sprite.setTexture(m_TextureArray[0]);
	m_Sprite.setPosition(locX, locY);

	m_Sprite.setScale(_Texturescale, _Texturescale);
}

void Animation::Play(sf::RenderWindow &renderWindow, sf::Font &font)
{
	current_Time--;
	int CharacterSize = 24;

	if (current_Time==0)
	{
		current_Time = m_delay;

		if (currentImage<m_TextureArray.size())
		{
			m_Sprite.setTexture(m_TextureArray[currentImage]);
			currentImage++;
		}
		else
		{

			Remove = true;
		}
		switch (currentImage % 3)
		{
		case 0:
			text.setFillColor(sf::Color(255, 0, 0, 255));
			break;
		case 1:
			text.setFillColor(sf::Color(0, 255, 255, 255));
			break;
		case 2:
			text.setFillColor(sf::Color(0, 0, 255, 255));
			break;
		}

	}
	if (printScore!=0)
	{
		//得分不为0时打印分数
		text.setString(std::to_string(printScore));
		text.setCharacterSize(CharacterSize);
		text.setFont(font);
	}

	renderWindow.draw(m_Sprite);
	renderWindow.draw(text);
}

