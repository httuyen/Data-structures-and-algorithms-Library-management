#include "stdafx.h"
#include "xuLyMT.h"
#include "Check_Input.h"
#include "TempDG.h"
#include "RWDocGia.h"

int xDisplayDMS[4] = { 7,22,42, 60 };

void drawNhapMaThe(int x, int y)
{
	setHighLightColor();

	drawCell(x, x+45, y, y+2);
	
	setDefaultColor();
}

void drawInfoDG(int x, int y)
{
	setDefaultColor();
	//gotoxy(120, 8);
	gotoxy(x, y);
	cout << "THONG TIN DOC GIA";
	setHighLightColor();
	drawCell(x - 15, x + 4, y + 1, y + 11);
	// ho va ten
	drawCell(x - 15, x + 30, y + 1, y + 3);
	// trang thai the
	drawCell(x - 15, x + 30, y + 3, y + 5);
	// phai
	drawCell(x - 15, x + 30, y + 5, y + 7);
	// so sach da muon
	drawCell(x - 15, x + 30, y + 7, y + 9);
	// so sach chua tra
	drawCell(x - 15, x + 30, y + 9, y + 11);

	setDefaultColor();
	gotoxy(x - 13, y + 2); cout << "Ho va ten";
	gotoxy(x - 13, y + 4); cout << "Trang thai the";
	gotoxy(x - 13, y + 6); cout << "Phai";
	gotoxy(x - 13, y + 8); cout << "So sach da muon";
	gotoxy(x - 13, y + 10); cout << "So sach chua tra";
}

void drawListSachMuon()
{
	setDefaultColor();
	gotoxy(120, 21);
	cout << "CAC SACH DANG MUON";
	setHighLightColor();
	drawCell(105, 150, 22, 24);
	// ten sach
	drawCell(105, 137, 22, 32);
	// ngay muon
	drawCell(137, 150, 22, 32);

	setDefaultColor();
	gotoxy(107, 23); cout << "Ten sach";
	gotoxy(139, 23); cout << "Ngay muon";

	/*for (int i = 0; i < 5; i=i+2) {
		gotoxy(107, 23 + 3 + i);
		cout << "KIEM VAN KIEU TRUYEN";
		gotoxy(139, 23 + 3 + i);
		cout << "12/12/1212";
	}*/
}

void drawListSachMuon_FD()
{
	setDefaultColor();
	gotoxy(70, 21);
	cout << "CAC SACH DANG MUON";
	setHighLightColor();
	// ten sach
	drawCell(10, 40, 22, 32);
	// ma sach
	drawCell(40, 55, 22, 32);
	// ngay muon
	drawCell(55, 70, 22, 32);
	// ngay tra
	drawCell(70, 85, 22, 32);
	// so ngay da muon
	drawCell(85, 105, 22, 32);
	// vi tri sach
	drawCell(105, 125, 22, 32);
	// trang thai
	drawCell(125, 145, 22, 32);

	drawCell(10, 145, 22, 24);

	setDefaultColor();
	gotoxy(12, 23);
	cout << "TEN SACH";
	gotoxy(42, 23);
	cout << "MA SACH";
	gotoxy(57, 23);
	cout << "NGAY MUON";
	gotoxy(72, 23);
	cout << "NGAY TRA";
	gotoxy(87, 23);
	cout << "SO NGAY DA MUON";
	gotoxy(107, 23);
	cout << "VI TRI SACH";
	gotoxy(127, 23);
	cout << "TRANG THAI";
	/*for (int i = 0; i < 5; i=i+2) {
		gotoxy(12, 23 + 3 + i);
		cout << "KIEM VAN KIEU TRUYEN";
		gotoxy(42, 23 + 3 + i);
		cout << "AAAA_99";
		gotoxy(57, 23 + 3 + i);
		cout << "12/12/1212";
		gotoxy(72, 23 + 3 + i);
		cout << "12/12/1212";
		gotoxy(87, 23 + 3 + i);
		cout << "SO NGAY DA MUON";
		gotoxy(107, 23 + 3 + i);
		cout << "HANG 99, DAY 99";
		gotoxy(127, 23 + 3 + i);
		cout << "QUA HAN 7 NGAY";
	}*/
}

