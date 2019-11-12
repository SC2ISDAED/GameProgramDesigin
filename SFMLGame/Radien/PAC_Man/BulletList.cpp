#include "BulletList.h"
void BulletList::push_forward(Bullet &&_bullet)
{
	if (head==nullptr)
	{
		head= std::make_shared<ListNode>(std::forward<Bullet>(_bullet));

	}
	else
	{
		std::shared_ptr<ListNode> old_head = head;
		std::shared_ptr<ListNode> newHead = std::make_shared<ListNode>(std::forward<Bullet>(_bullet));
		//将新的头指针指向旧的头指针，并且将头指针指向新的头节点
		newHead->nextNode = old_head;
		head = newHead;
	}

}

void BulletList::UpdateBullets(int WindowsWidth, int WindowsHeight)
{
	std::shared_ptr < ListNode > current= head;
	for (; current != nullptr; current = current->nextNode)
	{
		current->bullet.Update();
		std::pair<float, float> newloc = current->bullet.GetCenter();
		if ((newloc.first > WindowsWidth+20 || newloc.first < -20) || (newloc.second > WindowsHeight+20 || newloc.second < -20))
		{
			current->bullet.Destory();
		}
	}

	current = head;
	if (head != nullptr)
	{
		for (; current->nextNode != nullptr; current = current->nextNode)
		{

			if (current->nextNode->bullet.ShouldRemove())
			{
				if (current->nextNode->nextNode != nullptr)
				{
					current->nextNode = current->nextNode->nextNode;
				}
				else
				{
					//当把下一个节点置为nullptr后，遍历又会将当前节点置为空，导致循环条件读取空指针
					current->nextNode=nullptr;
					break;
				}
			}
		}
		if (head->bullet.ShouldRemove())
		{
			head = head->nextNode;
		}
	}
}

void BulletList::Draw(sf::RenderWindow & renderWindow)
{
	std::shared_ptr<ListNode> current = head;
	for (;current!=nullptr;current=current->nextNode)
	{
		current->bullet.Draw(renderWindow);
	}
}

void BulletList::DamageTest(Actor &_actor)
{
	std::shared_ptr<ListNode> current = head;
	RectCollision _temp = _actor.GetCollision();
	for (; current != nullptr; current = current->nextNode)
	{
		if (current->bullet.Hit(_temp))
		{
			current->bullet.Destory();
			_actor.Damage(current->bullet.GetDamage());

		}
		
	}
}

void BulletList::Clear()
{
	std::shared_ptr < ListNode > current = head;
	for (; current != nullptr; current = current->nextNode)
	{
		current->bullet.Destory();
	}
}

