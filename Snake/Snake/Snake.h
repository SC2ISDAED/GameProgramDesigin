#pragma once
#include "memory"
enum class SnakeDirection
{
	STOP=0,
	LEFT,
	RIGHT,
	UP,
	DOWN
};
struct SnakeNode
{
	short locx;
	short locy;
	std::shared_ptr<SnakeNode> nextSnakeNode;
	SnakeNode(short _locx,short _locy):locx(_locx),locy(_locy),nextSnakeNode(nullptr){}
};
class Snake
{
private:
	std::shared_ptr<SnakeNode> head;
	SnakeDirection m_direction;
	short m_Size;
	short m_Length;
	short initLocX;
	short initLocY;
	
public:
	Snake(short headLocX, short headLocY);
	void init();
	void Update(short _x,short _y);
	void AddLength(short addLength);
	bool BIsSameHeadLoc(short _x, short _y);
	bool BIsSameTrialLoc(short _x, short _y);

	short GetSize() { return m_Size; }
	void GetHeadLoc(short & locX, short & locY);
	bool SetSize(short _size) { m_Size = _size; }

	void SetDirection(SnakeDirection dir) { m_direction = dir; }
	SnakeDirection GetDirection() { return m_direction; }

	void pop_back();
	void push_forward(short newHeadLocX, short newHeadLocY);
	~Snake() {};
};