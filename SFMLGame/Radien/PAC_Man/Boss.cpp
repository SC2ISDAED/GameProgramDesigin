#include "Boss.h"
#include "BulletList.h"
#include "math.h"
#define  PI 3.1415926
void BossEnemy::inilize()
{
	m_bossState = BossState::State1;
	m_Location.first = 100;
	m_Location.second = -200;
	tex_Heart.loadFromFile("Resource//Boss//BossHeart.png");
	sp_Heart.setTexture(tex_Heart);
	death = false;
	tex_SecondHeart.loadFromFile("Resource//Boss//Heart.png");
	sp_SecondHeart.setTexture(tex_SecondHeart);
	secondHeart.SetCenter(m_Location.first + SecondHeartoffsetX, m_Location.second + SecondHeartoffsetY);
	secondHeart.m_Collision.SetWidth(tex_SecondHeart.getSize().x/2);
	secondHeart.m_Collision.SetHeight(tex_SecondHeart.getSize().y/2);
	secondHeart.inilize(2000);
	secondHeart.SetScore(200);

	firstheart.inilize(2000);
	firstheart.SetCenter(m_Location.first + firstHeartoffsetX, m_Location.second + SecondHeartoffsetY);
	firstheart.m_Collision.SetWidth(tex_SecondHeart.getSize().x/2);
	firstheart.m_Collision.SetHeight(tex_SecondHeart.getSize().y/2);
	firstheart.SetScore(1000);

	tex_LeftGun.loadFromFile("Resource//Boss//GunLeft.png");
	sp_LeftGun.setTexture(tex_LeftGun);
	leftGun.SetCenter(m_Location.first + leftGunoffetX, m_Location.second + leftGunoffetY);
	leftGun.m_Collision.SetWidth(tex_LeftGun.getSize().x);
	leftGun.m_Collision.SetHeight(tex_LeftGun.getSize().y);
	leftGun.inilize(1500);
	leftGun.SetScore(150);

	tex_RightGun.loadFromFile("Resource//Boss//gunRight.png");
	sp_RightGun.setTexture(tex_RightGun);
	rightGun.SetCenter(m_Location.first + rightGunGoffetX, m_Location.second + rightGunGoffetY);
	rightGun.m_Collision.SetWidth(tex_RightGun.getSize().x);
	rightGun.m_Collision.SetHeight(tex_RightGun.getSize().y);
	rightGun.inilize(1500);
	rightGun.SetScore(150);

	tex_RightShield.loadFromFile("Resource//Boss//armorRight.png");
	sp_RightShield.setTexture(tex_RightShield);
	rightShiled.SetCenter(m_Location.first + rightShiledoffetX, m_Location.second + rightShiledoffetY);
	rightShiled.m_Collision.SetWidth(tex_RightShield.getSize().x);
	rightShiled.m_Collision.SetHeight(tex_RightShield.getSize().y);
	rightShiled.inilize(1500);

	tex_LeftShield.loadFromFile("Resource//Boss//armorLeft.png");
	sp_LeftShield.setTexture(tex_LeftShield);
	leftShiled.SetCenter(m_Location.first + leftShiledoffetX, m_Location.second + leftShiledoffetY);
	leftShiled.m_Collision.SetWidth(tex_LeftShield.getSize().x);
	leftShiled.m_Collision.SetHeight(tex_LeftShield.getSize().y);
	leftShiled.inilize(1500);

	sp_Heart.setPosition(m_Location.first, m_Location.second);
	sp_SecondHeart.setPosition(m_Location.first+ SecondHeartoffsetX, m_Location.second+ SecondHeartoffsetY);
	sp_LeftGun.setPosition(m_Location.first+leftGunoffetX, m_Location.second+leftGunoffetY);
	sp_RightGun.setPosition(m_Location.first+ rightGunGoffetX, m_Location.second+ rightGunGoffetY);
	sp_RightShield.setPosition(m_Location.first+ rightShiledoffetX, m_Location.second+rightShiledoffetY);
	sp_LeftShield.setPosition(m_Location.first+ leftShiledoffetX, m_Location.second+ leftShiledoffetY);
}