void DrawTableDMS()
{
	setDefaultColor();
	gotoxy(5, 2); cout << "                                                                       ";
	gotoxy(22, 2); cout << "LIST DANH MUC SACH";
	setHighLightColor();
	drawCell(5, 60, 3, 5);
	// ma sach
	drawCell(5, 20, 3, 36);
	//trang thai
	drawCell(20, 40, 3, 36);
	//vi tri
	drawCell(40, 60, 3, 36);
	
	setDefaultColor();
	gotoxy(xDisplayDMS[0], yDisplayDG); cout << "MA SACH";
	gotoxy(xDisplayDMS[1], yDisplayDG); cout << "TRANG THAI";
	gotoxy(xDisplayDMS[2], yDisplayDG); cout << "VI TRI";

	/*for (int i = 0; i < 29; i++) {
		gotoxy(xDisplayDMS[0], yDisplayDG + 3 + i);
		cout << "hoa";
	}*/
}

bool MatSach(ListMT lMT)
{
	for (NODE_MT * p = lMT.pHeadMT; p != NULL; p = p->pNext)
	{
		if (p->data.trangThai == 2)
		{
			return true;
		}
	}
	return false;
}

bool CheckTenSach_MT(LIST_DauSach lDS, ListMT lMT, string tenSach)
{
	for (NODE_MT * p = lMT.pHeadMT; p != NULL; p = p->pNext)
	{
		if ((getTenSach(p->data.maSach, lDS) == tenSach && p->data.trangThai == 0) 
			|| (getTenSach(p->data.maSach, lDS) == tenSach && p->data.trangThai == 2))
		{
			return true;
		}
	}
	return false;
}

void DeleteLineTable_DMS(int locate)
{
	gotoxy(xDisplayDMS[0], yDisplayDG + 3 + locate);
	cout << setw(xDisplayDMS[1] - xDisplayDMS[0] - 3) << setfill(' ') << ' ';
	gotoxy(xDisplayDMS[1], yDisplayDG + 3 + locate);
	cout << setw(xDisplayDMS[2] - xDisplayDMS[1] - 3) << setfill(' ') << ' ';
	gotoxy(xDisplayDMS[2], yDisplayDG + 3 + locate);
	cout << setw(xDisplayDMS[3] - xDisplayDMS[2] - 3) << setfill(' ') << ' ';
}

void ClearTable_DMS()
{
	for (int i = 0; i < NUMBER_LINES; i++)
	{
		DeleteLineTable_DMS(i);
	}
}

void ClearTable_SachMuon()
{
	for (int i = 0; i < 5; i = i + 2) {
		gotoxy(107, 23 + 3 + i);
		cout << setw(30) << setfill(' ') << ' ';
		gotoxy(139, 23 + 3 + i);
		cout << setw(10) << setfill(' ') << ' ';
	}
}

void DeleteLineTable_SM_FD(int locate)
{
	gotoxy(11, 23 + 3 + locate);
	cout << setw(29) << setfill(' ') << ' ';
	gotoxy(41, 23 + 3 + locate);
	cout << setw(14) << setfill(' ') << ' ';
	gotoxy(56, 23 + 3 + locate);
	cout << setw(14) << setfill(' ') << ' ';
	gotoxy(71, 23 + 3 + locate);
	cout << setw(14) << setfill(' ') << ' ';
	gotoxy(86, 23 + 3 + locate);
	cout << setw(19) << setfill(' ') << ' ';
	gotoxy(106, 23 + 3 + locate);
	cout << setw(19) << setfill(' ') << ' ';
	gotoxy(126, 23 + 3 + locate);
	cout << setw(19) << setfill(' ') << ' ';
}

void ClearTable_SachMuon_FD()
{
	for (int i = 0; i < 5; i = i + 2) {
		DeleteLineTable_SM_FD(i);
	}
}

void Output_MT(NODE_MT * p, LIST_DauSach lDS, int locate)
{
	Date today;
	Today(today);
	gotoxy(12, 23 + 3 + locate);
	cout << getTenSach(p->data.maSach, lDS);
	gotoxy(42, 23 + 3 + locate);
	cout << p->data.maSach;
	gotoxy(57, 23 + 3 + locate);
	cout << p->data.ngayMuon.Ngay << "/" << p->data.ngayMuon.Thang << "/" << p->data.ngayMuon.Nam;
	gotoxy(72, 23 + 3 + locate);
	cout << p->data.ngayTra.Ngay << "/" << p->data.ngayTra.Thang << "/" << p->data.ngayTra.Nam;
	gotoxy(87, 23 + 3 + locate);
	cout << abs(DateToDate(p->data.ngayMuon, today));
	gotoxy(107, 23 + 3 + locate);
	cout << getSachByMS(lDS, p->data.maSach)->data.viTri;
	gotoxy(127, 23 + 3 + locate);
	if (p->data.trangThai == 2)
		cout << "MAT SACH";
	else if (DateToDate(p->data.ngayMuon, today) > 7)
		cout << "QUA HAN 7 NGAY";
	else if (p->data.trangThai == 0)
		cout << "DANG MUON";
}

