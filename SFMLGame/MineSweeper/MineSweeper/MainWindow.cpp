#pragma once
#include "MainWindow.h"
#include "iostream"
#include "sfml/Audio.hpp"
#include <sstream>
#include <string>
void MainWindows::showScore()
{
	
}

void MainWindows::Draw()
{
	renderWindow.clear();	//清屏
	//绘制背景
	sBackground.setPosition(0, 0);
	renderWindow.draw(sBackground);
	//绘制舞台
	DrawGrid();
	DrawButton();
	DrawTimer();
	DrawScore();
	if (gameData.BisGameOver)
		DrawGameEnd();
	renderWindow.display();				//把显示缓冲区的内容，显示在屏幕上。SFML采用的是双缓冲机制
}

void MainWindows::DrawGrid()
{

}

void MainWindows::DrawButton()
{
	Vector2i LeftCorner;
	int ButtonWidth = 60;
	int ButtonHeight = 36;
	int detaX;
	detaX = (Window_width - ButtonWidth * 7) / 8;//等分宽度
	LeftCorner.y = Window_height - GRIDSIZE * 3;//指定高度

	//ButtonRectEasy
	LeftCorner.x = detaX;
	sButtons.setTextureRect(IntRect(0 * ButtonWidth, 0, ButtonWidth, ButtonHeight));//读取按钮的纹理区域
	sButtons.setPosition(LeftCorner.x, LeftCorner.y);							//	设置按钮的位置坐标
	ButtonRectEasy.left = LeftCorner.x;											//记录按钮的位置区域
	ButtonRectEasy.top = LeftCorner.y;
	ButtonRectEasy.width = ButtonWidth;
	ButtonRectEasy.height = ButtonHeight;
	window.draw(sButtons);
	//ButtonRectNormal;
	LeftCorner.x = detaX * 2 + ButtonWidth;
	sButtons.setTextureRect(IntRect(1 * ButtonWidth, 0, ButtonWidth, ButtonHeight));//读取按钮的纹理区域
	sButtons.setPosition(LeftCorner.x, LeftCorner.y);							//	设置按钮的位置坐标
	ButtonRectNormal.left = LeftCorner.x;											//记录按钮的位置区域
	ButtonRectNormal.top = LeftCorner.y;
	ButtonRectNormal.width = ButtonWidth;
	ButtonRectNormal.height = ButtonHeight;
	window.draw(sButtons);
	//ButtonRectHard;
	LeftCorner.x = detaX * 3 + ButtonWidth * 2;
	sButtons.setTextureRect(IntRect(2 * ButtonWidth, 0, ButtonWidth, ButtonHeight));//读取按钮的纹理区域
	sButtons.setPosition(LeftCorner.x, LeftCorner.y);							//	设置按钮的位置坐标
	ButtonRectHard.left = LeftCorner.x;											//记录按钮的位置区域
	ButtonRectHard.top = LeftCorner.y;
	ButtonRectHard.width = ButtonWidth;
	ButtonRectHard.height = ButtonHeight;
	window.draw(sButtons);
	//ButtonRectSkin
	LeftCorner.x = detaX * 4 + ButtonWidth * 3;
	sButtons.setTextureRect(IntRect(3 * ButtonWidth, 0, ButtonWidth, ButtonHeight));//读取按钮的纹理区域
	sButtons.setPosition(LeftCorner.x, LeftCorner.y);							//	设置按钮的位置坐标
	ButtonRectSkin.left = LeftCorner.x;											//记录按钮的位置区域
	ButtonRectSkin.top = LeftCorner.y;
	ButtonRectSkin.width = ButtonWidth;
	ButtonRectSkin.height = ButtonHeight;
	window.draw(sButtons);
	//ButtonRectBG
	LeftCorner.x = detaX * 5 + ButtonWidth * 4;
	sButtons.setTextureRect(IntRect(4 * ButtonWidth, 0, ButtonWidth, ButtonHeight));//读取按钮的纹理区域
	sButtons.setPosition(LeftCorner.x, LeftCorner.y);							//	设置按钮的位置坐标
	ButtonRectBG.left = LeftCorner.x;											//记录按钮的位置区域
	ButtonRectBG.top = LeftCorner.y;
	ButtonRectBG.width = ButtonWidth;
	ButtonRectBG.height = ButtonHeight;
	window.draw(sButtons);
	//ButtonRectRestart;
	LeftCorner.x = detaX * 6 + ButtonWidth * 5;
	sButtons.setTextureRect(IntRect(5 * ButtonWidth, 0, ButtonWidth, ButtonHeight));//读取按钮的纹理区域
	sButtons.setPosition(LeftCorner.x, LeftCorner.y);							//	设置按钮的位置坐标
	ButtonRectRestart.left = LeftCorner.x;											//记录按钮的位置区域
	ButtonRectRestart.top = LeftCorner.y;
	ButtonRectRestart.width = ButtonWidth;
	ButtonRectRestart.height = ButtonHeight;
	window.draw(sButtons);
	//ButtonRectQuit;
	LeftCorner.x = detaX * 7 + ButtonWidth * 6;
	sButtons.setTextureRect(IntRect(6 * ButtonWidth, 0, ButtonWidth, ButtonHeight));//读取按钮的纹理区域
	sButtons.setPosition(LeftCorner.x, LeftCorner.y);							//	设置按钮的位置坐标
	ButtonRectQuit.left = LeftCorner.x;											//记录按钮的位置区域
	ButtonRectQuit.top = LeftCorner.y;
	ButtonRectQuit.width = ButtonWidth;
	ButtonRectQuit.height = ButtonHeight;
	window.draw(sButtons);
}

