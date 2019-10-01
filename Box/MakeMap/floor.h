#pragma once
#include "utility"
#include "string"
enum class  FloorType
{
	Wall,
	Road,
	Box,
	Target,
	Charcter,
	AtTarget
};

class Floor
{
private:
	std::pair<short, short> location;
	FloorType m_Type;
public:
	Floor(FloorType _type, std::pair<short, short> _location);
	bool SetLocation(std::pair<short, short> _location);
	std::pair<short, short> GetLocation() { return location; }
	FloorType GetType(){ return m_Type; }
};