void BossEnemy::Draw(sf::RenderWindow& _renderWindows)
{
	if (!leftGun.IsDead())
	{
		_renderWindows.draw(sp_LeftGun);
	}

	if (!rightGun.IsDead())
	{
		_renderWindows.draw(sp_RightGun);
	}
	if (!secondHeart.IsDead())
	{
		_renderWindows.draw(sp_SecondHeart);
	}
	if (!firstheart.IsDead())
	{
		_renderWindows.draw(sp_Heart);
	}
	

	if (!rightShiled.IsDead())
	{
		_renderWindows.draw(sp_RightShield);
	}
	if (!leftShiled.IsDead())
	{
		_renderWindows.draw(sp_LeftShield);
	}

}

void BossEnemy::Stage1(BulletList &_bulletList, std::pair<float, float> _Target)
{
	if (m_Location.second<=10)
	{
		m_Speed.first = 0;
		m_Speed.second = 3;
	}
	else if(m_Location.second>=10)
	{
		m_Speed.second = 0;
		if (currentGunDelay == 0)
		{
			
			currentGunDelay = gunDelay;

			if (!leftGun.IsDead())
			{
				std::string BulletResourcePath = "Resource\\Enemy\\EnemyBullet1.png";
				std::string BulletResourcePath2 = "Resource\\Enemy\\EnemyBullet2.png";
				std::string BulletResourcePath3 = "Resource\\Enemy\\EnemyBullet3.png";
				std::vector<std::string> path{ BulletResourcePath,BulletResourcePath2,BulletResourcePath3 };

				int bulletLocationX = m_Location.first;
				int bulletLocationY = m_Location.second + leftGunoffetY + 70;
				Bullet HelicopterBullet(bulletLocationX, bulletLocationY, 0, 5, 10, 0.5, path);
				_bulletList.push_forward(std::move(HelicopterBullet));
			}
			if (!rightGun.IsDead())
			{
				std::string BulletResourcePath = "Resource\\Enemy\\EnemyBullet1.png";
				std::string BulletResourcePath2 = "Resource\\Enemy\\EnemyBullet2.png";
				std::string BulletResourcePath3 = "Resource\\Enemy\\EnemyBullet3.png";
				std::vector<std::string> path{ BulletResourcePath,BulletResourcePath2,BulletResourcePath3 };
		
				int bulletLocationX = m_Location.first + rightGunGoffetX+40;
				int bulletLocationY = m_Location.second + rightGunGoffetY + 70;
				Bullet HelicopterBullet(bulletLocationX, bulletLocationY, 0, 5, 10, 0.5, path);
				_bulletList.push_forward(std::move(HelicopterBullet));
			}
		}
		else
		{
			currentGunDelay--;
		}

		if (currentSecondHeartGunDelay==0)
		{
			currentSecondHeartGunDelay = secondHeartGunDelay;
			int bulletLocationX = m_Location.first + SecondHeartoffsetX + 40;
			int bulletLocationY = m_Location.second + SecondHeartoffsetY + 70;

			float bulletSpeedXDirection = (_Target.first - bulletLocationX) / 1000;
			float bulletSpeedYDirection = (_Target.second - bulletLocationY) / 1000;
			float bulletSpeedX = bulletSpeedXDirection * 10;
			float bulletSpeedY = bulletSpeedYDirection * 10;

			std::string BulletResourcePath = "Resource\\Boss\\normalBullet.png";
			std::string BulletResourcePath2 = "Resource\\Boss\\normalBullet2.png";
			std::string BulletResourcePath3 = "Resource\\Boss\\normalBullet3.png";
			std::vector<std::string> path{ BulletResourcePath,BulletResourcePath2,BulletResourcePath3 };


			Bullet HelicopterBullet(bulletLocationX, bulletLocationY, bulletSpeedX, bulletSpeedY, 10, 0.5, path);
			_bulletList.push_forward(std::move(HelicopterBullet));
		}
		else
		{
			currentSecondHeartGunDelay--;
		}

		if (m_Location.first<=100)
		{
			m_Speed.first = 1;
		}
		if (m_Location.first>300)
		{
			m_Speed.first = -1;
		}
	}
	m_Location.first += m_Speed.first;
	m_Location.second += m_Speed.second;
	UpdateLocation(m_Location.first, m_Location.second);
	if (leftShiled.IsDead()&&rightShiled.IsDead())
	{
		secondHeartGunDelay = 40;
		m_bossState = BossState::Stage2;
		CilcleChangeGun = true;
	}
}

