#pragma once
#include "MainWindow.h"
#include "iostream"
#include <SFML/Graphics.hpp>
#include <string>
#include "NormalEnemy.cpp"
#include "Actor.h"
void MainWindows::DrawScore()
{
	int CharacterSize = 24;
	sf::Text text;
	text.setFont(sfFont);
	text.setCharacterSize(CharacterSize);
	text.setFillColor(sf::Color(255, 255, 255, 255));
	text.setPosition(WindowsWidth-120 , 0);
	text.setString("SCORE");
	renderWindow.draw(text);



	std::string score = std::to_string(currentShowScore);
	text.setPosition(WindowsWidth - 100, CharacterSize);
	if (currentShowScore!=gameData.Score)
	{
		currentShowScore++;
		if (textAnDelay == 0)
		{

			textAnFrame = (textAnFrame + 1) % 3;
			textAnDelay = 5;
		}
		textAnDelay--;
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
	}
	
	text.setString(score);
	renderWindow.draw(text);


}

void MainWindows::DrawGaming()
{
	renderWindow.draw(m_bgSprite);
	renderWindow.draw(m_HPofHeroSprite);
	m_Player.Draw(renderWindow);

	if (gameStage == GameStage::Boss)
	{
		boss.Draw(renderWindow);
	}

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
	for (auto & missle:missleEnemyList)
	{
		missle.Draw(renderWindow);
	}
	for (auto& death:DeathAnimation)
	{
		death.Play(renderWindow,sfFont);
	}
	
}

void MainWindows::Drawinitialize()
{

	renderWindow.draw(m_bgSprite);
	int CharacterSize = 48;
	sf::Text text;
	text.setFont(sfFont);
	text.setCharacterSize(CharacterSize);
	text.setFillColor(sf::Color(255, 255, 255, 255));
	text.setPosition(WindowsWidth / 2 - 50, WindowsHeigth / 2 - 150);
	text.setString(L"Radient");
	renderWindow.draw(text);

	if (textAnDelay == 0)
	{

		textAnFrame = (textAnFrame + 1) % 3;
		textAnDelay = 5;
	}
	textAnDelay--;
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
	text.setCharacterSize(CharacterSize/2);
	text.setPosition(WindowsWidth/2-75, WindowsHeigth/2-100);
	text.setString(L"-->E N T E R<--");
	renderWindow.draw(text);
	m_Player.Draw(renderWindow);
	

}

void MainWindows::DrawGameOver()
{
	renderWindow.draw(m_bgSprite);
	for (auto& death : DeathAnimation)
	{
		death.Play(renderWindow, sfFont);
	}
	DeathAnimation.remove_if([](Animation &enemy) { return enemy.ShouldRemove(); });

	if (DeathAnimation.size()==0)
	{

		int gameoverLocationY = WindowsHeigth / 2 - 100;
		sf::Text text;
		int CharacterSize = 48;
		text.setFont(sfFont);
		text.setCharacterSize(CharacterSize);
		text.setFillColor(sf::Color(255, 255, 255, 255));
		text.setPosition(WindowsWidth / 2 - 80, gameoverLocationY);
		text.setString(L"GAME OVER");
		renderWindow.draw(text);

		text.setPosition(WindowsWidth / 2 - 80, gameoverLocationY + CharacterSize);
		text.setString("SCORE:" + std::to_string(gameData.Score));
		if (textAnDelay == 0)
		{

			textAnFrame = (textAnFrame + 1) % 3;
			textAnDelay = 5;
		}
		textAnDelay--;

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
		renderWindow.draw(text);

		text.setFillColor(sf::Color(255, 255, 255, 255));
		text.setStyle(sf::Text::Bold);
		text.setCharacterSize(CharacterSize / 2);
		text.setPosition(WindowsWidth / 2 - 80, gameoverLocationY + CharacterSize * 3);
		text.setString(L"- - >R RePlay< - -");
		renderWindow.draw(text);
		text.setCharacterSize(CharacterSize / 2);
		text.setPosition(WindowsWidth / 2 - 50, gameoverLocationY + CharacterSize * 4);
		text.setString(L"-->Q Leave<--");
		renderWindow.draw(text);
	}
}

