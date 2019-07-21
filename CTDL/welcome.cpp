#include "stdafx.h"
#include "welcome.h"

void welcomeConsole() {
	ResizeConsole(windowWeight, windowHeight);
	anConTro();
	drawFrame();
	SetColor(YELLOW);
	gotoxy(50, 2);  std::cout << "                    @@@                      @   " << std::endl;
	gotoxy(50, 3);  std::cout << " @@@   @    @     @  @  @@   @      @   @   @ @  " << std::endl;
	gotoxy(50, 4);  std::cout << "@   @  @    @    @ @    @ @  @      @    @   @   " << std::endl;
	gotoxy(50, 5);  std::cout << "@   @  @    @   @@@@@   @  @ @      @     @ @    " << std::endl;
	gotoxy(50, 6);  std::cout << "@   @  @    @  @     @  @   @@      @      @     " << std::endl;
	gotoxy(50, 7);  std::cout << " @@@@  @@@@@@ @       @ @    @      @@@@@  @     " << std::endl;
	gotoxy(50, 8);  std::cout << "    @@                                           " << std::endl;
	gotoxy(50, 9);  std::cout << "                                    @            " << std::endl;
	gotoxy(50, 10); std::cout << "                                   @ @           " << std::endl;
	gotoxy(50, 11); std::cout << "@@@@@ @   @ @    @ @    @     @ @ @@@@@ @    @   " << std::endl;
	gotoxy(50, 12); std::cout << "  @   @   @ @    @@     @     @ @ @     @ @  @   " << std::endl;
	gotoxy(50, 13); std::cout << "  @   @@@@@ @    @       @   @  @ @@@@@ @  @ @   " << std::endl;
	gotoxy(50, 14); std::cout << "  @   @   @ @    @        @ @   @ @     @   @@   " << std::endl;
	gotoxy(50, 15); std::cout << "  @   @   @ @@@@@@         @    @ @@@@@ @    @   " << std::endl;
	gotoxy(50, 16); std::cout << "                                    @            " << std::endl;
	SetColor(WHITE);
}
void drawFrame() {
	drawCell(10, 150, 0, 40, 1, NULL);
	drawCell(11, 149, 1, 39, 1, NULL);
}

int index(std::string listMenu[], int i) {
	int index = (42 - listMenu[i - 1].length()) / 2;
	return index;
}
void menuFeature(int slFeature,int xStart,int yStart, int &flag) {
	int yStartConstant = yStart;
	std::string listMenu[4] = { "QUAN LY DOC GIA",
								"QUAN LY DAU SACH",
								"QUAN LY SACH",
								"THOAT"};
	for (int i = 1; i <= slFeature; i++) {
		drawCell(xStart, xStart + 40, yStart, yStart + 2, 1, NULL);
		if (i == 1) {
			SetBGColor(YELLOW);
			SetColor(BLACK);
		}
		//in text
		gotoxy(xStart + index(listMenu,i), yStart + 1);
		std::cout << listMenu[i - 1];
		SetBGColor(BLACK); SetColor(WHITE);
		//end of in text
		yStart += 4;
	}
	selection(flag,listMenu,slFeature,xStart,yStartConstant);
	system("cls");
	std::cout << flag;
}

int selection(int &flag, std::string listMenu[],int slFeature,int xStart, int yStart) {
	flag = 1;
	int key_press;
	int yStartText = yStart + 1;
	do
	{
		key_press = _getch();
		if (key_press == 224) {
			key_press = _getch();
			if (key_press != 13) {
				if (key_press == 72) {
					clearHighLight(flag, listMenu, slFeature, xStart, yStartText, key_press);
				}
				else if (key_press == 80) {
					clearHighLight(flag, listMenu, slFeature, xStart, yStartText, key_press);
				}
				else break;
			}
		}
	} while (key_press != 13);
	return flag;
}
void setDefaultColor() {
	SetColor(WHITE);
	SetBGColor(BLACK);
}
void setHighLightColor() {
	SetColor(BLACK);
	SetBGColor(YELLOW);
}
void clearHighLight(int &flag, std::string listMenu[], int slFeature, int xStart, int yStartText, int keypress) {
	if (keypress == 72) {
		switch (flag)
		{
		case 1:
			gotoxy(xStart + index(listMenu, flag), yStartText);
			setDefaultColor();
			std::cout << listMenu[flag - 1];
			
			flag = slFeature;
			setHighLightColor();
			gotoxy(xStart + index(listMenu, flag), yStartText + 12);
			std::cout << listMenu[flag - 1];
			break;
		case 2:
			gotoxy(xStart + index(listMenu, flag), yStartText + 4);
			setDefaultColor();
			std::cout << listMenu[flag - 1];

			flag--;
			setHighLightColor();
			gotoxy(xStart + index(listMenu, flag), yStartText);
			std::cout << listMenu[flag - 1];
			break;
		case 3:
			gotoxy(xStart + index(listMenu, flag), yStartText + 8);
			setDefaultColor();
			std::cout << listMenu[flag - 1];
			flag--;
			setHighLightColor();
			gotoxy(xStart + index(listMenu, flag), yStartText + 4);
			std::cout << listMenu[flag - 1];
			break;
		case 4:
			gotoxy(xStart + index(listMenu, flag), yStartText + 12);
			setDefaultColor();
			std::cout << listMenu[flag - 1];
			
			flag--;
			setHighLightColor();
			gotoxy(xStart + index(listMenu, flag), yStartText + 8);
			std::cout << listMenu[flag - 1];
			break;
		}
	}
	else {
		switch (flag)
		{
		case 1:
			gotoxy(xStart + index(listMenu, flag), yStartText);
			setDefaultColor();
			std::cout << listMenu[flag - 1];
			flag++;
			setHighLightColor();
			gotoxy(xStart + index(listMenu, flag), yStartText + 4);
			std::cout << listMenu[flag - 1];
			break;
		case 2:
			gotoxy(xStart + index(listMenu, flag), yStartText + 4);
			setDefaultColor();
			std::cout << listMenu[flag - 1];

			flag++;
			setHighLightColor();
			gotoxy(xStart + index(listMenu, flag), yStartText+8);
			std::cout << listMenu[flag - 1];
			break;
		case 3:
			gotoxy(xStart + index(listMenu, flag), yStartText + 8);
			setDefaultColor();
			std::cout << listMenu[flag - 1];
			flag++;
			setHighLightColor();
			gotoxy(xStart + index(listMenu, flag), yStartText + 12);
			std::cout << listMenu[flag - 1];
			break;
		case 4:
			gotoxy(xStart + index(listMenu, flag), yStartText + 12);
			setDefaultColor();
			std::cout << listMenu[flag - 1];
			flag = 1;
			setHighLightColor();
			gotoxy(xStart + index(listMenu, flag), yStartText);
			std::cout << listMenu[flag - 1];
			break;
		}
	}
}