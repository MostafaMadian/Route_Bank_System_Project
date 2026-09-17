
#include "Screens.h"
#include <windows.h> 


int main() {
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 10;                   // Width of each character in the font
	cfi.dwFontSize.Y = 18;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_BOLD;
	wcscpy_s(cfi.FaceName, L"Lucida Console"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	
	
	Screens::runApp();




	


	
}