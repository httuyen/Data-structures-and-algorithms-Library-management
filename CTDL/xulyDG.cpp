#include "stdafx.h"
#include "xulyDG.h"

int xDisplayDG[6] = {7,18,33, 48, 56, 70};

void drawTableDG()
{
	setDefaultColor();
	clrscr();
	gotoxy(30, 2); cout << "DANH SACH DOC GIA";
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
	//gotoxy(5, 38); cout << "ESC-Thoat, F2 - Them, F3 - Sua, F4 - Xoa, F10 - Luu, PgUP, PgDn";
	gotoxy(xDisplayDG[0], yDisplayDG); cout << "MA THE";
	gotoxy(xDisplayDG[1], yDisplayDG); cout << "HO DG";
	gotoxy(xDisplayDG[2], yDisplayDG); cout << "TEN DG";
	gotoxy(xDisplayDG[3], yDisplayDG); cout << "PHAI";
	gotoxy(xDisplayDG[4], yDisplayDG); cout << "TT THE";

	//drawEditDG(xEDIT_DG, yEDIT_DG);
	//drawNotiDG(xNOTI_DG, yNOTI_DG);
	//clrscr();
	//showListDS(lds, pDS);
	//system("pause");
}

void drawTableTop10()
{
	setDefaultColor();
	clrscr();
	gotoxy(15, 2); cout << "TOP 10 DAU SACH CO SO LUOT MUON NHIEU NHAT";
	setHighLightColor();
	// so thu tu
	drawCell(5, 19, 3, 17);
	// ten sach
	drawCell(19, 44, 3, 17);
	// so luot muon
	drawCell(44, 61, 3, 17);

	drawCell(5, 61, 3, 5);
	setDefaultColor();
	//gotoxy(5, 38); cout << "ESC-Thoat, F2 - Them, F3 - Sua, F4 - Xoa, F10 - Luu, PgUP, PgDn";
	gotoxy(xDisplayDG[0], yDisplayDG); cout << "SO THU TU";
	gotoxy(xDisplayDG[1], yDisplayDG); cout << "TEN SACH";
	gotoxy(xDisplayDG[2], yDisplayDG); cout << "SO LUOT MUON";
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

void drawNotiDG(int x, int y) {
	gotoxy(x + 15, y); cout << "THONG BAO";
	setHighLightColor();
	// dong thong bao
	drawCell(x, x + 45, y + 1, y + 3);
	// bang ghi chu
	drawCell(x, x + 45, y + 5, y + 15);
	setDefaultColor();
	gotoxy(x + 2, y + 7); cout << "MA THE: duoc tao tu dong\n";
	gotoxy(x + 2, y + 8); cout << "HO DOC GIA: toi da 10 ky tu\n";
	gotoxy(x + 2, y + 9); cout << "TEN DOC GIA: toi da 10 ky tu\n";
	gotoxy(x + 2, y + 10); cout << "PHAI: 0 = NU, 1 = NAM\n";
	gotoxy(x + 2, y + 11); cout << "TRANG THAI: 0 = KHOA, 1 = HOAT DONG\n";
}

int ChooseItems(Tree &t, ListTempDG &l, int tttrang, int tongtrang)
{
	int pos = 0;
	int kb_hit;
	pos = 0;
	SetColor(YELLOW);
	gotoxy(xDisplayDG[0] - 1, yDisplayDG + 3 + pos);
	cout << "<";
	gotoxy(xDisplayDG[0] + 8, yDisplayDG + 3 + pos);
	cout << ">";
	while (true)
	{
		if (_kbhit())
		{
			kb_hit = _getch();
			if (kb_hit == 224 || kb_hit == 0)
				kb_hit = _getch();

			switch (kb_hit)
			{
			case KEY_UP:
				// xoa muc truoc
				gotoxy(xDisplayDG[0] - 1, yDisplayDG + 3 + pos);
				cout << " ";
				gotoxy(xDisplayDG[0] + 8, yDisplayDG + 3 + pos);
				cout << " ";

				(pos > 0) ? pos-- : pos = 28;

				// to mau muc moi
				SetColor(YELLOW);
				gotoxy(xDisplayDG[0] - 1, yDisplayDG + 3 + pos);
				cout << "<";
				gotoxy(xDisplayDG[0] + 8, yDisplayDG + 3 + pos);
				cout << ">";
				break;

			case KEY_DOWN:
				// xoa muc truoc
				gotoxy(xDisplayDG[0] - 1, yDisplayDG + 3 + pos);
				cout << " ";
				gotoxy(xDisplayDG[0] + 8, yDisplayDG + 3 + pos);
				cout << " ";

				(pos < NUMBER_LINES - 1) ? pos++ : pos = 0;

				// to mau muc moi
				SetColor(YELLOW);
				gotoxy(xDisplayDG[0] - 1, yDisplayDG + 3 + pos);
				cout << "<";
				gotoxy(xDisplayDG[0] + 8, yDisplayDG + 3 + pos);
				cout << ">";
				break;

			case PAGE_UP:
				if (tttrang > 1)
				{
					tttrang--;
				}
				else
				{
					tttrang = tongtrang;
				}
				OutputDG_PerPage(t, l, tttrang);

				// high light hang dau.
				pos = 0;
				SetColor(YELLOW);
				gotoxy(xDisplayDG[0] - 1, yDisplayDG + 3 + pos);
				cout << "<";
				gotoxy(xDisplayDG[0] + 8, yDisplayDG + 3 + pos);
				cout << ">";
				break;

			case PAGE_DOWN:
				if (tttrang < tongtrang)
				{
					tttrang++;
				}
				else
				{
					tttrang = 1;

				}

				OutputDG_PerPage(t, l, tttrang);

				// high light hang dau.
				pos = 0;
				SetColor(YELLOW);
				gotoxy(xDisplayDG[0] - 1, yDisplayDG + 3 + pos);
				cout << "<";
				gotoxy(xDisplayDG[0] + 8, yDisplayDG + 3 + pos);
				cout << ">";
				break;

			case ENTER:

				// tra ve vi tri pos.
				return (pos == 0 && tttrang == 1) ? pos : pos + (tttrang - 1)* NUMBER_LINES;
			}
		}
		anConTro();
		SetColor(WHITE);
		gotoxy(30, 40);
		cout << "Trang " << tttrang << " / " << tongtrang;
		//normalBGColor();
	}
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
	DeleteLineTable_DG(locate);
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
	//setDefaultColor();
	ClearTable_DG();
	//SetColor(WHITE);
	//locate = 0;
	NodeTempDG * temp1 = NULL;
	NODE_TREE* temp2 = NULL;
	index--;
	for (int i = NUMBER_LINES * index; i < NUMBER_LINES * (index + 1); i++)
	{
		temp1 = Search_TempDG(l, i);
		if (temp1 == nullptr)
		{
			return;
		}
		temp2 = Find_DG(t, temp1->tl.MADG);
		Output_DG(temp2, (i-29*index));
	}
}

void OutputDG_PerPage_STH(Tree t, TenHo *arr, int index)
{
	ClearTable_DG();
	index--;
	NODE_TREE* temp = NULL;
	int nDG = countDG(t);

	if (t == NULL)
		return;
	else
	{
		for (int i = NUMBER_LINES * index; i < NUMBER_LINES*(1 + index) && i < nDG; i++)
		{
			temp = Find_DG(t, arr[i].MADG);
			Output_DG(temp, (i - 29 * index));
		}
	}
}

int Output_ListDG(Tree &t, ListTempDG &l, theDocGia &dg, int &tttrang)
{
	NodeTempDG * temp1 = NULL;
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
			case KEY_F2:{
				Beep(600, 100);
				Update_DG(t, dg, false);
				ClearAll_TempDG(l);
				return 1;}

				// hieu chinh
			case  KEY_F3:
				Beep(600, 100);
				choose = ChooseItems(t, l, tttrang, tongtrang);
				temp1 = Search_TempDG(l, choose);

				// check cac truong hop.
				if (temp1 == NULL)
				{
					return 1;
				}
				else
				{
					temp2 = Find_DG(t, temp1->tl.MADG);
					Update_DG(t, temp2->data.info, true);
					ClearAll_TempDG(l);
					return 1;
				}

				// xoa
			case KEY_F4:
				Beep(600, 100);
				choose = ChooseItems(t, l, tttrang, tongtrang);
				temp1 = Search_TempDG(l, choose);

				// truong hop khong chon doc gia nao.
				if (temp1 == NULL)
				{
					return 1;
				}
				else
				{
					temp2 = Find_DG(t, temp1->tl.MADG);
					if (temp2->data.listMT.n > 0)
					{
						gotoxy(xNOTI_DG + 2, yNOTI_DG + 2);
						cout << "(X) DOC GIA NAY DANG MUON SACH !!!";
						_getch();
						gotoxy(75, 20);
						cout << "                                                      ";
						return 1;
					}
					else
					{
						// check dung de thong bao check thanh cong
						check = IsDeleted_DG(t, temp2->data.info);
						if (check)
						{
							gotoxy(xNOTI_DG + 2, yNOTI_DG + 2);
							cout << "        XOA THANH CONG !!!";
							Sleep(800);
						}
						ClearAll_TempDG(l);
						return 1;
					}
				}

			case ESC:
				Beep(600, 100);
				ClearAll_TempDG(l);
				return 0;
			}
		}
		anConTro();
		gotoxy(30, 38);
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

		drawTableDG();
		gotoxy(5, 40); cout << "ESC-Thoat, F2 - Them, F3 - Sua, F4 - Xoa, F10 - Luu, PgUP, PgDn";
		drawEditDG(xEDIT_DG, yEDIT_DG);
		drawNotiDG(xNOTI_DG, yNOTI_DG);

		esc = Output_ListDG(t, l, dg, tttrang);
	} while (esc);
}

