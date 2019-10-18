#pragma once
#include "ScorePoint.h"
class Fruit :public ScorePoint
{
public:
	void UpdateData(short _x, short _y)override
	{
		Setloc(_x, _y);
	}
	int ScoreAdd()
	{
		return Score;
	}
};