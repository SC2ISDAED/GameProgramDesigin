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
		//���µ�ͷָ��ָ��ɵ�ͷָ�룬���ҽ�ͷָ��ָ���µ�ͷ�ڵ�
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
					//������һ���ڵ���Ϊnullptr�󣬱����ֻὫ��ǰ�ڵ���Ϊ�գ�����ѭ��������ȡ��ָ��
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

