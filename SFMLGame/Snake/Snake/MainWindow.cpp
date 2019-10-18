#pragma once
#include "MainWindow.h"
#include "iostream"
#include <SFML/Graphics.hpp>
#include <string>
void MainWindows::showScore()
{
	std::cout <<"Game Score: " << gameData.Score << std::endl;
}

void MainWindows::Draw()
{
	int detaX = UintSize;
	int detaY = UintSize;
	renderWindow.clear();
	m_SpriteBackground.setScale(0.5, 0.5);
	for (int i=0;i<WindowsWidth;i++)
	{
		for (int j=0;j<WindowsHeigth ;j++)
		{
			m_SpriteBackground.setPosition(i*UintSize,j*UintSize);
			renderWindow.draw(m_SpriteBackground);
		}
	}

	short locX = 0;
	short locY = 0;
	m_Snake.GetHeadLoc(locX, locY);
	m_SnakeHeadSprite.setScale(0.2, 0.2);
	m_SnakeHeadSprite.setPosition(locX*UintSize-25, locY*UintSize-25);
//	m_SnakeHeadSprite.setRotation((int)m_Snake.GetDirection());
	renderWindow.draw(m_SnakeHeadSprite);

	m_SnakeTailSprite.setScale(0.5, 0.5);
	//减去头的长度
	std::vector<std::pair<short, short>> TailLoc(m_Snake.GetLength()-1);
	m_Snake.GetTailLoc(TailLoc);
	for (auto location:TailLoc)
	{
		m_SnakeTailSprite.setPosition(location.first*UintSize, location.second*UintSize);
		renderWindow.draw(m_SnakeTailSprite);
	}

	m_fruits.GetLoc(locX, locY);
	//水果图片尺寸不对，需要偏移以下
	float fruitsPictureOffset = 12.5;
	m_SpriteFruit.setPosition(locX*UintSize- fruitsPictureOffset,locY*UintSize- fruitsPictureOffset);
	renderWindow.draw(m_SpriteFruit);

	DrawInfomation(WindowsWidth*UintSize, 0);
	renderWindow.display();
}

void MainWindows::ProcessInput()
{
	sf::Event event;
	while (renderWindow.pollEvent(event))
	{
		if (event.type==sf::Event::Closed)
		{
			renderWindow.close();
			BWindowsShouldOver = true;
		}
	}
	SnakeDirection dir = m_Snake.GetDirection();
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (dir != SnakeDirection::RIGHT)
			dir = SnakeDirection::LEFT;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (dir != SnakeDirection::DOWN)
			dir = SnakeDirection::UP;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (dir != SnakeDirection::UP)
			dir = SnakeDirection::DOWN;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (dir != SnakeDirection::LEFT)
			dir = SnakeDirection::RIGHT;
	}
		
	m_Snake.SetDirection(dir);
	delay--;
	if (delay==0)
	{
		GameLogic();
		delay = 10;
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
	short newX, newY;
	m_Snake.GetHeadLoc(newX, newY);
	SnakeDirection snakeDir = m_Snake.GetDirection();

	switch (snakeDir)
	{
	case SnakeDirection::STOP:
		break;
	case SnakeDirection::LEFT:
		newX-= 1;
		break;
	case SnakeDirection::RIGHT:
		newX+= 1;
		break;
	case SnakeDirection::UP:
		newY-= 1;
		break;
	case SnakeDirection::DOWN:
		newY+= 1;
		break;
	default:
		break;
	}

	if (newX>= WindowsWidth||newX<0||newY<0|| newY >= WindowsHeigth)
	{
		//撞到墙上死亡判断
		gameData.BisGameOver = true;
	}
	if (m_Snake.BIsSameTrialLoc(newX,newY))
	{
		//咬到蛇尾上面了 
		gameData.BisGameOver = true;
	}
	if (m_fruits.BIsSameLoc(newX,newY))
	{
	//这里比较难理解的地方是
	//如果蛇吃掉水果后，我们要增加蛇尾的长度，所以这里就不删除旧的最后一个蛇尾
		gameData.Score++;
		m_Snake.AddLength(1);
		initalFruits();
	}
	else
	{
		//相反，没有吃掉水果，那么我们应该删掉最后一个旧位置上的蛇尾
		m_Snake.pop_back();
	}
	if (snakeDir != SnakeDirection::STOP)
	{
		//更新蛇头位置
		m_Snake.push_forward(newX, newY);
		
	}
}

void MainWindows::initalFruits()
{
	short newfruitsX =-1;
	short newfruitsY =-1;
	bool isNotSuccessed = true;
	while (isNotSuccessed)
	{
		newfruitsX = rand() % WindowsWidth;
		newfruitsY = rand() % WindowsHeigth;
		if (newfruitsX >= WindowsWidth-1 || newfruitsX <= 1||newfruitsY >= WindowsHeigth||newfruitsY<=1)
		{
			//生成正在墙壁上了，重新生成
			continue;
		}
		if (m_Snake.BIsSameHeadLoc(newfruitsX,newfruitsY)||m_Snake.BIsSameTrialLoc(newfruitsX,newfruitsY))
		{
			//生成在蛇身上了,重新生成
			continue;
		}
		m_fruits.Setloc(newfruitsX, newfruitsY);
		isNotSuccessed = false;
	}
}

MainWindows::MainWindows(short _Width, short _Height,short _uintSize, const std::string& nameOfWindows)	:
	UintSize(_uintSize),
	m_Snake(_Width / 2, _Height / 2),
	renderWindow(sf::VideoMode(_uintSize*(_Width+15), _uintSize*_Height), nameOfWindows)
{
	WindowsWidth = _Width;
	WindowsHeigth = _Height;

	
	//初始化蛇
	short length = 6;

}

void MainWindows::Initial()
{
	renderWindow.setFramerateLimit(60);
	gameData.Score = 0;
	gameData.BisGameOver = false;
	m_Snake.init();
	initalFruits();

	m_SnakeHeadSprite.setOrigin(UintSize, UintSize);
	m_SpriteBackground.setOrigin(UintSize, UintSize);
	m_SnakeTailSprite.setOrigin(UintSize, UintSize);

	//加载资源
	m_SnakeHeadTexture.loadFromFile("Resource/images/Face1.png");
	m_SnakeHeadSprite.setTexture(m_SnakeHeadTexture);


	m_SnakeTailTexture.loadFromFile("Resource/images/sb0102.png");
	m_SnakeTailSprite.setTexture(m_SnakeTailTexture);

	m_FruitTexture.loadFromFile("Resource/images/red.png");
	m_SpriteFruit.setTexture(m_FruitTexture);

	m_BackgroundTexture.loadFromFile("Resource/images/BK.png");
	m_SpriteBackground.setTexture(m_BackgroundTexture);

	sfFont.loadFromFile("Resource/Fonts/ARCADE.TTF");
}

void MainWindows::TickFrame()
{
	Draw();
	ProcessInput();
}

