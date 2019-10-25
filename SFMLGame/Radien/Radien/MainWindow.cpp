#pragma once
#include "MainWindow.h"
#include "iostream"
#include <SFML/Graphics.hpp>
#include <string>
#include "NormalEnemy.cpp"

void MainWindows::showScore()
{
	std::cout <<"Game Score: " << gameData.Score << std::endl;
}

void MainWindows::Draw()
{
	renderWindow.draw(m_bgSprite);
	m_Player.Draw(renderWindow);
	HeroBulletList.Draw(renderWindow);
	EnemyBulletList.Draw(renderWindow);
	for (auto &normalEnmy : normalEnemyList)
	{
		normalEnmy.Draw(renderWindow);

	}
	for (auto & helicopter:helicopterList)
	{
		helicopter.Draw(renderWindow);
	}
	for (auto & bigEnemy:bigEnemyList)
	{
		bigEnemy.Draw(renderWindow);
	}

	renderWindow.display();
}

void MainWindows::ProcessInput()
{
	
	sf::Event event;
	while (renderWindow.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			renderWindow.close();
			BWindowsShouldOver = true;
		}
	}
	m_Player.ProcessInput(WindowsWidth,WindowsHeigth);
}

void MainWindows::Prompt_info(short _x, short _y)
{

}

void MainWindows::DrawInfomation(short _x, short _y)
{
	int initialX = 0, initialY = 0;
	int CharacterSize = 24;
	sf::Text text;
	text.setFont(sfFont);
	text.setCharacterSize(CharacterSize);
	if (textAnDelay == 0)
	{

		textAnFrame = (textAnFrame + 1) % 3;
		textAnDelay = 5;
	}
	switch (textAnFrame)
	{
	case 0:
		text.setFillColor(sf::Color(255, 0, 0, 255));
		break;
	case 1:
		text.setFillColor(sf::Color(0, 255, 255, 255));
		break;
	case 2:
		text.setFillColor(sf::Color(0, 0, 255, 255));
		break;
	default:
		break;
	}

	text.setStyle(sf::Text::Bold);

	text.setPosition(_x + initialX, _y + initialY);
	text.setString(L"■游戏说明 : ");
	renderWindow.draw(text);
	initialY += CharacterSize;

	text.setPosition(_x + initialX, _y + initialY);
	text.setString(L" A.蛇身自撞，游戏结束)");
	renderWindow.draw(text);
	initialY += CharacterSize;

	text.setPosition(_x + initialX, _y + initialY);
	text.setString(L" B.蛇撞到墙，游戏结束)");
	renderWindow.draw(text);
	initialY += CharacterSize;

	text.setPosition(_x + initialX, _y + initialY);
	text.setString(L" C.蛇头吃掉水果，增加分数)");
	renderWindow.draw(text);
	initialY += CharacterSize;
	textAnDelay--;
	

	
	text.setPosition(_x + initialX, _y + initialY);
	std::wstring score(L"GAME SCORE : ");
	score = score + std::to_wstring(gameData.Score);

	text.setString(score);
	renderWindow.draw(text);

}

