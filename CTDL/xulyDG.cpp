#include "stdafx.h"
#include "xulyDG.h"

int xDisplayDG[6] = {7,18,33, 48, 56, 70};

void drawTableDG(Tree &t)
{
	clrscr();
	gotoxy(30, 2); cout << "CAP NHAT DOC GIA";
	setHighLightColor();
	//ma the
	drawCell(5, 16, 3, 36);
	//ho
	drawCell(16, 31, 3, 36);
	//ten
	drawCell(31, 46, 3, 36);
	//phai
	drawCell(46, 54, 3, 36);
	//trang thai the
	drawCell(54, 68, 3, 36);

	drawCell(5, 68, 3, 5);
	setDefaultColor();
	gotoxy(5, 38); cout << "ESC-Thoat, F2 - Them, F3 - Sua, F4 - Xoa, F10 - Luu, PgUP, PgDn";
	gotoxy(xDisplayDG[0], yDisplayDG); cout << "MA THE";
	gotoxy(xDisplayDG[1], yDisplayDG); cout << "HO DG";
	gotoxy(xDisplayDG[2], yDisplayDG); cout << "TEN DG";
	gotoxy(xDisplayDG[3], yDisplayDG); cout << "PHAI";
	gotoxy(xDisplayDG[4], yDisplayDG); cout << "TT THE";

	/*for (int i = 0; i < 29; i++) {
		gotoxy(7, (4 + 3 + i)); cout << "hoa";
		gotoxy(18, (4 + 3 + i)); cout << "HO DG";
		DeleteLineTable_DG(i);
	}*/

	drawEditDG(71, 3);
	//drawNoti(110, 24);
	//clrscr();
	//showListDS(lds, pDS);
	//system("pause");
}

void drawEditDG(int x, int y)
{
	gotoxy(x + 15, y - 1); cout << "CAP NHAT DOC GIA";
	setHighLightColor();
	drawCell(x, x + 45, y, y + 16);
	//draw ma the
	drawCell(x + 15, x + 44, y + 1, y + 3);
	//draw ho
	drawCell(x + 15, x + 44, y + 4, y + 6);
	//draw Ten
	drawCell(x + 15, x + 44, y + 7, y + 9);
	//draw phai
	drawCell(x + 15, x + 44, y + 10, y + 12);
	//draw trang thai the
	drawCell(x + 15, x + 44, y + 13, y + 15);

	setDefaultColor();
	gotoxy(x + 2, y + 2); cout << "MA THE:";
	gotoxy(x + 2, y + 5); cout << "HO DOC GIA:";
	gotoxy(x + 2, y + 8); cout << "TEN DOC GIA:";
	gotoxy(x + 2, y + 11); cout << "PHAI:";
	gotoxy(x + 2, y + 14); cout << "TRANG THAI:";
}

void DeleteLineTable_DG(int locate)
{
	gotoxy(xDisplayDG[0], yDisplayDG + 3 + locate);
	cout << setw(xDisplayDG[1] - xDisplayDG[0] - 3) << setfill(' ') << ' ';
	gotoxy(xDisplayDG[1], yDisplayDG + 3 + locate);
	cout << setw(xDisplayDG[2] - xDisplayDG[1] - 3) << setfill(' ') << ' ';
	gotoxy(xDisplayDG[2], yDisplayDG + 3 + locate);
	cout << setw(xDisplayDG[3] - xDisplayDG[2] - 3) << setfill(' ') << ' ';
	gotoxy(xDisplayDG[3], yDisplayDG + 3 + locate);
	cout << setw(xDisplayDG[4] - xDisplayDG[3] - 3) << setfill(' ') << ' ';
	gotoxy(xDisplayDG[4], yDisplayDG + 3 + locate);
	cout << setw(xDisplayDG[5] - xDisplayDG[4] - 3) << setfill(' ') << ' ';
}

void ClearTable_DG()
{
	for (int i = 0; i < NUMBER_LINES; i++)
		DeleteLineTable_DG(i);
}

void Output_DG(NODE_TREE* dg, int locate)
{
	DeleteLineTable_DG(1);
	gotoxy(xDisplayDG[0], yDisplayDG + 3 + locate);
	cout << dg->data.info.maThe;
	gotoxy(xDisplayDG[1], yDisplayDG + 3 + locate);
	cout << dg->data.info.ho;
	gotoxy(xDisplayDG[2], yDisplayDG + 3 + locate);
	cout << dg->data.info.ten;
	gotoxy(xDisplayDG[3], yDisplayDG + 3 + locate);
	cout << dg->data.info.phai;
	gotoxy(xDisplayDG[4], yDisplayDG + 3 + locate);
	(dg->data.info.trangThai == 0) ? cout << "KHOA" : cout << "HOAT DONG";
}

void OutputDG_PerPage(Tree t, ListTempDG &l, int index)
{
	ClearTable_DG();
	//SetColor(WHITE);
	//locate = 0;
	NodeTempDG * temp1 = NULL;
	NODE_TREE* temp2 = NULL;
	index--;
	for (int i = NUMBER_LINES * index; i < NUMBER_LINES * (index + 1); i++)
	{
		temp1 = Search_TempDG(l, i);
		if (temp1 == NULL)
		{
			return;
		}
		temp2 = Find_DG(t, temp1->tl.MADG);
		Output_DG(temp2, (i-29*index));
	}
}

