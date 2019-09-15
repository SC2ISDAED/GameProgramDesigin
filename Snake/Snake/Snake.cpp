#include "Snake.h"

void Snake::pop_back()
{
	std::shared_ptr<SnakeNode> currentNode = head;
	for (;currentNode->nextSnakeNode->nextSnakeNode!=nullptr;currentNode=currentNode->nextSnakeNode)
	{
		//�ҵ����һ���ڵ��ǰһ��
	}
	currentNode->nextSnakeNode = nullptr;
}

void Snake::push_forward(short newHeadLocX, short newHeadLocY)
{

	std::shared_ptr<SnakeNode> old_head = head;
	std::shared_ptr<SnakeNode> newHead = std::make_shared<SnakeNode>(newHeadLocX, newHeadLocY);
	//���µ�ͷָ��ָ��ɵ�ͷָ�룬���ҽ�ͷָ��ָ���µ�ͷ�ڵ�
	newHead->nextSnakeNode = old_head;
	head = newHead;
}
Snake::Snake(short headLocX, short headLocY)
{
	initLocX = headLocX;
	initLocY = headLocY;
}

void Snake::init()
{
	m_Length = 6;
	m_Size = 10;
	head = std::make_shared<SnakeNode>(initLocX, initLocY);
	std::shared_ptr<SnakeNode> currentNode = head;
	for (int i = 0; i < m_Length - 1; i++)
	{
		currentNode->nextSnakeNode = std::make_shared<SnakeNode>(initLocX - i - 1, initLocY);
		currentNode = currentNode->nextSnakeNode;
	}
	m_direction = SnakeDirection::RIGHT;
}

void Snake::Update(short _x, short _y)
{

}

void Snake::AddLength(short addLength)
{
	short newLength = m_Length + addLength;
	if (newLength >m_Size)
	{
		m_Length = m_Size;
	}
	else
	{
		m_Length = newLength;
	}
}

bool Snake::BIsSameHeadLoc(short _x, short _y)
{

	return (_x == head->locx&&_y == head->locy);

}

bool Snake::BIsSameTrialLoc(short _x, short _y)
{
	std::shared_ptr<SnakeNode> currentNode = head->nextSnakeNode;
	bool isSame = false;
	for (;currentNode!=nullptr;currentNode=currentNode->nextSnakeNode)
	{
		if (_x == currentNode->locx&&_y == currentNode->locy)
		{
			isSame= true;
			break;
		}
	}
	return isSame;
}

void Snake::GetHeadLoc(short & locX, short & locY)
{
	locX = head->locx;
	locY = head->locy;
}

