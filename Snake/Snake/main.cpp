#include "MainWindow.h"
#include "string"
int main()
{
	int width = 50;
	int height = 20;
	std::string nameofWindow("Console_Ã∞≥‘…ﬂ");
	MainWindows mainwnd(width,height,nameofWindow);
	while (!mainwnd.gameData.BisGameOver)
	{
		mainwnd.TickFrame();
	}
	return 0;
}