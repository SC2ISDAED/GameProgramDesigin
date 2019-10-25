#include "BigEnemy.h"
#include "BulletList.h"
BigEnemy::BigEnemy(float locX, float locY, float speedX, float speedY, std::vector<std::string> path, int health, float _scale)
{
	m_Health = health;
	MaxHP = health;
	m_scale = _scale;
	m_Texture.resize(path.size());

	for (int i = 0; i < path.size(); i++)
	{
		m_Texture[i].loadFromFile(path[i]);
	}

	m_Sprite.setTexture(m_Texture[stage]);

	m_Collision.SetWidth(m_Texture[stage].getSize().x * m_scale);
	m_Collision.SetHeight(m_Texture[stage].getSize().y*m_scale);
	m_Collision.SetCenter(locX, locY);

	m_Speed.first = speedX;
	m_Speed.second = speedY;

	m_Location.first = locX;
	m_Location.second = locY;
}

void BigEnemy::inilize(float locX, float locY, float speedX, float speedY,std::vector<std::string> &path, int health, float _scale)
{
	m_Health = health;
	m_scale = _scale;
	m_Texture.resize(path.size());

	for (int i=0;i<path.size();i++)
	{
		m_Texture[i].loadFromFile(path[i]);
	}

	m_Sprite.setTexture(m_Texture[stage]);

	m_Collision.SetWidth(m_Texture[stage].getSize().x * m_scale);
	m_Collision.SetHeight(m_Texture[stage].getSize().y*m_scale);
	m_Collision.SetCenter(locX, locY);

	m_Speed.first = speedX;
	m_Speed.second = speedY;

	m_Location.first = locX;
	m_Location.second = locY;
}

void BigEnemy::Update(int WindowsWidth, int WindowsHeight)
{
	
	float newlocX = m_Location.first + m_Speed.first;
	float newlocY = m_Location.second + m_Speed.second;
	if (m_Location.second >= 100)
	{

		m_Speed.second = 0;
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

void BigEnemy::Draw(sf::RenderWindow &_renderWindow)
{
	m_Sprite.setPosition(m_Location.first, m_Location.second);
	m_Sprite.setScale(m_scale, m_scale);
	m_Sprite.setTexture(m_Texture[stage]);

	_renderWindow.draw(m_Sprite);
}

void BigEnemy::Damage(int damage)
{
	m_Health -= damage;
	if (m_Health <= MaxHP / 2)
	{
		stage = 1;
	}
	if (m_Health<=0)
	{
		Detory();
	}
}

void BigEnemy::Shoot(BulletList &_BulletList, std::pair<float, float> _Target, float speed)
{


	std::string BulletResourcePath = "Resource\\Enemy\\BigEnemyBullet1.png";
	std::string BulletResourcePath2 = "Resource\\Enemy\\BigEnemyBullet2.png";
	std::vector<std::string> path{ BulletResourcePath,BulletResourcePath2 };
	if (stage==0)
	{
	

		int bulletLocationX = m_Location.first + m_Texture[stage].getSize().x / 2;
		int bulletLocationY = m_Location.second + m_Texture[stage].getSize().y;

		float bulletSpeedXDirection = (_Target.first - bulletLocationX) / 1000;
		float bulletSpeedYDirection = (_Target.second - bulletLocationY) / 1000;
		float bulletSpeedX = bulletSpeedXDirection * speed;
		float bulletSpeedY = bulletSpeedYDirection * speed;

		Bullet oneBullet(bulletLocationX, bulletLocationY, bulletSpeedX, bulletSpeedY, 20, 0.5, path);
		_BulletList.push_forward(std::move(oneBullet));
	}
	else if (stage==1)
	{

		int bulletLocationX = m_Location.first;
		int bulletLocationY = m_Location.second;
		float bulletSpeedXDirection = (_Target.first - bulletLocationX) / 1000;
		float bulletSpeedYDirection = (_Target.second - bulletLocationY) / 1000;

		float bulletSpeedX = bulletSpeedXDirection * speed;
		float bulletSpeedY = bulletSpeedYDirection * speed;

		
		
		Bullet oneBullet(bulletLocationX, bulletLocationY, bulletSpeedX, bulletSpeedY, 20, 0.5, path);
		_BulletList.push_forward(std::move(oneBullet));



		bulletLocationX = m_Location.first + m_Texture[stage].getSize().x ;
		bulletSpeedXDirection = (_Target.first - bulletLocationX) / 1000;

		bulletSpeedX = bulletSpeedXDirection * speed;


		Bullet otherBullet(bulletLocationX, bulletLocationY, bulletSpeedX, bulletSpeedY, 20, 0.5, path);
		_BulletList.push_forward(std::move(otherBullet));
	}
}