void OutputList_MT(ListMT listMT, LIST_DauSach lDS)
{
	ClearTable_SachMuon_FD();
	int i = 0;

	// thuc hien ouput
	for (NODE_MT * p = listMT.pHeadMT; p != NULL; p = p->pNext)
	{
		if (p->data.trangThai == 0 || p->data.trangThai == 2)
		{
			Output_MT(p, lDS, i);
			i = i + 2;
		}
	}
}

void Output_DMS(DMS dms, int locate)
{
	DeleteLineTable_DMS(locate);
	gotoxy(xDisplayDMS[0], yDisplayDG + 2 + locate);
	cout << dms.maSach;
	gotoxy(xDisplayDMS[1], yDisplayDG + 2 + locate);
	if (dms.trangThai == 0)
	{
		cout << "CHO MUON DUOC";
	}
	else if (dms.trangThai == 1)
	{
		cout << "DA CHO MUON";
	}
	else if (dms.trangThai == 2)
	{
		cout << "DA THANH LY";
	}
	gotoxy(xDisplayDMS[2], yDisplayDG + 2 + locate);
	cout << dms.viTri;
	locate++;
}

void OutputDMS_PerPage(pDauSach pDS, int index)
{
	ClearTable_DMS();
	//locate = 0;

	if (pDS->dms.pHeadDMS == nullptr && pDS->dms.pTailDMS == nullptr)
	{
		return;
	}
		
	index--;
	index *= NUMBER_LINES;
	int count = 0;
	NODE_DMS * temp = nullptr;
	if (index == 0) {
		for (temp = pDS->dms.pHeadDMS; temp != nullptr && count < index; temp = temp->pNext)
		{
			count++;
		}
		for (int i = 0; i < NUMBER_LINES && temp != nullptr; i++)
		{
			Output_DMS(temp->data, i);
			temp = temp->pNext;
		}
	}
	else {
		for (temp = pDS->dms.pHeadDMS; temp != nullptr && count < index; temp = temp->pNext)
		{
			Output_DMS(temp->data, count);
			count++;
		}
	}
}

int ChooseItem_DMS(pDauSach &pDS, int &tttrang, int tongtrang)
{
loop:
	clrscr();
	DrawTableDMS();
	OutputDMS_PerPage(pDS, tttrang);
	NODE_DMS *p;
	int slSach = 0;
	int pos = 0;
	int kb_hit;
	int nDMS = pDS->dms.n;
	pos = 0;
	setHighLightColor();
	gotoxy(xDisplayDMS[0], yDisplayDG + 2 + pos);
	cout << pDS->dms.pHeadDMS->data.maSach;
	setDefaultColor();
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
				setDefaultColor();
				gotoxy(xDisplayDMS[0], yDisplayDG + 2 + pos);
				p = Search_DMS_Pos(pDS->dms.pHeadDMS, pos);
				cout << p->data.maSach;
				(pos > 0) ? pos-- : pos = nDMS - 1;

				// to mau muc moi
				setHighLightColor();
				gotoxy(xDisplayDMS[0], yDisplayDG + 2 + pos);
				p = Search_DMS_Pos(pDS->dms.pHeadDMS, pos);
				cout << p->data.maSach;
				setDefaultColor();
				break;

			case KEY_DOWN:

				// xoa muc truoc
				setDefaultColor();
				gotoxy(xDisplayDMS[0], yDisplayDG + 2 + pos);
				p = Search_DMS_Pos(pDS->dms.pHeadDMS, pos);
				cout << p->data.maSach;
				(pos < nDMS - 1) ? pos++ : pos = 0;

				// to mau muc moi
				setHighLightColor();
				gotoxy(xDisplayDMS[0], yDisplayDG + 2 + pos);
				p = Search_DMS_Pos(pDS->dms.pHeadDMS, pos);
				cout << p->data.maSach;
				setDefaultColor();
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
				ClearTable_DMS();
				OutputDMS_PerPage(pDS, tttrang);

				pos = 0;
				setDefaultColor();
				gotoxy(xDisplayDMS[0], yDisplayDG + 2 + pos);
				p = Search_DMS_Pos(pDS->dms.pHeadDMS, pos);
				cout << p->data.maSach;
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
				ClearTable_DMS();
				OutputDMS_PerPage(pDS, tttrang);
				pos = 0;
				setDefaultColor();
				gotoxy(xDisplayDMS[0], yDisplayDG + 2 + pos);
				p = Search_DMS_Pos(pDS->dms.pHeadDMS, pos);
				cout << p->data.maSach;
				break;
			case KEY_F2:
				
				slSach = drawInputSLSach();
				InputDMS(pDS, slSach);
				clrscr();
				DrawTableDMS();
				ChooseItem_DMS(pDS, tttrang, tongtrang);
//				NhapSach(pDS);
				break;
			case KEY_F3:
				clrscr();
				drawInputDMS();
				if (SuaDanhMucSach(pDS, Search_DMS_Pos(pDS->dms.pHeadDMS, pos)) == 1) {
					goto loop;
				}
			case ENTER:
				/*if (pDS->dms.) {

				}*/
				//return (pos == 0 && tttrang == 1) ? pos : pos + (tttrang - 1)* NUMBER_LINES;
				break;
			case ESC:
				return -1;
			}
		}
		anConTro();
		setDefaultColor();
		gotoxy(25, 38);
		cout << "Trang " << tttrang << " / " << tongtrang;
		gotoxy(12, 40);
		cout << "KeyUp, KeyDn, Enter - Chon, PgUp, PgDn";
	}
}

