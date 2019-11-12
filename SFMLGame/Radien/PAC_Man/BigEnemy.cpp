#include "BigEnemy.h"
#include "BulletList.h"
#define  PI 3.1415926
BigEnemy::BigEnemy(float locX, float locY, float speedX, float speedY, std::vector<std::string> path, int health,int _score, float _scale)
{
	
	m_Health = health;
	score = _score;
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

void BigEnemy::Update(int WindowsWidth, int WindowsHeight, BulletList &_BulletList, std::pair<float, float> _Target)
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
	if (currentDelay==0)
	{
		currentDelay = shootDelay;
		if (stage==0)
		{
			ShootStage1(_BulletList, _Target, bulletSpeed);
		}
		else
		{
			ShootStage2(_BulletList, _Target, bulletSpeed);
		}
	}
	else
	{
		currentDelay--;
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
	if (m_Health <= MaxHP / 3)
	{
		stage = 1;
		shootDelay = 50;
	}
	if (m_Health<=0)
	{
		Detory();
	}
}

Animation BigEnemy::SpawnDeathAnimation(int locxOffset, int locYoffset, int delay, float _scale)
{
	std::vector<std::string > anpath{
	"Resource\\image\\b11.gif","Resource\\image\\b10.gif","Resource\\image\\b9.gif","Resource\\image\\b8.gif",
	"Resource\\image\\b7.gif","Resource\\image\\b6.gif","Resource\\image\\b5.gif","Resource\\image\\b4.gif",
	"Resource\\image\\b3.gif","Resource\\image\\b2.gif","Resource\\image\\b1.gif"
	};

	Animation deathAnimation(m_Location.first, m_Location.second, 2, anpath, 2.0, score);
	return deathAnimation;
}

void BigEnemy::ShootStage1(BulletList &_BulletList, std::pair<float, float> _Target, float speed)
{
	std::string BulletResourcePath = "Resource\\Enemy\\BigEnemyBullet1.png";
	std::string BulletResourcePath2 = "Resource\\Enemy\\BigEnemyBullet2.png";
	std::vector<std::string> path{ BulletResourcePath,BulletResourcePath2 };


	int bulletLocationX = m_Location.first + m_Texture[stage].getSize().x / 2;
	int bulletLocationY = m_Location.second + m_Texture[stage].getSize().y;

	float bulletSpeedXDirection = (_Target.first - bulletLocationX) / 1000;
	float bulletSpeedYDirection = (_Target.second - bulletLocationY) / 1000;
	float bulletSpeedX = bulletSpeedXDirection * speed;
	float bulletSpeedY = bulletSpeedYDirection * speed;

	Bullet oneBullet(bulletLocationX, bulletLocationY, bulletSpeedX, bulletSpeedY, 20, 0.5, path);
	_BulletList.push_forward(std::move(oneBullet));

}

void BigEnemy::ShootStage2(BulletList &_BulletList, std::pair<float, float> _Target, float speed)
{
	std::vector<std::string> path{ "Resource\\Enemy\\BigEnemyBullet1.png",
		"Resource\\Enemy\\BigEnemyBullet2.png" };

	std::vector<std::string> path2{ "Resource\\Boss\\normalBullet3.png",
		"Resource\\Boss\\normalBullet2.png",
		"Resource\\Boss\\normalBullet.png" };
	int bulletLocationX = m_Location.first;
	int bulletLocationY = m_Location.second;
	float bulletSpeedXDirection = (_Target.first - bulletLocationX) / 1000;
	float bulletSpeedYDirection = (_Target.second - bulletLocationY) / 1000;

	float bulletSpeedX = bulletSpeedXDirection * speed;
	float bulletSpeedY = bulletSpeedYDirection * speed;



	Bullet oneBullet(bulletLocationX, bulletLocationY, bulletSpeedX, bulletSpeedY, 20, 0.5, path);
	_BulletList.push_forward(std::move(oneBullet));



	bulletLocationX = m_Location.first + m_Texture[stage].getSize().x;
	bulletSpeedXDirection = (_Target.first - bulletLocationX) / 1000;

	bulletSpeedX = bulletSpeedXDirection * speed;


	Bullet otherBullet(bulletLocationX, bulletLocationY, bulletSpeedX, bulletSpeedY, 20, 0.5, path);
	_BulletList.push_forward(std::move(otherBullet));


	bulletLocationX = m_Location.first + m_Texture[stage].getSize().x / 2;
	bulletLocationY = m_Location.second + m_Texture[stage].getSize().y;

	if (changeGun < changeGunTotalNum / 4)
	{
		for (int i = 0; i < 8; i++)
		{
			float cicleSpeedx = cos(2 * PI / 8 * i) * 2;
			float cicleSpeedy = sin(2 * PI / 8 * i) * 2;
			Bullet HelicopterBullet(bulletLocationX, bulletLocationY, cicleSpeedx, cicleSpeedy, 10, 0.5, path2);
			_BulletList.push_forward(std::move(HelicopterBullet));
		}
	}
	else
	{

		float cicleSpeedx = cos(2 * PI / 12 * cicleGun) * 2;
		float cicleSpeedy = sin(2 * PI / 12 * cicleGun) * 2;
		Bullet HelicopterBullet(bulletLocationX, bulletLocationY, cicleSpeedx, cicleSpeedy, 10, 0.5, path);
		_BulletList.push_forward(std::move(HelicopterBullet));

		if (cicleGun >= 12)
		{
			cicleGun = 0;
		}
		else
		{
			cicleGun++;
		}
	}
	changeGun--;
	if (changeGun <= 0)
	{
		changeGun = changeGunTotalNum;
	}
}

