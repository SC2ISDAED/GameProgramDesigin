#pragma once
#include <conio.h>

#include "WindowsProcess.h"
#include "iostream"
#include "floor.h"
#include "string"
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
	Direction newDirection=Direction::STOP;
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'w':
		case 'W':
			newDirection=Direction::UP;
			break;
		case 'a':
		case 'A':
			newDirection = Direction::LEFT;
			break;
		case 's':
		case 'S':
			newDirection = Direction::DOWN;
			break;
		case 'd':
		case 'D':
			newDirection = Direction::RIGHT;
			break;
		case '\033':
			BWindowsShouldOver = true;
			break;
		default:
			newDirection = Direction::STOP;
			break;
		}
	}
	Player.SetDirection(newDirection);
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
	DrawInfomation(_x + WindowsWidth + 4, _y + 2, 0x0F, "A.�������Ƶ�ָ��λ��");
	DrawInfomation(_x + WindowsWidth + 4, _y + 3, 0x0F, "B.��ESC�˳���Ϸ");
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
	//����˼·��Ϊ���Σ�1.���ȸ��ݺ���λ�ã��Լ��¸��µĺ���λ�û�ȡ��Ϣ������������ǽ����ô��Ҿ��Ʋ���
	//2.��θ��ݽ�ɫ���µ�ͼ��Ϣ����������ǽ�ڣ�Ŀ���ȵ�
	//3.����ǰ��������Ϣ���ٴθ��µ�ͼ����Ҫ���½�ɫ��λ���ϵ���Ϣ				
	std::pair<short, short> newLoc = Player.GetLocation();
	std::pair<short, short> oldLoc = Player.GetLocation();
	switch (Player.GetDirection())
	{
	case Direction::DOWN:
		newLoc.second++;
		break;
	case Direction::UP:
		newLoc.second--;
		break;
	case Direction::LEFT:
		newLoc.first--;
		break;
	case Direction::RIGHT:
		newLoc.first++;
		break;
	default:
		break;
	}
	std::pair<short, short> newBoxLoc = newLoc;
	std::pair<short, short> oldBoxLoc = newLoc;
	short newActorLocIndex = newLoc.first + newLoc.second*mapHeight;
	short newindexBoxLoc = 0;
	if (m_Map[newActorLocIndex].IsSameLocation(newLoc))
	{
		//��һ�θ���
		if (m_Map[newActorLocIndex].GetType() == FloorType::Box)
		{
			//����µ�����λ��
			switch (Player.GetDirection())
			{
			case Direction::DOWN:
				newBoxLoc.second++;
				break;
			case Direction::UP:
				newBoxLoc.second--;
				break;
			case Direction::LEFT:
				newBoxLoc.first--;
				break;
			case Direction::RIGHT:
				newBoxLoc.first++;
				break;
			default:
				break;
			}
			newindexBoxLoc = newBoxLoc.first + newBoxLoc.second*mapHeight;

			if (m_Map[newindexBoxLoc].IsSameLocation(newBoxLoc))
			{

				if (m_Map[newindexBoxLoc].GetType() == FloorType::Road)
				{
					m_Map[newindexBoxLoc].SetType(FloorType::Box);
				}
				else if (m_Map[newindexBoxLoc].GetType() == FloorType::Target)
				{
					m_Map[newindexBoxLoc].SetType(FloorType::AtTarget);
					targetNum--;
				}
				else if (m_Map[newindexBoxLoc].GetType() == FloorType::AtTarget)
				{
					m_Map[newindexBoxLoc].SetType(FloorType::Box);
					targetNum++;
				}
				else if (m_Map[newindexBoxLoc].GetType() == FloorType::Wall)
				{
					Player.SetDirection(Direction::STOP);
				}
			}
			short indexOldBoxloc = oldBoxLoc.first + oldBoxLoc.second*mapHeight;
			if (m_Map[indexOldBoxloc].IsSameLocation(oldBoxLoc) && Player.GetDirection() != Direction::STOP)
			{
				m_Map[indexOldBoxloc].SetType(FloorType::Road);
			}
		}
	}
	int oldActorLocIndex = oldLoc.first + oldLoc.second*mapHeight;
	if (m_Map[newActorLocIndex].IsSameLocation(newLoc))
	{
		//�ڶ��θ���
		if (m_Map[newActorLocIndex].GetType() == FloorType::Road)
		{
			m_Map[newActorLocIndex].SetType(FloorType::Charcter);
			Player.SetLocation(newLoc);
		}
		else if (m_Map[newActorLocIndex].GetType() == FloorType::AtTarget)
		{
			switch (Player.GetDirection())
			{
			case Direction::DOWN:
				newBoxLoc.second++;
				break;
			case Direction::UP:
				newBoxLoc.second--;
				break;
			case Direction::LEFT:
				newBoxLoc.first--;
				break;
			case Direction::RIGHT:
				newBoxLoc.first++;
				break;
			default:
				break;
			}
			short newindexBoxLoc = newBoxLoc.first + newBoxLoc.second*mapHeight;
			short oldindexBoxLoc = oldBoxLoc.first + oldBoxLoc.second*mapHeight;
			if (m_Map[newindexBoxLoc].GetType() == FloorType::Road)
			{
				m_Map[newActorLocIndex].SetType(FloorType::Charcter);
				m_Map[newindexBoxLoc].SetType(FloorType::Box);
				m_Map[oldActorLocIndex].SetType(FloorType::Target);
				Player.SetLocation(newLoc);
				
				targetNum++;
			}
			else if(m_Map[newindexBoxLoc].GetType() == FloorType::Target)
			{
				m_Map[newindexBoxLoc].SetType(FloorType::AtTarget);
				m_Map[oldindexBoxLoc].SetType(FloorType::Charcter);
				IsCharcterAtTarget = true;
				Player.SetLocation(newLoc);
			}
			else
			{
				Player.SetDirection(Direction::STOP);
			}
		}
		else if (m_Map[newActorLocIndex].GetType() == FloorType::Target)
		{
			m_Map[newActorLocIndex].SetType(FloorType::Charcter);
			Player.SetLocation(newLoc);


			IsCharcterAtTarget = true;
	/*		latterFrame = false;*/
			
		
		}
		else
		{
			Player.SetDirection(Direction::STOP);
		}

	}
	if (Player.GetDirection() != Direction::STOP)
	{
		//�����θ���
		if (IsCharcterAtTarget)
		{
			//���ڻ�ԭtargetĿ������Ϣ
			if (!latterFrame)
			{
				m_Map[oldActorLocIndex].SetType(FloorType::Road);
			}
			else
			{
				m_Map[oldActorLocIndex].SetType(FloorType::Target);
			}
			IsCharcterAtTarget = false;

			latterFrame = true;

		}
 		else if (latterFrame)
 		{
			m_Map[oldActorLocIndex].SetType(FloorType::Target);
			latterFrame = false;
			IsCharcterAtTarget = false;
 		}
		else
		{
			m_Map[oldActorLocIndex].SetType(FloorType::Road);
		}

	}
	Player.SetDirection(Direction::STOP);
	if (targetNum==0)
	{
		Initial();
	}
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
	m_Map.resize(mapWidhth*mapHeight);
	
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
				targetNum++;
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
			m_Map[locY*mapHeight+locX]=std::move(floor);
		}
	}
	return;
}

