#pragma once
#include "Bullet.h"
#include "Actor.h"
/*
	Ϊ�˴����ӵ�����ʾ�������ݽṹ�����õ�������ͨ��һ�α���ɾ��������Ҫ��ɾ�����ӵ�
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