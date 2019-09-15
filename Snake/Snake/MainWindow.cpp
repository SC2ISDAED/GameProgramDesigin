#pragma once
#include <conio.h>

#include "MainWindow.h"
#include "iostream"
void MainWindows::showScore()
{
	std::cout << "Game Score: " << gameData.Score << std::endl;
}

void MainWindows::Draw()
{

	int textColor = 0x06;
	COORD coord = { 0,0 };
	DWORD bytes = 0;
	SetPos(-1, -1);
	SetConsoleTextAttribute(sawpWindHandle[currentWindHandleNum], textColor);
	screenData[currentWindHandleNum].empty();
	for (short i=0;i< WindowsHeigth;i++)
	{
		std::string line;
		for (short j=0;j<WindowsWidth;j++)
		{
			if (m_Snake.BIsSameHeadLoc(j,i))
			{
				line += "@";
			}
			else if (m_Snake.BIsSameTrialLoc(j, i))
			{
				line += "*";
			}
			else if (m_fruits.BIsSameLoc(j,i))
			{
				line += "&";
			}
			else if (j== WindowsWidth -1||j==0)
			{
				line += "#";
			}
			else if (i== WindowsHeigth -1||i==0)
			{
				line += "#";
			}
			else
			{
				line += " ";
			}
		}
		line+='\n';
		screenData[currentWindHandleNum][i]=std::move(line);
	}

	for (int i=0;i<WindowsHeigth;i++)
	{
		coord.Y = i;
		WriteConsoleOutputCharacterA(sawpWindHandle[currentWindHandleNum],
			screenData[currentWindHandleNum][i].c_str(),
			WindowsWidth, coord, &bytes);
	}

	SetConsoleActiveScreenBuffer(sawpWindHandle[currentWindHandleNum]);
	Prompt_info( 3,  3);
	showScore();
	currentWindHandleNum = (currentWindHandleNum + 1) % sizeofSwapWind ;
	Sleep(100);
}

void MainWindows::ProcessInput()
{
	SnakeDirection dir = m_Snake.GetDirection();
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
		case 'A':
			if (dir!=SnakeDirection::RIGHT)
					dir = SnakeDirection::LEFT;
			break;
		case 'w':
		case 'W':
			if (dir != SnakeDirection::DOWN)
				dir = SnakeDirection::UP;
			break;
		case 'd':
		case 'D':
			if (dir != SnakeDirection::LEFT)
				dir = SnakeDirection::RIGHT;
			break;
		case 's':
		case 'S':
			if (dir != SnakeDirection::UP)
				dir = SnakeDirection::DOWN;
			break;
		case '\033':
			BWindowsShouldOver = true;
			break;
		}
	}
	m_Snake.SetDirection(dir);
	GameLogic();
}

void MainWindows::SetPos(short X, short Y)
{

	COORD pos = { X,Y };
	//���ù��λ�� 
	SetConsoleCursorPosition(sawpWindHandle[currentWindHandleNum], pos);
}

void MainWindows::Prompt_info(short _x, short _y)
{
	DrawInfomation(_x + WindowsWidth, _y + 0, 0x0F, "����Ϸ˵����");
	DrawInfomation(_x + WindowsWidth + 4, _y + 2, 0x0F, "A.������ײ��Ϸ����");
	DrawInfomation(_x + WindowsWidth + 4, _y + 3, 0x0F, "B.�߿ɴ�ǽ");
	DrawInfomation(_x + WindowsWidth, _y + 5, 0x0F, "������˵����");
	DrawInfomation(_x + WindowsWidth + 4, _y + 7, 0x0F, "�������ƶ����� A");
	DrawInfomation(_x + WindowsWidth + 4, _y + 8, 0x0F, "�������ƶ����� D");
	DrawInfomation(_x + WindowsWidth + 4, _y + 9, 0x0F, "�������ƶ����� S");
	DrawInfomation(_x + WindowsWidth + 4, _y + 10, 0x0F, "�������ƶ����� W");
	DrawInfomation(_x + WindowsWidth + 4, _y + 12, 0x0F, "����ʼ��Ϸ�����ⷽ���");
}

void MainWindows::DrawInfomation(short _x, short _y, int color, const std::string & information)
{
	COORD pos = { _x,_y };
	//���ù��λ�� 
	SetConsoleCursorPosition(sawpWindHandle[currentWindHandleNum], pos);
	std::cout << information;
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
		newX--;
		break;
	case SnakeDirection::RIGHT:
		newX++;
		break;
	case SnakeDirection::UP:
		newY--;
		break;
	case SnakeDirection::DOWN:
		newY++;
		break;
	default:
		break;
	}
	

	if (newX>= WindowsWidth-1||newX<1||newY<1|| newY >= WindowsHeigth-1)
	{
		//ײ��ǽ�������ж�
		gameData.BisGameOver = true;
	}
	if (m_Snake.BIsSameTrialLoc(newX,newY))
	{
		//ҧ����β������ 
		gameData.BisGameOver = true;
	}
	if (m_fruits.BIsSameLoc(newX,newY))
	{
	//����Ƚ������ĵط���
	//����߳Ե�ˮ��������Ҫ������β�ĳ��ȣ���������Ͳ�ɾ���ɵ����һ����β
		gameData.Score++;
		m_Snake.AddLength(1);
		initalFruits();
	}
	else
	{
		//�෴��û�гԵ�ˮ������ô����Ӧ��ɾ�����һ����λ���ϵ���β
		m_Snake.pop_back();
	}
	if (snakeDir != SnakeDirection::STOP)
	{
		//������ͷλ��
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
			//��������ǽ�����ˣ���������
			continue;
		}
		if (m_Snake.BIsSameHeadLoc(newfruitsX,newfruitsY)||m_Snake.BIsSameTrialLoc(newfruitsX,newfruitsY))
		{
			//��������������,��������
			continue;
		}
		m_fruits.Setloc(newfruitsX, newfruitsY);
		isNotSuccessed = false;
	}


}

MainWindows::MainWindows(short _Width, short _Height, const std::string& nameOfWindows)	:m_Snake(_Width / 2, _Height / 2)
{
	WindowsWidth = _Width;
	WindowsHeigth = _Height;
	screenData[0].resize(_Height);
	screenData[1].resize(_Height);
	//��ʼ��˫����ָ��
	currentWindHandleNum = 0;
	sizeofSwapWind = 2;
	sawpWindHandle[0] = CreateConsoleScreenBuffer
	(   GENERIC_WRITE,
		FILE_SHARE_WRITE,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL);
	
	sawpWindHandle[1] = CreateConsoleScreenBuffer
	(GENERIC_WRITE,
		FILE_SHARE_WRITE,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL);
	SetConsoleTitleA(nameOfWindows.c_str());	//������Ŀ
	COORD dSiz = { 80, 30 };
	SetConsoleScreenBufferSize(sawpWindHandle[0], dSiz);//���ô��ڻ�������С
	SetConsoleScreenBufferSize(sawpWindHandle[1], dSiz);
	CONSOLE_CURSOR_INFO _cursor = { 1, FALSE };//���ù���С�����ع��
	SetConsoleCursorInfo(sawpWindHandle[0], &_cursor);
	SetConsoleCursorInfo(sawpWindHandle[1], &_cursor);

	system("color 0f");			//���û�����ɫ
	//��ʼ����
	short length = 6;

}

void MainWindows::Initial()
{
	gameData.Score = 0;
	gameData.BisGameOver = false;
	m_Snake.init();
	initalFruits();
	
}

void MainWindows::TickFrame()
{
	Draw();
	ProcessInput();
}