MainWindows::MainWindows(short _Width, short _Height, const std::string& nameOfWindows)
{
	WindowsWidth = _Width;
	WindowsHeigth = _Height;

	//��ʼ��˫����ָ��
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
	SetConsoleTitleA(nameOfWindows.c_str());	//������Ŀ
	COORD dSiz = { _Width, _Height };
	SetConsoleScreenBufferSize(sawpWindHandle[0], dSiz);//���ô��ڻ�������С
	SetConsoleScreenBufferSize(sawpWindHandle[1], dSiz);
	CONSOLE_CURSOR_INFO _cursor = { 1, FALSE };//���ù���С�����ع��
	SetConsoleCursorInfo(sawpWindHandle[0], &_cursor);
	SetConsoleCursorInfo(sawpWindHandle[1], &_cursor);

	system("color 0f");			//���û�����ɫ

}

void MainWindows::Initial()
{
	gameInstancedData.Score = 0;
	std::string mapName;

	mapName = std::string("Map/Map") +std::to_string(mapCurrentNum)  + std::string(".txt");
	LoadMap(mapName);
	mapCurrentNum = (mapCurrentNum + 1) % mapNum;

}

void MainWindows::TickFrame()
{
	Draw();
	ProcessInput();
}

void MainWindows::ShowScore()
{
	std::cout << "targetNum: " << targetNum << std::endl;
}

