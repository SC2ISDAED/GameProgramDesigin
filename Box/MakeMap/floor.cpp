#include "floor.h"
Floor::Floor(FloorType _type, std::pair<short, short> _location):location(std::move(_location)), m_Type(_type)
{

}

bool Floor::SetLocation(std::pair<short, short> _location)
{
	location = std::move(_location);
	return true;
}

