#include "stdafx.h"
#include "mylib.h"
void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void SetBGColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	color <<= 4;
	wAttributes &= 0xff0f;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void ResizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
bool deleteFile1(char* directory_path) {
	if (remove(directory_path) == -1) return false;
	else return true;
}

void openFile(char* fileName) {
	ShellExecuteA(GetDesktopWindow(), "open", fileName, NULL, NULL, SW_SHOW);
	return;
}
void strcpy_s2(char* destination_string, int Size, char* source_string) {
	int i = 0;
	while (source_string[i] != NULL && i < Size) {
		destination_string[i] = source_string[i];
		i++;
	}
	destination_string[i] = NULL;
	return;
}
void strcat_s2(char* destination_string, char* source_string) {
	int Size = strlen(destination_string) + 1;
	int i = 0;
	int j = Size - 1;
	while (source_string[i] != NULL) {
		destination_string[j] = source_string[i];
		i++; j++;
	}
	destination_string[j] = NULL;
	return;
}
void gotoxy(short int x,short int y) {
	// creates the handle we need to use
	HANDLE OutputH;

	/* the (x,y) position we want to place the cursor at
	Max: y=80 x=50*/
	COORD position = { x, y };

	// grab the handle so we can use it
	OutputH = GetStdHandle(STD_OUTPUT_HANDLE);

	// sets the cursor to the (x,y) position desired
	SetConsoleCursorPosition(OutputH, position);
}
int wherex(void)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	return screen_buffer_info.dwCursorPosition.X;
}
int wherey(void)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	return screen_buffer_info.dwCursorPosition.Y;
}
void textColor(int textColor, int BackColor) {
	// converts the textColor and BackColor to one
	int color = textColor + (BackColor * 16);

	// creates the handle we need to use
	HANDLE Console_Handle;

	// grab the handle so we can use it
	Console_Handle = GetStdHandle(STD_OUTPUT_HANDLE);

	// sets the color desired
	SetConsoleTextAttribute(Console_Handle, color);
}
void anConTro() {
	HANDLE hOut;
	CONSOLE_CURSOR_INFO ConCurInf;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = FALSE;
	SetConsoleCursorInfo(hOut, &ConCurInf);
}
void hienConTro() {
	HANDLE hOut;
	CONSOLE_CURSOR_INFO ConCurInf;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = TRUE;
	SetConsoleCursorInfo(hOut, &ConCurInf);
}
void veNetNgang(int xStart, int xEnd, int y) {
	for (int x = xStart; x <= xEnd; x++) {
		gotoxy(x, y); std::cout << VERTICAL;
	}
}
void veNetDoc(int yStart, int yString, int x) {
	for (int y = yStart; y <= yString; y++) {
		gotoxy(x, y); std::cout << HORIZONTAL;
	}
}
void xoaNetNgang(int xStart, int xEnd, int y) {
	for (int x = xStart; x <= xEnd; x++) {
		gotoxy(x, y); std::cout << " ";
	}
}
void xoaNetDoc(int yStart, int yString, int x) {
	for (int y = yStart; y <= yString; y++) {
		gotoxy(x, y); std::cout << " ";
	}
}
void drawCell(int xStartPoint, int xEndPoint, int yStartPoint, int yEndPoint, int Mode, char* side) {
	if (Mode == 1) {
		veNetNgang(xStartPoint + 1, xEndPoint - 1, yStartPoint);
		veNetNgang(xStartPoint + 1, xEndPoint - 1, yEndPoint);
		veNetDoc(yStartPoint + 1, yEndPoint - 1, xStartPoint);
		veNetDoc(yStartPoint + 1, yEndPoint - 1, xEndPoint);
		gotoxy(xStartPoint, yStartPoint); std::cout << UPPERLEFT;
		gotoxy(xEndPoint, yStartPoint); std::cout << UPPERRIGHT;
		gotoxy(xStartPoint, yEndPoint); std::cout << BOTTOMLEFT;
		gotoxy(xEndPoint, yEndPoint); std::cout << BOTTOMRIGHT;
	}
	if (Mode != 1) {
		if (strcmp(side, "u") == 0) {
			veNetNgang(xStartPoint + 1, xEndPoint - 1, yStartPoint);

			veNetDoc(yStartPoint + 1, yEndPoint - 1, xStartPoint);
			veNetDoc(yStartPoint + 1, yEndPoint - 1, xEndPoint);
			gotoxy(xStartPoint, yStartPoint); std::cout << UPPERLEFT;
			gotoxy(xEndPoint, yStartPoint); std::cout << UPPERRIGHT;
			gotoxy(xStartPoint, yEndPoint); std::cout << Tleft;
			gotoxy(xEndPoint, yEndPoint); std::cout << Tright;
		}
		else if (strcmp(side, "d") == 0) {

			veNetNgang(xStartPoint + 1, xEndPoint - 1, yEndPoint);
			veNetDoc(yStartPoint + 1, yEndPoint - 1, xStartPoint);
			veNetDoc(yStartPoint + 1, yEndPoint - 1, xEndPoint);
			gotoxy(xStartPoint, yStartPoint); std::cout << Tleft;
			gotoxy(xEndPoint, yStartPoint); std::cout << Tright;
			gotoxy(xStartPoint, yEndPoint); std::cout << BOTTOMLEFT;
			gotoxy(xEndPoint, yEndPoint); std::cout << BOTTOMRIGHT;
		}
		else if (strcmp(side, "l") == 0) {
			veNetNgang(xStartPoint + 1, xEndPoint - 1, yStartPoint);
			veNetNgang(xStartPoint + 1, xEndPoint - 1, yEndPoint);
			veNetDoc(yStartPoint + 1, yEndPoint - 1, xStartPoint);

			gotoxy(xStartPoint, yStartPoint); std::cout << UPPERLEFT;
			gotoxy(xEndPoint, yStartPoint); std::cout << Tcross;
			gotoxy(xStartPoint, yEndPoint); std::cout << BOTTOMLEFT;
			gotoxy(xEndPoint, yEndPoint); std::cout << Tinvert;
		}
		else if (strcmp(side, "r") == 0) {
			veNetNgang(xStartPoint + 1, xEndPoint - 1, yStartPoint);
			veNetNgang(xStartPoint + 1, xEndPoint - 1, yEndPoint);

			veNetDoc(yStartPoint + 1, yEndPoint - 1, xEndPoint);
			gotoxy(xStartPoint, yStartPoint); std::cout << Tcross;
			gotoxy(xEndPoint, yStartPoint); std::cout << UPPERRIGHT;
			gotoxy(xStartPoint, yEndPoint); std::cout << Tinvert;
			gotoxy(xEndPoint, yEndPoint); std::cout << BOTTOMRIGHT;
		}
		else if (strcmp(side, "u&l") == 0 || strcmp(side, "l&u") == 0) {
			veNetNgang(xStartPoint + 1, xEndPoint - 1, yStartPoint);
			veNetNgang(xStartPoint + 1, xEndPoint - 1, yEndPoint);
			veNetDoc(yStartPoint + 1, yEndPoint - 1, xStartPoint);
			veNetDoc(yStartPoint + 1, yEndPoint - 1, xEndPoint);
			gotoxy(xStartPoint, yStartPoint); std::cout << UPPERLEFT;
			gotoxy(xEndPoint, yStartPoint); std::cout << UPPERRIGHT;
			gotoxy(xStartPoint, yEndPoint); std::cout << BOTTOMLEFT;
			gotoxy(xEndPoint, yEndPoint); std::cout << CROSS;
		}
		else if (strcmp(side, "u&r") == 0 || strcmp(side, "r&u") == 0) {
			veNetNgang(xStartPoint + 1, xEndPoint - 1, yStartPoint);
			veNetNgang(xStartPoint + 1, xEndPoint - 1, yEndPoint);
			veNetDoc(yStartPoint + 1, yEndPoint - 1, xStartPoint);
			veNetDoc(yStartPoint + 1, yEndPoint - 1, xEndPoint);
			gotoxy(xStartPoint, yStartPoint); std::cout << UPPERLEFT;
			gotoxy(xEndPoint, yStartPoint); std::cout << UPPERRIGHT;
			gotoxy(xStartPoint, yEndPoint); std::cout << CROSS;
			gotoxy(xEndPoint, yEndPoint); std::cout << BOTTOMRIGHT;
		}
		else if (strcmp(side, "d&l") == 0 || strcmp(side, "l&d") == 0) {
			veNetNgang(xStartPoint + 1, xEndPoint - 1, yStartPoint);
			veNetNgang(xStartPoint + 1, xEndPoint - 1, yEndPoint);
			veNetDoc(yStartPoint + 1, yEndPoint - 1, xStartPoint);
			veNetDoc(yStartPoint + 1, yEndPoint - 1, xEndPoint);
			gotoxy(xStartPoint, yStartPoint); std::cout << UPPERLEFT;
			gotoxy(xEndPoint, yStartPoint); std::cout << CROSS;
			gotoxy(xStartPoint, yEndPoint); std::cout << BOTTOMLEFT;
			gotoxy(xEndPoint, yEndPoint); std::cout << BOTTOMRIGHT;
		}
		else if (strcmp(side, "d&r") == 0 || strcmp(side, "r&d") == 0) {
			veNetNgang(xStartPoint + 1, xEndPoint - 1, yStartPoint);
			veNetNgang(xStartPoint + 1, xEndPoint - 1, yEndPoint);
			veNetDoc(yStartPoint + 1, yEndPoint - 1, xStartPoint);
			veNetDoc(yStartPoint + 1, yEndPoint - 1, xEndPoint);
			gotoxy(xStartPoint, yStartPoint); std::cout << CROSS;
			gotoxy(xEndPoint, yStartPoint); std::cout << UPPERRIGHT;
			gotoxy(xStartPoint, yEndPoint); std::cout << BOTTOMLEFT;
			gotoxy(xEndPoint, yEndPoint); std::cout << BOTTOMRIGHT;
		}
		else if (strcmp(side, "ul") == 0 || strcmp(side, "lu") == 0) {
			veNetNgang(xStartPoint + 1, xEndPoint - 1, yStartPoint);

			veNetDoc(yStartPoint + 1, yEndPoint - 1, xStartPoint);

			gotoxy(xStartPoint, yStartPoint); std::cout << UPPERLEFT;
			gotoxy(xEndPoint, yStartPoint); std::cout << Tcross;
			gotoxy(xStartPoint, yEndPoint); std::cout << Tleft;
			gotoxy(xEndPoint, yEndPoint); std::cout << CROSS;
		}
		else if (strcmp(side, "ur") == 0 || strcmp(side, "ru") == 0) {
			veNetNgang(xStartPoint + 1, xEndPoint - 1, yStartPoint);


			veNetDoc(yStartPoint + 1, yEndPoint - 1, xEndPoint);
			gotoxy(xStartPoint, yStartPoint); std::cout << Tcross;
			gotoxy(xEndPoint, yStartPoint); std::cout << UPPERRIGHT;
			gotoxy(xStartPoint, yEndPoint); std::cout << CROSS;
			gotoxy(xEndPoint, yEndPoint); std::cout << Tright;
		}
		else if (strcmp(side, "dl") == 0 || strcmp(side, "ld") == 0) {

			veNetNgang(xStartPoint + 1, xEndPoint - 1, yEndPoint);
			veNetDoc(yStartPoint + 1, yEndPoint - 1, xStartPoint);

			gotoxy(xStartPoint, yStartPoint); std::cout << Tleft;
			gotoxy(xEndPoint, yStartPoint); std::cout << CROSS;
			gotoxy(xStartPoint, yEndPoint); std::cout << BOTTOMLEFT;
			gotoxy(xEndPoint, yEndPoint); std::cout << Tinvert;
		}
		else if (strcmp(side, "dr") == 0 || strcmp(side, "rd") == 0) {

			veNetNgang(xStartPoint + 1, xEndPoint - 1, yEndPoint);

			veNetDoc(yStartPoint + 1, yEndPoint - 1, xEndPoint);
			gotoxy(xStartPoint, yStartPoint); std::cout << CROSS;
			gotoxy(xEndPoint, yStartPoint); std::cout << Tright;
			gotoxy(xStartPoint, yEndPoint); std::cout << Tinvert;
			gotoxy(xEndPoint, yEndPoint); std::cout << BOTTOMRIGHT;
		}
		////////////////////////////////////////////////////////////////////////////////// update
		else if (strcmp(side, "u3l") == 0 || strcmp(side, "l3u") == 0) {
			veNetNgang(xStartPoint + 1, xEndPoint - 1, yStartPoint);

			veNetDoc(yStartPoint + 1, yEndPoint - 1, xStartPoint);

			gotoxy(xStartPoint, yStartPoint); std::cout << UPPERLEFT;
			gotoxy(xEndPoint, yStartPoint); std::cout << Tcross;
			gotoxy(xStartPoint, yEndPoint); std::cout << Tleft;
			gotoxy(xEndPoint, yEndPoint); std::cout << CROSS;
		}
		else if (strcmp(side, "u3r") == 0 || strcmp(side, "r3u") == 0) {
			veNetNgang(xStartPoint + 1, xEndPoint - 1, yStartPoint);


			veNetDoc(yStartPoint + 1, yEndPoint - 1, xEndPoint);
			gotoxy(xStartPoint, yStartPoint); std::cout << Tcross;
			gotoxy(xEndPoint, yStartPoint); std::cout << UPPERRIGHT;
			gotoxy(xStartPoint, yEndPoint); std::cout << CROSS;
			gotoxy(xEndPoint, yEndPoint); std::cout << Tright;
		}
		else if (strcmp(side, "d3l") == 0 || strcmp(side, "l3d") == 0) {

			veNetNgang(xStartPoint + 1, xEndPoint - 1, yEndPoint);
			veNetDoc(yStartPoint + 1, yEndPoint - 1, xStartPoint);

			gotoxy(xStartPoint, yStartPoint); std::cout << Tleft;
			gotoxy(xEndPoint, yStartPoint); std::cout << CROSS;
			gotoxy(xStartPoint, yEndPoint); std::cout << BOTTOMLEFT;
			gotoxy(xEndPoint, yEndPoint); std::cout << Tinvert;
		}
		else if (strcmp(side, "d3r") == 0 || strcmp(side, "r3d") == 0) {

			veNetNgang(xStartPoint + 1, xEndPoint - 1, yEndPoint);

			veNetDoc(yStartPoint + 1, yEndPoint - 1, xEndPoint);
			gotoxy(xStartPoint, yStartPoint); std::cout << CROSS;
			gotoxy(xEndPoint, yStartPoint); std::cout << Tright;
			gotoxy(xStartPoint, yEndPoint); std::cout << Tinvert;
			gotoxy(xEndPoint, yEndPoint); std::cout << BOTTOMRIGHT;
		}
		else if (strcmp(side, "l,u") == 0) {
			veNetNgang(xStartPoint + 1, xEndPoint - 1, yStartPoint);
			veNetNgang(xStartPoint + 1, xEndPoint - 1, yEndPoint);
			veNetDoc(yStartPoint + 1, yEndPoint - 1, xStartPoint);

			gotoxy(xStartPoint, yStartPoint); std::cout << UPPERLEFT;
			gotoxy(xEndPoint, yStartPoint); std::cout << Tcross;
			gotoxy(xStartPoint, yEndPoint); std::cout << BOTTOMLEFT;
			gotoxy(xEndPoint, yEndPoint); std::cout << CROSS;
		}
		else if (strcmp(side, "l,d") == 0) {
			veNetNgang(xStartPoint + 1, xEndPoint - 1, yStartPoint);
			veNetNgang(xStartPoint + 1, xEndPoint - 1, yEndPoint);
			veNetDoc(yStartPoint + 1, yEndPoint - 1, xStartPoint);

			gotoxy(xStartPoint, yStartPoint); std::cout << UPPERLEFT;
			gotoxy(xEndPoint, yStartPoint); std::cout << CROSS;
			gotoxy(xStartPoint, yEndPoint); std::cout << BOTTOMLEFT;
			gotoxy(xEndPoint, yEndPoint); std::cout << Tinvert;

		}
		else if (strcmp(side, "r,u") == 0) {
			veNetNgang(xStartPoint + 1, xEndPoint - 1, yStartPoint);
			veNetNgang(xStartPoint + 1, xEndPoint - 1, yEndPoint);

			veNetDoc(yStartPoint + 1, yEndPoint - 1, xEndPoint);
			gotoxy(xStartPoint, yStartPoint); std::cout << Tcross;
			gotoxy(xEndPoint, yStartPoint); std::cout << UPPERRIGHT;
			gotoxy(xStartPoint, yEndPoint); std::cout << CROSS;
			gotoxy(xEndPoint, yEndPoint); std::cout << BOTTOMRIGHT;
		}
		else if (strcmp(side, "r,d") == 0) {
			veNetNgang(xStartPoint + 1, xEndPoint - 1, yStartPoint);
			veNetNgang(xStartPoint + 1, xEndPoint - 1, yEndPoint);

			veNetDoc(yStartPoint + 1, yEndPoint - 1, xEndPoint);
			gotoxy(xStartPoint, yStartPoint); std::cout << CROSS;
			gotoxy(xEndPoint, yStartPoint); std::cout << UPPERRIGHT;
			gotoxy(xStartPoint, yEndPoint); std::cout << Tinvert;
			gotoxy(xEndPoint, yEndPoint); std::cout << BOTTOMRIGHT;
		}
		else if (strcmp(side, "u,l") == 0) {
			veNetNgang(xStartPoint + 1, xEndPoint - 1, yStartPoint);

			veNetDoc(yStartPoint + 1, yEndPoint - 1, xStartPoint);
			veNetDoc(yStartPoint + 1, yEndPoint - 1, xEndPoint);
			gotoxy(xStartPoint, yStartPoint); std::cout << UPPERLEFT;
			gotoxy(xEndPoint, yStartPoint); std::cout << UPPERRIGHT;
			gotoxy(xStartPoint, yEndPoint); std::cout << Tleft;
			gotoxy(xEndPoint, yEndPoint); std::cout << CROSS;
		}
		else if (strcmp(side, "u,r") == 0) {
			veNetNgang(xStartPoint + 1, xEndPoint - 1, yStartPoint);

			veNetDoc(yStartPoint + 1, yEndPoint - 1, xStartPoint);
			veNetDoc(yStartPoint + 1, yEndPoint - 1, xEndPoint);
			gotoxy(xStartPoint, yStartPoint); std::cout << UPPERLEFT;
			gotoxy(xEndPoint, yStartPoint); std::cout << UPPERRIGHT;
			gotoxy(xStartPoint, yEndPoint); std::cout << CROSS;
			gotoxy(xEndPoint, yEndPoint); std::cout << Tright;
		}
		else if (strcmp(side, "d,l") == 0) {

			veNetNgang(xStartPoint + 1, xEndPoint - 1, yEndPoint);
			veNetDoc(yStartPoint + 1, yEndPoint - 1, xStartPoint);
			veNetDoc(yStartPoint + 1, yEndPoint - 1, xEndPoint);
			gotoxy(xStartPoint, yStartPoint); std::cout << Tleft;
			gotoxy(xEndPoint, yStartPoint); std::cout << CROSS;
			gotoxy(xStartPoint, yEndPoint); std::cout << BOTTOMLEFT;
			gotoxy(xEndPoint, yEndPoint); std::cout << BOTTOMRIGHT;
		}
		else if (strcmp(side, "d,r") == 0) {

			veNetNgang(xStartPoint + 1, xEndPoint - 1, yEndPoint);
			veNetDoc(yStartPoint + 1, yEndPoint - 1, xStartPoint);
			veNetDoc(yStartPoint + 1, yEndPoint - 1, xEndPoint);
			gotoxy(xStartPoint, yStartPoint); std::cout << CROSS;
			gotoxy(xEndPoint, yStartPoint); std::cout << Tright;
			gotoxy(xStartPoint, yEndPoint); std::cout << BOTTOMLEFT;
			gotoxy(xEndPoint, yEndPoint); std::cout << BOTTOMRIGHT;
		}
		/////////////////////////////////////////////////////////////////////////////////
		else if (strcmp(side, "ml") == 0 || strcmp(side, "lm") == 0) {
			veNetNgang(xStartPoint + 1, xEndPoint - 1, yStartPoint);
			veNetNgang(xStartPoint + 1, xEndPoint - 1, yEndPoint);
			veNetDoc(yStartPoint + 1, yEndPoint - 1, xStartPoint);

			gotoxy(xStartPoint, yStartPoint); std::cout << UPPERLEFT;
			gotoxy(xEndPoint, yStartPoint); std::cout << CROSS;
			gotoxy(xStartPoint, yEndPoint); std::cout << BOTTOMLEFT;
			gotoxy(xEndPoint, yEndPoint); std::cout << CROSS;
		}
		else if (strcmp(side, "mr") == 0 || strcmp(side, "rm") == 0) {
			veNetNgang(xStartPoint + 1, xEndPoint - 1, yStartPoint);
			veNetNgang(xStartPoint + 1, xEndPoint - 1, yEndPoint);

			veNetDoc(yStartPoint + 1, yEndPoint - 1, xEndPoint);
			gotoxy(xStartPoint, yStartPoint); std::cout << CROSS;
			gotoxy(xEndPoint, yStartPoint); std::cout << UPPERRIGHT;
			gotoxy(xStartPoint, yEndPoint); std::cout << CROSS;
			gotoxy(xEndPoint, yEndPoint); std::cout << BOTTOMRIGHT;
		}
		//update 2
		else if (strcmp(side, "mu") == 0 || strcmp(side, "um") == 0) {
			veNetNgang(xStartPoint + 1, xEndPoint - 1, yStartPoint);

			veNetDoc(yStartPoint + 1, yEndPoint - 1, xStartPoint);
			veNetDoc(yStartPoint + 1, yEndPoint - 1, xEndPoint);
			gotoxy(xStartPoint, yStartPoint); std::cout << UPPERLEFT;
			gotoxy(xEndPoint, yStartPoint); std::cout << UPPERRIGHT;
			gotoxy(xStartPoint, yEndPoint); std::cout << CROSS;
			gotoxy(xEndPoint, yEndPoint); std::cout << CROSS;
		}
		else if (strcmp(side, "md") == 0 || strcmp(side, "dm") == 0) {

			veNetNgang(xStartPoint + 1, xEndPoint - 1, yEndPoint);
			veNetDoc(yStartPoint + 1, yEndPoint - 1, xStartPoint);
			veNetDoc(yStartPoint + 1, yEndPoint - 1, xEndPoint);
			gotoxy(xStartPoint, yStartPoint); std::cout << CROSS;
			gotoxy(xEndPoint, yStartPoint); std::cout << CROSS;
			gotoxy(xStartPoint, yEndPoint); std::cout << BOTTOMLEFT;
			gotoxy(xEndPoint, yEndPoint); std::cout << BOTTOMRIGHT;
		}
		else if (strcmp(side, "u,ml") == 0 || strcmp(side, "u,lm") == 0) {
			veNetNgang(xStartPoint + 1, xEndPoint - 1, yStartPoint);

			veNetDoc(yStartPoint + 1, yEndPoint - 1, xStartPoint);

			gotoxy(xStartPoint, yStartPoint); std::cout << UPPERLEFT;
			gotoxy(xEndPoint, yStartPoint); std::cout << CROSS;
			gotoxy(xStartPoint, yEndPoint); std::cout << Tleft;

		}
		else if (strcmp(side, "u,mr") == 0 || strcmp(side, "u,rm") == 0) {
			veNetNgang(xStartPoint + 1, xEndPoint - 1, yStartPoint);


			veNetDoc(yStartPoint + 1, yEndPoint - 1, xEndPoint);
			gotoxy(xStartPoint, yStartPoint); std::cout << CROSS;
			gotoxy(xEndPoint, yStartPoint); std::cout << UPPERRIGHT;

			gotoxy(xEndPoint, yEndPoint); std::cout << Tright;
		}
		else if (strcmp(side, "d,ml") == 0 || strcmp(side, "d,lm") == 0) {

			veNetNgang(xStartPoint + 1, xEndPoint - 1, yEndPoint);
			veNetDoc(yStartPoint + 1, yEndPoint - 1, xStartPoint);

			gotoxy(xStartPoint, yStartPoint); std::cout << Tleft;

			gotoxy(xStartPoint, yEndPoint); std::cout << BOTTOMLEFT;
			gotoxy(xEndPoint, yEndPoint); std::cout << CROSS;
		}
		else if (strcmp(side, "d,mr") == 0 || strcmp(side, "d,rm") == 0) {

			veNetNgang(xStartPoint + 1, xEndPoint - 1, yEndPoint);

			veNetDoc(yStartPoint + 1, yEndPoint - 1, xEndPoint);

			gotoxy(xEndPoint, yStartPoint); std::cout << Tright;
			gotoxy(xStartPoint, yEndPoint); std::cout << CROSS;
			gotoxy(xEndPoint, yEndPoint); std::cout << BOTTOMRIGHT;
		}
		else if (strcmp(side, "l,mu") == 0 || strcmp(side, "l,um") == 0) {
			veNetNgang(xStartPoint + 1, xEndPoint - 1, yStartPoint);

			veNetDoc(yStartPoint + 1, yEndPoint - 1, xStartPoint);

			gotoxy(xStartPoint, yStartPoint); std::cout << UPPERLEFT;
			gotoxy(xEndPoint, yStartPoint); std::cout << Tcross;
			gotoxy(xStartPoint, yEndPoint); std::cout << CROSS;

		}
		else if (strcmp(side, "l,md") == 0 || strcmp(side, "l,dm") == 0) {

			veNetNgang(xStartPoint + 1, xEndPoint - 1, yEndPoint);
			veNetDoc(yStartPoint + 1, yEndPoint - 1, xStartPoint);

			gotoxy(xStartPoint, yStartPoint); std::cout << CROSS;

			gotoxy(xStartPoint, yEndPoint); std::cout << BOTTOMLEFT;
			gotoxy(xEndPoint, yEndPoint); std::cout << Tinvert;
		}
		else if (strcmp(side, "r,mu") == 0 || strcmp(side, "r,um") == 0) {
			veNetNgang(xStartPoint + 1, xEndPoint - 1, yStartPoint);


			veNetDoc(yStartPoint + 1, yEndPoint - 1, xEndPoint);
			gotoxy(xStartPoint, yStartPoint); std::cout << Tcross;
			gotoxy(xEndPoint, yStartPoint); std::cout << UPPERRIGHT;

			gotoxy(xEndPoint, yEndPoint); std::cout << CROSS;
		}
		else if (strcmp(side, "r,md") == 0 || strcmp(side, "r,dm") == 0) {

			veNetNgang(xStartPoint + 1, xEndPoint - 1, yEndPoint);

			veNetDoc(yStartPoint + 1, yEndPoint - 1, xEndPoint);

			gotoxy(xEndPoint, yStartPoint); std::cout << CROSS;
			gotoxy(xStartPoint, yEndPoint); std::cout << Tinvert;
			gotoxy(xEndPoint, yEndPoint); std::cout << BOTTOMRIGHT;
		}
		//
	}
}
void joinCell(int xStartPoint, int xEndPoint, int yStartPoint, int yEndPoint, int Mode, char* side) {
	if (Mode == 1) {
		veNetNgang(xStartPoint + 1, xEndPoint - 1, yStartPoint);
		veNetNgang(xStartPoint + 1, xEndPoint - 1, yEndPoint);
		veNetDoc(yStartPoint + 1, yEndPoint - 1, xStartPoint);
		veNetDoc(yStartPoint + 1, yEndPoint - 1, xEndPoint);
		gotoxy(xStartPoint, yStartPoint); std::cout << UPPERLEFT;
		gotoxy(xEndPoint, yStartPoint); std::cout << UPPERRIGHT;
		gotoxy(xStartPoint, yEndPoint); std::cout << BOTTOMLEFT;
		gotoxy(xEndPoint, yEndPoint); std::cout << BOTTOMRIGHT;
	}
	else {
		if (strcmp(side, "u") == 0) {
			veNetNgang(xStartPoint + 1, xEndPoint - 1, yStartPoint);
			xoaNetNgang(xStartPoint + 1, xEndPoint - 1, yEndPoint);
			veNetDoc(yStartPoint + 1, yEndPoint - 1, xStartPoint);
			veNetDoc(yStartPoint + 1, yEndPoint - 1, xEndPoint);
			gotoxy(xStartPoint, yStartPoint); std::cout << UPPERLEFT;
			gotoxy(xEndPoint, yStartPoint); std::cout << UPPERRIGHT;
			gotoxy(xStartPoint, yEndPoint); std::cout << HORIZONTAL;
			gotoxy(xEndPoint, yEndPoint); std::cout << HORIZONTAL;
		}
		else if (strcmp(side, "d") == 0) {
			xoaNetNgang(xStartPoint + 1, xEndPoint - 1, yStartPoint);
			veNetNgang(xStartPoint + 1, xEndPoint - 1, yEndPoint);
			veNetDoc(yStartPoint + 1, yEndPoint - 1, xStartPoint);
			veNetDoc(yStartPoint + 1, yEndPoint - 1, xEndPoint);
			gotoxy(xStartPoint, yStartPoint); std::cout << HORIZONTAL;
			gotoxy(xEndPoint, yStartPoint); std::cout << HORIZONTAL;
			gotoxy(xStartPoint, yEndPoint); std::cout << BOTTOMLEFT;
			gotoxy(xEndPoint, yEndPoint); std::cout << BOTTOMRIGHT;
		}
		else if (strcmp(side, "l") == 0) {
			veNetNgang(xStartPoint + 1, xEndPoint - 1, yStartPoint);
			veNetNgang(xStartPoint + 1, xEndPoint - 1, yEndPoint);
			veNetDoc(yStartPoint + 1, yEndPoint - 1, xStartPoint);
			xoaNetDoc(yStartPoint + 1, yEndPoint - 1, xEndPoint);
			gotoxy(xStartPoint, yStartPoint); std::cout << UPPERLEFT;
			gotoxy(xEndPoint, yStartPoint); std::cout << VERTICAL;
			gotoxy(xStartPoint, yEndPoint); std::cout << BOTTOMLEFT;
			gotoxy(xEndPoint, yEndPoint); std::cout << VERTICAL;
		}
		else if (strcmp(side, "r") == 0) {
			veNetNgang(xStartPoint + 1, xEndPoint - 1, yStartPoint);
			veNetNgang(xStartPoint + 1, xEndPoint - 1, yEndPoint);
			xoaNetDoc(yStartPoint + 1, yEndPoint - 1, xStartPoint);
			veNetDoc(yStartPoint + 1, yEndPoint - 1, xEndPoint);
			gotoxy(xStartPoint, yStartPoint); std::cout << VERTICAL;
			gotoxy(xEndPoint, yStartPoint); std::cout << UPPERRIGHT;
			gotoxy(xStartPoint, yEndPoint); std::cout << VERTICAL;
			gotoxy(xEndPoint, yEndPoint); std::cout << BOTTOMRIGHT;
		}
		else if (strcmp(side, "ul") == 0 || strcmp(side, "lu") == 0) {
			veNetNgang(xStartPoint + 1, xEndPoint - 1, yStartPoint);
			xoaNetNgang(xStartPoint + 1, xEndPoint - 1, yEndPoint);
			veNetDoc(yStartPoint + 1, yEndPoint - 1, xStartPoint);
			xoaNetDoc(yStartPoint + 1, yEndPoint - 1, xEndPoint);
			gotoxy(xStartPoint, yStartPoint); std::cout << UPPERLEFT;
			gotoxy(xEndPoint, yStartPoint); std::cout << VERTICAL;
			gotoxy(xStartPoint, yEndPoint); std::cout << HORIZONTAL;
			gotoxy(xEndPoint, yEndPoint); std::cout << UPPERLEFT;
		}
		else if (strcmp(side, "ur") == 0 || strcmp(side, "ru") == 0) {
			veNetNgang(xStartPoint + 1, xEndPoint - 1, yStartPoint);
			xoaNetNgang(xStartPoint + 1, xEndPoint - 1, yEndPoint);
			xoaNetDoc(yStartPoint + 1, yEndPoint - 1, xStartPoint);
			veNetDoc(yStartPoint + 1, yEndPoint - 1, xEndPoint);
			gotoxy(xStartPoint, yStartPoint); std::cout << VERTICAL;
			gotoxy(xEndPoint, yStartPoint); std::cout << UPPERRIGHT;
			gotoxy(xStartPoint, yEndPoint); std::cout << UPPERRIGHT;
			gotoxy(xEndPoint, yEndPoint); std::cout << HORIZONTAL;
		}
		else if (strcmp(side, "dl") == 0 || strcmp(side, "ld") == 0) {
			xoaNetNgang(xStartPoint + 1, xEndPoint - 1, yStartPoint);
			veNetNgang(xStartPoint + 1, xEndPoint - 1, yEndPoint);
			veNetDoc(yStartPoint + 1, yEndPoint - 1, xStartPoint);
			xoaNetDoc(yStartPoint + 1, yEndPoint - 1, xEndPoint);
			gotoxy(xStartPoint, yStartPoint); std::cout << HORIZONTAL;
			gotoxy(xEndPoint, yStartPoint); std::cout << BOTTOMLEFT;
			gotoxy(xStartPoint, yEndPoint); std::cout << BOTTOMLEFT;
			gotoxy(xEndPoint, yEndPoint); std::cout << VERTICAL;
		}
		else if (strcmp(side, "dr") == 0 || strcmp(side, "rd") == 0) {
			xoaNetNgang(xStartPoint + 1, xEndPoint - 1, yStartPoint);
			veNetNgang(xStartPoint + 1, xEndPoint - 1, yEndPoint);
			xoaNetDoc(yStartPoint + 1, yEndPoint - 1, xStartPoint);
			veNetDoc(yStartPoint + 1, yEndPoint - 1, xEndPoint);
			gotoxy(xStartPoint, yStartPoint); std::cout << BOTTOMRIGHT;
			gotoxy(xEndPoint, yStartPoint); std::cout << HORIZONTAL;
			gotoxy(xStartPoint, yEndPoint); std::cout << VERTICAL;
			gotoxy(xEndPoint, yEndPoint); std::cout << BOTTOMRIGHT;
		}
	}
}
void deleteCell(int xStartPoint, int xEndPoint, int yStartPoint, int yEndPoint, char* side) {
	//////////////////////////////////////////////////////////////////// update
	if (strcmp(side, "u") == 0) {
		xoaNetNgang(xStartPoint + 1, xEndPoint - 1, yStartPoint);
		veNetNgang(xStartPoint + 1, xEndPoint - 1, yEndPoint);
		xoaNetDoc(yStartPoint + 1, yEndPoint - 1, xStartPoint);
		xoaNetDoc(yStartPoint + 1, yEndPoint - 1, xEndPoint);
		gotoxy(xStartPoint, yStartPoint); std::cout << " ";
		gotoxy(xEndPoint, yStartPoint); std::cout << " ";
		gotoxy(xStartPoint, yEndPoint); std::cout << UPPERLEFT;
		gotoxy(xEndPoint, yEndPoint); std::cout << UPPERRIGHT;
	}
	else if (strcmp(side, "d") == 0) {
		veNetNgang(xStartPoint + 1, xEndPoint - 1, yStartPoint);
		xoaNetNgang(xStartPoint + 1, xEndPoint - 1, yEndPoint);
		xoaNetDoc(yStartPoint + 1, yEndPoint - 1, xStartPoint);
		xoaNetDoc(yStartPoint + 1, yEndPoint - 1, xEndPoint);
		gotoxy(xStartPoint, yStartPoint); std::cout << BOTTOMLEFT;
		gotoxy(xEndPoint, yStartPoint); std::cout << BOTTOMRIGHT;
		gotoxy(xStartPoint, yEndPoint); std::cout << " ";
		gotoxy(xEndPoint, yEndPoint); std::cout << " ";
	}
	else if (strcmp(side, "l") == 0) {
		xoaNetNgang(xStartPoint + 1, xEndPoint - 1, yStartPoint);
		xoaNetNgang(xStartPoint + 1, xEndPoint - 1, yEndPoint);
		xoaNetDoc(yStartPoint + 1, yEndPoint - 1, xStartPoint);
		veNetDoc(yStartPoint + 1, yEndPoint - 1, xEndPoint);
		gotoxy(xStartPoint, yStartPoint); std::cout << " ";
		gotoxy(xEndPoint, yStartPoint); std::cout << UPPERLEFT;
		gotoxy(xStartPoint, yEndPoint); std::cout << " ";
		gotoxy(xEndPoint, yEndPoint); std::cout << BOTTOMLEFT;
	}
	else if (strcmp(side, "r") == 0) {
		xoaNetNgang(xStartPoint + 1, xEndPoint - 1, yStartPoint);
		xoaNetNgang(xStartPoint + 1, xEndPoint - 1, yEndPoint);
		veNetDoc(yStartPoint + 1, yEndPoint - 1, xStartPoint);
		xoaNetDoc(yStartPoint + 1, yEndPoint - 1, xEndPoint);
		gotoxy(xStartPoint, yStartPoint); std::cout << UPPERRIGHT;
		gotoxy(xEndPoint, yStartPoint); std::cout << " ";
		gotoxy(xStartPoint, yEndPoint); std::cout << BOTTOMRIGHT;
		gotoxy(xEndPoint, yEndPoint); std::cout << " ";
	}
	else if (strcmp(side, "u3l") == 0 || strcmp(side, "l3u") == 0) {
		xoaNetNgang(xStartPoint + 1, xEndPoint - 1, yStartPoint);

		xoaNetDoc(yStartPoint + 1, yEndPoint - 1, xStartPoint);

		gotoxy(xStartPoint, yStartPoint); std::cout << " ";
		gotoxy(xEndPoint, yStartPoint); std::cout << UPPERLEFT;
		gotoxy(xStartPoint, yEndPoint); std::cout << UPPERLEFT;

	}
	else if (strcmp(side, "u3r") == 0 || strcmp(side, "r3u") == 0) {
		xoaNetNgang(xStartPoint + 1, xEndPoint - 1, yStartPoint);


		xoaNetDoc(yStartPoint + 1, yEndPoint - 1, xEndPoint);
		gotoxy(xStartPoint, yStartPoint); std::cout << UPPERRIGHT;
		gotoxy(xEndPoint, yStartPoint); std::cout << " ";

		gotoxy(xEndPoint, yEndPoint); std::cout << UPPERRIGHT;
	}
	else if (strcmp(side, "d3l") == 0 || strcmp(side, "l3d") == 0) {

		xoaNetNgang(xStartPoint + 1, xEndPoint - 1, yEndPoint);
		xoaNetDoc(yStartPoint + 1, yEndPoint - 1, xStartPoint);

		gotoxy(xStartPoint, yStartPoint); std::cout << BOTTOMLEFT;

		gotoxy(xStartPoint, yEndPoint); std::cout << " ";
		gotoxy(xEndPoint, yEndPoint); std::cout << BOTTOMLEFT;
	}
	else if (strcmp(side, "d3r") == 0 || strcmp(side, "r3d") == 0) {

		xoaNetNgang(xStartPoint + 1, xEndPoint - 1, yEndPoint);

		xoaNetDoc(yStartPoint + 1, yEndPoint - 1, xEndPoint);

		gotoxy(xEndPoint, yStartPoint); std::cout << BOTTOMRIGHT;
		gotoxy(xStartPoint, yEndPoint); std::cout << BOTTOMRIGHT;
		gotoxy(xEndPoint, yEndPoint); std::cout << " ";
	}
	else if (strcmp(side, "l,u") == 0) {
		xoaNetNgang(xStartPoint + 1, xEndPoint - 1, yStartPoint);
		xoaNetNgang(xStartPoint + 1, xEndPoint - 1, yEndPoint);
		xoaNetDoc(yStartPoint + 1, yEndPoint - 1, xStartPoint);

		gotoxy(xStartPoint, yStartPoint); std::cout << " ";
		gotoxy(xEndPoint, yStartPoint); std::cout << UPPERLEFT;
		gotoxy(xStartPoint, yEndPoint); std::cout << " ";
		gotoxy(xEndPoint, yEndPoint); std::cout << Tleft;
	}
	else if (strcmp(side, "l,d") == 0) {
		xoaNetNgang(xStartPoint + 1, xEndPoint - 1, yStartPoint);
		xoaNetNgang(xStartPoint + 1, xEndPoint - 1, yEndPoint);
		xoaNetDoc(yStartPoint + 1, yEndPoint - 1, xStartPoint);

		gotoxy(xStartPoint, yStartPoint); std::cout << " ";
		gotoxy(xEndPoint, yStartPoint); std::cout << Tleft;
		gotoxy(xStartPoint, yEndPoint); std::cout << " ";
		gotoxy(xEndPoint, yEndPoint); std::cout << BOTTOMLEFT;
	}
	else if (strcmp(side, "r,u") == 0) {
		xoaNetNgang(xStartPoint + 1, xEndPoint - 1, yStartPoint);
		xoaNetNgang(xStartPoint + 1, xEndPoint - 1, yEndPoint);

		xoaNetDoc(yStartPoint + 1, yEndPoint - 1, xEndPoint);
		gotoxy(xStartPoint, yStartPoint); std::cout << UPPERRIGHT;
		gotoxy(xEndPoint, yStartPoint); std::cout << " ";
		gotoxy(xStartPoint, yEndPoint); std::cout << Tright;
		gotoxy(xEndPoint, yEndPoint); std::cout << " ";
	}
	else if (strcmp(side, "r,d") == 0) {
		xoaNetNgang(xStartPoint + 1, xEndPoint - 1, yStartPoint);
		xoaNetNgang(xStartPoint + 1, xEndPoint - 1, yEndPoint);

		xoaNetDoc(yStartPoint + 1, yEndPoint - 1, xEndPoint);
		gotoxy(xStartPoint, yStartPoint); std::cout << Tright;
		gotoxy(xEndPoint, yStartPoint); std::cout << " ";
		gotoxy(xStartPoint, yEndPoint); std::cout << BOTTOMRIGHT;
		gotoxy(xEndPoint, yEndPoint); std::cout << " ";
	}
	else if (strcmp(side, "u,l") == 0) {
		xoaNetNgang(xStartPoint + 1, xEndPoint - 1, yStartPoint);

		xoaNetDoc(yStartPoint + 1, yEndPoint - 1, xStartPoint);
		xoaNetDoc(yStartPoint + 1, yEndPoint - 1, xEndPoint);
		gotoxy(xStartPoint, yStartPoint); std::cout << " ";
		gotoxy(xEndPoint, yStartPoint); std::cout << " ";
		gotoxy(xStartPoint, yEndPoint); std::cout << UPPERLEFT;
		gotoxy(xEndPoint, yEndPoint); std::cout << Tcross;
	}
	else if (strcmp(side, "u,r") == 0) {
		xoaNetNgang(xStartPoint + 1, xEndPoint - 1, yStartPoint);

		xoaNetDoc(yStartPoint + 1, yEndPoint - 1, xStartPoint);
		xoaNetDoc(yStartPoint + 1, yEndPoint - 1, xEndPoint);
		gotoxy(xStartPoint, yStartPoint); std::cout << " ";
		gotoxy(xEndPoint, yStartPoint); std::cout << " ";
		gotoxy(xStartPoint, yEndPoint); std::cout << Tcross;
		gotoxy(xEndPoint, yEndPoint); std::cout << UPPERRIGHT;
	}
	else if (strcmp(side, "d,l") == 0) {

		xoaNetNgang(xStartPoint + 1, xEndPoint - 1, yEndPoint);
		xoaNetDoc(yStartPoint + 1, yEndPoint - 1, xStartPoint);
		xoaNetDoc(yStartPoint + 1, yEndPoint - 1, xEndPoint);
		gotoxy(xStartPoint, yStartPoint); std::cout << BOTTOMLEFT;
		gotoxy(xEndPoint, yStartPoint); std::cout << Tinvert;
		gotoxy(xStartPoint, yEndPoint); std::cout << " ";
		gotoxy(xEndPoint, yEndPoint); std::cout << " ";
	}
	else if (strcmp(side, "d,r") == 0) {

		xoaNetNgang(xStartPoint + 1, xEndPoint - 1, yEndPoint);
		xoaNetDoc(yStartPoint + 1, yEndPoint - 1, xStartPoint);
		xoaNetDoc(yStartPoint + 1, yEndPoint - 1, xEndPoint);
		gotoxy(xStartPoint, yStartPoint); std::cout << Tinvert;
		gotoxy(xEndPoint, yStartPoint); std::cout << BOTTOMRIGHT;
		gotoxy(xStartPoint, yEndPoint); std::cout << " ";
		gotoxy(xEndPoint, yEndPoint); std::cout << " ";
	}
	else if (strcmp(side, "ml") == 0 || strcmp(side, "lm") == 0) {
		xoaNetNgang(xStartPoint + 1, xEndPoint - 1, yStartPoint);
		xoaNetNgang(xStartPoint + 1, xEndPoint - 1, yEndPoint);
		xoaNetDoc(yStartPoint + 1, yEndPoint - 1, xStartPoint);

		gotoxy(xStartPoint, yStartPoint); std::cout << " ";
		gotoxy(xEndPoint, yStartPoint); std::cout << Tleft;
		gotoxy(xStartPoint, yEndPoint); std::cout << " ";
		gotoxy(xEndPoint, yEndPoint); std::cout << Tleft;
	}
	else if (strcmp(side, "mr") == 0 || strcmp(side, "rm") == 0) {
		xoaNetNgang(xStartPoint + 1, xEndPoint - 1, yStartPoint);
		xoaNetNgang(xStartPoint + 1, xEndPoint - 1, yEndPoint);

		xoaNetDoc(yStartPoint + 1, yEndPoint - 1, xEndPoint);
		gotoxy(xStartPoint, yStartPoint); std::cout << Tright;
		gotoxy(xEndPoint, yStartPoint); std::cout << " ";
		gotoxy(xStartPoint, yEndPoint); std::cout << Tright;
		gotoxy(xEndPoint, yEndPoint); std::cout << " ";
	}
	else if (strcmp(side, "mu") == 0 || strcmp(side, "um") == 0) {
		xoaNetNgang(xStartPoint + 1, xEndPoint - 1, yStartPoint);

		xoaNetDoc(yStartPoint + 1, yEndPoint - 1, xStartPoint);
		xoaNetDoc(yStartPoint + 1, yEndPoint - 1, xEndPoint);
		gotoxy(xStartPoint, yStartPoint); std::cout << " ";
		gotoxy(xEndPoint, yStartPoint); std::cout << " ";
		gotoxy(xStartPoint, yEndPoint); std::cout << Tcross;
		gotoxy(xEndPoint, yEndPoint); std::cout << Tcross;
	}
	else if (strcmp(side, "md") == 0 || strcmp(side, "dm") == 0) {

		xoaNetNgang(xStartPoint + 1, xEndPoint - 1, yEndPoint);
		xoaNetDoc(yStartPoint + 1, yEndPoint - 1, xStartPoint);
		xoaNetDoc(yStartPoint + 1, yEndPoint - 1, xEndPoint);
		gotoxy(xStartPoint, yStartPoint); std::cout << Tinvert;
		gotoxy(xEndPoint, yStartPoint); std::cout << Tinvert;
		gotoxy(xStartPoint, yEndPoint); std::cout << " ";
		gotoxy(xEndPoint, yEndPoint); std::cout << " ";
	}
	else if (strcmp(side, "u,ml") == 0 || strcmp(side, "u,lm") == 0) {
		xoaNetNgang(xStartPoint + 1, xEndPoint - 1, yStartPoint);

		xoaNetDoc(yStartPoint + 1, yEndPoint - 1, xStartPoint);

		gotoxy(xStartPoint, yStartPoint); std::cout << " ";
		gotoxy(xEndPoint, yStartPoint); std::cout << Tleft;
		gotoxy(xStartPoint, yEndPoint); std::cout << UPPERLEFT;

	}
	else if (strcmp(side, "u,mr") == 0 || strcmp(side, "u,rm") == 0) {
		xoaNetNgang(xStartPoint + 1, xEndPoint - 1, yStartPoint);


		xoaNetDoc(yStartPoint + 1, yEndPoint - 1, xEndPoint);
		gotoxy(xStartPoint, yStartPoint); std::cout << Tright;
		gotoxy(xEndPoint, yStartPoint); std::cout << " ";

		gotoxy(xEndPoint, yEndPoint); std::cout << UPPERRIGHT;
	}
	else if (strcmp(side, "d,ml") == 0 || strcmp(side, "d,lm") == 0) {

		xoaNetNgang(xStartPoint + 1, xEndPoint - 1, yEndPoint);
		xoaNetDoc(yStartPoint + 1, yEndPoint - 1, xStartPoint);

		gotoxy(xStartPoint, yStartPoint); std::cout << BOTTOMLEFT;

		gotoxy(xStartPoint, yEndPoint); std::cout << " ";
		gotoxy(xEndPoint, yEndPoint); std::cout << Tleft;
	}
	else if (strcmp(side, "d,mr") == 0 || strcmp(side, "d,rm") == 0) {

		xoaNetNgang(xStartPoint + 1, xEndPoint - 1, yEndPoint);

		xoaNetDoc(yStartPoint + 1, yEndPoint - 1, xEndPoint);

		gotoxy(xEndPoint, yStartPoint); std::cout << BOTTOMRIGHT;
		gotoxy(xStartPoint, yEndPoint); std::cout << Tright;
		gotoxy(xEndPoint, yEndPoint); std::cout << " ";
	}
	else if (strcmp(side, "l,mu") == 0 || strcmp(side, "l,um") == 0) {
		xoaNetNgang(xStartPoint + 1, xEndPoint - 1, yStartPoint);

		xoaNetDoc(yStartPoint + 1, yEndPoint - 1, xStartPoint);

		gotoxy(xStartPoint, yStartPoint); std::cout << " ";
		gotoxy(xEndPoint, yStartPoint); std::cout << UPPERLEFT;
		gotoxy(xStartPoint, yEndPoint); std::cout << Tcross;

	}
	else if (strcmp(side, "l,md") == 0 || strcmp(side, "l,dm") == 0) {

		xoaNetNgang(xStartPoint + 1, xEndPoint - 1, yEndPoint);
		xoaNetDoc(yStartPoint + 1, yEndPoint - 1, xStartPoint);

		gotoxy(xStartPoint, yStartPoint); std::cout << Tinvert;

		gotoxy(xStartPoint, yEndPoint); std::cout << " ";
		gotoxy(xEndPoint, yEndPoint); std::cout << BOTTOMLEFT;
	}
	else if (strcmp(side, "r,mu") == 0 || strcmp(side, "r,um") == 0) {
		xoaNetNgang(xStartPoint + 1, xEndPoint - 1, yStartPoint);


		xoaNetDoc(yStartPoint + 1, yEndPoint - 1, xEndPoint);
		gotoxy(xStartPoint, yStartPoint); std::cout << UPPERRIGHT;
		gotoxy(xEndPoint, yStartPoint); std::cout << " ";

		gotoxy(xEndPoint, yEndPoint); std::cout << Tcross;
	}
	else if (strcmp(side, "r,md") == 0 || strcmp(side, "r,dm") == 0) {

		xoaNetNgang(xStartPoint + 1, xEndPoint - 1, yEndPoint);

		xoaNetDoc(yStartPoint + 1, yEndPoint - 1, xEndPoint);

		gotoxy(xEndPoint, yStartPoint); std::cout << Tinvert;
		gotoxy(xStartPoint, yEndPoint); std::cout << BOTTOMRIGHT;
		gotoxy(xEndPoint, yEndPoint); std::cout << " ";
	}
	////////////////////////////////////////////////////////////////////////////////////////
}
void drawRow(int xStartPoint, int yStartPoint, int xWidth, int yWidth, int Amount, int Mode, char side) {
	int xUpperLeft = xStartPoint, yUpperLeft = yStartPoint;
	int xUpperRight = xStartPoint + (xWidth + 1)*Amount, yUpperRight = yStartPoint;
	int xBottomLeft = xStartPoint, yBottomLeft = yStartPoint + yWidth + 1;
	int xBottomRight = xUpperRight, yBottomRight = yBottomLeft;
	int x = xStartPoint, y = yStartPoint;
	for (int i = 1; i <= Amount + 1; i++, x += xWidth + 1, y = yStartPoint) {
		if (i == 1) {
			veNetNgang(x + 1, x + xWidth, y); veNetDoc(y + 1, y + yWidth, x);
			y += yWidth + 1;
			veNetNgang(x + 1, x + xWidth, y);
			continue;
		}
		if (i == Amount + 1) {
			veNetDoc(y + 1, y + yWidth, x);
			y += yWidth + 1;
			break;
		}
		gotoxy(x, y);
		if (Mode == 1 || side == 'u') std::cout << Tcross;
		else std::cout << CROSS;
		veNetNgang(x + 1, x + xWidth, y); veNetDoc(y + 1, y + yWidth, x);
		y += yWidth + 1;
		gotoxy(x, y);
		if (Mode == 1 || side == 'd')std::cout << Tinvert;
		else std::cout << CROSS;
		veNetNgang(x + 1, x + xWidth, y);
	}
	if (Mode == 1) {
		gotoxy(xUpperLeft, yUpperLeft); std::cout << UPPERLEFT;
		gotoxy(xUpperRight, yUpperRight); std::cout << UPPERRIGHT;
		gotoxy(xBottomLeft, yBottomLeft); std::cout << BOTTOMLEFT;
		gotoxy(xBottomRight, yBottomRight); std::cout << BOTTOMRIGHT;
	}
	else if (side == 'u') {
		gotoxy(xUpperLeft, yUpperLeft); std::cout << UPPERLEFT;
		gotoxy(xUpperRight, yUpperRight); std::cout << UPPERRIGHT;
		gotoxy(xBottomLeft, yBottomLeft); std::cout << Tleft;
		gotoxy(xBottomRight, yBottomRight); std::cout << Tright;
	}
	else {
		gotoxy(xUpperLeft, yUpperLeft); std::cout << Tleft;
		gotoxy(xUpperRight, yUpperRight); std::cout << Tright;
		gotoxy(xBottomLeft, yBottomLeft); std::cout << BOTTOMLEFT;
		gotoxy(xBottomRight, yBottomRight); std::cout << BOTTOMRIGHT;
	}
}
void deleteRow(int xStartPoint, int yStartPoint, int xWidth, int yWidth, int Amount, int Mode, char side) {
	int xUpperLeft = xStartPoint, yUpperLeft = yStartPoint;
	int xUpperRight = xStartPoint + (xWidth + 1)*Amount, yUpperRight = yStartPoint;
	int xBottomLeft = xStartPoint, yBottomLeft = yStartPoint + yWidth + 1;
	int xBottomRight = xUpperRight, yBottomRight = yBottomLeft;
	int x = xStartPoint, y = yStartPoint;
	for (int i = 1; i <= Amount + 1; i++, x += xWidth + 1, y = yStartPoint) {
		if (i == 1) {
			xoaNetDoc(y + 1, y + yWidth, x);
			if (Mode == 1 || side == 'u') xoaNetNgang(x + 1, x + xWidth, y);
			y += yWidth + 1;
			if (Mode == 1 || side == 'd') xoaNetNgang(x + 1, x + xWidth, y);
			continue;
		}
		if (i == Amount + 1) {
			xoaNetDoc(y + 1, y + yWidth, x);
			y += yWidth + 1;
			break;
		}
		gotoxy(x, y);
		if (Mode == 1 || side == 'u') {
			std::cout << " ";
			xoaNetNgang(x + 1, x + xWidth, y);
		}
		else std::cout << Tinvert;
		xoaNetDoc(y + 1, y + yWidth, x);
		y += yWidth + 1;
		gotoxy(x, y);
		if (Mode == 1 || side == 'd') {
			std::cout << " ";
			xoaNetNgang(x + 1, x + xWidth, y);
		}
		else std::cout << Tcross;
	}
	if (Mode == 1) {
		gotoxy(xUpperLeft, yUpperLeft); std::cout << " ";
		gotoxy(xUpperRight, yUpperRight); std::cout << " ";
		gotoxy(xBottomLeft, yBottomLeft); std::cout << " ";
		gotoxy(xBottomRight, yBottomRight); std::cout << " ";
	}
	else if (side == 'u') {
		gotoxy(xUpperLeft, yUpperLeft); std::cout << " ";
		gotoxy(xUpperRight, yUpperRight); std::cout << " ";
		gotoxy(xBottomLeft, yBottomLeft); std::cout << UPPERLEFT;
		gotoxy(xBottomRight, yBottomRight); std::cout << UPPERRIGHT;
	}
	else {
		gotoxy(xUpperLeft, yUpperLeft); std::cout << BOTTOMLEFT;
		gotoxy(xUpperRight, yUpperRight); std::cout << BOTTOMRIGHT;
		gotoxy(xBottomLeft, yBottomLeft); std::cout << " ";
		gotoxy(xBottomRight, yBottomRight); std::cout << " ";
	}
}
void drawColumn(int xStartPoint, int yStartPoint, int xWidth, int yWidth, int Amount, int Mode, char side) {
	int xUpperLeft = xStartPoint, yUpperLeft = yStartPoint;
	int xUpperRight = xStartPoint + xWidth + 1, yUpperRight = yStartPoint;
	int xBottomLeft = xStartPoint, yBottomLeft = yStartPoint + (yWidth + 1)*Amount;
	int xBottomRight = xUpperRight, yBottomRight = yBottomLeft;
	int x = xStartPoint, y = yStartPoint;
	for (int i = 1; i <= Amount + 1; i++, x = xStartPoint, y += yWidth + 1) {
		if (i == 1) {
			veNetNgang(x + 1, x + xWidth, y); veNetDoc(y + 1, y + yWidth, x);
			x += xWidth + 1;
			veNetDoc(y + 1, y + yWidth, x);
			continue;
		}
		if (i == Amount + 1) {
			veNetNgang(x + 1, x + xWidth, y);
			x += xWidth + 1;
			break;
		}
		gotoxy(x, y);
		if (Mode == 1 || side == 'l') std::cout << Tleft;
		else std::cout << CROSS;
		veNetNgang(x + 1, x + xWidth, y); veNetDoc(y + 1, y + yWidth, x);
		x += xWidth + 1;
		gotoxy(x, y);
		if (Mode == 1 || side == 'r') std::cout << Tright;
		else std::cout << CROSS;
		veNetDoc(y + 1, y + yWidth, x);
	}
	if (Mode == 1) {
		gotoxy(xUpperLeft, yUpperLeft); std::cout << UPPERLEFT;
		gotoxy(xUpperRight, yUpperRight); std::cout << UPPERRIGHT;
		gotoxy(xBottomLeft, yBottomLeft); std::cout << BOTTOMLEFT;
		gotoxy(xBottomRight, yBottomRight); std::cout << BOTTOMRIGHT;
	}
	else if (side == 'l') {
		gotoxy(xUpperLeft, yUpperLeft); std::cout << UPPERLEFT;
		gotoxy(xUpperRight, yUpperRight); std::cout << Tcross;
		gotoxy(xBottomLeft, yBottomLeft); std::cout << BOTTOMLEFT;
		gotoxy(xBottomRight, yBottomRight); std::cout << Tinvert;
	}
	else {
		gotoxy(xUpperLeft, yUpperLeft); std::cout << Tcross;
		gotoxy(xUpperRight, yUpperRight); std::cout << UPPERRIGHT;
		gotoxy(xBottomLeft, yBottomLeft); std::cout << Tinvert;
		gotoxy(xBottomRight, yBottomRight); std::cout << BOTTOMRIGHT;
	}
}
void deleteColumn(int xStartPoint, int yStartPoint, int xWidth, int yWidth, int Amount, int Mode, char side) {
	int xUpperLeft = xStartPoint, yUpperLeft = yStartPoint;
	int xUpperRight = xStartPoint + xWidth + 1, yUpperRight = yStartPoint;
	int xBottomLeft = xStartPoint, yBottomLeft = yStartPoint + (yWidth + 1)*Amount;
	int xBottomRight = xUpperRight, yBottomRight = yBottomLeft;
	int x = xStartPoint, y = yStartPoint;
	for (int i = 1; i <= Amount + 1; i++, x = xStartPoint, y += yWidth + 1) {
		if (i == 1) {
			xoaNetNgang(x + 1, x + xWidth, y);
			if (Mode == 1 || side == 'l') xoaNetDoc(y + 1, y + yWidth, x);
			x += xWidth + 1;
			if (Mode == 1 || side == 'r') xoaNetDoc(y + 1, y + yWidth, x);
			continue;
		}
		if (i == Amount + 1) {
			xoaNetNgang(x + 1, x + xWidth, y);
			x += xWidth + 1;
			break;
		}
		gotoxy(x, y);
		if (Mode == 1 || side == 'l') {
			std::cout << " ";
			xoaNetDoc(y + 1, y + yWidth, x);
		}
		else std::cout << Tright;
		xoaNetNgang(x + 1, x + xWidth, y);
		x += xWidth + 1;
		gotoxy(x, y);
		if (Mode == 1 || side == 'r') {
			std::cout << " ";
			xoaNetDoc(y + 1, y + yWidth, x);
		}
		else std::cout << Tleft;
	}
	if (Mode == 1) {
		gotoxy(xUpperLeft, yUpperLeft); std::cout << " ";
		gotoxy(xUpperRight, yUpperRight); std::cout << " ";
		gotoxy(xBottomLeft, yBottomLeft); std::cout << " ";
		gotoxy(xBottomRight, yBottomRight); std::cout << " ";
	}
	else if (side == 'l') {
		gotoxy(xUpperLeft, yUpperLeft); std::cout << " ";
		gotoxy(xUpperRight, yUpperRight); std::cout << UPPERLEFT;
		gotoxy(xBottomLeft, yBottomLeft); std::cout << " ";
		gotoxy(xBottomRight, yBottomRight); std::cout << BOTTOMLEFT;
	}
	else {
		gotoxy(xUpperLeft, yUpperLeft); std::cout << UPPERRIGHT;
		gotoxy(xUpperRight, yUpperRight); std::cout << " ";
		gotoxy(xBottomLeft, yBottomLeft); std::cout << BOTTOMRIGHT;
		gotoxy(xBottomRight, yBottomRight); std::cout << " ";
	}
}
double lamTronSauDauPhay(double Number, int amount) {
	if (int(Number*pow(10, amount + 1)) % 10 >= 5) return double((int(Number*pow(10, amount + 1))) / 10 + 1) / pow(10, amount);
	else return double((int(Number*pow(10, amount + 1))) / 10) / pow(10, amount);
}
template<class Type>
bool randomArray(Type* array, int sizeofArray, int leftLimit, int rightLimit) {
	if (leftLimit >= rightLimit) return false;
	else if (leftLimit < 0 || rightLimit < 0) return false;
	else if (leftLimit >= sizeofArray || rightLimit >= sizeofArray) return false;
	int realSize = rightLimit - leftLimit + 1;
	int* orderArray = new int[realSize];
	for (int i = 0; i < realSize; i++) orderArray[i] = i;
	int randomValue = 0;
	Type tempArray;
	for (int i = 0; i < realSize - 1; i++) {
		randomValue = rand() % (realSize - i) + i;
		tempArray = array[i + leftLimit];
		array[i + leftLimit] = array[orderArray[randomValue] + leftLimit];
		array[orderArray[randomValue] + leftLimit] = tempArray;
	}
	delete[]orderArray;
	return true;
}
template<class Type>
bool selectionSort(Type* array, int sizeofArray, int leftLimit, int rightLimit, bool increase = true) {
	if (leftLimit > rightLimit) return false;
	else if (leftLimit < 0 || rightLimit < 0) return false;
	else if (leftLimit >= sizeofArray || rightLimit >= sizeofArray) return false;
	if (increase == true) {
		int minLocation = 0;
		Type min;
		Type temp;
		for (int i = leftLimit; i < rightLimit; i++) {
			minLocation = i;
			min = array[i];
			for (int j = i + 1; j <= rightLimit; j++) {
				if (array[j] < min) {
					minLocation = j;
					min = array[j];
				}
			}
			temp = array[i];
			array[i] = min;
			array[minLocation] = temp;
		}
		return true;
	}
	else {
		int maxLocation = 0;
		Type max;
		Type temp;
		for (int i = leftLimit; i < rightLimit; i++) {
			maxLocation = i;
			max = array[i];
			for (int j = i + 1; j <= rightLimit; j++) {
				if (array[j] > max) {
					maxLocation = j;
					max = array[j];
				}
			}
			temp = array[i];
			array[i] = max;
			array[maxLocation] = temp;
		}
		return true;
	}
}
template <class Type>
bool numberToString(Type number, char* String, int SizeOfString) {
	if (number == 0) {
		String[0] = '0';
		String[1] = '\0';
		return true;
	}
	bool am = false;
	Type test = number*-1;
	if (test > number) am = true;
	bool soNguyen = false;
	test = int(number);
	if (test - number == 0) soNguyen = true;
	if (am == true && soNguyen == true) {
		String[0] = NULL;
		int digitAmount = -1;
		number *= -1;
		while (Type(pow(10, digitAmount)) <= number) digitAmount++;
		char Char;
		int number2 = number;
		if (digitAmount >= SizeOfString - 1) return false;
		for (int i = 0; i <= digitAmount - 1; number2 = number, i++) {
			number2 = int(number2 / pow(10, digitAmount - i - 1));
			number2 = int(number2 % 10);
			String[i + 1] = char(number2 + 48);
		}
		String[0] = '-';
		String[digitAmount + 1] = NULL;
		return true;
	}
	else if (am == false && soNguyen == true) {
		String[0] = NULL;
		int digitAmount = 0;
		while (Type(pow(10, digitAmount)) <= number) digitAmount++;
		char Char;
		int number2 = number;
		if (digitAmount >= SizeOfString) return false;
		for (int i = 0; i <= digitAmount - 1; number2 = number, i++) {
			number2 = int(number2 / pow(10, digitAmount - i - 1));
			number2 = int(number2 % 10);
			String[i] = char(number2 + 48);
		}
		String[digitAmount] = NULL;
		return true;
	}
	else if (am == false && soNguyen == false) {
		String[0] = NULL;
		int digitAmount = 0;
		while (Type(pow(10, digitAmount)) <= test) digitAmount++;
		int number2 = test;
		int i;
		for (i = 0; i <= digitAmount - 1; number2 = number, i++) {
			number2 = int(number2 / pow(10, digitAmount - i - 1));
			number2 = int(number2 % 10);
			String[i] = char(number2 + 48);
		}
		String[digitAmount] = '.';
		/////////////////////////////////////////////////////////////////////////////
		while (test - number != 0) {
			number *= 10;
			test = int(number);
		}
		int digitAmount2 = 0;
		while (Type(pow(10, digitAmount2)) <= number) digitAmount2++;
		if (digitAmount2 >= SizeOfString - 1) return false;
		number2 = number;
		for (++i; i <= digitAmount2; number2 = number, i++) {
			number2 = int(number2 / pow(10, digitAmount2 - i));
			number2 = int(number2 % 10);
			String[i] = char(number2 + 48);
		}
		String[digitAmount2 + 1] = NULL;
		return true;
	}
	else if (am == true && soNguyen == false) {
		String[0] = '-';
		int digitAmount = 0;
		number *= -1;
		test *= -1;
		while (Type(pow(10, digitAmount)) <= test) digitAmount++;
		int number2 = test;
		int i;
		for (i = 0; i <= digitAmount - 1; number2 = number, i++) {
			number2 = int(number2 / pow(10, digitAmount - i - 1));
			number2 = int(number2 % 10);
			String[i + 1] = char(number2 + 48);
		}
		String[digitAmount + 1] = '.';
		/////////////////////////////////////////////////////////////////////////////
		while (test - number != 0) {
			number *= 10;
			test = int(number);
		}
		int digitAmount2 = 0;
		while (Type(pow(10, digitAmount2)) <= number) digitAmount2++;
		if (digitAmount2 >= SizeOfString - 2) return false;
		number2 = number;
		for (++i; i <= digitAmount2; number2 = number, i++) {
			number2 = int(number2 / pow(10, digitAmount2 - i));
			number2 = int(number2 % 10);
			String[i + 1] = char(number2 + 48);
		}
		String[digitAmount2 + 2] = NULL;
		return true;
	}
}
template <class Type>
bool stringToNumber(char* String, Type& number) {
	int length = strlen(String);
	int radix = length - 1;
	number = 0;
	for (int i = 0; i < length; i++) {
		number += (int(String[i]) - 48)*pow(10, radix);
		radix--;
	}
	return true;
}
