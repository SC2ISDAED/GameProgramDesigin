#include "WindowsProcess.h"
#include "string"
#include "iostream"
int main()
{
	int width = 50;
	int height = 20;
	std::string nameofWindow("Console_ÍÆÏä×Ó");
	MainWindows mainwnd(width, height, nameofWindow);
	while (!mainwnd.BWindosOver())
	{
		mainwnd.Initial();
		while (!mainwnd.BGameOver() && !mainwnd.BWindosOver())
		{
			mainwnd.TickFrame();
		}
		Sleep(10);
	}
	return 0;
}