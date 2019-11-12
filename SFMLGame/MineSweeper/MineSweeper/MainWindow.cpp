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
	renderWindow.clear();	//����
	//���Ʊ���
	sBackground.setPosition(0, 0);
	renderWindow.draw(sBackground);
	//������̨
	DrawGrid();
	DrawButton();
	DrawTimer();
	DrawScore();
	if (gameData.BisGameOver)
		DrawGameEnd();
	renderWindow.display();				//����ʾ�����������ݣ���ʾ����Ļ�ϡ�SFML���õ���˫�������
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
	detaX = (Window_width - ButtonWidth * 7) / 8;//�ȷֿ��
	LeftCorner.y = Window_height - GRIDSIZE * 3;//ָ���߶�

	//ButtonRectEasy
	LeftCorner.x = detaX;
	sButtons.setTextureRect(IntRect(0 * ButtonWidth, 0, ButtonWidth, ButtonHeight));//��ȡ��ť����������
	sButtons.setPosition(LeftCorner.x, LeftCorner.y);							//	���ð�ť��λ������
	ButtonRectEasy.left = LeftCorner.x;											//��¼��ť��λ������
	ButtonRectEasy.top = LeftCorner.y;
	ButtonRectEasy.width = ButtonWidth;
	ButtonRectEasy.height = ButtonHeight;
	window.draw(sButtons);
	//ButtonRectNormal;
	LeftCorner.x = detaX * 2 + ButtonWidth;
	sButtons.setTextureRect(IntRect(1 * ButtonWidth, 0, ButtonWidth, ButtonHeight));//��ȡ��ť����������
	sButtons.setPosition(LeftCorner.x, LeftCorner.y);							//	���ð�ť��λ������
	ButtonRectNormal.left = LeftCorner.x;											//��¼��ť��λ������
	ButtonRectNormal.top = LeftCorner.y;
	ButtonRectNormal.width = ButtonWidth;
	ButtonRectNormal.height = ButtonHeight;
	window.draw(sButtons);
	//ButtonRectHard;
	LeftCorner.x = detaX * 3 + ButtonWidth * 2;
	sButtons.setTextureRect(IntRect(2 * ButtonWidth, 0, ButtonWidth, ButtonHeight));//��ȡ��ť����������
	sButtons.setPosition(LeftCorner.x, LeftCorner.y);							//	���ð�ť��λ������
	ButtonRectHard.left = LeftCorner.x;											//��¼��ť��λ������
	ButtonRectHard.top = LeftCorner.y;
	ButtonRectHard.width = ButtonWidth;
	ButtonRectHard.height = ButtonHeight;
	window.draw(sButtons);
	//ButtonRectSkin
	LeftCorner.x = detaX * 4 + ButtonWidth * 3;
	sButtons.setTextureRect(IntRect(3 * ButtonWidth, 0, ButtonWidth, ButtonHeight));//��ȡ��ť����������
	sButtons.setPosition(LeftCorner.x, LeftCorner.y);							//	���ð�ť��λ������
	ButtonRectSkin.left = LeftCorner.x;											//��¼��ť��λ������
	ButtonRectSkin.top = LeftCorner.y;
	ButtonRectSkin.width = ButtonWidth;
	ButtonRectSkin.height = ButtonHeight;
	window.draw(sButtons);
	//ButtonRectBG
	LeftCorner.x = detaX * 5 + ButtonWidth * 4;
	sButtons.setTextureRect(IntRect(4 * ButtonWidth, 0, ButtonWidth, ButtonHeight));//��ȡ��ť����������
	sButtons.setPosition(LeftCorner.x, LeftCorner.y);							//	���ð�ť��λ������
	ButtonRectBG.left = LeftCorner.x;											//��¼��ť��λ������
	ButtonRectBG.top = LeftCorner.y;
	ButtonRectBG.width = ButtonWidth;
	ButtonRectBG.height = ButtonHeight;
	window.draw(sButtons);
	//ButtonRectRestart;
	LeftCorner.x = detaX * 6 + ButtonWidth * 5;
	sButtons.setTextureRect(IntRect(5 * ButtonWidth, 0, ButtonWidth, ButtonHeight));//��ȡ��ť����������
	sButtons.setPosition(LeftCorner.x, LeftCorner.y);							//	���ð�ť��λ������
	ButtonRectRestart.left = LeftCorner.x;											//��¼��ť��λ������
	ButtonRectRestart.top = LeftCorner.y;
	ButtonRectRestart.width = ButtonWidth;
	ButtonRectRestart.height = ButtonHeight;
	window.draw(sButtons);
	//ButtonRectQuit;
	LeftCorner.x = detaX * 7 + ButtonWidth * 6;
	sButtons.setTextureRect(IntRect(6 * ButtonWidth, 0, ButtonWidth, ButtonHeight));//��ȡ��ť����������
	sButtons.setPosition(LeftCorner.x, LeftCorner.y);							//	���ð�ť��λ������
	ButtonRectQuit.left = LeftCorner.x;											//��¼��ť��λ������
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

	if (!tBackground.loadFromFile(ss.str()))//��������ͼƬ
	{
		std::cout << "BK image û���ҵ�" << std::endl;
	}

	ss.str("");//����ַ���
	ss << "data/images/Game" << imgSkinNo << ".jpg";//"data/images/Game1.jpg"
	if (!tTiles.loadFromFile(ss.str()))
	{
		std::cout << "Game Skin image û���ҵ�" << std::endl;
	}

	if (!tNum.loadFromFile("data/images/num.jpg"))
	{
		std::cout << "num.jpg û���ҵ�" << std::endl;
	}
	if (!tTimer.loadFromFile("data/images/jishiqi.jpg"))
	{
		std::cout << "jishiqi.jpg û���ҵ�" << std::endl;
	}
	if (!tCounter.loadFromFile("data/images/jishuqi.jpg"))
	{
		std::cout << "jishuqi.jpg û���ҵ�" << std::endl;
	}
	if (!tButtons.loadFromFile("data/images/button.jpg"))
	{
		std::cout << "button.jpg û���ҵ�" << std::endl;
	}
	if (!tGameOver.loadFromFile("data/images/gameover.jpg"))
	{
		std::cout << "gameover.jpg û���ҵ�" << std::endl;
	}
	sBackground.setTexture(tBackground);					//���þ�����������
	sTiles.setTexture(tTiles);
	sNum.setTexture(tNum);
	sTimer.setTexture(tTimer);
	sCounter.setTexture(tCounter);
	sButtons.setTexture(tButtons);
	sGameOver.setTexture(tGameOver);
}

