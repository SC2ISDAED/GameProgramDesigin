#include "Hero.h"
#include "Bullet.h"
void Hero::inilize(float locX, float locY, std::string path, std::string TrailPath, std::string bulletPath, int health, float _scale)
{
	m_Location.first = locX;
	m_Location.second = locY;
	direction = Direction::STOP;
	m_Heath = health;
	m_sacle = _scale;
	BulletResourcePath = bulletPath;
	m_Texture.loadFromFile(path);
	m_Sprite.setTexture(m_Texture);

	imageRect.height = m_Texture.getSize().x;
	imageRect.width = m_Texture.getSize().y-10;

	m_width = m_Texture.getSize().x / 5 * m_sacle;
	m_height = m_Texture.getSize().y*m_sacle-15;

	m_Collision.SetWidth(m_width);
	m_Collision.SetHeight(m_height);
	m_Collision.SetCenter(locX,locY);
	
	imageRect.left = 116;

	m_Sprite.setScale(m_sacle, m_sacle);
	m_Sprite.setTextureRect(imageRect);

	sf::IntRect trailRect(0, 0, 53, 100);
	m_TrailTexture.loadFromFile(TrailPath);
	m_TrailSprite1.setTexture(m_TrailTexture);
	m_TrailSprite1.setScale(m_sacle-0.25, m_sacle-0.25);
	m_TrailSprite1.setTextureRect(trailRect);

	trailRect.left = 55;
	m_TrailSprite2.setTexture(m_TrailTexture);
	m_TrailSprite2.setScale(m_sacle - 0.25, m_sacle - 0.25);
	m_TrailSprite2.setTextureRect(trailRect);
}

void Hero::Draw(sf::RenderWindow &_renderWindow)
{
	m_Sprite.setPosition(m_Location.first, m_Location.second);
	if (trialTransalte)
	{
		m_TrailSprite1.setPosition(m_Location.first + trailOffsetX, m_Location.second + 30);
		_renderWindow.draw(m_TrailSprite1);
		trialTransalte = !trialTransalte;
	}

	else
	{
		m_TrailSprite2.setPosition(m_Location.first + trailOffsetX, m_Location.second + 35);
		_renderWindow.draw(m_TrailSprite2);
		trialTransalte = !trialTransalte;
	}
	_renderWindow.draw(m_Sprite);

}

void Hero::ProcessInput(int WinWidth, int WinHeight)
{
	/*
		处理玩家的输入，当有不同方向按键时候，切换图片形成侧飞的效果
	*/
	bool isNotGetInput = true;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		isNotGetInput = false;
		imageRect.width = 65;
		imageRect.left = 50;
		m_Location.first -= speed;
		m_Sprite.setTextureRect(imageRect);
		m_TrailSprite1.setScale(m_sacle - 0.3, m_sacle - 0.3);
		m_TrailSprite2.setScale(m_sacle - 0.3, m_sacle - 0.3);
		trailOffsetX = 10;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		isNotGetInput = false;
		imageRect.width = 65;
		imageRect.left = 200;
		m_Location.first += speed;
		m_Sprite.setTextureRect(imageRect);
		m_TrailSprite1.setScale(m_sacle - 0.3, m_sacle - 0.3);
		m_TrailSprite2.setScale(m_sacle - 0.3, m_sacle - 0.3);
		trailOffsetX = 10;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		m_Location.second -= speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_Location.second += speed;
	}
	if (isNotGetInput)
	{
		imageRect.width = 80;
		imageRect.left = 116;
		m_Sprite.setTextureRect(imageRect);
		m_TrailSprite1.setScale(m_sacle - 0.25, m_sacle - 0.25);
		m_TrailSprite2.setScale(m_sacle - 0.25, m_sacle - 0.25);
		trailOffsetX = 13;
	}
	if (m_Location.first>= WinWidth- m_width)
	{
    	m_Location.first = WinWidth- m_width;
	}
	if (m_Location.first <= 0)
	{
		m_Location.first = 0;
	}

	if (m_Location.second >= WinHeight - m_height)
	{
		m_Location.second = WinHeight- m_height;
	}
	if (m_Location.second <= 0)
	{
		m_Location.second = 0;
	}



	m_Collision.SetCenter(m_Location.first, m_Location.second);
}

Bullet Hero::Shoot()
{
	std::vector<std::string> path{ BulletResourcePath };
	
	Bullet HeroBullet(m_Location.first, m_Location.second,0,-5,100,1.0,path);
	return HeroBullet;
}
