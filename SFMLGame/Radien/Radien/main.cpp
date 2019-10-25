#include "iostream"
#include "SFML/Graphics.hpp"

#include "MainWindow.h"
#include "Windows.h"
int main()
{

	int width = 520;
	int height = 800;
	int uintSize = 25;
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