void MainWindows::DrawGamePause()
{

	
	int CharacterSize = 48;
	sf::Text text;
	text.setFont(sfFont);
	text.setCharacterSize(CharacterSize);
	text.setFillColor(sf::Color(255, 255, 255, 255));
	text.setPosition(WindowsWidth / 2 - 50, WindowsHeigth / 2 - 150);
	text.setString(L"PAUSE");
	renderWindow.draw(text);

	textAnFrame = (textAnFrame + 1) % 3;

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
	text.setCharacterSize(CharacterSize / 2);
	text.setPosition(WindowsWidth / 2 - 75, WindowsHeigth / 2 - 100);
	text.setString(L"-->E N T E R<--");
	renderWindow.draw(text);

}

void MainWindows::DrawGameWin()
{
	renderWindow.draw(m_bgSprite);
	for (auto& death : DeathAnimation)
	{
		death.Play(renderWindow, sfFont);
	}
	DeathAnimation.remove_if([](Animation &enemy) { return enemy.ShouldRemove(); });

	if (DeathAnimation.size() == 0)
	{

		int gameoverLocationY = WindowsHeigth / 2 - 100;
		sf::Text text;
		int CharacterSize = 48;
		text.setFont(sfFont);
		text.setCharacterSize(CharacterSize);
		text.setFillColor(sf::Color(255, 255, 255, 255));
		text.setPosition(WindowsWidth / 2 - 80, gameoverLocationY);
		text.setString(L"YOU WIN!!!!");
		renderWindow.draw(text);

		text.setPosition(WindowsWidth / 2 - 80, gameoverLocationY + CharacterSize);
		text.setString("SCORE:" + std::to_string(gameData.Score));
		if (textAnDelay == 0)
		{

			textAnFrame = (textAnFrame + 1) % 3;
			textAnDelay = 5;
		}
		textAnDelay--;

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
		renderWindow.draw(text);

		text.setFillColor(sf::Color(255, 255, 255, 255));
		text.setStyle(sf::Text::Bold);
		text.setCharacterSize(CharacterSize / 2);
		text.setPosition(WindowsWidth / 2 - 80, gameoverLocationY + CharacterSize * 3);
		text.setString(L"- - >R RePlay< - -");
		renderWindow.draw(text);
		text.setCharacterSize(CharacterSize / 2);
		text.setPosition(WindowsWidth / 2 - 50, gameoverLocationY + CharacterSize * 4);
		text.setString(L"-->Q Leave<--");
		renderWindow.draw(text);
	}
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

	switch (gameState)
	{
	case GameState::Gaming:
		m_Player.ProcessInput(WindowsWidth, WindowsHeigth);
		break;
	case GameState::GameOver:
		break;
	case GameState::GameInitialize:
		m_Player.ProcessInput(WindowsWidth, WindowsHeigth);
		break;
	default:
		break;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)&&(gameState==GameState::GameInitialize|| gameState == GameState::GamePause))
	{
		//��Ϸ��ͣ���ʼ��ʱ����ENTER ������Ϸ
		gameState = GameState::Gaming;
		renderWindow.setFramerateLimit(60);

		if (GamingBG.getStatus() != GamingBG.Playing)
		{
			GamingBG.setLoop(true);
			GamingBG.play();
		}
		mapBG.pause();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) && (gameState == GameState::Gaming))
	{
		//����P ������Ϸ��ͣ
		gameState = GameState::GamePause;
		renderWindow.setFramerateLimit(10);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && (gameState == GameState::GameOver || gameState == GameState::GameWin))
	{
		BWindowsShouldOver = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && (gameState == GameState::GameOver|| gameState == GameState::GameWin))
	{
		gameData.BisGameOver = true;
		gameState = GameState::GameInitialize;
	}
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
	text.setString(L"����Ϸ˵�� : ");
	renderWindow.draw(text);
	initialY += CharacterSize;

	text.setPosition(_x + initialX, _y + initialY);
	text.setString(L" A.������ײ����Ϸ����)");
	renderWindow.draw(text);
	initialY += CharacterSize;

	text.setPosition(_x + initialX, _y + initialY);
	text.setString(L" B.��ײ��ǽ����Ϸ����)");
	renderWindow.draw(text);
	initialY += CharacterSize;

	text.setPosition(_x + initialX, _y + initialY);
	text.setString(L" C.��ͷ�Ե�ˮ�������ӷ���)");
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
	gameData.gameRate += gameData.gameSpeed;
	switch (gameStage)
	{
	case GameStage::Stage1:
		GameStage1();
		break;
	case GameStage::Stage2:
		GameStage2();
		break;
	case GameStage::Stage3:
		GameStage3();
		break;
	case GameStage::Stage4:
		GameStage4();
		break;
	case GameStage::Stage5:
		GameStage5();
		break;
	case GameStage::Boss:
		Boss();
		break;
	default:
		break;
	}


	//������ɱ����list��ʱ���� hero�ӵ�����һ�ν�����ײ��⣬��������ҽ�����ײ���
	for (auto &normalEnmy:normalEnemyList)
	{
		normalEnmy.Update(WindowsWidth, WindowsHeigth);
		HeroBulletList.DamageTest(normalEnmy);
		if (normalEnmy.Hit(m_Player.GetCollision()))
		{
			m_Player.Damage(50);
		}
		if (normalEnmy.IsDead())
		{
			gameData.Score += normalEnmy.GetScore();
			DeathAnimation.push_back(std::move(normalEnmy.SpawnDeathAnimation(0,0,2,0.5)));
		}
	}

	for (auto &helicopter:helicopterList)
	{
		helicopter.Update(WindowsWidth, WindowsHeigth,m_Player.GetLocation(),EnemyBulletList);
		HeroBulletList.DamageTest(helicopter);
		if (helicopter.Hit(m_Player.GetCollision()))
		{
			m_Player.Damage(50);
		}
		if (helicopter.IsDead())
		{
			gameData.Score += helicopter.GetScore();
			DeathAnimation.push_back(std::move(helicopter.SpawnDeathAnimation(0,0,2,0.7)));
		}
	}
	
	//���͵л���ֱ��������
	for (auto &bigEnemy:bigEnemyList)
	{
		bigEnemy.Update(WindowsWidth, WindowsHeigth,EnemyBulletList,m_Player.GetLocation());
		HeroBulletList.DamageTest(bigEnemy);

		if (bigEnemy.IsDead())
		{
			gameData.Score += bigEnemy.GetScore();
			DeathAnimation.push_back(std::move(bigEnemy.SpawnDeathAnimation(0,0,2,3)));
		}
	}

	for (auto &MissleEnemy : missleEnemyList)
	{
		MissleEnemy.Update(WindowsWidth, WindowsHeigth, m_Player.GetLocation());
		HeroBulletList.DamageTest(MissleEnemy);
		if (MissleEnemy.Hit(m_Player.GetCollision()))
		{
			m_Player.Damage(50);
			MissleEnemy.Detory();

		}
		if (MissleEnemy.IsDead())
		{
			gameData.Score += MissleEnemy.GetScore();
			DeathAnimation.push_back(std::move(MissleEnemy.SpawnDeathAnimation(0, 0, 2, 0.5)));
		}
	}

	//���о��������ӵ������Hero������ײ���
	EnemyBulletList.UpdateBullets(WindowsWidth, WindowsHeigth);
	EnemyBulletList.DamageTest(m_Player);

	//����������
	weaponDelay--;
	if (weaponDelay==0)
	{
		
		weaponDelay = m_Player.GetWeaponDelay();
		m_Player.Shoot(HeroBulletList);
		
		
	}
	HeroBulletList.UpdateBullets(WindowsWidth, WindowsHeigth);

	//��ײ��������ɾ��
	normalEnemyList.remove_if([](NomalEnemy &enemy) { return enemy.IsRemove(); });
	helicopterList.remove_if([](Helicopter &enemy) { return enemy.IsRemove(); });
	bigEnemyList.remove_if([](BigEnemy &enemy) { return enemy.IsRemove(); });
	missleEnemyList.remove_if([](Missle &enemy) { return enemy.IsRemove(); });
	bossList.remove_if([](Actor *enemy) { return enemy->IsRemove(); });
	DeathAnimation.remove_if([](Animation &enemy) { return enemy.ShouldRemove(); });

	//��ȡ����


	if (m_Player.Death())
	{
		//���������Ϸ����
		gameState = GameState::GameOver;
		DeathAnimation.push_back(m_Player.SpawnDeathAnimation(0,0,2,2));
	}
}