void MainWindows::GameLogic()
{
	SpawnNormalEnemyDelay--;
	if (SpawnNormalEnemyDelay == 0)
	{
		SpawnNormalEnemyDelay = 60;
		SpawnNormalEnemy();
	}
	for (auto &normalEnmy:normalEnemyList)
	{
		normalEnmy.Update(WindowsWidth, WindowsHeigth);
		HeroBulletList.DamageTest(normalEnmy);
		if (normalEnmy.Hit(m_Player.GetCollision()))
		{
			m_Player.Damage(100);
		}
	}

	SpawnHelicopterDelay--;
	if (SpawnHelicopterDelay == 0)
	{
		SpawnHelicopterDelay = 120;
		SpawnnHelicopter();
	}
	for (auto &helicopter:helicopterList)
	{
		helicopter.Update(WindowsWidth, WindowsHeigth);
		HeroBulletList.DamageTest(helicopter);
		if (helicopter.Hit(m_Player.GetCollision()))
		{
			m_Player.Damage(100);
		}
	}
	helicopterWeaponDelay--;
	if (helicopterWeaponDelay == 0)
	{
		helicopterWeaponDelay = Helicopter::shootDelay;
		for (auto helicopter : helicopterList)
		{
			//EnemyBulletList.push_forward(helicopter.Shoot(m_Player.GetLocation(), 5));
		}
		for (auto &bigEnemy : bigEnemyList)
		{
			bigEnemy.Shoot(EnemyBulletList, m_Player.GetLocation(), 10);
		}
	}

	for (auto &bigEnemy:bigEnemyList)
	{
		bigEnemy.Update(WindowsWidth, WindowsHeigth);
		HeroBulletList.DamageTest(bigEnemy);
	}

	EnemyBulletList.UpdateBullets(WindowsWidth, WindowsHeigth);
	EnemyBulletList.DamageTest(m_Player);

	weaponDelay--;
	if (weaponDelay==0)
	{
		weaponDelay = m_Player.GetWeaponDelay();
		HeroBulletList.push_forward(m_Player.Shoot());
	}
	HeroBulletList.UpdateBullets(WindowsWidth, WindowsHeigth);

	normalEnemyList.remove_if([](NomalEnemy &enemy) { return enemy.IsRemove(); });
	helicopterList.remove_if([](Helicopter &enemy) { return enemy.IsRemove(); });
	bigEnemyList.remove_if([](BigEnemy &enemy) { return enemy.IsRemove(); });
}


void MainWindows::SpawnNormalEnemy()
{
	float locX = std::rand() % (WindowsWidth-50);
	float locY = 0;
	std::string path = "Resource\\Enemy\\NormalEnemy.png";
	for (int i=0;i<3;i++)
	{
		NomalEnemy newEnemy(locX, locY-i*50, 0, 5, path, 100, 0.5);
		normalEnemyList.push_back(std::move(newEnemy));
	}
}

void MainWindows::SpawnnHelicopter()
{
	int random = rand() % 2;
	float locX = random* (WindowsWidth - 50);
	float locY = 0;
	std::string path = "Resource\\Enemy\\Helicopter.png";
	Helicopter newEnemy(locX, locY,1- random*2, 1, path, 300,1);
	helicopterList.push_back(std::move(newEnemy));

}

void MainWindows::SpawnBigEnemy()
{
	float locX = WindowsWidth / 2;
	float locY = 0;
	std::string path1 = "Resource\\Enemy\\BigEnemy1.png";
	std::string path2 = "Resource\\Enemy\\BigEnemy2.png";
	std::vector<std::string> path{ path1,path2};
	BigEnemy newEnemy(locX, locY,0, 1, path, 3000, 1);
	bigEnemyList.push_back(std::move(newEnemy));
}

MainWindows::MainWindows(short _Width, short _Height, const std::string& nameOfWindows)	:

	renderWindow(sf::VideoMode(_Width, _Height), nameOfWindows),
	m_currentRect(0, 700, _Width, _Height)
{
	WindowsWidth = _Width;
	WindowsHeigth = _Height;
	BWindowsShouldOver = false;
	//初始化蛇
	short length = 6;

}

void MainWindows::Initial()
{
	renderWindow.setFramerateLimit(60);
	normalEnemyList.clear();
	helicopterList.clear();
	EnemyBulletList.Clear();
	HeroBulletList.Clear();
	bigEnemyList.clear();
	LoadResource();
	m_Player.inilize(0, WindowsHeigth-100, "Resource\\Hero\\Hero.png", "Resource\\Hero\\Trail.png", "Resource/Bullet/normalGun.png", 100,0.5);
	gameData.Score = 0;
	gameData.BisGameOver = false;
	helicopterWeaponDelay = Helicopter::shootDelay;
	weaponDelay = m_Player.GetWeaponDelay();
	SpawnBigEnemy();
}

void MainWindows::TickFrame()
{
	GameLogic();
	Draw();
	ProcessInput();
	UpdateBackGround();


	if (m_Player.Death())
	{
		gameData.BisGameOver = true;
	}
}

void MainWindows::UpdateBackGround()
{

	m_currentRect.top -= 1;
	if (m_currentRect.top<0)
	{
		m_currentRect.top = 700;
	}

	m_bgSprite.setTextureRect(m_currentRect);
}

void MainWindows::LoadResource()
{
	m_backGround.loadFromFile("Resource\\BG\\background.jpg");
	m_bgSprite.setTexture(m_backGround);
	m_bgSprite.setPosition(0, 0);
}

