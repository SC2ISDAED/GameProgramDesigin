#pragma once
class ScorePoint
{
protected:
	short locX;
	short  locY;
	int Score = 100;
public:
	virtual void UpdateData(short _x, short _y) = 0;
	void Setloc(short _x, short _y)
	{
		locX = _x;
		locY = _y;
	};
	bool BIsSameLoc(short _x, short _y)
	{
		return _x == locX && _y == locY;
	}
	virtual ~ScorePoint() {};
};