void MainWindows::SpawnNormalEnemy()
{
	//������ɱ�����ɻ����߼�
	float locX = std::rand() % (WindowsWidth-50);
	float locY = 0;
	std::string path = "Resource\\Enemy\\NormalEnemy.png";
	for (int i=0;i<3;i++)
	{
		NomalEnemy newEnemy(locX, locY-i*50, 0, 5, path, 100,10, 0.5);
		normalEnemyList.push_back(std::move(newEnemy));
	}
}

void MainWindows::SpawnnHelicopter()
{
	//ֱ���������߼�
	int random = rand() % 2;
	float locX = random* (WindowsWidth - 50);
	float locY = 0;
	std::string path = "Resource\\Enemy\\Helicopter.png";
	Helicopter newEnemy(locX, locY,1- random*2, 1, path, 300,20,1);
	helicopterList.push_back(std::move(newEnemy));

}

void MainWindows::SpawnBigEnemy()
{
	//���͵л������߼�
	float locX = WindowsWidth / 2-100;
	float locY = -100;
	std::string path1 = "Resource\\Enemy\\BigEnemy1.png";
	std::string path2 = "Resource\\Enemy\\BigEnemy2.png";
	std::vector<std::string> path{ path1,path2};
	BigEnemy newEnemy(locX, locY,0, 1, path, 6000,600, 1);
	bigEnemyList.push_back(std::move(newEnemy));
}