int ChooseItem_MT(ListMT lMT)
{
	int pos = 0;
	int kb_hit;
	pos = 0;
	int nMT = 0;
	nMT = SoSachDangMuon(lMT);
	if (nMT == 0)
		return -1;
	SetColor(YELLOW);
	gotoxy(11, 23 + 3 + pos);
	cout << "<";
	gotoxy(39, 23 + 3 + pos);
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
				gotoxy(11, 23 + 3 + pos);
				cout << " ";
				gotoxy(39, 23 + 3 + pos);
				cout << " ";

				(pos > 0) ? pos -= 2 : pos = 2 * (nMT - 1);

				// to mau muc moi
				SetColor(YELLOW);
				gotoxy(11, 23 + 3 + pos);
				cout << "<";
				gotoxy(39, 23 + 3 + pos);
				cout << ">";
				break;

			case KEY_DOWN:
				// xoa muc truoc
				gotoxy(11, 23 + 3 + pos);
				cout << " ";
				gotoxy(39, 23 + 3 + pos);
				cout << " ";

				(pos < 2 * (nMT - 1)) ? pos += 2 : pos = 0;

				// to mau muc moi
				SetColor(YELLOW);
				gotoxy(11, 23 + 3 + pos);
				cout << "<";
				gotoxy(39, 23 + 3 + pos);
				cout << ">";
				break;

			case ENTER:

				// tra ve vi tri pos.
				return pos/2;
			}
		}
		anConTro();
	}
}