int Output_ListDG(Tree &t, ListTempDG &l, theDocGia &dg, int &tttrang)
{
	//NODE_TEMPLIST * temp1 = NULL;
	NODE_TREE* temp2 = NULL;
	int choose;
	bool check;

	// nDG la so DG hien co trong cay
	int nDG = countDG(t);

	// thu tu trang
	int  tongtrang;
	tongtrang = (nDG / NUMBER_LINES) + 1;
	OutputDG_PerPage(t, l, tttrang);

	int kb_hit;
	do
	{
		if (_kbhit())
		{
			kb_hit = _getch();
			if (kb_hit == 224 || kb_hit == 0)
				kb_hit = _getch();
			switch (kb_hit)
			{
			case PAGE_UP:

				(tttrang > 1) ? tttrang-- : tttrang = tongtrang;
				OutputDG_PerPage(t, l, tttrang);
				break;

			case PAGE_DOWN:
				(tttrang < tongtrang) ? tttrang++ : tttrang = 1;
				OutputDG_PerPage(t, l, tttrang);
				break;

				// them
			case KEY_F2:
				Beep(600, 100);
				Update_DG(t, dg, false);
				ClearAll_TempDG(l);
				return 1;

				// hieu chinh
			/*case  KEY_F3:
				Beep(600, 100);
				choose = ChooseItems(t, l, tttrang, tongtrang);
				temp1 = BinarySearch_TEMPLIST(l, choose);

				// check cac truong hop.
				if (temp1 == NULL)
				{
					return 1;
				}
				else
				{
					temp2 = Find_DG(t, temp1->tl.MADG);
					Update_DG(t, temp2->DG, true);
					ClearAll_TEMPLIST(l);
					return 1;
				}

				// xoa
			case KEY_F4:
				Beep(600, 100);
				choose = ChooseItems(t, l, tttrang, tongtrang);
				temp1 = BinarySearch_TEMPLIST(l, choose);

				// truong hop khong chon doc gia nao.
				if (temp1 == NULL)
				{
					return 1;
				}
				else
				{
					temp2 = Find_DG(t, temp1->tl.MADG);
					if (SoSachDangMuon(temp2->mt) > 0)
					{
						gotoxy(75, 20);
						cout << "Doc Gia da muon sach nen khong duoc phep xoa !";
						_getch();
						gotoxy(75, 20);
						cout << "                                                      ";
						return 1;
					}
					else
					{
						// check dung de thong bao check thanh cong
						check = IsDeleted_DG(t, temp2->DG);
						ClearAll_TEMPLIST(l);
						return 1;
					}
				}

			case ESC:
				Beep(600, 100);
				ClearAll_TEMPLIST(l);
				return 0;*/
			}
		}
		//ShowCur(false);
		gotoxy(30, 36);
		cout << "Trang " << tttrang << " / " << tongtrang;
	} while (true);
}

void Menu_DocGia(Tree &t)
{
	clrscr();
	//normalBGColor();
	int tttrang = 1;
	int esc = 1;

	do
	{
		clrscr();
		theDocGia dg;
		int index = 0;

	
		ListTempDG l;
		initList_TempDG(l);
		CreateList_TempDG(t, l, index);
		drawTableDG(t);
		esc = Output_ListDG(t, l, dg, tttrang);
	} while (esc);
}

void InDocGia(Tree t)
{
	clrscr();
	//normalBGColor();
	//ShowCur(false);

	int c = 0;
	int chosen = 0;
	while (c != ESC)
	{
		clrscr();
		//SetColor(BRIGHT_WHITE);
		gotoxy(xORDER_DG, yORDER_DG);
		cout << " THEO THU TU TEN_HO TANG DAN ";
		gotoxy(xORDER_DG, yORDER_DG + 2);
		cout << " THEO THU TU MA_DG TANG DAN  ";
		while (c != ENTER)
		{
			//SetColor(LIGHT_GREEN);
			gotoxy(xORDER_DG - 3, yORDER_DG + chosen);
			cout << "->";
			gotoxy(xORDER_DG + 30, yORDER_DG + chosen);
			cout << "<-";
			c = _getch();

			if (c == KEY_UP || c == KEY_DOWN)
			{
				gotoxy(xORDER_DG - 3, yORDER_DG + chosen);
				cout << "   ";
				gotoxy(xORDER_DG + 30, yORDER_DG + chosen);
				cout << "   ";

				if (chosen == 0)
				{
					chosen = 2;
				}
				else if (chosen == 2)
				{
					chosen = 0;
				}
			}
			else if (c == ESC)
			{
				return;
			}
		}
		/*if (chosen == 0)
		{
			index = 0;
			TEN_HO* ArrTenHo = new TEN_HO[nDG];
			Create_ArrTenHo(t, ArrTenHo);
			DisplayDG(keyDisplayDG, 5, xDisplayDG);
			QuicKsort_ARRTenHo(ArrTenHo, 0, nDG - 1);
			Output_ListDG1(t, ArrTenHo);

			// xoa vung nho
			delete[] ArrTenHo;
		}
		else if (chosen == 2)
		{
			index = 0;

			// su dung cap phat dong.
			uint* arrMADG = new uint[nDG];
			DisplayDG(keyDisplayDG, 5, xDisplayDG);
			Create_ArrMADG(t, arrMADG);
			Output_ListDG2(t, arrMADG);

			// xoa vung nho
			delete[]arrMADG;
		}*/
		//c = 0;
		//chosen = 0;
	}
}