#include "Missle.h"
#include "random"
Missle::Missle(float locX, float locY, float speedX, float speedY, int health, int _score, float _scale,MissleType _type)
{
	misstype = _type;
	m_Location.first = locX;
	m_Location.second = locY;
	m_Health = health;
	m_scale = _scale;
	height = rand() % 150 + 80;
	std::vector<std::string> path{
		"Resource\\Missile\\Missle1.png","Resource\\Missile\\Missle2.png","Resource\\Missile\\Missle3.png",
		"Resource\\Missile\\Missle4.png","Resource\\Missile\\Missle5.png","Resource\\Missile\\Missle6.png",
		"Resource\\Missile\\Missle7.png","Resource\\Missile\\Missle8.png","Resource\\Missile\\Missle9.png",
		"Resource\\Missile\\Missle10.png"
	};
	m_Texture.resize(path.size());
	for (int i=0;i<m_Texture.size();i++)
	{
		m_Texture[i].loadFromFile(path[i]);
	}
	m_Collision.SetWidth(m_Texture[0].getSize().x * m_scale);
	m_Collision.SetHeight(m_Texture[0].getSize().y*m_scale);
	m_Collision.SetCenter(locX, locY);

	std::vector<std::string> trailPath{
		"Resource\\Missile\\Trial_1.png","Resource\\Missile\\Trial_2.png"
	};
	m_TrialTexture.resize(trailPath.size());
	for (int i = 0; i < m_TrialTexture.size(); i++)
	{
		m_TrialTexture[i].loadFromFile(trailPath[i]);
	}
}

void Missle::Update(int WindowsWidth, int WindowsHeight, std::pair<float, float>_target)
{
	if (misstype == MissleType::Type1)
	{
		if (m_Location.second<80)
		{
			//导弹发射至锁定目标前的速度
			m_Speed.second = 2;
		}
		else if (m_Location.second > height&&m_Location.second< _target.second-150)
		{
			//导弹追踪目标
			float bulletSpeedXDirection = (_target.first - m_Location.first) / 1000;
			float bulletSpeedYDirection = (_target.second - m_Location.second) / 1000;
			float ratateTan = (_target.first - m_Location.first) / (_target.second - m_Location.second);


			m_Speed.first = bulletSpeedXDirection * 10;
			m_Speed.second = 5;
		}
		else if(m_Location.second >= _target.second - 150)
		{
			//距离目标一定距离后，不再更新导弹速度
			m_Speed.second = 5;
		}
		else 
		{
			//导弹锁定目标时短暂停留
			m_Speed.second = 1;
		}
	}
	else
	{
		m_Speed.second = 7;
	}
	float newlocX = m_Location.first+ m_Speed.first;
	float newlocY = m_Location.second + m_Speed.second;
	/*m_Sprite.setOrigin(newlocX, newlocY);*/
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

void Missle::Draw(sf::RenderWindow &_renderWindow)
{
	m_Sprite.setPosition(m_Location.first, m_Location.second);
	m_Sprite.setScale(m_scale, m_scale);

	m_TrialSprite.setPosition(m_Location.first+6, m_Location.second-25);
	m_TrialSprite.setScale(1, 1);

	if (currentDelay==0)
	{
		currentDelay = UpdateDelay;
		currentTexture++;
		if (currentTexture>=m_Texture.size())
		{
			currentTexture = 0;
		}
	}
	else
	{
		currentDelay--;
	}
	m_Sprite.setTexture(m_Texture[currentTexture]);

	if (currentUpdateTrialDelay == 0)
	{
		currentUpdateTrialDelay = UpdateTrialDelay;
		currentTrailTexture++;
		if (currentTrailTexture >= m_TrialTexture.size())
		{
			currentTrailTexture = 0;
		}
	}
	else
	{
		currentUpdateTrialDelay--;
	}
	m_TrialSprite.setTexture(m_TrialTexture[currentTrailTexture]);

	_renderWindow.draw(m_TrialSprite);
	_renderWindow.draw(m_Sprite);
}