void MainWindows::SpawnMissleEnemy(MissleType _type)
{
	//������ɱ�����ɻ����߼�
	float locX = std::rand() % (WindowsWidth - 50);
	float locY = 0;
	std::string path = "Resource\\Enemy\\NormalEnemy.png";

	Missle newEnemy(locX, locY, 0, 5,  150, 10, 0.7,_type);
	missleEnemyList.push_back(std::move(newEnemy));

}

void MainWindows::GameStage1()
{

	//������ɱ�����ӳ��ж�
	currentNormalEnemyDealy--;
	if (currentNormalEnemyDealy == 0)
	{
		currentNormalEnemyDealy = SpawnNormalEnemyDelay;
		SpawnNormalEnemy();
	}

	if (gameData.gameRate >= 1000)
	{
		gameStage = GameStage::Stage2;
		gameData.gameRate = 0;
		SpawnNormalEnemyDelay = 200;
	}

}

void MainWindows::GameStage2()
{
	//ֱ���������ɣ�ͬ����Ҫ�������ӵ�����ҵ���ײ��⣬ֱ����Shoot()���÷�����Update������
	currentHelicopterDelay--;
	if (currentHelicopterDelay == 0)
	{
		currentHelicopterDelay = SpawnHelicopterDelay;
		SpawnnHelicopter();
	}

	currentNormalEnemyDealy--;
	if (currentNormalEnemyDealy == 0)
	{
		currentNormalEnemyDealy = SpawnNormalEnemyDelay;
		SpawnNormalEnemy();
	}

	if (gameData.gameRate >= 1500)
	{
		SpawnBigEnemy();
		gameStage = GameStage::Stage3;
		SpawnNormalEnemyDelay = 300;
		SpawnHelicopterDelay = 300;
	}
}

void MainWindows::GameStage3()
{
	currentHelicopterDelay--;
	if (currentHelicopterDelay == 0)
	{
		currentHelicopterDelay = SpawnHelicopterDelay;
		SpawnnHelicopter();
	}

	currentNormalEnemyDealy--;
	if (currentNormalEnemyDealy == 0)
	{
		currentNormalEnemyDealy = SpawnNormalEnemyDelay;
		SpawnNormalEnemy();
	}
	if (bigEnemyList.size()==0)
	{
		gameStage = GameStage::Stage4;
		gameData.gameRate = 0;
		SpawnNormalEnemyDelay = 50;
		MissleTimeBG.setLoop(true);
		MissleTimeBG.play();
	}
}

