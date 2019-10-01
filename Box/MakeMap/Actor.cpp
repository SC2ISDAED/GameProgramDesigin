#include "Actor.h"
bool Actor::SetLocation(std::pair<short, short> _location)
{
	location = std::move(_location);
	return true;
}

