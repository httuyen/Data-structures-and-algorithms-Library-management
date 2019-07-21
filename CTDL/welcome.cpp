#include "stdafx.h"
#include "welcome.h"

void welcomeConsole() {
	ResizeConsole(windowWeight, windowHeight);
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
void menuFeature(int slFeature,int xStart,int yStart) {
	std::string listMenu[4] = { "QUAN LY DOC GIA                      ",
								"QUAN LY DAU SACH                     ",
								"QUAN LY SACH                         ",
								"THOAT                                "};
	for (int i = 1; i <= slFeature; i++) {
		drawCell(xStart, xStart + 40, yStart, yStart + 2, 1, NULL);
		gotoxy(xStart + 2, yStart + 1); SetBGColor(YELLOW); std::cout << listMenu[i - 1]; SetBGColor(BLACK);
		yStart += 4;
		
	}
	
}
void highLight() {
	SetBGColor(WHITE); std::cout << "                                       ";
}