void MainWindows::GameStage4()
{	//�����������ӳ��ж�
	currentNormalEnemyDealy--;
	if (currentNormalEnemyDealy == 0)
	{
		currentNormalEnemyDealy = SpawnNormalEnemyDelay;

	
		SpawnMissleEnemy(MissleType::Type2);
		SpawnMissleEnemy(MissleType::Type2);
	}
	if (currentNormalEnemyDealy%30==0)
	{
		SpawnMissleEnemy(MissleType::Type1);
	}

	if (gameData.gameRate < 1500&& gameData.gameRate>1000)
	{
		SpawnNormalEnemyDelay = 200;
		MissleTimeBG.pause();
		currentHelicopterDelay--;
		if (currentHelicopterDelay == 0)
		{
			currentHelicopterDelay = SpawnHelicopterDelay;
			SpawnnHelicopter();
		}

		currentNormalEnemyDealy--;
		if (currentNormalEnemyDealy == 0)
		{
			currentNormalEnemyDealy = SpawnNormalEnemyDelay;
			SpawnNormalEnemy();
			SpawnMissleEnemy(MissleType::Type2);
			SpawnMissleEnemy(MissleType::Type1);
		}
	}
	if (gameData.gameRate>1500)
	{
		gameStage = GameStage::Stage5;
		gameData.gameRate = 0;
		SpawnNormalEnemyDelay = 150;
		WarningBG.play();
		
	}
}

void MainWindows::GameStage5()
{
	
		int CharacterSize = 70;
		sf::Text text;
		text.setFont(sfFont);
		text.setCharacterSize(CharacterSize);
		if (gameData.gameRate % 30 < 15)
		{
			text.setFillColor(sf::Color(255, 0, 0, 255));
		}
		else
		{
			text.setFillColor(sf::Color(0, 0, 0, 255));
		}
		text.setPosition(0, 100);
		text.setString("-----WARNING-----");
		renderWindow.draw(text);
	
	if (WarningBG.getStatus() == WarningBG.Stopped)
	{
		gameStage = GameStage::Boss;
		SpawnNormalEnemyDelay = 70;
		SpawnNumber = 20;
		BossBG.setLoop(true);
		BossBG.play();
		MissleTimeBG.setLoop(false);
		GamingBG.pause();
	}
}

void MainWindows::Boss()
{

	for (auto bossactor:bossList)
	{
		HeroBulletList.DamageTest(*bossactor);
		if (bossactor->IsDead())
		{
			gameData.Score += bossactor->GetScore();
			DeathAnimation.push_back(std::move(bossactor->SpawnDeathAnimation(10, 10, 2, 1)));
		}
	}
	boss.Update(EnemyBulletList,m_Player.GetLocation());
	if (boss.IsDead())
	{
		gameState = GameState::GameWin;
		BossBG.stop();
		GamingBG.play();
	}

	if (boss.GetBossState() == BossState::Stage2 && !State2SpawnMissle)
	{
		currentNormalEnemyDealy--;
		if (MissleTimeBG.getStatus()!=MissleTimeBG.Playing)
		{
			MissleTimeBG.play();
		}
		if (currentNormalEnemyDealy == 0)
		{
			currentNormalEnemyDealy = SpawnNormalEnemyDelay;
			SpawnMissleEnemy(MissleType::Type2);
			SpawnMissleEnemy(MissleType::Type1);
			SpawnNumber-=2;
			if (SpawnNumber == 0)
			{
				MissleTimeBG.stop();
				State2SpawnMissle = true;
				SpawnNumber = 20;
				SpawnNormalEnemyDelay = 50;
			}
		}

	}
	if (boss.GetBossState() == BossState::State3 && !State3SpawnMissle)
	{
		if (MissleTimeBG.getStatus() != MissleTimeBG.Playing)
		{
			MissleTimeBG.play();
		}
		currentNormalEnemyDealy--;
		if (currentNormalEnemyDealy == 0)
		{
			currentNormalEnemyDealy = SpawnNormalEnemyDelay;
			if (SpawnNumber&2==0)
			{
				SpawnMissleEnemy(MissleType::Type1);
			}
			else
			{
				SpawnMissleEnemy(MissleType::Type2);
			}
			SpawnNumber--;
			if (SpawnNumber == 0)
			{
				MissleTimeBG.stop();
				State3SpawnMissle = true;
			}
		}

	}
}

