#pragma once
#include <conio.h>

#include "WindowsProcess.h"
#include "iostream"
#include "floor.h"

#include "fstream"
void MainWindows::Draw()
{
	int textColor = 0x06;
	COORD coord = { 0,0 };
	DWORD bytes = 0;
	SetPos(-1, -1);

	SetConsoleTextAttribute(sawpWindHandle[currentWindHandleNum], textColor);
	screenData[currentWindHandleNum].empty();
	int lineI = 0;
	std::string line;
	for (auto ele:m_Map)
	{
		std::pair<short, short> spair = ele.GetLocation();
		SetPos(ele.GetLocation().first, ele.GetLocation().second);
		
		switch (ele.GetType())
		{
		case FloorType::Wall:
			line+=  map[0];
			break;
		case  FloorType::Road:
			line += map[1];
			break;
		case FloorType::Box:
			line += map[2];
			break;
		case  FloorType::Target:
			line += map[3];
			break;
		case FloorType::Charcter:
			line += map[4];
			break;
		case FloorType::AtTarget:
			line += map[5];
			break;
		default:
			break;
		}
		if (ele.GetLocation().first==mapWidhth-1)
		{
			line += '\0';
			screenData[currentWindHandleNum][lineI] = std::move(line);
			lineI++;
			line.clear();
		}
	}
	for (int i = 0; i < screenData->size(); i++)
	{
		coord.Y = i;
		const char * str = screenData[currentWindHandleNum][i].c_str();
		WriteConsoleOutputCharacterA(sawpWindHandle[currentWindHandleNum],
			screenData[currentWindHandleNum][i].c_str(),
			mapWidhth+10, coord, &bytes);
	}
	SetConsoleActiveScreenBuffer(sawpWindHandle[currentWindHandleNum]);
	Prompt_info(3, 3);
	ShowScore();
	currentWindHandleNum = (currentWindHandleNum + 1) % sizeofSwapWind;
	Sleep(100);

}

void MainWindows::ProcessInput()
{
	if (_kbhit())
	{
		switch (_getch())
		{

		case '\033':
			BWindowsShouldOver = true;
			break;
		}
	}
	GameLogic();
}

void MainWindows::SetPos(short X, short Y)
{

	COORD pos = { X,Y };
	//设置光标位置 
	SetConsoleCursorPosition(sawpWindHandle[currentWindHandleNum], pos);
}

void MainWindows::Prompt_info(short _x, short _y)
{
	DrawInfomation(_x + WindowsWidth, _y + 0, 0x0F, "■游戏说明：");
	DrawInfomation(_x + WindowsWidth + 4, _y + 2, 0x0F, "A.将箱子推到指定位置");
	DrawInfomation(_x + WindowsWidth + 4, _y + 3, 0x0F, "B.按ESC退出游戏");
	DrawInfomation(_x + WindowsWidth, _y + 5, 0x0F, "■操作说明：");
	DrawInfomation(_x + WindowsWidth + 4, _y + 7, 0x0F, "□向左移动：← A");
	DrawInfomation(_x + WindowsWidth + 4, _y + 8, 0x0F, "□向右移动：→ D");
	DrawInfomation(_x + WindowsWidth + 4, _y + 9, 0x0F, "□向下移动：↓ S");
	DrawInfomation(_x + WindowsWidth + 4, _y + 10, 0x0F, "□向上移动：↑ W");
	DrawInfomation(_x + WindowsWidth + 4, _y + 12, 0x0F, "□开始游戏：任意方向键");
}

void MainWindows::DrawInfomation(short _x, short _y, int color, const std::string & information)
{
	COORD pos = { _x,_y };
	//设置光标位置 
	SetConsoleCursorPosition(sawpWindHandle[currentWindHandleNum], pos);
	std::cout << information;
}

void MainWindows::GameLogic()
{
	
}

void MainWindows::LoadMap(const std::string &source)
{
	std::fstream file(source.c_str());

	file >> mapWidhth >> mapHeight;
	mapHeight = mapHeight ;
	mapWidhth = mapWidhth;
	screenData[0].resize(mapHeight);
	screenData[1].resize(mapHeight);
	std::string getline;
	file >> getline;
	m_Map.reserve(mapWidhth*mapHeight);
	
	for (short locY = 0; locY < mapHeight; locY++)
	{
		for (short locX = 0; locX < mapWidhth; locX++)
		{
			short type = 0;

			FloorType FType = FloorType::Wall;
			file >> type;
	
			switch (type)
			{
			case 1:
				FType = FloorType::Road;
				break;
			case 2:
				FType = FloorType::Box;
				break;
			case 3:
				FType = FloorType::Target;
				break;
			case 4:
				FType = FloorType::Charcter;
				Player.SetLocation(std::pair<short, short>(locX, locY));
				break;
			default:
				FType = FloorType::Wall;
				break;
			}
			Floor floor(FType, std::pair<short, short>(locX, locY));
			m_Map.push_back(std::move(floor));
		}
	}
	return;
}

MainWindows::MainWindows(short _Width, short _Height, const std::string& nameOfWindows)
{
	WindowsWidth = _Width;
	WindowsHeigth = _Height;

	//初始化双缓冲指针
	currentWindHandleNum = 0;
	sizeofSwapWind = 2;
	sawpWindHandle[0] = CreateConsoleScreenBuffer
	(GENERIC_WRITE,
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
	SetConsoleTitleA(nameOfWindows.c_str());	//设置题目
	COORD dSiz = { _Width, _Height };
	SetConsoleScreenBufferSize(sawpWindHandle[0], dSiz);//设置窗口缓冲区大小
	SetConsoleScreenBufferSize(sawpWindHandle[1], dSiz);
	CONSOLE_CURSOR_INFO _cursor = { 1, FALSE };//设置光标大小，隐藏光标
	SetConsoleCursorInfo(sawpWindHandle[0], &_cursor);
	SetConsoleCursorInfo(sawpWindHandle[1], &_cursor);

	system("color 0f");			//设置画布颜色

}

void MainWindows::Initial()
{
	gameInstancedData.Score = 0;
	std::string mapName;
/*	mapCurrentNum = (mapCurrentNum+1) % mapNum;*/
	LoadMap("Map/Map0.txt");

}

void MainWindows::TickFrame()
{
	Draw();
	ProcessInput();
}

void MainWindows::ShowScore()
{
	std::cout << "Game Score: " << gameInstancedData.Score << std::endl;
}

