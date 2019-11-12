#include "iostream"
#include "SFML/Graphics.hpp"
#include "MainWindow.h"
#include "Windows.h"
int main()
{
	int width = 860;
	int height = 600;
	std::string nameofWindow("SFML");
	MainWindows mainwnd(width,height,nameofWindow);

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