void MainWindows::DrawScore()
{

}

void MainWindows::DrawTimer()
{

}

void MainWindows::DrawGameEnd()
{

}

void MainWindows::ProcessInput()
{
	

}

void MainWindows::Prompt_info(short _x, short _y)
{

}

void MainWindows::DrawInfomation(short _x, short _y)
{

}

void MainWindows::GameLogic()
{
	
}


MainWindows::MainWindows(short _Width, short _Height, const std::string& nameOfWindows)	:
	renderWindow(sf::VideoMode(_Width, _Height), nameOfWindows)
{
	WindowsWidth = _Width;
	WindowsHeigth = _Height;


}

void MainWindows::Initial()
{
	renderWindow.setFramerateLimit(60);
	gameData.Score = 0;
	gameData.BisGameOver = false;
	LoadResource();
}

void MainWindows::TickFrame()
{
	Draw();
	ProcessInput();
}

void MainWindows::LoadResource()
{
	std::stringstream ss;
	ss << "data/images/BK0" << imgBGno << ".jpg";//"data/images/BK01.jpg"

	if (!tBackground.loadFromFile(ss.str()))//加载纹理图片
	{
		std::cout << "BK image 没有找到" << std::endl;
	}

	ss.str("");//清空字符串
	ss << "data/images/Game" << imgSkinNo << ".jpg";//"data/images/Game1.jpg"
	if (!tTiles.loadFromFile(ss.str()))
	{
		std::cout << "Game Skin image 没有找到" << std::endl;
	}

	if (!tNum.loadFromFile("data/images/num.jpg"))
	{
		std::cout << "num.jpg 没有找到" << std::endl;
	}
	if (!tTimer.loadFromFile("data/images/jishiqi.jpg"))
	{
		std::cout << "jishiqi.jpg 没有找到" << std::endl;
	}
	if (!tCounter.loadFromFile("data/images/jishuqi.jpg"))
	{
		std::cout << "jishuqi.jpg 没有找到" << std::endl;
	}
	if (!tButtons.loadFromFile("data/images/button.jpg"))
	{
		std::cout << "button.jpg 没有找到" << std::endl;
	}
	if (!tGameOver.loadFromFile("data/images/gameover.jpg"))
	{
		std::cout << "gameover.jpg 没有找到" << std::endl;
	}
	sBackground.setTexture(tBackground);					//设置精灵对象的纹理
	sTiles.setTexture(tTiles);
	sNum.setTexture(tNum);
	sTimer.setTexture(tTimer);
	sCounter.setTexture(tCounter);
	sButtons.setTexture(tButtons);
	sGameOver.setTexture(tGameOver);
}