void ListDG_Sort_MDG(Tree &t, ListTempDG &l, int &tttrang)
{
	//setDefaultColor();
	anConTro();
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

			case ESC:
				Beep(600, 100);
				return;
			}
		}
		gotoxy(xORDER_DG - 3, yORDER_DG + 2);
		cout << "<< THEO THU TU MA_DG TANG DAN >>";
		gotoxy(25, 40);
		cout << "HotKey: PgUp, PgDn, ESC ";
		gotoxy(30, 38);
		cout << "Trang " << tttrang << " / " << tongtrang;
	} while (true);
}

void ListDG_Sort_TenHo(Tree t, TenHo *arr)
{
	//setDefaultColor();
	anConTro();
	int nDG = countDG(t);

	// thu tu trang
	int tttrang, tongtrang;
	tttrang = 1;
	tongtrang = (nDG / NUMBER_LINES) + 1;
	OutputDG_PerPage_STH(t, arr, tttrang);

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
				OutputDG_PerPage_STH(t, arr, tttrang);
				break;

			case PAGE_DOWN:
				(tttrang < tongtrang) ? tttrang++ : tttrang = 1;
				OutputDG_PerPage_STH(t, arr, tttrang);
				break;

			case ESC:
				Beep(600, 100);
				return;
			}
		}
		gotoxy(xORDER_DG - 3, yORDER_DG);
		cout << "<< THEO THU TU TEN_HO TANG DAN >>";
		gotoxy(25, 40);
		cout << "HotKey: PgUp, PgDn, ESC ";
		gotoxy(30, 38);
		cout << "Trang " << tttrang << " / " << tongtrang;
	} while (true);
}

