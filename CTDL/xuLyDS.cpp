#include "stdafx.h"
#include "xuLyDS.h"
using namespace std;
void drawTable() {
	clrscr();
	gotoxy(7,2); cout << "DANH SACH CAC DAU SACH TRONG THU VIEN THEO THE LOAI, TEN SACH TANG DAN THEO THE LOAI";
	setHighLightColor();
	//The Loai
	drawCell(5, 20, 3, 36);
	//ten sach
	drawCell(20, 47, 3, 36);
	//ISBN
	drawCell(47, 54, 3, 36);
	//tac gia
	drawCell(54, 85, 3, 36);
	//soTR
	drawCell(85, 93, 3, 36);
	//nam XB
	drawCell(93, 100, 3, 36);
	drawCell(5, 100, 3, 5);
	setDefaultColor();
	gotoxy(6, 4); cout << "THE LOAI";
	gotoxy(21, 4); cout << "TEN SACH";
	gotoxy(48, 4); cout << "ISBN";
	gotoxy(55, 4); cout << "TAC GIA";
	gotoxy(86, 4); cout << "SO TR";
	gotoxy(94, 4); cout << "NAM XB";
	drawEditDS(110,3);
	system("pause");
}
void drawEditDS(int x, int y) {
	gotoxy(x+10, y - 1); cout << "CAP NHAT DAU SACH";
	setHighLightColor(); 
	drawCell(x, x + 40, y, y + 19);
	//draw ISBN frame
	drawCell(x + 10, x + 39, y + 1, y + 3); 
	//draw The loai
	drawCell(x + 10, x + 39, y + 4, y + 6); 
	//draw Ten sach
	drawCell(x + 10, x + 39, y + 7, y + 9); 
	//draw tac gia
	drawCell(x + 10, x + 39, y + 10, y + 12); 
	//draw so trang
	drawCell(x + 10, x + 39, y + 13, y + 15); 
	//draw namxb
	drawCell(x + 10, x + 39, y + 16, y + 18); 
	
	setDefaultColor();
	gotoxy(x + 1, y + 2); cout << "ISBN:";
	gotoxy(x + 1, y + 5); cout << "THE LOAI:";
	gotoxy(x + 1, y + 8); cout << "TEN SACH:";
	gotoxy(x + 1, y + 11); cout << "TAC GIA:";
	gotoxy(x + 1, y + 14); cout << "SO TRANG:";
	gotoxy(x + 1, y + 17); cout << "NAM XB:";
}
void showListDS() {

}
void getEventKey() {

}