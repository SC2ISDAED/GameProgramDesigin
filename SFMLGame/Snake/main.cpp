#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
using namespace std;
bool gameOver;					//��Ϸ������
const int width = 50;			//��Ϸ���ڿ��
const int height = 20;			//��Ϸ���ڸ߶�
int snakeX, snakeY;				//��ͷ���ꣻ��������
int fruitX, fruitY;				//��ͷ���ꣻ��������
int score;						//�÷�
int tailX[100], tailY[100];		//��������
int nTail = 1;					//�߳���

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };	//����ö��
eDirection dir;					//�������

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);	//ȡ����
int textColor = 0X06;			//��ɫ

//��Ϸ��ʼ��
void Initial()
{
	SetConsoleTitleA("Console_̰����");	//������Ŀ
	COORD dSiz = { 80, 25 };
	SetConsoleScreenBufferSize(h, dSiz);//���ô��ڻ�������С
	CONSOLE_CURSOR_INFO _cursor = { 1, FALSE };//���ù���С�����ع��
	SetConsoleCursorInfo(h, &_cursor);
	system("color 0f");			//���û�����ɫ

	//��ʼ������

}

//���λ��
void setPos(int X, int Y)
{

}

//ָ��λ������ַ���
void Draw(int x, int y, int color, std::string ch)
{

}

//���Ƴ�ʼͼ�Σ���Ϸ����ͷλ�á�����λ�ã�
void DrawMap()
{
	system("cls");								//����
	SetConsoleTextAttribute(h, textColor);		//������ɫ

	//����

	//���ƻ�

	//������ͷ
}

//ɾ��ԭ��
void eraseSnake()
{

}

//��ǰ������ʾ
void showScore(int _x, int _y)
{
	Draw(_x + width, _y + 14, 0x0F, "�� ��ǰ���֣� ");
	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << score;
}

//�ֲ����ƶ�̬���֣������ߡ��÷�
void DrawLocally()
{
	//���ƻ�

	//����������

	//��ʾ��Ϸ�÷�
	showScore(3, 3);
}

//���������
void Input()
{

}

//���Ʒ����
void Logic()
{
	//�ƶ���ͷλ��

	//�������߽���Ϸ����

	//��ɴ�Խ�߽�

	//�Ե�������

	//�ƶ���������

	//�ж��Ƿ���ͷ��������ײ

}

//����˵����ʾ��ϢPrompt_info
void Prompt_info(int _x, int _y)
{
	Draw(_x + width, _y + 0, 0x0F, "����Ϸ˵����");
	Draw(_x + width + 4, _y + 2, 0x0F, "A.������ײ��Ϸ����");
	Draw(_x + width + 4, _y + 3, 0x0F, "B.�߿ɴ�ǽ");
	Draw(_x + width, _y + 5, 0x0F, "������˵����");
	Draw(_x + width + 4, _y + 7, 0x0F, "�������ƶ����� A");
	Draw(_x + width + 4, _y + 8, 0x0F, "�������ƶ����� D");
	Draw(_x + width + 4, _y + 9, 0x0F, "�������ƶ����� S");
	Draw(_x + width + 4, _y + 10, 0x0F, "�������ƶ����� W");
	Draw(_x + width + 4, _y + 12, 0x0F, "����ʼ��Ϸ�����ⷽ���");
}

//������ʾ
void is_gameover()
{
	Draw(width / 2 - 5, 8, 0xec, "game over!");
	Draw(width / 2 - 7, 9, 0xec, "Y���¿�ʼ/N�˳�");
	SetConsoleTextAttribute(h, 0x0f);
}

//���س���
int main()
{
	bool gameQuit = false;	//��Ϸ�˳���

	do {
		Initial();			//ȫ�ֱ�����ʼ��
		DrawMap();			//����Ϸ��
		Prompt_info(3, 3);	//����˵����Ϣ

		while (!gameOver)	//����Ϸδ����
		{
			Input();		//�õ���������
			eraseSnake();	//Ĩȥԭ����
			Logic();		//���Ƽ��̴���
			DrawLocally();	//���ƶ�̬���ݣ������ߡ��÷֣�
			Sleep(100);		//��ͣ100ms
		}
		is_gameover();		//��ʾ�Ƿ��˳�

		while (gameOver)
		{
			//ѡ���Ƿ��˳�
			if (_kbhit())
			{
				switch (tolower(_getch()))
				{
				case 'y':	//��Ϸ���¿�ʼ
					gameOver = false;
					system("cls");		//����
					break;
				case 'n':	//��Ϸ�˳�
					gameOver = false;
					gameQuit = true;
					break;
				}
			}
			Sleep(10);
		}
	} while (!gameQuit);

	return 0;
}