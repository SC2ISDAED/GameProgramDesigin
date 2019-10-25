#pragma once
#include "NormalEnemy.h"
NomalEnemy::NomalEnemy(float locX, float locY, float speedX, float speedY, std::string path,  int health, float _scale)
{
	m_Health = health;
	m_scale = _scale;
	m_Texture.loadFromFile(path);
	m_Sprite.setTexture(m_Texture);

	m_Collision.SetWidth(m_Texture.getSize().x * m_scale);
	m_Collision.SetHeight(m_Texture.getSize().y*m_scale);
	m_Collision.SetCenter(locX, locY);

	m_Speed.first = speedX;
	m_Speed.second = speedY;

	m_Location.first = locX;
	m_Location.second = locY;
}

void NomalEnemy::inilize(float locX, float locY, std::string path, int health, float _scale)
{
	m_Health = health;
	m_scale = _scale;
	m_Texture.loadFromFile(path);
	m_Sprite.setTexture(m_Texture);

	m_Collision.SetWidth(m_Texture.getSize().x * m_scale);
	m_Collision.SetHeight(m_Texture.getSize().y*m_scale);
	m_Collision.SetCenter(locX, locY);

	m_Speed.first = 0;
	m_Speed.second = 5;

	m_Location.first = locX;
	m_Location.second = locY;
}

void NomalEnemy::Update(int WindowsWidth, int WindowsHeight)
{
	float newlocX = m_Location.first + m_Speed.first;
	float newlocY = m_Location.second + m_Speed.second;
	//延迟Y轴，让一次能够产生更多飞机
	if ((newlocX > WindowsWidth + 20 || newlocX < -20) || (newlocY > WindowsHeight + 20 || newlocY < -200))
	{
		Detory();
	}
	else
	{
		SetCenter(newlocX, newlocY);
	}
	
}

void NomalEnemy::Draw(sf::RenderWindow &_renderWindow)
{
	m_Sprite.setPosition(m_Location.first, m_Location.second);
	m_Sprite.setScale(m_scale, m_scale);
	m_Sprite.setTexture(m_Texture);
	_renderWindow.draw(m_Sprite);
}
