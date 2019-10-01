#pragma once
#include "utility"
enum class  Direction
{
	LEFT,
	RIGHT,
	UP,
	DOWN
};
class Actor
{
public:
	std::pair<short, short> location;
public:
	std::pair<short, short> GetLocation() { return location; }
	bool SetLocation(std::pair<short, short> _location);
};