void InDocGia(Tree t)
{
	clrscr();
	anConTro();

	int nDG = countDG(t);
	int c = 0;
	int chosen = 0;
	while (c != ESC)
	{
		clrscr();
		//SetColor(BRIGHT_WHITE);
		setDefaultColor();
		gotoxy(xORDER_DG, yORDER_DG);
		cout << " THEO THU TU TEN_HO TANG DAN ";
		gotoxy(xORDER_DG, yORDER_DG + 2);
		cout << " THEO THU TU MA_DG TANG DAN  ";
		while (c != ENTER)
		{
			//SetColor(LIGHT_GREEN);
			/*gotoxy(xORDER_DG - 3, yORDER_DG + chosen);
			cout << "<<";
			gotoxy(xORDER_DG + 30, yORDER_DG + chosen);
			cout << ">>";*/
			if (chosen == 0) {
				setHighLightColor();
				gotoxy(xORDER_DG, yORDER_DG);
				cout << " THEO THU TU TEN_HO TANG DAN ";
				setDefaultColor();
				gotoxy(xORDER_DG, yORDER_DG + 2);
				cout << " THEO THU TU MA_DG TANG DAN  ";
			}
			else {
				setDefaultColor();
				gotoxy(xORDER_DG, yORDER_DG);
				cout << " THEO THU TU TEN_HO TANG DAN ";
				setHighLightColor();
				gotoxy(xORDER_DG, yORDER_DG + 2);
				cout << " THEO THU TU MA_DG TANG DAN  ";
			}
			
			c = _getch();

			if (c == KEY_UP || c == KEY_DOWN)
			{
				/*gotoxy(xORDER_DG - 3, yORDER_DG + chosen);
				cout << "   ";
				gotoxy(xORDER_DG + 30, yORDER_DG + chosen);
				cout << "   ";*/
				if (chosen == 0) {
					chosen = 2;
					setHighLightColor();
					gotoxy(xORDER_DG, yORDER_DG);
					cout << " THEO THU TU TEN_HO TANG DAN ";
					setDefaultColor();
					gotoxy(xORDER_DG, yORDER_DG + 2);
					cout << " THEO THU TU MA_DG TANG DAN  ";
				}
				else if (chosen == 2) {
					chosen = 0;
					setDefaultColor();
					gotoxy(xORDER_DG, yORDER_DG);
					cout << " THEO THU TU TEN_HO TANG DAN ";
					setHighLightColor();
					gotoxy(xORDER_DG, yORDER_DG + 2);
					cout << " THEO THU TU MA_DG TANG DAN  ";
				}

				/*if (chosen == 0)
				{
					chosen = 2;
				}
				else if (chosen == 2)
				{
					chosen = 0;
				}*/
			}
			else if (c == ESC)
			{
				return;
			}
		}
		if (chosen == 0)
		{
			int index = 0;
			TenHo* ArrTenHo = new TenHo[nDG];
			Create_ArrTenHo(t, ArrTenHo, index);
			drawTableDG();
			QuicKsort_ARRTenHo(ArrTenHo, 0, nDG - 1);
			ListDG_Sort_TenHo(t, ArrTenHo);

			// xoa vung nho
			delete[] ArrTenHo;
		}
		else if (chosen == 2)
		{
			clrscr();
			//normalBGColor();
			int tttrang = 1;
			int index = 0;
			ListTempDG l;

			initList_TempDG(l);
			CreateList_TempDG(t, l, index);
			drawTableDG();
			ListDG_Sort_MDG(t, l, tttrang);	
		}
		c = 0;
		chosen = 0;
	}
}