int TacVuMuonSach(LIST_DauSach lDS , NODE_TREE* dg)
{
	Tree t;
	int choose1 = 0, choose2 = 0;
	bool check;
	// nDs : so luong dau sach.
	int nDS = lDS.n;
	int tttrang, tongtrang;
	pDauSach pDS = NULL;
	tttrang = 1;
	tongtrang = (nDS / NUMBER_LINES) + 1;
	int temp = 1;

label:
	do
	{
		gotoxy(5, 2);
		cout << "                                                                   ";
		clrscrTableDS();
		gotoxy(28, 2);
		cout << "CHON 1 DAU SACH DE TIEN HANH MUON SACH ";
		drawTableDS();
		//show hot key
		gotoxy(28, yHotkey + 3);
		SetColor(WHITE);
		cout << "HotKey:  ESC - Thoat, ENTER - Chon, PgUP, PgDn";
		setDefaultColor();
		// thu tu trang
		choose1 = ChooseItemTL_MT(lDS, t, pDS);

		// check cac truong hop ...
		if (choose1 == -1)
		{
			return -1;
		}
		else if (choose1 > lDS.n)
		{
			//gotoxy(2, yDisplay + 3 + choose1 % NUMBER_LINES);
			cout << setw(27) << setfill(' ') << ' ';
			continue;
		}

		pDS = lDS.nodesDauSach[choose1];

		check = CheckTenSach_MT(lDS, dg->data.listMT, pDS->info.tenSach);

		// check cac truong hop
		if (check == true)
		{
			nhapNhay("DOC GIA DA MUON SACH THUOC DAU SACH NAY", 111, 35);
			_getch();
			gotoxy(111, 35);
			cout << "                                                       ";
			setDefaultColor();
		}
		else
		{
			//XoaMotVung(1, 1, 35, 79);
			// thoat vong lap
			temp = 2;
		}

	} while (temp == 1);


label1:

	temp = 1;
	tttrang = 1;
	tongtrang = (pDS->dms.n / NUMBER_LINES) + 1;

	clrscrTableDS();
	DrawTableDMS();
	do
	{		
		// kiem tra dau sach co dms k
		if (pDS->dms.n == 0) {
			nhapNhay("DAU SACH NAY CHUA CO DANH MUC SACH !!!", 110, 35);
			gotoxy(110, 35);
			cout << "                                     ";
			setDefaultColor();
			goto label;
		}
		OutputDMS_PerPage(pDS, tttrang);
		choose2 = ChooseItem_DMS_MT(pDS, tttrang, tongtrang);
		if (choose2 == -1)
		{
			temp = 1;
			tttrang = 1;
			gotoxy(22, 2);
			cout << "                                 ";
			goto label;
		}
		//else if (choose2 + 1 > pDS->dms.n)
		//{

		
		//	gotoxy(2, yDisplay + 3 + choose2 % NUMBER_LINES);
		//	cout << setw(12) << setfill(' ') << ' ';
		//	continue;
		//}
		else
		{
			NODE_DMS* dms = Search_DMS_Pos(pDS->dms.pHeadDMS, choose2);

			if (dms->data.trangThai == 1)
			{
				nhapNhay("SACH NAY DA CO NGUOI MUON. CHON SACH KHAC!!!", 106, 35);
				_getch();
				gotoxy(106, 35);
				cout << "                                             ";
				setDefaultColor();
				goto label1;
			}

			else if (dms->data.trangThai == 2)
			{
				nhapNhay("SACH NAY DA DUOC THANH LY. CHON SACH KHAC!!!", 106, 35);
				_getch();
				gotoxy(106, 35);
				cout << "                                              ";
				setDefaultColor();
				goto label1;
			}

			else if (dms->data.trangThai == 0)
			{
				// lay ma sach muon
				maSach = dms->data.maSach;
				// cap nhat trang thai sach
				dms->data.trangThai = 1;

			}

			temp = 0;
		}
	} while (temp);
	return 1;
}

