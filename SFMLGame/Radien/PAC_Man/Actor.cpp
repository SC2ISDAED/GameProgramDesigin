#include "Actor.h"

void Actor::Damage(int damage)
{
	m_Health -= damage;
	if (m_Health<=0)
	{
		death = true;
		Detory();
	}
}

bool Actor::Hit(RectCollision _temp)
{
	return m_Collision.isHit(_temp);
}

Animation Actor::SpawnDeathAnimation(int locxOffset,int locYoffset,int delay,float _scale)
{
	std::vector<std::string > anpath{
		"Resource\\image\\b11.gif","Resource\\image\\b10.gif","Resource\\image\\b9.gif","Resource\\image\\b8.gif",
		"Resource\\image\\b7.gif","Resource\\image\\b6.gif","Resource\\image\\b5.gif","Resource\\image\\b4.gif",
		"Resource\\image\\b3.gif","Resource\\image\\b2.gif","Resource\\image\\b1.gif"
	};

	Animation deathAnimation(m_Location.first+ locxOffset, m_Location.second+ locYoffset, delay, anpath, _scale,score);
	return deathAnimation;
}

void Actor::inilize(int _health)
{
	m_Health = _health;
	death = false;
	ShouldRemove = false;
}

void Actor::SetCenter(float locX, float locY)
{
	m_Location.first = locX;
	m_Location.second = locY;
	m_Collision.SetCenter(locX , locY);
}