void BossEnemy::Stage2(BulletList &_bulletList, std::pair<float, float> _Target)
{
	if (m_Location.first>200)
	{
		m_Location.first--;
	}
	else if (m_Location.first<200)
	{
		m_Location.first++;
	}
	UpdateLocation(m_Location.first, m_Location.second);
	if (currentSecondHeartGunDelay == 0)
	{
		currentSecondHeartGunDelay = secondHeartGunDelay;
		if (!secondHeart.IsDead())
		{
			if (changeGun)
			{
				changeGun = !changeGun;

				if (!leftGun.IsDead())
				{
					int bulletLocationX = m_Location.first;
					int bulletLocationY = m_Location.second + leftGunoffetY + 70;

					float bulletSpeedXDirection = (_Target.first - bulletLocationX) / 1000;
					float bulletSpeedYDirection = (_Target.second - bulletLocationY) / 1000;
					float bulletSpeedX = bulletSpeedXDirection * 10;
					float bulletSpeedY = bulletSpeedYDirection * 10;

					std::string BulletResourcePath = "Resource\\Enemy\\EnemyBullet1.png";
					std::string BulletResourcePath2 = "Resource\\Enemy\\EnemyBullet2.png";
					std::string BulletResourcePath3 = "Resource\\Enemy\\EnemyBullet3.png";
					std::vector<std::string> path{ BulletResourcePath,BulletResourcePath2,BulletResourcePath3 };

					Bullet HelicopterBullet(bulletLocationX, bulletLocationY, bulletSpeedX, bulletSpeedY, 10, 0.5, path);
					_bulletList.push_forward(std::move(HelicopterBullet));
				}
				if (!rightGun.IsDead())
				{
					int bulletLocationX = m_Location.first + rightGunGoffetX + 40;
					int bulletLocationY = m_Location.second + rightGunGoffetY + 70;

					float bulletSpeedXDirection = (_Target.first - bulletLocationX) / 1000;
					float bulletSpeedYDirection = (_Target.second - bulletLocationY) / 1000;
					float bulletSpeedX = bulletSpeedXDirection * 10;
					float bulletSpeedY = bulletSpeedYDirection * 10;

					std::string BulletResourcePath = "Resource\\Enemy\\EnemyBullet1.png";
					std::string BulletResourcePath2 = "Resource\\Enemy\\EnemyBullet2.png";
					std::string BulletResourcePath3 = "Resource\\Enemy\\EnemyBullet3.png";
					std::vector<std::string> path{ BulletResourcePath,BulletResourcePath2,BulletResourcePath3 };

					
					Bullet HelicopterBullet(bulletLocationX, bulletLocationY, bulletSpeedX, bulletSpeedY, 10, 0.5, path);
					_bulletList.push_forward(std::move(HelicopterBullet));
				}
			}
			else
			{
				changeGun = !changeGun;
				std::string BulletResourcePath = "Resource\\Boss\\normalBullet.png";
				std::string BulletResourcePath2 = "Resource\\Boss\\normalBullet2.png";
				std::string BulletResourcePath3 = "Resource\\Boss\\normalBullet3.png";
				std::vector<std::string> path{ BulletResourcePath,BulletResourcePath2,BulletResourcePath3 };

				int bulletLocationX = m_Location.first + SecondHeartoffsetX + 40;
				int bulletLocationY = m_Location.second + SecondHeartoffsetY + 70;
				Bullet HelicopterBullet(bulletLocationX, bulletLocationY, -3, 5, 10, 0.5, path);
				Bullet HelicopterBullet1(bulletLocationX, bulletLocationY, -1, 5, 10, 0.5, path);
				Bullet HelicopterBullet2(bulletLocationX, bulletLocationY, 0, 5, 10, 0.5, path);
				Bullet HelicopterBullet3(bulletLocationX, bulletLocationY, 1, 5, 10, 0.5, path);
				Bullet HelicopterBullet4(bulletLocationX, bulletLocationY, 3, 5, 10, 0.5, path);
				_bulletList.push_forward(std::move(HelicopterBullet));
				_bulletList.push_forward(std::move(HelicopterBullet1));
				_bulletList.push_forward(std::move(HelicopterBullet2));
				_bulletList.push_forward(std::move(HelicopterBullet3));
				_bulletList.push_forward(std::move(HelicopterBullet4));
			}
		}
	}
	else
	{
		currentSecondHeartGunDelay--;
	}

	if (currentFirstHeartGunDelay==0)
	{
		if (CilcleChangeGun)
		{
			currentGun--;
			if (currentGun <= 0)
			{
				currentGun = CicleGunNum/4;
				CilcleChangeGun = !CilcleChangeGun;
			}
			else
			{
				currentFirstHeartGunDelay = CicleGunDelay;
				std::string BulletResourcePath = "Resource\\Boss\\normalBullet.png";
				std::string BulletResourcePath2 = "Resource\\Boss\\normalBullet2.png";
				std::string BulletResourcePath3 = "Resource\\Boss\\normalBullet3.png";
				std::vector<std::string> path{ BulletResourcePath,BulletResourcePath2,BulletResourcePath3 };
				int bulletLocationX = m_Location.first + firstHeartoffsetX + 30;
				int bulletLocationY = m_Location.second + firstHeartoffsetY + 20;

				float cicleSpeedx = cos(2 * PI / CicleGunNum * currentGun) * 2;
				float cicleSpeedy = sin(2 * PI / CicleGunNum * currentGun) * 2;
				Bullet HelicopterBullet5(bulletLocationX, bulletLocationY, cicleSpeedx, cicleSpeedy, 10, 0.5, path);
				_bulletList.push_forward(std::move(HelicopterBullet5));
			}
		}
		else
		{

			currentGun--;
			if (currentGun <= 0)
			{
				currentGun = CicleGunNum;
				CilcleChangeGun = !CilcleChangeGun;
			}

			currentFirstHeartGunDelay = firstHeartGunDelay;
			std::string BulletResourcePath = "Resource\\Boss\\HeartBullet.png";

			std::vector<std::string> path{ BulletResourcePath };

			int bulletLocationX = m_Location.first + firstHeartoffsetX + 30;
			int bulletLocationY = m_Location.second + firstHeartoffsetY + 20;
			Bullet HelicopterBullet(bulletLocationX, bulletLocationY, 0, 8, 30, 1, path);
			_bulletList.push_forward(std::move(HelicopterBullet));
		}

	}
	else
	{
		currentFirstHeartGunDelay--;
	}
	if (secondHeart.IsDead())
	{
		m_bossState = BossState::State3;
	}
}