void DanhSachQuaHan(Tree t, LIST_DauSach lDS)
{
	clrscr();
	int nDG_MAX = countDG(t);

	// tao mang phu de xu ly.
	QuaHan *ArrQuaHan = new QuaHan[nDG_MAX];

	int ndg = 0;

	// duyet cay NLR khong de quy
	const int STACKSIZE = 500;
	NODE_TREE* Stack[STACKSIZE];
	int sp = -1;	// Khoi tao Stack rong
	NODE_TREE* p = t;
	while (p != NULL)
	{
		// cap nhat du lieu vao mang.
		ArrQuaHan[ndg].docGia.MADG = p->data.info.maThe;
		char* ho = strcat(p->data.info.ho, " ");
		ArrQuaHan[ndg].docGia.hoten = strcat(ho, p->data.info.ten);
		ArrQuaHan[ndg].sachQuaHan = TimSachQuaHan(p->data.listMT, lDS);
		//ArrQuaHan[ndg].soNgayQuaHan = SoNgayQuaHan(p->data.listMT);
		
		
		ndg++;
		if (p->pRight != NULL)
			Stack[++sp] = p->pRight;
		if (p->pLeft != NULL)
			p = p->pLeft;
		else if (sp == -1)
			break;
		else p = Stack[sp--];
	}

	// quicksort ArrQuaHan theo thu tu giam dan.
	Sort_QuaHan(ArrQuaHan, 0, ndg - 1);

	// in thong tin ra ngoai man hinh.
	string text = "DANH SACH DOC GIA MUON QUA HAN ";
	//CreateBox(48, 2, text, (int)text.length());
	//SetBGColor(GREEN);

	gotoxy(47, 2);
	cout << "DANH SACH DOC GIA MUON QUA HAN ";
	gotoxy(3, 5);
	cout << "STT";
	gotoxy(10, 5);
	cout << "MA DOC GIA";
	gotoxy(25, 5);
	cout << "HO TEN DOC GIA";
	gotoxy(48, 5);
	cout << "MA SACH";
	gotoxy(65, 5);
	cout << "TEN SACH";
	gotoxy(80, 5);
	cout << "NGAY MUON";
	gotoxy(100, 5);
	cout << "TONG SO NGAY QUA HAN";
	//normalBGColor();
	//SetColor(WHITE);

	// in danh sach doc gia muon qua han theo thoi gian giam dan.
	int j = 0;
	for (int i = 0; i < ndg; i++)
	{
		if (ArrQuaHan[i].sachQuaHan.soNgayQuaHan > 0)
		{
			//NODE_TREE* p = Find_DG(t, ArrQuaHan[i].docGia.MADG);
			gotoxy(12, 6 + j);
			cout << ArrQuaHan[i].docGia.MADG;
			gotoxy(25, 6 + j);
			cout << ArrQuaHan[i].docGia.hoten;
			gotoxy(50, 6 + j);
			cout << ArrQuaHan[i].sachQuaHan.maSach;
			gotoxy(67, 6 + j);
			cout << ArrQuaHan[i].sachQuaHan.tenSach;
			gotoxy(82, 6 + j);
			cout << ArrQuaHan[i].sachQuaHan.ngayMuon.Ngay << "/" << ArrQuaHan[i].sachQuaHan.ngayMuon.Thang << "/" << ArrQuaHan[i].sachQuaHan.ngayMuon.Nam;
			gotoxy(108, 6 + j);
			cout << ArrQuaHan[i].sachQuaHan.soNgayQuaHan;
			gotoxy(4, 6 + j);
			j++;
			cout << j;
		}
	}
	if (j == 0)
	{
		gotoxy(50, 10); 
		cout << "KHONG CO DOC GIA NAO MUON SACH QUA HAN";
	}
	_getch();
	delete[] ArrQuaHan;
}

