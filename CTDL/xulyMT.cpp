#include "stdafx.h"
#include "xuLyMT.h"
#include "Check_Input.h"
#include "TempDG.h"

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
			/*check2 = Menu_MuonSach(lDS, temp);

			// check cac truong hop
			if (check2 == -1)
			{
				return;
			}
			else if (check2 == 1)
			{

				// nap thong tin vao cau truc muon tra bao gom ten sach, ngay muon, ngay tra..v.v.v
				mt.tensach = tensach;
				mt.ngaytra.nam = 0;
				mt.ngaytra.thang = 0;
				mt.ngaytra.ngay = 0;
				mt.MASACH = masach;
				mt.vitrisach = vitrisach;

				mt.trangthai = 0;


				// nhap thong tin ngay muon va xu ly truong hop nhap ngay muon lon hon ngay he thong;
				do
				{
					gotoxy(83, 28);
					cout << "Nhap vao ngay muon. Nhan F10 de luu, ESC de huy !";
					check3 = NhapNgayThang(mt.ngaymuon, 100, 30);

					// check cac truong hop
					if (check3 == -1)
					{
						return;
					}
					else if (check3 == 2)
					{
						AddHeadList_MT(temp->mt, mt);
						goto label1;
					}
				} while (check3);
			}*/
		}
	}
}
