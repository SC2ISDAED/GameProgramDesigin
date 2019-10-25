#include "Helicopter.h"
Helicopter::Helicopter(float locX, float locY, float speedX, float speedY, std::string path, int health, float _scale)
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

void Helicopter::Update(int WindowsWidth, int WindowsHeight)
{
	float newlocX = m_Location.first + m_Speed.first;
	float newlocY = m_Location.second + m_Speed.second;
	if (m_Location.second==WindowsHeight/2)
	{
		m_Speed.first = -m_Speed.first;
		m_Speed.second = -1;
	}
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

void Helicopter::Draw(sf::RenderWindow &_renderWindow)
{
	m_Sprite.setPosition(m_Location.first, m_Location.second);
	m_Sprite.setScale(m_scale, m_scale);
	m_Sprite.setTexture(m_Texture);
	_renderWindow.draw(m_Sprite);
}
//@AbSpeed参数是绝对速度，不带方向
Bullet Helicopter::Shoot(std::pair<float, float> _Target,float Abspeed)
{
	float bulletSpeedXDirection = (_Target.first - m_Location.first)  /1000;
	float bulletSpeedYDirection = (_Target.second - m_Location.second) /1000;
	float bulletSpeedX = bulletSpeedXDirection * Abspeed;
	float bulletSpeedY = bulletSpeedYDirection * Abspeed;

	std::string BulletResourcePath = "Resource\\Enemy\\EnemyBullet1.png";
	std::string BulletResourcePath2= "Resource\\Enemy\\EnemyBullet2.png";
	std::string BulletResourcePath3= "Resource\\Enemy\\EnemyBullet3.png";
	std::vector<std::string> path{ BulletResourcePath,BulletResourcePath2,BulletResourcePath3 };

	int bulletLocationX = m_Location.first + m_Texture.getSize().x / 2;
	int bulletLocationY = m_Location.second+ m_Texture.getSize().y;
	Bullet HelicopterBullet(bulletLocationX, bulletLocationY, bulletSpeedX, bulletSpeedY, 50,0.5, path);
	return HelicopterBullet;
}

