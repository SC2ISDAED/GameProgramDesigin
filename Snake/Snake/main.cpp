#include "MainWindow.h"
#include "string"
int main()
{
	int width = 50;
	int height = 20;
	std::string nameofWindow("Console_̰����");
	MainWindows mainwnd(width,height,nameofWindow);
	while (!mainwnd.BWindosOver())
	{
		mainwnd.Initial();
		while (!mainwnd.BGameOver()&& !mainwnd.BWindosOver())
		{
			mainwnd.TickFrame();
		}
		Sleep(1000);
	}
	return 0;
}