#pragma once
#include "utility"
class RectCollision
{
private:
	int  m_Width;
	int  m_Height;
	std::pair<float, float>  m_Center;
public:
	RectCollision(int left,int Top,int Width,int Height);
	RectCollision() = default;
	std::pair<float, float> GetCenter() { return m_Center; }
	void SetWidth(int _width) { m_Width = _width; }
	void SetHeight(int _height) { m_Height = _height; }
	int Width() { return m_Width; }
	int Height() { return m_Height; }
	bool SetCenter(float locX, float locY) { m_Center = std::pair<float, float>(locX+m_Width*0.5, locY+m_Height*0.5); return true; }
	bool isHit(RectCollision & _Rect);
};