MainWindows::MainWindows(short _Width, short _Height, const std::string& nameOfWindows)	:

	renderWindow(sf::VideoMode(_Width, _Height), nameOfWindows),
	m_currentRect(0, 700, _Width, _Height)
{
	WindowsWidth = _Width;
	WindowsHeigth = _Height;
	BWindowsShouldOver = false;
	//��ʼ����
	short length = 6;

}

void MainWindows::Initial()
{
	renderWindow.setFramerateLimit(60);
	//������������б�
	normalEnemyList.clear();
	helicopterList.clear();
	EnemyBulletList.Clear();
	HeroBulletList.Clear();
	bigEnemyList.clear();

	LoadResource();
	m_Player.inilize(0, WindowsHeigth-100, "Resource\\Hero\\Hero.png", "Resource\\Hero\\Trail.png", "Resource/Bullet/normalGun.png", player_MaxHP,0.5);
	boss.inilize();
	bossList.push_back(&boss.leftGun);
	bossList.push_back(&boss.rightGun);
	bossList.push_back(&boss.leftShiled);
	bossList.push_back(&boss.rightShiled);
	bossList.push_back(&boss.secondHeart);
	bossList.push_back(&boss.firstheart);

	mapBG.play();

	gameData.Score = 0;
	currentShowScore = 0;
	gameData.BisGameOver = false;
	gameData.gameRate = 0;
	gameData.gameSpeed = 1;
	gameStage = GameStage::Stage4;
	helicopterWeaponDelay = Helicopter::shootDelay;
	weaponDelay = m_Player.GetWeaponDelay();
	m_Player.SetCenter(250, 500);

}

void MainWindows::TickFrame()
{
	renderWindow.clear();

	//����Ϸ״̬������Ϸ����
	switch (gameState)
	{
	case GameState::Gaming:	
		DrawGaming();
		UpdateBGandUI();
		GameLogic();
		DrawScore();
		break;
	case GameState::GameOver:
		DrawGameOver();
		
		break;
	case GameState::GameInitialize:
		
		Drawinitialize();
		break;
	case GameState::GamePause:
		DrawGaming();
		DrawScore();
		DrawGamePause();
		break;
	case GameState::GameWin:
		DrawGameWin();
		break;
	default:
		break;
	}
	ProcessInput();

	renderWindow.display();


}

void MainWindows::UpdateBGandUI()
{

	m_currentRect.top -= 1;
	if (m_currentRect.top<0)
	{
		m_currentRect.top = 700;
	}
	m_bgSprite.setTextureRect(m_currentRect);
	int rectWidth = m_HPofHeroImage.getSize().x / player_MaxHP * m_Player.GetHealth();
	sf::IntRect rect(0, 0, rectWidth, m_HPofHeroImage.getSize().y);
	m_HPofHeroSprite.setTextureRect(rect);
}

void MainWindows::LoadResource()
{
	m_backGround.loadFromFile("Resource\\BG\\background.jpg");
	m_bgSprite.setTexture(m_backGround);
	m_bgSprite.setPosition(0, 0);

	m_HPofHeroImage.loadFromFile("Resource\\Hero\\hp.png");
	m_HPofHeroSprite.setTexture(m_HPofHeroImage);
	m_HPofHeroSprite.setPosition(0, WindowsHeigth-30);

	sfFont.loadFromFile("Resource\\Fonts\\ARCADE.TTF");
	
	mapBG.openFromFile("Resource\\Audio\\map.wav");
	GamingBG.openFromFile("Resource\\Audio\\gaming.wav");
	WarningBG.openFromFile("Resource\\Audio\\Waring.wav");
	BossBG.openFromFile("Resource\\Audio\\Boss.wav");
	MissleTimeBG.openFromFile("Resource\\Audio\\Missle.wav");
}

