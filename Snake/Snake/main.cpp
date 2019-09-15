#include "MainWindow.h"
#include "string"
int main()
{
	int width = 50;
	int height = 20;
	std::string nameofWindow("Console_Ã∞≥‘…ﬂ");
	MainWindows mainwnd(width,height,nameofWindow);
	while (!mainwnd.BWindosOver())
	{
		mainwnd.Initial();
		while (!mainwnd.BGameOver()&& !mainwnd.BWindosOver())
		{
			mainwnd.TickFrame();
		}
		Sleep(100);
	}
	return 0;
}