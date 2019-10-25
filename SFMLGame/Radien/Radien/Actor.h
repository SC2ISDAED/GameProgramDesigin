#pragma once
#include "Collision.h"
enum class TAG
{
	ENEMY,
	HERO
};
enum class Direction
{
	STOP,
	LEFT,
	RIGHT,
	UP,
	DOWN
};
class Actor
{
private:

protected:
	int m_Health;
	std::pair<float, float> m_Location;
	std::pair<float, float> m_Speed;
	bool ShouldRemove = false;
	float m_scale;
	RectCollision m_Collision;
public:
	RectCollision GetCollision() { return m_Collision; }

	void Detory() { ShouldRemove = true; }
	bool IsRemove() { return ShouldRemove; }

	virtual void  Damage(int damage);
	virtual bool Hit(RectCollision  _temp);
	void SetCenter(float locX, float locY);
};