void Top10Sach(LIST_DauSach lDS)
{
	clrscr();
	int count = 0;
	TopSach *top10 = new TopSach[lDS.n + 1];

	// nhap thong tin vao mang.
	for (int i = 0; i <= lDS.n; i++)
	{
		top10[i].tensach = lDS.nodesDauSach[i]->info.tenSach;
		top10[i].sosachmuon = soSachMuon(lDS.nodesDauSach[i]->dms);//Loi cho nay ne
	}

	Sort_Top10(top10, 0, lDS.n);
	// in thong tin ra  console
	//gotoxy(50, 2);
	//SetBGColor(GREEN);
	//cout << "TOP 10 DAU SACH CO SO LUOC MUON NHIEU NHAT ";
	//normalBGColor();
	int j = 0;
	/*while (top10[j].sosachmuon != 0 && j < 10 || top10[j].sosachmuon == top10[j + 1].sosachmuon  && top10[j].sosachmuon != 0)
	{
		SetColor(WHITE);
		gotoxy(xDisplayTop10[1] + 3, yDisplayTop10 + 2 + j);
		cout << top10[j].tensach;
		gotoxy(xDisplayTop10[2] + 16, yDisplayTop10 + 2 + j);
		cout << top10[j].sosachmuon;
		gotoxy(xDisplayTop10[0] + 7, yDisplayTop10 + 2 + j);
		j++;
		cout << j;
	}*/
	drawTableTop10();
	//DisplayTop10(keyDisplayTop10, 3, xDisplayTop10, j + 2);
	_getch();
	// xoa vung nho....
	delete[] top10;
}