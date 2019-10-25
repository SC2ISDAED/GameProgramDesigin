#pragma once
#include "Bullet.h"
#include "Actor.h"
/*
	为了大量子弹的显示做的数据结构，采用单向链表，通过一次遍历删除所有需要被删除的子弹
*/
struct ListNode
{
	Bullet bullet;
	std::shared_ptr<ListNode> nextNode;
	ListNode(Bullet &&_bullet) :bullet(_bullet), nextNode(nullptr) {}
};
class BulletList
{
private:
	std::shared_ptr<ListNode> head;
public:
	void push_forward(Bullet &&_bullet);
	void UpdateBullets(int windowsWidth,int windowsHeight); 
	void Draw(sf::RenderWindow & renderWindow);
	void DamageTest(Actor &_actor);
	void Clear();
	BulletList() :head(nullptr) {}
};