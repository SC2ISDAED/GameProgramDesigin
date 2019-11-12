#include "Collision.h"


RectCollision::RectCollision(int left, int Top, int Width, int Height):m_Center(left+Width/2,Top+Height/2),m_Width(Width),m_Height(Height)
{

}



bool RectCollision::isHit(RectCollision & _Rect)
{
	//¾ØÐÎÅö×²¼ì²â
	auto t_loc = _Rect.GetCenter();
	int distanceX = t_loc.first - m_Center.first > 0 ? t_loc.first - m_Center.first : m_Center.first - t_loc.first;
	int distanceY = t_loc.second - m_Center.second > 0 ? t_loc.second - m_Center.second : m_Center.second - t_loc.second;
	if (distanceX<(m_Width+_Rect.Width())/2 && distanceY<(m_Height+_Rect.Height())/2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