void MuonSach(Tree &t, LIST_DauSach &lDS)
{
	clrscr();
	int maThe = 0;
	int check1, check2, check3 = 0;
	MuonTra mt;
	NODE_TREE* temp;

label:
	setDefaultColor();
	gotoxy(115, 2);
	cout << "NHAP MA DOC GIA MUON SACH";
	drawNhapMaThe(105, 3);
	gotoxy(123, 4);
	check1 = InputMaThe(maThe);

	// kiem tra ca truong hop
	if (check1 == -1)
	{
		anConTro();
		nhapNhay("BAN VUA HUY TAC VU MUON SACH !!!", 109, 8);
		_getch();
		setDefaultColor();
	}
	else if (check1 == 1)
	{
		temp = Find_DG(t, maThe);
		if (temp == NULL)
		{
			anConTro();
			nhapNhay("BAN VUA NHAP MA DOC GIA KHONG CO TRONG THU VIEN !!!", 102, 8);
			_getch();
			gotoxy(102, 8); 
			cout << "                                                   ";
			setDefaultColor();
			goto label;
		}
		else
		{
			// in thong tin doc gia.
		label1:
			drawInfoDG(120, 8);
			gotoxy(126, 10);
			cout << temp->data.info.ho << " " << temp->data.info.ten;
			gotoxy(126, 12); 
			(temp->data.info.trangThai == 0) ? cout << "KHOA" : cout << "HOAT DONG";
			gotoxy(126, 14);
			cout << temp->data.info.phai;
			gotoxy(126, 16);
			cout << temp->data.listMT.n;
			gotoxy(126, 18);
			cout << SoSachDangMuon(temp->data.listMT);
			drawListSachMuon();

			// clear table list sach muon
			ClearTable_SachMuon();
			// in danh sach cac sach dang muon trong list MUONTRA cua doc gia.
			int i = 0;
			for (NODE_MT * p = temp->data.listMT.pHeadMT ; p != NULL; p = p->pNext)
			{
				// truong hop dang muon chua tra, va truong hop dang muon nhung bi mat sach.
				if (p->data.trangThai == 0 || p->data.trangThai == 2)
				{
					// liet ke cac sach muon cua doc gia qua bien i
					gotoxy(107, 23 + 3 + i);
					cout << getTenSach(p->data.maSach, lDS);
					gotoxy(139, 23 + 3 + i);
					cout << p->data.ngayMuon.Ngay << "/" << p->data.ngayMuon.Thang << "/" << p->data.ngayMuon.Nam;
					
					i = i + 2;
					if (i == 6)
					{
						anConTro();
						nhapNhay("DOC GIA CHI DUOC MUON TOI DA 3 CUON SACH", 108, 35);
						_getch();
						gotoxy(108, 35);
						cout << "                                                   ";
						setDefaultColor();
						return;
					}
				}
			}

			// xu ly truong hop khong cho muon sach khi trang thai the da bi khoa.
			if (temp->data.info.trangThai == 0)
			{
				anConTro();
				nhapNhay("THE DOC GIA BI KHOA NEN KHONG THE MUON SACH", 107, 35);
				_getch();
				gotoxy(107, 35);
				cout << "                                                   ";
				setDefaultColor();
				return;
			}

			// xu ly truong hop khong cho muon sach khi doc gia lam mat sach.
			if (MatSach(temp->data.listMT))
			{
				anConTro();
				nhapNhay("DOC GIA KHONG DUOC MUON SACH VI DA LAM MAT SACH", 105, 35);
				_getch();
				gotoxy(105, 35);
				cout << "                                                   ";
				setDefaultColor();
				return;
			}

			// xu ly truong hop muon sach qua han 7 ngay.
			if (SoNgayMuon_Max(temp->data.listMT) > 7)
			{
				anConTro();
				nhapNhay("DOC GIA KHONG DUOC MUON SACH VI DA GIU SACH QUA HAN 7 NGAY", 96, 35);
				_getch();
				gotoxy(96, 35);
				cout << "                                                               ";
				setDefaultColor();
				return;

			}

			anConTro();
			nhapNhay("NHAN PHIM BAT KI DE TIEP TUC !!!",111, 35);		
			_getch();
			gotoxy(111, 35);
			cout << "                                 ";
			setDefaultColor();
			
			// xu ly thao tac muon tra.
			check2 = TacVuMuonSach(lDS, temp);

			// check cac truong hop
			if (check2 == -1)
			{
				return;
			}
			else if (check2 == 1)
			{

				// nap thong tin vao cau truc muon tra
				strcpy(mt.maSach, maSach);
				mt.ngayTra.Nam = 0;
				mt.ngayTra.Thang = 0;
				mt.ngayTra.Ngay = 0;
				mt.trangThai = 0;

				// nhap thong tin ngay muon va xu ly truong hop nhap ngay muon lon hon ngay he thong;
				do
				{
					gotoxy(104, 35);
					cout << "NHAP VAO NGAY MUON. NHAN F10 DE LUU, ESC DE HUY!";
					check3 = InputNgayThang(mt.ngayMuon, 123, 37);

					// check cac truong hop
					if (check3 == -1)
					{
						return;
					}
					else if (check3 == 2)
					{
						AddHeadList_MT(temp->data.listMT, mt);
						//saveDG(t);
						goto label1;
					}
				} while (check3);
			}
		}
	}
}

