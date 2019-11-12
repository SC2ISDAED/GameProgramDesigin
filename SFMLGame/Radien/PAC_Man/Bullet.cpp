#include "Bullet.h"


Bullet::Bullet(float locX, float locY,float speedX, float speedY,int _damage,float scale,const std::vector<std::string> & ResourcePath):m_ImageArray(ResourcePath.size())
{
	m_Location.first = locX;
	m_Location.second = locY;
	m_speed.first = speedX;
	m_speed.second = speedY;
	m_scale = scale;
	for (int i=0;i<ResourcePath.size();i++)
	{
		m_ImageArray[i].loadFromFile(ResourcePath[i]);
		
	}
	currentImageNumber = 0;
	m_Sprite.setTexture(m_ImageArray[currentImageNumber]);
	m_Sprite.setPosition(locX, locY);
	m_Sprite.setScale(m_scale, m_scale);
	Damage = _damage;

	m_Collision.SetWidth(m_ImageArray[currentImageNumber].getSize().x*m_scale);
	m_Collision.SetHeight(m_ImageArray[currentImageNumber].getSize().y*m_scale);
}

Bullet::Bullet(float locX, float locY, const std::vector<std::string> & ResourcePath)
{

}

void Bullet::SetCenter(float locX, float locY)
{
	m_Sprite.setPosition(locX, locY);

	m_Collision.SetCenter(locX, locY);
	m_Location.first = locX;
	m_Location.second = locY;
}

void Bullet::Update()
{
	float newlocX = m_Location.first + m_speed.first;
	float newlocY = m_Location.second + m_speed.second;
	SetCenter(newlocX, newlocY);
}

void Bullet::Draw(sf::RenderWindow & _renderWindow)
{
	m_Sprite.setTexture(m_ImageArray[currentImageNumber]);
	m_Sprite.setPosition(m_Location.first, m_Location.second);
	AminationDelay--;
	if (AminationDelay==0)
	{
		AminationDelay = 10;
		currentImageNumber = (currentImageNumber + 1) % m_ImageArray.size();
	}


	_renderWindow.draw(m_Sprite);
}

bool Bullet::Hit( RectCollision &rect)
{
	return m_Collision.isHit(rect);
}