void BossEnemy::Stage3(BulletList &_bulletList, std::pair<float, float> _Target)
{
	std::string BulletResourcePath = "Resource\\Boss\\normalBullet.png";
	std::string BulletResourcePath2 = "Resource\\Boss\\normalBullet2.png";
	std::string BulletResourcePath3 = "Resource\\Boss\\normalBullet3.png";
	std::vector<std::string> path{ BulletResourcePath,BulletResourcePath2,BulletResourcePath3 };
	int bulletLocationX = m_Location.first + firstHeartoffsetX + 30;
	int bulletLocationY = m_Location.second + firstHeartoffsetY + 20;
	std::vector<std::string> path2{ "Resource\\Boss\\bossBullet1.png","Resource\\Boss\\bossBullet2.png",
	"Resource\\Boss\\bossBullet3.png","Resource\\Boss\\bossBullet4.png","Resource\\Boss\\bossBullet5.png" };


	if (currentFirstHeartGunDelay == 0)
	{

		Bullet HelicopterBullet(bulletLocationX, bulletLocationY, -3, 5, 10, 0.5, path);
		Bullet HelicopterBullet1(bulletLocationX, bulletLocationY, -1, 5, 10, 0.5, path);
		Bullet HelicopterBullet2(bulletLocationX, bulletLocationY, 0, 5, 10, 0.5, path);
		Bullet HelicopterBullet3(bulletLocationX, bulletLocationY, 1, 5, 10, 0.5, path);
		Bullet HelicopterBullet4(bulletLocationX, bulletLocationY, 3, 5, 10, 0.5, path);
		_bulletList.push_forward(std::move(HelicopterBullet));
		_bulletList.push_forward(std::move(HelicopterBullet1));
		_bulletList.push_forward(std::move(HelicopterBullet2));
		_bulletList.push_forward(std::move(HelicopterBullet3));
		_bulletList.push_forward(std::move(HelicopterBullet4));

		currentFirstHeartGunDelay = firstHeartGunDelay;
		if (currentGun< CicleGunNum /2)
		{
			m_Speed.first = 0;
			m_Speed.second = 0;
			for (int i = 1; i <= CicleGunNum; i++)
			{
				float cicleSpeedx = cos(2 * PI / CicleGunNum * i) * 2;
				float cicleSpeedy = sin(2 * PI / CicleGunNum * i) * 2;
				Bullet HelicopterBullet(bulletLocationX, bulletLocationY, cicleSpeedx, cicleSpeedy, 10, 1, path2);
				_bulletList.push_forward(std::move(HelicopterBullet));
			}
			m_Speed.second = -0.5;
		}
		else 
		{
			if (m_Location.first > 100)
			{
				m_Speed.first=-1;
			}
			else if (m_Location.first < 200)
			{
				m_Speed.first=1;
			}
			m_Speed.second = 1;
			float bulletSpeedXDirection = (_Target.first - bulletLocationX) / 1000;
			float bulletSpeedYDirection = (_Target.second - bulletLocationY) / 1000;
			float bulletSpeedX = bulletSpeedXDirection * 10;
			float bulletSpeedY = bulletSpeedYDirection * 10;
			Bullet HelicopterBullet(bulletLocationX, bulletLocationY, bulletSpeedX, bulletSpeedY, 10, 1.0, path2);
			_bulletList.push_forward(std::move(HelicopterBullet));
		}
		currentGun--;
		if (currentGun<=0)
		{
			currentGun = CicleGunNum;
		}
	}
	else
	{
		currentFirstHeartGunDelay--;
	}
	if (currentfirstHeartGgun2Delay==0)
	{
		currentCicleGun--;
		currentfirstHeartGgun2Delay = firstHeartGgun2Delay;
		if (currentCicleGun <= 0)
		{
			currentCicleGun = CicleGunNum;
		}
		float cicleSpeedx = cos(2 * PI / CicleGunNum * currentCicleGun) * 2;
		float cicleSpeedy = sin(2 * PI / CicleGunNum * currentCicleGun) * 2;
		Bullet HelicopterBullet5(bulletLocationX, bulletLocationY, cicleSpeedx, cicleSpeedy, 10, 0.5, path);
		_bulletList.push_forward(std::move(HelicopterBullet5));
	}
	else
	{
		currentfirstHeartGgun2Delay--;
	}
	if (m_Location.second<0)
	{
		m_Speed.second = 1;
	}
	if (m_Location.second>500)
	{
		m_Speed.second = -1;
	}
	m_Location.first += m_Speed.first;
	m_Location.second += m_Speed.second;
	UpdateLocation(m_Location.first, m_Location.second);

	if (firstheart.IsDead())
	{
		m_bossState = BossState::Dead;
	}
}