void TraSach(Tree &t, LIST_DauSach &lDS)
{
	clrscr();
	int maThe = 0;
	char thongbao[] = "         Doc Gia chua muon sach !  ";
	char thongbao1[] = "    Thong tin da duoc cap nhat. Bao mat sach thanh cong !";
	int check;
	NODE_TREE* temp;
	Date ngayTra;
	int condition = 1;

label:
	setDefaultColor();
	gotoxy(65, 2);
	cout << "NHAP MA DOC GIA TRA SACH";
	drawNhapMaThe(55, 3);
	gotoxy(73, 4);
	check = InputMaThe(maThe);

	// kiem tra ca truong hop
	if (check == -1)
	{
		anConTro();
		nhapNhay("BAN VUA HUY TAC VU TRA SACH !!!", 60, 10);
		_getch();
		setDefaultColor();
	}
	else if (check == 1)
	{
		temp = Find_DG(t, maThe);
		if (temp == NULL)
		{
			anConTro();
			nhapNhay("BAN VUA NHAP MA DOC GIA KHONG CO TRONG THU VIEN !!!", 52, 10);
			_getch();
			gotoxy(52, 10);
			cout << "                                                   ";
			setDefaultColor();
			goto label;
		}
		else
		{
		label1:
			anConTro();
			drawInfoDG(70, 8);
			gotoxy(76, 10);
			cout << temp->data.info.ho << " " << temp->data.info.ten;
			gotoxy(76, 12);
			(temp->data.info.trangThai == 0) ? cout << "KHOA" : cout << "HOAT DONG";
			gotoxy(76, 14);
			cout << temp->data.info.phai;
			gotoxy(76, 16);
			cout << temp->data.listMT.n;
			gotoxy(76, 18);
			cout << SoSachDangMuon(temp->data.listMT);

			// hien thi list sach muon
			drawListSachMuon_FD();
			OutputList_MT(temp->data.listMT, lDS);
			gotoxy(52, 33);
			cout << "HotKey: F3 - TRA SACH, F4 - BAO MAT SACH, ESC - THOAT";
			do
			{
				while (_kbhit())
				{
					int kb_hit = _getch();
					if (kb_hit == 224 || kb_hit == 0)
						kb_hit = _getch();

					switch (kb_hit)
					{
					case  KEY_F3:
					{
						Beep(600, 100);

						int choose, itemMT = -1, check1 = 0;
						Date ngayTra;

						choose = ChooseItem_MT(temp->data.listMT);
						if (choose == -1)
						{
							anConTro();
							nhapNhay("DOC GIA CHUA MUON SACH", 50, 30);
							setDefaultColor();
							return;
						}
						for (NODE_MT * pMT = temp->data.listMT.pHeadMT; pMT != NULL; pMT = pMT->pNext)
						{
							if (pMT->data.trangThai == 0 || pMT->data.trangThai == 2)
							{
								itemMT++;
								if (itemMT == choose)
								{

									// chuc nang nhap thong tin ngay tra.
									do
									{
										gotoxy(55, 35);
										cout << "NHAP VAO NGAY TRA. NHAN F10 DE LUU, ESC DE HUY !";
										check1 = InputNgayThang(ngayTra, 74, 37);

										// check cac truong hop
										if (check1 == 2)
										{
											if (DateToDate(ngayTra, pMT->data.ngayMuon) < 0)
											{
												check1 = 1;
											}
											else
											{
												// thay doi trang thai sang da tra sach.
												pMT->data.trangThai = 1;
												pMT->data.ngayTra = ngayTra;

												// tim kiem sach ma doc gia da muon
												NODE_DMS* pDMS = getSachByMS(lDS, pMT->data.maSach);

												// thay doi trang thai sach tu da co nguoi muon sang chua co nguoi muon
												pDMS->data.trangThai = 0;
												goto label1;
											}
										}
										else if (check1 == -1)
										{
											goto label1;
										}

									} while (check1);
								}
							}
						}
						goto label1;
					}


					case KEY_F4:
					{
						Beep(600, 100);

						int choose;
						int itemMT = -1;
						choose = ChooseItem_MT(temp->data.listMT);
						if (choose == -1)
						{
							anConTro();
							nhapNhay("DOC GIA CHUA MUON SACH", 50, 30);
							setDefaultColor();
							return;
						}
						for (NODE_MT * pMT = temp->data.listMT.pHeadMT; pMT != NULL; pMT = pMT->pNext)
						{
							if (pMT->data.trangThai == 0 || pMT->data.trangThai == 2)
							{
								itemMT++;
								if (itemMT == choose)
								{
									// thay doi trang thai sang da lam mat sach.
									pMT->data.trangThai = 2;
									anConTro();
									nhapNhay("BAO MAT SACH THANH CONG !!!", 65, 37);
									gotoxy(65, 37);
									cout << "                           ";
									setDefaultColor();
								}
							}
						}
						goto label1;

					}

					case ESC:
						Beep(600, 100);
						condition = 0;
						break;
					}
				}			
			} while (condition);
		}
	}
}