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
	Floor(FloorType _type=FloorType::Wall, std::pair<short, short> _location=std::pair<short,short>(0,0));
	bool SetLocation(std::pair<short, short> _location);
	bool IsSameLocation(std::pair<short, short> _location);
	std::pair<short, short> GetLocation() { return location; }
	FloorType GetType() { return m_Type; }
	void SetType(FloorType _Type) {
		m_Type = _Type;
	}
};
