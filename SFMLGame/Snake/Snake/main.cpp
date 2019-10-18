#include "iostream"
#include "SFML/Graphics.hpp"
#include "MainWindow.h"
#include "Windows.h"
int main()
{
	int width = 30;
	int height = 20;
	int uintSize = 25;
	std::string nameofWindow("SFML");
	MainWindows mainwnd(width,height,uintSize,nameofWindow);

	while (!mainwnd.BWindosOver())
	{
		mainwnd.Initial();
		while (!mainwnd.BGameOver()&& !mainwnd.BWindosOver())
		{
			mainwnd.TickFrame();
		}

	}
	return 0;
}