void BossEnemy::Update(BulletList &_bulletList, std::pair<float, float> _Target)
{
	switch (m_bossState)
	{
	case BossState::State1:
		Stage1(_bulletList,_Target);
		break;
	case BossState::Stage2:
		Stage2(_bulletList, _Target);
		break;
	case BossState::State3:
		Stage3(_bulletList,_Target);
		break;
	case BossState::Dead:
		DeadAmination();
		break;
	default:
		break;
	}
}

void BossEnemy::UpdateLocation(int _locx, int _locy)
{
	m_Location.first = _locx;
	m_Location.second = _locy;

	sp_Heart.setPosition(m_Location.first, m_Location.second);
	firstheart.SetCenter(m_Location.first + firstHeartoffsetX, m_Location.second + firstHeartoffsetY);

	sp_SecondHeart.setPosition(m_Location.first + SecondHeartoffsetX, m_Location.second + SecondHeartoffsetY);
	secondHeart.SetCenter(m_Location.first + SecondHeartoffsetX, m_Location.second + SecondHeartoffsetY);

	leftGun.SetCenter(m_Location.first + leftGunoffetX, m_Location.second + leftGunoffetY);

	sp_LeftGun.setPosition(m_Location.first + leftGunoffetX, m_Location.second + leftGunoffetY);

	rightGun.SetCenter(m_Location.first + rightGunGoffetX, m_Location.second + rightGunGoffetY);

	sp_RightGun.setPosition(m_Location.first + rightGunGoffetX, m_Location.second + rightGunGoffetY);

	rightShiled.SetCenter(m_Location.first + rightShiledoffetX, m_Location.second + rightShiledoffetY);
	sp_RightShield.setPosition(m_Location.first + rightShiledoffetX, m_Location.second + rightShiledoffetY);

	leftShiled.SetCenter(m_Location.first + leftShiledoffetX, m_Location.second + leftShiledoffetY);
	sp_LeftShield.setPosition(m_Location.first + leftShiledoffetX, m_Location.second + leftShiledoffetY);
}

void BossEnemy::DeadAmination()
{
	death = true;
	ShouldRemove = true;
}
