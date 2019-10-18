#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
using namespace std;
bool gameOver;					//游戏结束否
const int width = 50;			//游戏窗口宽度
const int height = 20;			//游戏窗口高度
int snakeX, snakeY;				//蛇头坐标；花的坐标
int fruitX, fruitY;				//蛇头坐标；花的坐标
int score;						//得分
int tailX[100], tailY[100];		//蛇身数据
int nTail = 1;					//蛇长度

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };	//方向枚举
eDirection dir;					//方向变量

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);	//取画柄
int textColor = 0X06;			//黄色

//游戏初始化
void Initial()
{
	SetConsoleTitleA("Console_贪吃蛇");	//设置题目
	COORD dSiz = { 80, 25 };
	SetConsoleScreenBufferSize(h, dSiz);//设置窗口缓冲区大小
	CONSOLE_CURSOR_INFO _cursor = { 1, FALSE };//设置光标大小，隐藏光标
	SetConsoleCursorInfo(h, &_cursor);
	system("color 0f");			//设置画布颜色

	//初始化数据

}

//光标位置
void setPos(int X, int Y)
{

}

//指定位置输出字符串
void Draw(int x, int y, int color, std::string ch)
{

}

//绘制初始图形（游戏框、蛇头位置、花的位置）
void DrawMap()
{
	system("cls");								//清屏
	SetConsoleTextAttribute(h, textColor);		//设置颜色

	//画框

	//绘制花

	//绘制蛇头
}

//删除原蛇
void eraseSnake()
{

}

//当前积分显示
void showScore(int _x, int _y)
{
	Draw(_x + width, _y + 14, 0x0F, "◆ 当前积分： ");
	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << score;
}

//局部绘制动态部分，花、蛇、得分
void DrawLocally()
{
	//绘制花

	//绘制蛇身体

	//显示游戏得分
	showScore(3, 3);
}

//方向键输入
void Input()
{

}

//控制方向键
void Logic()
{
	//移动蛇头位置

	//若遇到边界游戏结束

	//或可穿越边界

	//吃到花处理

	//移动蛇身坐标

	//判断是否蛇头与蛇身自撞

}

//操作说明提示信息Prompt_info
void Prompt_info(int _x, int _y)
{
	Draw(_x + width, _y + 0, 0x0F, "■游戏说明：");
	Draw(_x + width + 4, _y + 2, 0x0F, "A.蛇身自撞游戏结束");
	Draw(_x + width + 4, _y + 3, 0x0F, "B.蛇可穿墙");
	Draw(_x + width, _y + 5, 0x0F, "■操作说明：");
	Draw(_x + width + 4, _y + 7, 0x0F, "□向左移动：← A");
	Draw(_x + width + 4, _y + 8, 0x0F, "□向右移动：→ D");
	Draw(_x + width + 4, _y + 9, 0x0F, "□向下移动：↓ S");
	Draw(_x + width + 4, _y + 10, 0x0F, "□向上移动：↑ W");
	Draw(_x + width + 4, _y + 12, 0x0F, "□开始游戏：任意方向键");
}

//结束提示
void is_gameover()
{
	Draw(width / 2 - 5, 8, 0xec, "game over!");
	Draw(width / 2 - 7, 9, 0xec, "Y重新开始/N退出");
	SetConsoleTextAttribute(h, 0x0f);
}

//主控程序
int main()
{
	bool gameQuit = false;	//游戏退出否

	do {
		Initial();			//全局变量初始化
		DrawMap();			//画游戏框
		Prompt_info(3, 3);	//操作说明信息

		while (!gameOver)	//若游戏未结束
		{
			Input();		//得到键盘输入
			eraseSnake();	//抹去原蛇身
			Logic();		//控制键盘处理
			DrawLocally();	//绘制动态数据（花、蛇、得分）
			Sleep(100);		//暂停100ms
		}
		is_gameover();		//提示是否退出

		while (gameOver)
		{
			//选择是否退出
			if (_kbhit())
			{
				switch (tolower(_getch()))
				{
				case 'y':	//游戏重新开始
					gameOver = false;
					system("cls");		//清屏
					break;
				case 'n':	//游戏退出
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