#pragma once
#include "Collision.h"
#include "Animation.h"
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

	int score = 10;
	bool death = false;
public:
	RectCollision m_Collision;
	RectCollision GetCollision() { return m_Collision; }

	void Detory() { 
		death = true;
		ShouldRemove = true; }
	void inilize(int _health);
	bool IsRemove() { return ShouldRemove; }
	bool IsDead() { return death; }
	void SetCenter(float locX, float locY);
	int GetScore() { return score; }
	void SetScore(int _score) { score = _score; }
	void SetHealth(int _Health) { m_Health = _Health; }
	virtual void  Damage(int damage);
	virtual bool Hit(RectCollision  _temp);
	virtual Animation SpawnDeathAnimation(int locxOffset, int locYoffset, int delay, float _scale);
	
};