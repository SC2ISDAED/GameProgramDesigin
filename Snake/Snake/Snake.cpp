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
	m_Length = 6;
	m_Size = 10;
	head = std::make_shared<SnakeNode>(headLocX,headLocY);
	std::shared_ptr<SnakeNode> currentNode = head;
	for (int i=0;i< m_Length -1;i++)
	{
		currentNode->nextSnakeNode = std::make_shared<SnakeNode>(headLocX - i - 1, headLocY);
		currentNode = currentNode->nextSnakeNode;
	}
}

void Snake::Update(short _x, short _y)
{

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

