#pragma once
#include "utility"
enum class  Direction
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	STOP
};
class Actor
{
private:
	std::pair<short, short> location;
	Direction direction;
public:
	std::pair<short, short> GetLocation() { return location; }
	Direction GetDirection() { return direction; }
	bool SetLocation(std::pair<short, short> _location);
	void SetDirection(Direction _direction) { direction = _direction; }
};
