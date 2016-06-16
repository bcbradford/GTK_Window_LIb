
#include "WindowLib/WindowLib.hpp"
#include "MainWindow.h"

int main(int argc, char *argv[])
{
	gtk_init(&argc, &argv);
	WindowLib::MainWindow window = WindowLib::MainWindow();
	window.Show();
	
	return 0;
}
