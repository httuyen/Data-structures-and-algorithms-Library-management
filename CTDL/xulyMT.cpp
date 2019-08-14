#include "stdafx.h"
#include "xuLyMT.h"
#include "Check_Input.h"
#include "TempDG.h"

int xDisplayDMS[4] = { 7,22,42, 60 };

void drawNhapMaThe()
{
	setDefaultColor();
	gotoxy(115, 2);
	cout << "NHAP MA DOC GIA MUON SACH";
	setHighLightColor();

	drawCell(105, 150, 3, 5);
	
	setDefaultColor();
}

void drawInfoDG()
{
	setDefaultColor();
	gotoxy(120, 8);
	cout << "THONG TIN DOC GIA";
	setHighLightColor();
	drawCell(105, 124, 9, 19);
	// ho va ten
	drawCell(105, 150, 9, 11);
	// trang thai the
	drawCell(105, 150, 11, 13);
	// phai
	drawCell(105, 150, 13, 15);
	// so sach da muon
	drawCell(105, 150, 15, 17);
	// so sach chua tra
	drawCell(105, 150, 17, 19);

	setDefaultColor();
	gotoxy(107, 10); cout << "Ho va ten";
	gotoxy(107, 12); cout << "Trang thai the";
	gotoxy(107, 14); cout << "Phai";
	gotoxy(107, 16); cout << "So sach da muon";
	gotoxy(107, 18); cout << "So sach chua tra";
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

void DrawTableDMS()
{
	setDefaultColor();
	gotoxy(5, 2); cout << "                                                                       ";
	gotoxy(22, 2); cout << "CHON SACH DE MUON";
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

void Output_DMS(DMS dms, int locate)
{
	DeleteLineTable_DMS(locate);
	gotoxy(xDisplayDMS[0], yDisplayDG + 3 + locate);
	cout << dms.maSach;
	gotoxy(xDisplayDMS[1], yDisplayDG + 3 + locate);
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
	gotoxy(xDisplayDMS[2], yDisplayDG + 3 + locate);
	cout << dms.viTri;
	locate++;
}

void OutputDMS_PerPage(pDauSach pDS, int index)
{
	ClearTable_DMS();
	//locate = 0;
	if (pDS->dms.pHeadDMS == NULL && pDS->dms.pTailDMS == NULL)
		return;
	index--;
	index *= NUMBER_LINES;
	int count = 0;
	NODE_DMS * temp = NULL;
	for (temp = pDS->dms.pHeadDMS; temp != NULL && count < index; temp = temp->pNext)
	{
		count++;
	}
	for (int i = 0; i < NUMBER_LINES && temp != NULL; i++)
	{
		Output_DMS(temp->data, i);
		temp = temp->pNext;
	}
	return;
}

int ChooseItem_DMS(pDauSach &pDS, int &tttrang, int tongtrang)
{
	int pos = 0;
	int kb_hit;
	pos = 0;

	gotoxy(xDisplayDMS[0] - 1, yDisplayDG + 3 + pos);
	cout << "<";
	gotoxy(xDisplayDMS[0] + 12, yDisplayDG + 3 + pos);
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
				gotoxy(xDisplayDMS[0] - 1, yDisplayDG + 3 + pos);
				cout << " ";
				gotoxy(xDisplayDMS[0] + 12, yDisplayDG + 3 + pos);
				cout << " ";
				(pos > 0) ? pos-- : pos = 28;

				// to mau muc moi
				gotoxy(xDisplayDMS[0] - 1, yDisplayDG + 3 + pos);
				cout << "<";
				gotoxy(xDisplayDMS[0] + 12, yDisplayDG + 3 + pos);
				cout << ">";
				break;

			case KEY_DOWN:

				// xoa muc truoc
				gotoxy(xDisplayDMS[0] - 1, yDisplayDG + 3 + pos);
				cout << " ";
				gotoxy(xDisplayDMS[0] + 12, yDisplayDG + 3 + pos);
				cout << " ";
				(pos < 28) ? pos++ : pos = 0;

				// to mau muc moi
				gotoxy(xDisplayDMS[0] - 1, yDisplayDG + 3 + pos);
				cout << "<";
				gotoxy(xDisplayDMS[0] + 12, yDisplayDG + 3 + pos);
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
				ClearTable_DMS();
				OutputDMS_PerPage(pDS, tttrang);

				pos = 0;
				gotoxy(xDisplayDMS[0] - 1, yDisplayDG + 3 + pos);
				cout << "<";
				gotoxy(xDisplayDMS[0] + 12, yDisplayDG + 3 + pos);
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
				ClearTable_DMS();
				OutputDMS_PerPage(pDS, tttrang);
				pos = 0;
				gotoxy(xDisplayDMS[0] - 1, yDisplayDG + 3 + pos);
				cout << "<";
				gotoxy(xDisplayDMS[0] + 12, yDisplayDG + 3 + pos);
				cout << ">";
				break;

			case ENTER:
				return (pos == 0 && tttrang == 1) ? pos : pos + (tttrang - 1)* NUMBER_LINES;

			case ESC:
				return -1;
			}
		}
		anConTro();
		gotoxy(25, 38);
		cout << "Trang " << tttrang << " / " << tongtrang;
		gotoxy(12, 40);
		cout << "KeyUp, KeyDn, Enter - Chon, PgUp, PgDn";
	}
}

int TacVuMuonSach(LIST_DauSach lDS , NODE_TREE* dg)
{
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
		// hien thi bang chua thong tin dau sach
		gotoxy(23, 2);
		cout << "CHON 1 DAU SACH DE TIEN HANH MUON SACH ";
		//drawTable(lDS, pDS);
		//OutputDS_PerPage(lDS, tttrang);

		// chon dau sach muon nhap sach vao
		//choose1 = ChooseItems(lDS, tttrang, tongtrang);

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

	DrawTableDMS();
	do
	{

		// hien thi bang chua thong tin danh muc sach
		//();
		OutputDMS_PerPage(pDS, tttrang);
		choose2 = ChooseItem_DMS(pDS, tttrang, tongtrang);
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
	drawNhapMaThe();
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
			drawInfoDG();
			gotoxy(126, 10);
			cout << temp->data.info.ho << " " << temp->data.info.ho;
			gotoxy(126, 12); 
			(temp->data.info.trangThai == 0) ? cout << "KHOA" : cout << "HOAT DONG";
			gotoxy(126, 14);
			cout << temp->data.info.phai;
			gotoxy(126, 16);
			cout << temp->data.listMT.n;
			gotoxy(126, 18);
			cout << SoSachDangMuon(temp->data.listMT);
			drawListSachMuon();
			// in danh sach cac sach dang muon trong list MUONTRA cua doc gia.
			int i = 0;
			for (NODE_MT * p = temp->data.listMT.pHeadMT ; p != NULL; p = p->pNext)
			{
				// truong hop dang muon chua tra, va truong hop dang muon nhung bi mat sach.
				if (p->data.trangThai == 0 || p->data.trangThai == 2)
				{
					// nap vao so sach muon cua doc gia qua bien i
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
					check3 = InputNgayThang(mt.ngayMuon);

					// check cac truong hop
					if (check3 == -1)
					{
						return;
					}
					else if (check3 == 2)
					{
						AddHeadList_MT(temp->data.listMT, mt);
						goto label1;
					}
				} while (check3);
			}
		}
	}
}
