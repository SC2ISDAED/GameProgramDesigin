#include "Actor.h"

void Actor::Damage(int damage)
{
	m_Health -= damage;
	if (m_Health<=0)
	{
		Detory();
	}
}

bool Actor::Hit(RectCollision _temp)
{
	return m_Collision.isHit(_temp);
}

void Actor::SetCenter(float locX, float locY)
{
	m_Location.first = locX;
	m_Location.second = locY;
	m_Collision.SetCenter(locX , locY);
}
