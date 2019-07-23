#include "stdafx.h"
#include "xuLyDS.h"
using namespace std;
void drawTable() {
	clrscr();
	gotoxy(7,2); cout << "DANH SACH CAC DAU SACH TRONG THU VIEN THEO THE LOAI, TEN SACH TANG DAN THEO THE LOAI";
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
	gotoxy(6, 4); cout << "THE LOAI";
	gotoxy(21, 4); cout << "TEN SACH";
	gotoxy(48, 4); cout << "ISBN";
	gotoxy(55, 4); cout << "TAC GIA";
	gotoxy(86, 4); cout << "SO TR";
	gotoxy(94, 4); cout << "NAM XB";
	int a; cin >> a;
}
void showListDS() {

}