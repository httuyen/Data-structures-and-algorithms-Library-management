#include "stdafx.h"
#include "xuLyDS.h"

using namespace std;

int xDisplayDS[6] = { 6, 21, 48, 55, 86, 94 };
<<<<<<< HEAD

//int xDisplayDMS[4] = { 7,22,42, 60 };


int vi_tri = 0;

=======
//int xDisplayDMS[4] = { 7,22,42, 60 };
int vi_tri = 0;
>>>>>>> a4583d3bccbb7716aba1b22796c4e0dcedf1149a
void drawTable() {
	clrscr();
	gotoxy(7, 2); cout << "DANH SACH CAC DAU SACH TRONG THU VIEN THEO THE LOAI, TEN SACH TANG DAN THEO THE LOAI";
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
	drawEditDS(110, 3);
	drawNoti(110, 24);
}

void drawTableDS() {
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
	setDefaultColor();
	gotoxy(6, 4); cout << "THE LOAI";
	gotoxy(21, 4); cout << "TEN SACH";
	gotoxy(48, 4); cout << "ISBN";
	gotoxy(55, 4); cout << "TAC GIA";
	gotoxy(86, 4); cout << "SO TR";
	gotoxy(94, 4); cout << "NAM XB";
}

void drawEditDS(int x, int y) {
	gotoxy(x + 10, y - 1); cout << "CAP NHAT DAU SACH";
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
int drawInputSLSach() {
	clrscr();
	gotoxy(xDMS, yDMS);
	cout << "NHAP VAO SO LUONG SACH CAN NHAP: ";
	int sl;
	cin >> sl;
	return sl;
}
void clearInputDMS() {
	gotoxy(xDMS + 16, yDMS + 2);
	cout << "                              ";
	gotoxy(xDMS + 16, yDMS + 5);
	cout << "                              ";
	gotoxy(xDMS + 16, yDMS + 8);
	cout << "                              ";
}
void InputDMS(pDauSach &pDS, int slSach) {
	drawInputDMS();
	int isEsc = 0;
	for (int i = 0; i < slSach && isEsc != -1; i++) {
		gotoxy(xDMS + 20,yDMS + 12);
		cout << slSach;
		clearInputDMS();
		isEsc = NhapSach(pDS);
		gotoxy(xDMS + 18, yDMS + 14);
		cout << i+1;
	}
}
void drawInputDMS() {
	clrscr();
	setHighLightColor();
	drawCell(xDMS, xDMS + 70, yDMS, yDMS + 16);
	drawCell(xDMS + 15, xDMS + 69, yDMS + 1, yDMS + 3);
	drawCell(xDMS + 15, xDMS + 69, yDMS + 4, yDMS + 6);
	drawCell(xDMS + 15, xDMS + 69, yDMS + 7, yDMS + 9);
	veNetNgang(xDMS + 1, xDMS + 69, yDMS + 10);
	setDefaultColor();
	gotoxy(xDMS + 2, yDMS + 2);
	cout << "MA SACH: ";
	gotoxy(xDMS + 2, yDMS + 5);
	cout << "TRANG THAI: ";
	gotoxy(xDMS + 2, yDMS + 8);
	cout << "VI TRI: ";
	gotoxy(xDMS + 2, yDMS + 12);
	cout << "SO SACH CAN NHAP :";
	gotoxy(xDMS + 2, yDMS + 14);
	cout << "SO SACH DA NHAP: ";
	setHighLightColor();
	drawCell(xDMS, xDMS + 70, yDMS + 18, yDMS + 24);
	setDefaultColor();
	gotoxy(xDMS + 2, yDMS + 19);
	cout << "MA SACH DU DANH TU DONG";
	gotoxy(xDMS + 2, yDMS + 21);
	cout << "TRANG THAI: 0 = CHO MUON DUOC, 2 = DA THANH LY";
	gotoxy(xDMS + 2, yDMS + 23);
	cout << "VI TRI: TOI DA 20 KY TU, CHI LAY KY TU CHU, SO VA DAY PHAY";
}
void drawNoti(int x, int y) {
	gotoxy(x + 15, y); cout << "NOTIFICATION";
	setHighLightColor();
	drawCell(x, x + 40, y + 1, y + 12);
	veNetNgang(x + 1, x + 39, y + 3);
	setDefaultColor();
	gotoxy(x + 1, y + 4); cout << "ISBN toi da 6 ky tu\n";
	gotoxy(x + 1, y + 5); cout << "THE LOAI toi da 20 ky tu\n";
	gotoxy(x + 1, y + 6); cout << "TEN SACH toi da 20 ky tu\n";
	gotoxy(x + 1, y + 7); cout << "TAC GIA toi da 20 ky tu\n";
	gotoxy(x + 1, y + 8); cout << "SO TRANG toi da 6 ky tu\n";
	gotoxy(x + 1, y + 9); cout << "Nam XB toi da 4 ky tu";
}
void showListTL(string listTL[], int tttrangTL, int slTL) {
	vi_tri = 0;
	tttrangTL--;
	for (int i = NUMBER_LINES * tttrangTL; i < NUMBER_LINES*(1 + tttrangTL) && i <slTL; i++)
	{
		gotoxy(xD, yD +vi_tri);
		cout << listTL[i] << endl;
		if (listTL[i] == "") break;
		vi_tri++;
	}
}
string getEventKey(string strKey) {

	return strKey;
}
void clearNoti() {
	gotoxy(XTB, YTB);
	SetColor(WHITE);
	cout << setw(38) << setfill(' ') << " ";
	setDefaultColor();
}

void clrscrTableDS()
{
	for (int y = 3; y <= 42; y++) {
			gotoxy(5, y);
			cout << setw(96) << setfill(' ') << ' ';
	}
}

void clearInput() {
	int x = XINPUT;
	int y = YINPUT;
	gotoxy(x + 11, y + 2);
	XoaMotDong(25);
	gotoxy(x + 11, y + 5);
	XoaMotDong(25);
	gotoxy(x + 11, y + 8);
	XoaMotDong(25);
	gotoxy(x + 11, y + 11);
	XoaMotDong(25);
	gotoxy(x + 11, y + 14);
	XoaMotDong(25);
	gotoxy(x + 11, y + 17);
	XoaMotDong(25);
}
void clearTL() {
	for (int i = 0; i < NUMBER_LINES; i++) {
		gotoxy(xD , yD + i);
		XoaMotDong(12);
	}
}
void inputDS(LIST_DauSach &lds, pDauSach &pDS, bool isEdited) {
	hienConTro();
	dauSach ds;
	Date dateHT;
	Today(dateHT);	//temp DS
	string ISBN = "";
	string tenSach = "";
	int soTrang = 0;
	string tacGia = "";
	int namXB = 0;
	string theLoai = "";

	int x = XINPUT;
	int y = YINPUT;
	int flag = 0;
	bool isSave = false;
	bool isEsc = false;

	if (isEdited)
	{
		ISBN = pDS->info.ISBN;
		theLoai = pDS->info.theLoai;
		tenSach = pDS->info.tenSach;
		tacGia = pDS->info.tacGia;
		soTrang = pDS->info.soTrang;
		namXB = pDS->info.namXuatBan;

		gotoxy(x + 11, y + 2);
		cout << ISBN;
		gotoxy(x + 11, y + 5);
		cout << theLoai;
		gotoxy(x + 11, y + 8);
		cout << tenSach;
		gotoxy(x + 11, y + 11);
		cout << tacGia;
		gotoxy(x + 11, y + 14);
		cout << soTrang;
		gotoxy(x + 11, y + 17);
		cout << namXB;
	}
	while (true) {
		switch (flag) {
		case 0:
			//clearNoti();
			gotoxy(x + 11, y + 2);
			nhapISBN(ISBN, flag, isSave, isEsc);
			break;
		case 1:
			//clearNoti();
			gotoxy(x + 11, y + 5);
			NhapTheLoaiSach(theLoai, flag, isSave, isEsc);
			break;
		case 2:
			//clearNoti();
			gotoxy(x + 11, y + 8);
			NhapTenSach(tenSach, flag, isSave, isEsc);
			break;
		case 3:
			//clearNoti();
			gotoxy(x + 11, y + 11);
			NhapTenTacGia(tacGia, flag, isSave, isEsc);
			break;
		case 4:
			//clearNoti();
			gotoxy(x + 11, y + 14);
			nhapSoTrang(soTrang, flag, isSave, isEsc);
			break;
		case 5:
			//clearNoti();
			gotoxy(x + 11, y + 17);
			NhapNamXuatBan(namXB, flag, isSave, isEsc);
			break;
		}

		if (isSave)
		{
			// cap nhat lai flag
			isSave = false;
			// check rong;
			if (ISBN.length() == 0)
			{
				gotoxy(XTB, YTB);
				SetColor(RED);
				cout << "ISBN khong duoc de trong!!! ";
				setDefaultColor();
				flag = 0;
				continue;
			}
			else if (theLoai.length() == 0)
			{
				gotoxy(XTB, YTB);
				SetColor(RED);
				cout << "The Loai khong duoc de trong!!! ";
				setDefaultColor();
				flag = 1;
				continue;
			}
			else if (tenSach.length() == 0)
			{
				gotoxy(XTB, YTB);
				SetColor(RED);
				cout << "Ten sach khong duoc de trong!!! ";
				setDefaultColor();
				flag = 2;
				continue;
			}
			else if (tacGia.length() == 0)
			{
				gotoxy(XTB, YTB);
				SetColor(RED);
				cout << "Tac gia khong duoc de trong!!! ";
				setDefaultColor();
				flag = 3;
				continue;
			}
			else if (soTrang == 0)
			{
				gotoxy(XTB, YTB);
				SetColor(RED);
				cout << "So trang khong duoc de trong!!! ";
				setDefaultColor();
				flag = 4;
				continue;
			}
			else if (namXB == 0)
			{
				gotoxy(XTB, YTB);
				SetColor(RED);
				cout << "Nam XB khong duoc de trong!!! ";
				setDefaultColor();
				flag = 5;
				continue;
			}
			else if (namXB > dateHT.Nam)
			{
				gotoxy(XTB, YTB);
				SetColor(RED);
				cout << "NamXB khong lon hon nam hien tai!";
				setDefaultColor();
				flag = 5;
				continue;
			}

			if (SearchISBN_DS(lds, ISBN))
			{
				if (pDS->info.ISBN != ISBN)
				{
					gotoxy(XTB, YTB);
					SetColor(BLUE);
					cout << "ISBN da ton tai !";
					setDefaultColor();
					flag = 0;
					continue;
				}
			}

			// import data vao info
			ChuanHoaString(ISBN).copy(ds.ISBN, ISBN.size() + 1);
			ChuanHoaString(theLoai).copy(ds.theLoai, theLoai.size() + 1);
			ChuanHoaString(tenSach).copy(ds.tenSach, tenSach.size() + 1);
			ChuanHoaString(tacGia).copy(ds.tacGia, tacGia.size() + 1);
			ds.namXuatBan = namXB;
			ds.soTrang = soTrang;

			if (isEdited)
			{
				pDS->info = ds;
				SetColor(RED);
				gotoxy(XTB, YTB);
				Sleep(100);
				cout << "SUCCESSFULLY !!! ";
				Sleep(1000);
				clearNoti;
				clearInput();
				Xoa_OutDS_29lines();
				setDefaultColor();
				return;
			}
			else
			{
				initList_DMS(pDS->dms);
				pDS->info = ds;
				int temp = Insert_DauSach(lds, pDS);
				if (temp == 0)
				{
					for (int i = 0; i < 5; i++)
					{
						SetColor(RED);
						gotoxy(XTB, YTB);
						Sleep(100);
						cout << "Bo nho day, khong the them";
					}
				}
				else {
					SetColor(RED);
					gotoxy(XTB, YTB);
					Sleep(100);
					cout << "SUCCESSFULLY !!! ";
					Sleep(1000);
					clearInput();
					clearNoti();
					Xoa_OutDS_29lines();
					//SaveDS(lds);
				}
				setDefaultColor();
				return;
			}
		}

		// thoat	
		if (isEsc)
		{
			return;
		}
		anConTro();
	}
}
void menuDS(LIST_DauSach &lds, pDauSach &pDS, Tree &t) {
	drawTable();
	//show hot key
<<<<<<< HEAD

	gotoxy(10, yHotkey + 3);

=======
	gotoxy(7, yHotkey + 1);
>>>>>>> a4583d3bccbb7716aba1b22796c4e0dcedf1149a
	SetColor(WHITE);
	cout << "HotKey: F2 - Them, F3 - Sua, F4 - Xoa, F5 - Them DMS, F6 - Cap nhat DMS, F10 - Luu,";
	gotoxy(10, yHotkey + 4);
	cout << "                            PgUp, PgDn, ESC - Thoat";
	setDefaultColor();
	// thu tu trang
	ChooseItemTL(lds, t, pDS);
	xuLy(lds, t);
}
void OutputDS_PerPage(LIST_DauSach &lDS, string theLoai, int tttrang)
{
	Xoa_OutDS_29lines();
	//SetColor(WHITE);
	//viTri = 0;
	vi_tri = 0;
	tttrang--;
	LIST_DauSach l = getDSByTL(lDS, theLoai);
	QuicKsortTS(l, 0, l.n-1);
	/*if (l.n == -1)
		return;*/
	for (int i = NUMBER_LINES * tttrang; i < NUMBER_LINES*(1 + tttrang) && i < l.n; i++)
	{
		Output_DS(l.nodesDauSach[i]->info,vi_tri);
		vi_tri++;
	}
}
void Output_DS(dauSach ds, int viTri)
{
	anConTro();
	//Xoa1lineDS(viTri);
	gotoxy(xDisplayDS[1] , yD + viTri);
	cout << ds.tenSach;
	gotoxy(xDisplayDS[2] , yD + viTri);
	cout << ds.ISBN;
	gotoxy(xDisplayDS[3], yD + viTri);
	cout << ds.tacGia;
	gotoxy(xDisplayDS[4], yD + viTri);
	cout << ds.soTrang;
	gotoxy(xDisplayDS[5], yD + viTri);
	cout << ds.namXuatBan;
	//viTri++;
}
void XoaMotVung(int x, int y, int ndoc, int width)
{
	for (int i = 0; i < ndoc; i++)
	{
		gotoxy(x, y + i);
		XoaMotDong(width);
	}
}
void XoaMotDong(int width)
{
	SetBGColor(BLACK);
	cout << " " << setw(width) << setfill(' ') << " ";
}
void Xoa1lineDS(int viTri)
{
	setDefaultColor();
	//gotoxy(xDisplayDS[0], yD + viTri);
	//cout << setw(13) << setfill(' ') << ' ';
	gotoxy(xDisplayDS[1] , yD + viTri);
	cout << setw(25) << setfill(' ') << ' ';
	gotoxy(xDisplayDS[2] , yD + viTri);
	cout << setw(6) << setfill(' ') << ' ';
	gotoxy(xDisplayDS[3] , yD + viTri);
	cout << setw(29) << setfill(' ') << ' ';
	gotoxy(xDisplayDS[4] , yD + viTri);
	cout << setw(7) << setfill(' ') << ' ';
	gotoxy(xDisplayDS[5] , yD + viTri);
	cout << setw(6) << setfill(' ') << ' ';
}
void clearTheLoai(int sl) {
	for (int i = 0; i < sl; i++) {
		gotoxy(xDisplayDS[0], yD + i);
		cout << setw(13) << setfill(' ') << ' ';
	}
}
void Xoa_OutDS_29lines()
{
	for (int i = 0; i < NUMBER_LINES; i++)
	{
		Xoa1lineDS(i);
	}
}
void nhapISBN(string &ISBN, int &flag, bool &isSave, bool &isEsc) {
	hienConTro();
	cout << ISBN;
	int count = (int)ISBN.length();
	int x, y;

	while (true)
	{
		x = wherex();
		y = wherey();

		while (_kbhit())
		{
			int kb_hit = _getch();
			// chi nhan chu thuong hoac  chu in hoa. 
			// chi nhap ten toi da 6 ky tu, vi tu dai nhat tieng viet chi la 6.
			if (((kb_hit >= 65 && kb_hit <= 90) || (kb_hit >= 97 && kb_hit <= 122)) && count < MAX_ISBN)
			{
				count++;
				clearNoti();
				gotoxy(x, y);

				// chuyen qua in hoa
				kb_hit = toupper((char)kb_hit);
				cout << (char)kb_hit;
				ISBN += (char)kb_hit;
				//copy(ISBN.begin(), ISBN.end(), ISBN);

			}
			else if (kb_hit == 224)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_UP)
				{
					flag = 5;
					return;
				}
				else
				{
					flag = 1;
					return;
				}
			}
			else if (kb_hit == ENTER)
			{
				flag = 1;
				return;
			}
			else if (kb_hit == BACKSPACE && count > 0)
			{
				clearNoti();
				gotoxy(x, y);

				count--;
				cout << "\b" << " " << "\b";

				ISBN.erase(ISBN.length() - 1, 1);
			}
			else if (kb_hit == 0)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_F10)
				{
					isSave = true;
					return;
				}
			}
			else if (kb_hit == ESC)
			{
				isEsc = true;
				return;
			}
			else {
				gotoxy(XTB, YTB);
				SetColor(RED);
				cout << "TOI DA 6 KY TU, CHI LAY KY TU CHU !!!";
				setDefaultColor();
				gotoxy(x, y);
			}
		}
	}
}
void NhapTheLoaiSach(string &theLoai, int &flag, bool &isSave, bool &isEsc)
{
	hienConTro();
	cout << theLoai;
	int count = (int)theLoai.length();
	int x, y;
	int nSpace = 0;

	while (true)
	{
		x = wherex();
		y = wherey();
		while (_kbhit())
		{
			int kb_hit = _getch();
			// chi nhan chu thuong hoac  chu in hoa va dau cach
			if (((kb_hit >= 65 && kb_hit <= 90) || (kb_hit >= 97 && kb_hit <= 122) || kb_hit == SPACE)
				&& count < MAX_THELOAISACH && count >= 0)
			{
				clearNoti();
				gotoxy(x, y);

				if (nSpace == 1 && kb_hit == SPACE)
				{
					count++;
					cout << (char)kb_hit;
					theLoai += (char)kb_hit;
					nSpace = 0;
				}
				else if (kb_hit != SPACE)
				{
					count++;
					kb_hit = toupper((char)kb_hit);
					cout << (char)kb_hit;
					theLoai += (char)kb_hit;
					nSpace = 1;
				}

			}
			else if (kb_hit == 224)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_UP)
				{
					flag = 0;
					return;
				}
				else
				{
					flag = 2;
					return;
				}
			}
			else if (kb_hit == ENTER)
			{
				flag = 2;
				return;
			}
			else if (kb_hit == BACKSPACE && count > 0)
			{
				clearNoti();
				gotoxy(x, y);
				cout << "\b" << " " << "\b";
				count--;
				theLoai.erase(theLoai.length() - 1, 1);
			}
			else if (kb_hit == 0)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_F10)
				{
					isSave = true;
					return;
				}
			}
			else if (kb_hit == ESC)
			{
				isEsc = true;
				return;
			}
			else {
				gotoxy(XTB, YTB);
				SetColor(RED);
				cout << "TOI DA 20 KY TU, CHI LAY KY TU CHU !!!";
				setDefaultColor();
				gotoxy(x, y);
			}
		}

	}


}
void NhapTenSach(string &tenSach, int &flag, bool &isSave, bool &isEsc)
{
	hienConTro();
	// bien dem so chu da duoc nhap vao cho result
	cout << tenSach;
	int count = (int)tenSach.length();
	int x, y;
	// bien co hieu
	int nSpace = 0;

	while (true)
	{

		x = wherex();
		y = wherey();
		while (_kbhit())
		{
			int kb_hit = _getch();

			// chi nhan chu thuong hoac  chu in hoa va dau cach va so
			if (((kb_hit >= 65 && kb_hit <= 90) || (kb_hit >= 97 && kb_hit <= 122)
				|| (kb_hit >= 48 && kb_hit <= 57) || kb_hit == SPACE) && count < MAX_TENSACH && count >= 0)
			{
				clearNoti();
				gotoxy(x, y);

				if (nSpace == 1 && kb_hit == SPACE)
				{
					count++;
					cout << (char)kb_hit;
					tenSach += (char)kb_hit;
					nSpace = 0;
				}
				else if (kb_hit != SPACE)
				{
					count++;
					kb_hit = toupper((char)kb_hit);
					cout << (char)kb_hit;
					tenSach += (char)kb_hit;
					nSpace = 1;
				}

			}
			else if (kb_hit == 224)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_UP)
				{
					flag = 1;
					return;
				}
				else
				{
					flag = 3;
					return;
				}
			}
			else if (kb_hit == ENTER)
			{
				flag = 3;
				return;
			}
			else if (kb_hit == BACKSPACE && count > 0)
			{
				clearNoti();
				gotoxy(x, y);
				cout << "\b" << " " << "\b";
				count--;
				tenSach.erase(tenSach.length() - 1, 1);
			}
			else if (kb_hit == 0)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_F10)
				{
					isSave = true;
					return;
				}
			}
			else if (kb_hit == ESC)
			{
				isEsc = true;
				return;
			}
			else {
				gotoxy(XTB, YTB);
				SetColor(RED);
				cout << "TOI DA 20 KY TU, GOM KY TU CHU VA SO";
				setDefaultColor();
				gotoxy(x, y);
			}
		}
	}
}
void NhapTenTacGia(string &tacGia, int &flag, bool &isSave, bool &isEsc)
{
	hienConTro();
	// bien dem so chu da duoc nhap vao cho result
	cout << tacGia;
	int count = (int)tacGia.length();
	int x, y;
	// bien co hieu
	int nSpace = 0;

	while (true)
	{

		x = wherex();
		y = wherey();
		while (_kbhit())
		{
			int kb_hit = _getch();

			// chi nhan chu thuong hoac  chu in hoa va dau cach

			if (((kb_hit >= 65 && kb_hit <= 90) || (kb_hit >= 97 && kb_hit <= 122) || kb_hit == SPACE)
				&& count < MAX_TENTG && count >= 0)
			{
				clearNoti();
				gotoxy(x, y);

				if (nSpace == 1 && kb_hit == SPACE)
				{
					count++;
					cout << (char)kb_hit;
					tacGia += (char)kb_hit;
					nSpace = 0;
				}
				else if (kb_hit != SPACE)
				{
					count++;
					kb_hit = toupper((char)kb_hit);
					cout << (char)kb_hit;
					tacGia += (char)kb_hit;
					nSpace = 1;
				}

			}
			else if (kb_hit == 224)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_UP)
				{
					flag = 2;
					return;
				}
				else
				{
					flag = 4;
					return;
				}
			}
			else if (kb_hit == ENTER)
			{
				flag = 4;
				return;
			}
			else if (kb_hit == BACKSPACE && count > 0)
			{
				clearNoti();
				gotoxy(x, y);
				cout << "\b" << " " << "\b";
				count--;
				tacGia.erase(tacGia.length() - 1, 1);


			}
			else if (kb_hit == 0)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_F10)
				{
					isSave = true;
					return;
				}
			}
			else if (kb_hit == ESC)
			{
				isEsc = true;
				return;
			}
			else {
				gotoxy(XTB, YTB);
				SetColor(RED);
				cout << "TOI DA 20 KY TU, CHI LAY KY TU CHU";
				setDefaultColor();
				gotoxy(x, y);
			}
		}

	}


}
void nhapSoTrang(int &nTrang, int &flag, bool &isSave, bool &isEsc)
{
	hienConTro();
	// dem so chu so
	// cout << nTrang;
	int temp = nTrang;
	int count = 0;
	int x, y;
	while (temp != 0)
	{
		count++;
		temp /= 10;
	}

	if (count)
	{
		cout << nTrang;
	}
	while (true)
	{
		x = wherex();
		y = wherey();
		while (_kbhit())
		{
			int kb_hit = _getch();
			if (kb_hit >= 48 && kb_hit <= 57 && count < 6)
			{
				clearNoti();
				gotoxy(x, y);


				int f = kb_hit - 48;
				cout << f;
				nTrang = nTrang * 10 + (f);
				count++;
			}
			else if (kb_hit == 224)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_UP)
				{
					flag = 3;
					return;
				}
				else
				{
					flag = 5;
					return;
				}
			}
			else if (kb_hit == ENTER)
			{
				flag = 5;
				return;
			}
			else if (kb_hit == BACKSPACE && count > 0)
			{
				clearNoti();
				gotoxy(x, y);
				cout << "\b" << " " << "\b";
				count--;
				nTrang /= 10;
			}
			else if (kb_hit == 0)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_F10)
				{
					isSave = true;
					return;
				}
			}
			else if (kb_hit == ESC)
			{
				isEsc = true;
				return;
			}
			else {
				gotoxy(XTB, YTB);
				SetColor(RED);
				cout << "KY TU SO VA CHIEU DAI <= 6";
				setDefaultColor();
				gotoxy(x, y);
			}
		}
	}


}
void NhapNamXuatBan(int &namXB, int &flag, bool &isSave, bool &isEsc)
{
	hienConTro();
	// dem so chu so
	int temp = namXB;
	int count = 0;
	int x, y;
	while (temp != 0)
	{
		count++;
		temp /= 10;
	}
	if (count)
	{
		cout << namXB;
	}
	while (true)
	{
		x = wherex();
		y = wherey();
		while (_kbhit())
		{
			int kb_hit = _getch();
			if (kb_hit >= 48 && kb_hit <= 57 && count <= 3)
			{
				clearNoti();
				gotoxy(x, y);

				int f = kb_hit - 48;
				cout << f;
				namXB = namXB * 10 + (f);
				count++;
			}
			else if (kb_hit == 224)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_UP)
				{

					flag = 4;
					return;
				}
				else
				{
					flag = 0;
					return;
				}
			}
			else if (kb_hit == ENTER)
			{

				flag = 0;
				return;
			}
			else if (kb_hit == BACKSPACE && count > 0)
			{
				clearNoti();
				gotoxy(x, y);
				cout << "\b" << " " << "\b";
				count--;
				namXB /= 10;
			}
			else if (kb_hit == 0)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_F10)
				{
					isSave = true;
					return;
				}
			}
			else if (kb_hit == ESC)
			{
				isEsc = true;
				return;
			}
			else {
				gotoxy(XTB, YTB);
				SetColor(RED);
				cout << "KY TU SO VA CHIEU DAI <= 4";
				setDefaultColor();
				gotoxy(x, y);
			}
		}
	}
}
void NhapTrangThaiSach(int &result, int &ordinal, bool &isSave, bool &isEscape, int a, int b)
{
	gotoxy(a -1, b -1);
	hienConTro();
	int count = 0;

	int x = wherex() , y = wherey() ;
	if (result == 3)
	{
		result = 0;
		gotoxy(x, y);
		cout << result << ":  CHO MUON DUOC ";

	}
	while (true)
	{
		while (_kbhit())
		{
			int kb_hit = _getch();
			if ((kb_hit == 48 || kb_hit == 50) && count < 1)
			{
				count++;
				result = kb_hit - 48;
				// xoa dong thong bao
				gotoxy(XTB - 52, YTB + 6);
				cout << setw(49) << setfill(' ') << " ";
				gotoxy(x, y);
				if (result == 0)
					cout << result << ":   CHO MUON DUOC ";
				else if (result == 1)
					cout << result << ":   DA DUOC MUON  ";
				else if (result == 2)
					cout << result << ":   DA THANH LY   ";

			}
			else if (kb_hit == 224)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_UP)
				{
					ordinal = 2;
					return;
				}
				else
				{
					ordinal = 2;
					return;
				}
			}
			else if (kb_hit == ENTER)
			{
				ordinal = 2;
				return;
			}
			else if (kb_hit == BACKSPACE && count > 0)
			{

				gotoxy(x, y);
				result = 3;
				cout << " " << setw(17) << setfill(' ') << " ";
				count--;
				// chuyen ve vi tri ban dau.
				gotoxy(x, y);
			}
			else if (kb_hit == 0)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_F10)
				{
					isSave = true;
					return;
				}
			}
			else if (kb_hit == ESC)
			{
				isEscape = true;
				return;
			}
			else {

				gotoxy(XTB - 52, YTB + 6);
				SetColor(RED);
				cout << "BAN HAY NHAP 0, 2, HOAC Backspace DE XOA !!!";
				setDefaultColor();
				gotoxy(x, y);
			}

		}
	}
}
void NhapViTri(string &result, int &ordinal, bool &isSave, bool &isEscape, int a, int b)
{
	gotoxy(a, b);
	hienConTro();
	// bien dem so chu da duoc nhap vao cho result
	cout << result;
	int count = (int)result.length();
	int x, y;
	// bien co hieu
	int nSpace = 0;

	while (true)
	{

		x = wherex() ;
		y = wherey() ;
		while (_kbhit())
		{
			int kb_hit = _getch();

			// chi nhan chu thuong hoac  chu in hoa va dau cach, dau phay, va so.
			if (((kb_hit >= 65 && kb_hit <= 90) || (kb_hit >= 97 && kb_hit <= 122) || (kb_hit >= 48 && kb_hit <= 57)
				|| kb_hit == SPACE || kb_hit == 44) && count < MAX_TENTG && count >= 0)
			{
				// xoa dong thong bao
				gotoxy(XTB - 52, YTB + 6);
				cout << setw(48) << setfill(' ') << " ";
				gotoxy(x, y);
				// chuan hoa khoang trong
				if (nSpace == 1 && kb_hit == SPACE)
				{
					count++;
					cout << (char)kb_hit;
					result += (char)kb_hit;
					nSpace = 0;
				}
				else if (kb_hit != SPACE)
				{
					count++;
					kb_hit = toupper((char)kb_hit);
					cout << (char)kb_hit;
					result += (char)kb_hit;
					nSpace = 1;
				}

			}
			else if (kb_hit == 224)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_UP)
				{
					ordinal = 1;
					return;
				}
				else
				{
					ordinal = 1;
					return;
				}
			}
			else if (kb_hit == ENTER)
			{
				ordinal = 1;
				return;
			}
			else if (kb_hit == BACKSPACE && count > 0)
			{
				cout << "\b" << " " << "\b";
				count--;
				result.erase(result.length() - 1, 1);


			}
			else if (kb_hit == 0)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_F10)
				{
					isSave = true;
					return;
				}
			}
			else if (kb_hit == ESC)
			{
				isEscape = true;
				return;
			}
			else {// check vi tri a ne.
				gotoxy(XTB - 52, YTB + 6);
				SetColor(RED);
				cout << "TOI DA 17  KY TU, BAO GOM CHU, SO VA DAU PHAY !";
				setDefaultColor();
				gotoxy(x, y);
			}

		}

	}


}
int NhapSach(pDauSach &pDS)
{
	DMS info;
	// hien con tro nhap
	hienConTro();
	// cac flag dieu khien qua trinh cap nhat
	int ordinal = 1;
	bool isSave = false;
	bool isEscape = false;
	int stt = pDS->dms.n;
	string maSach = pDS->info.ISBN + (string)("_")+ to_string(++stt);
	// neu maSach co trung thi tang ma sach len.
	while (Search_DMS1(pDS, maSach) != NULL)
	{
		stt++;
		maSach = pDS->info.ISBN + (string)("_") + to_string(stt);
	}

	int ttSach = 3;
	string viTri = "";

	gotoxy(xDMS + 16,yDMS+2);
	cout << maSach;

	while (true)
	{
		switch (ordinal)
		{
		case 1:
			NhapTrangThaiSach(ttSach, ordinal, isSave, isEscape, xDMS + 17, yDMS+6);
			break;
		case 2:
			NhapViTri(viTri, ordinal, isSave, isEscape, xDMS + 16, yDMS + 8);
			break;
		}

		// check Save
		if (isSave)
		{
			// cap nhat lai flag
			isSave = false;

			// check rong;
			if (ttSach == 3)
			{
				gotoxy(XTB - 52, YTB + 6);
				SetColor(RED);
				cout << "CAC TRUONG DU LIEU KHONG DUOC DE TRONG !!!";
				setDefaultColor();
				// quay lai va dien vao truong du lieu do
				ordinal = 1;
				continue;
			}

			if (viTri.length() == 0)
			{
				gotoxy(XTB - 52, YTB + 6);
				SetColor(RED);
				cout << "CAC TRUONG DU LIEU KHONG DUOC DE TRONG !!!";
				setDefaultColor();
				// quay lai va dien vao truong du lieu do
				ordinal = 2;
				continue;
			}

			// import data vao info
			ChuanHoaString(maSach).copy(info.maSach, maSach.size() + 1);
			info.trangThai = ttSach;
			ChuanHoaString(viTri).copy(info.viTri, viTri.size() + 1);
			AddTailList_DMS(pDS->dms, info);
			return 0;
		}
		if (isEscape)
		{
			return -1;
		}
	}
}
int SuaDanhMucSach(pDauSach &pDS, NODE_DMS* dms)
{
	DMS info;
	// kiem tra dieu kien.
	if (dms->data.trangThai == 1)
		return 2;
	// hien con tro nhap
	hienConTro();
	setDefaultColor();
	// cac flag dieu khien qua trinh cap nhat
	int ordinal = 1;
	bool isSave = false;
	bool isEscape = false;

	string maSach = dms->data.maSach;
	int ttSach = dms->data.trangThai;
	string viTri = dms->data.viTri;

	gotoxy(xDMS + 16, yDMS + 2);
	cout << maSach;

	gotoxy(xDMS + 16, yDMS + 5);
	if (ttSach == 0)
		cout << ttSach << ":   CHO MUON DUOC  ";
	else if (ttSach == 1)
		cout << ttSach << ":   DA DUOC MUON   ";
	else if (ttSach == 2)
		cout << ttSach << ":   DA THANH LY    ";

	gotoxy(xDMS + 16, yDMS + 8);
	cout << viTri;
	while (true)
	{
		switch (ordinal)
		{
		case 1:
			NhapTrangThaiSach(ttSach, ordinal, isSave, isEscape, xDMS + 17, yDMS + 6);
			break;
		case 2:

			NhapViTri(viTri, ordinal, isSave, isEscape, xDMS + 16, yDMS + 8);
			break;
		}

		// check Save
		if (isSave)
		{
			// cap nhat lai flag
			isSave = false;

			// check rong;
			if (ttSach == 3)
			{
				gotoxy(XTB, YTB);
				SetColor(RED);
				cout << "CAC TRUONG DU LIEU KHONG DUOC DE TRONG !!! ";
				setDefaultColor();
				// quay lai va dien vao truong du lieu do
				ordinal = 1;
				continue;
			}

			if (viTri.length() == 0)
			{
				gotoxy(XTB, YTB);
				SetColor(RED);
				cout << "CAC TRUONG DU LIEU KHONG DUOC DE TRONG !!! ";
				setDefaultColor();

				// quay lai va dien vao truong du lieu do
				ordinal = 2;
				continue;
			}

			// import data vao info
			ChuanHoaString(maSach).copy(info.maSach, maSach.size() + 1);
			info.trangThai = ttSach;
			ChuanHoaString(viTri).copy(info.viTri, viTri.size() + 1);

			dms->data = info;
			return 1;
		}
		if (isEscape)
		{
			return -1;
		}
	}

}
int ChooseItemTL(LIST_DauSach &lDS, Tree &t, pDauSach &pDS) {

	string lTL[100] = {};
	int slTL = getTheLoai(lDS, lTL);
	//clearTheLoai(slTL+2);
	int x, y;
	int pos = 0;
	int kb_hit;
	int tttrangTL, tongtrangTL;
	
	tttrangTL = 1;
	int iTL = 0;
	tongtrangTL = (slTL / (NUMBER_LINES)) +1;
	pos = 0;
	
loop:
	clearTL();
	showListTL(lTL, tttrangTL, slTL);
	SetBGColor(YELLOW);
	SetColor(BLACK);
	gotoxy(xD, yD + pos);
	iTL = (tttrangTL - 1)*(NUMBER_LINES);
	cout << lTL[iTL];
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
			case PAGE_UP:
				(tttrangTL > 1) ? tttrangTL-- : tttrangTL = tongtrangTL;
				pos = 0;
				goto loop;

			case PAGE_DOWN:
				(tttrangTL < tongtrangTL) ? tttrangTL++ : tttrangTL = 1;
				pos = 0;
				goto loop;
			case KEY_UP:
				// xoa muc truoc
				SetBGColor(BLACK);
				SetColor(WHITE);
				gotoxy(xD, yD + pos);
				cout << lTL[iTL + pos];
				setDefaultColor();
				//(pos > 0) ? pos-- : pos = NUMBER_LINES;
				if (pos > 0) pos--;
				else {
					if (iTL < NUMBER_LINES) {
						pos = NUMBER_LINES - 1;
					}
					else {
						pos = slTL - iTL - 1;
					}
				}
				// to mau muc moi
				SetBGColor(YELLOW);
				SetColor(BLACK);
				gotoxy(xD, yD + pos);
				cout << lTL[iTL + pos];
				setDefaultColor();
				break;

			case KEY_DOWN:
				// xoa muc truoc
				SetBGColor(BLACK);
				SetColor(WHITE);
				gotoxy(xD, yD + pos);
				cout << lTL[iTL + pos];
				setDefaultColor();
				//(pos < NUMBER_LINES && pos < iTL + pos) ? pos++ : pos = 0;
				if (pos < NUMBER_LINES - 1) {
					if (iTL < NUMBER_LINES) {
						pos++;
					}
					else if (pos < slTL - iTL - 1) {
						pos++;
					}
					else pos = 0;
				}
				else pos = 0;
				// to mau muc moi
				SetBGColor(YELLOW);
				SetColor(BLACK);
				gotoxy(xD, yD + pos);
				cout << lTL[iTL + pos];
				setDefaultColor();
				break;
			case KEY_F2:
				pDS = new DauSach;
				inputDS(lDS, pDS, false);
				ChooseItemTL(lDS, t, pDS);
				break;
			case KEY_F5:

				break;
			case ENTER:
				OutputDS_PerPage(lDS, lTL[iTL + pos], 1);
				break;
			case KEY_RIGHT:
				OutputDS_PerPage(lDS, lTL[iTL + pos], 1);
				ChooseItems_DS(lDS, t, pDS, lTL[iTL + pos]);
				break;
			case ESC:
				xuLy(lDS, t);
				break;
			}
		}
		anConTro();
		SetColor(WHITE);
		gotoxy(xD, 36);
		cout << tttrangTL << " / " << tongtrangTL;
		setDefaultColor();
	}
}

int ChooseItemTL_MT(LIST_DauSach &lDS, Tree &t, pDauSach &pDS)
{

	string lTL[100] = {};
	int slTL = getTheLoai(lDS, lTL) - 1;
	clearTheLoai(slTL + 2);
	
	int pos = 0;
	int kb_hit;
	int tttrang, tongtrang;
	tttrang = 1;
	tongtrang = (lDS.n / NUMBER_LINES) + 1;
<<<<<<< HEAD
	showListTL(lTL,tttrang,slTL );
=======
	showListTL(lTL, tttrang,slTL);
>>>>>>> a4583d3bccbb7716aba1b22796c4e0dcedf1149a
	pos = 0;
	SetBGColor(YELLOW);
	SetColor(BLACK);
	gotoxy(xD, yD + pos);
	cout << lTL[0];
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
				SetBGColor(BLACK);
				SetColor(WHITE);
				gotoxy(xD, yD + pos);
				cout << lTL[pos];
				setDefaultColor();
				//(pos > 0) ? pos-- : pos = slTL;
				if (slTL <= (NUMBER_LINES - 1))
					(pos > 0) ? pos-- : pos = slTL;
				else (pos > 0) ? pos-- : pos = NUMBER_LINES - 1;

				// to mau muc moi
				SetBGColor(YELLOW);
				SetColor(BLACK);
				gotoxy(xD, yD + pos);
				cout << lTL[pos];
				setDefaultColor();
				break;

			case KEY_DOWN:
				// xoa muc truoc
				SetBGColor(BLACK);
				SetColor(WHITE);
				gotoxy(xD, yD + pos);
				cout << lTL[pos];
				setDefaultColor();
				//(pos < slTL) ? pos++ : pos = 0;
				if (slTL <= (NUMBER_LINES - 1))
					(pos < slTL) ? pos++ : pos = 0;
				else (pos < NUMBER_LINES - 1) ? pos++ : pos = 0;

				// to mau muc moi
				SetBGColor(YELLOW);
				SetColor(BLACK);
				gotoxy(xD, yD + pos);
				cout << lTL[pos];
				setDefaultColor();
				break;

			case KEY_F5:

				break;
			case ENTER:
				OutputDS_PerPage(lDS, lTL[pos], tttrang);
				break;
			case KEY_RIGHT:
				OutputDS_PerPage(lDS, lTL[pos], tttrang);
				return ChooseItems_DS_MT(lDS, t, pDS, lTL[pos]);
				break;
			case ESC:
				return -1;
				break;
			}
		}
		anConTro();
		SetColor(WHITE);
		gotoxy(45, 38);
		cout << "Trang " << tttrang << " / " << tongtrang;
		setDefaultColor();
	}
}

int ChooseItems_DS(LIST_DauSach &lDS,Tree &t, pDauSach &pDS, string theLoai)
{
	LIST_DauSach l = getDSByTL(lDS, theLoai);
	NODE_DMS *dms;
	int slSach = 0;
	int pos = 0;
	int choose = 0;
	int kb_hit;
	int tttrangDS, tongtrangDS;
	int iDS = 0;
	tttrangDS = 1;
	tongtrangDS = (l.n / NUMBER_LINES) + 1;
loop:
	
	pos = 0;
	OutputDS_PerPage(lDS,theLoai,tttrangDS);
	SetColor(BLACK);
	SetBGColor(YELLOW);
	gotoxy(xDisplayDS[1], yD + pos);
	iDS = (tttrangDS - 1)*(NUMBER_LINES);
	cout << l.nodesDauSach[iDS  + pos]->info.tenSach;
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
			case PAGE_UP:
				(tttrangDS > 1) ? tttrangDS-- : tttrangDS = tongtrangDS;
				pos = 0;
				goto loop;

			case PAGE_DOWN:
				(tttrangDS < tongtrangDS) ? tttrangDS++ : tttrangDS = 1;
				pos = 0;
				goto loop;
			case KEY_UP:
				// xoa muc truoc
				SetColor(WHITE);
				SetBGColor(BLACK);
				gotoxy(xDisplayDS[1], yD + pos);
				cout << l.nodesDauSach[iDS + pos]->info.tenSach;
				setDefaultColor();
				//(pos > 0) ? pos-- : pos = l.n-1;

				if (pos > 0) pos--;
				else if (tttrangDS == tongtrangDS){
					pos = l.n - iDS - 1;
				}else {
					pos = NUMBER_LINES - 1;
				}

				// to mau muc moi
				SetBGColor(YELLOW);
				SetColor(BLACK);
				gotoxy(xDisplayDS[1], yD + pos);
				cout << l.nodesDauSach[iDS + pos]->info.tenSach;
				setDefaultColor();
				break;

			case KEY_DOWN:
				// xoa muc truoc
				SetColor(WHITE);
				SetBGColor(BLACK);
				gotoxy(xDisplayDS[1], yD + pos);
				cout << l.nodesDauSach[iDS +pos]->info.tenSach;
				setDefaultColor();
				//(pos < l.n-1) ? pos++ : pos = 0;
				
				if (tttrangDS == tongtrangDS) {
					if (pos < l.n - iDS - 1) {
						pos++;
					}
					else pos = 0;
				}
				else if (pos < NUMBER_LINES - 1) {
					pos++;
				}else pos = 0;
				
			
				// to mau muc moi
				SetBGColor(YELLOW);
				SetColor(BLACK);
				gotoxy(xDisplayDS[1], yD + pos);
				cout << l.nodesDauSach[iDS + pos]->info.tenSach;
				setDefaultColor();
				break;
			case KEY_F2:
				pDS = new DauSach;
				inputDS(lDS, pDS, false);
				ChooseItemTL(lDS,t,pDS);
				break;
			case KEY_F3:
				pos = getPosByPDS(lDS, l.nodesDauSach[iDS +pos]);
				inputDS(lDS, lDS.nodesDauSach[pos + iDS], true);
				ChooseItemTL(lDS,t,pDS);
				break;
			case KEY_F4:
				// neu co nguoi muon thi se khong duoc phep xoa .
				if (Check_DMS(l.nodesDauSach[iDS + pos]->dms.pHeadDMS))
				{
					gotoxy(XTB, YTB);
					SetColor(RED);
					cout << "Sach dang muon, khong the xoa";
					setDefaultColor();
					break;
				}
				DeleteDauSach(lDS, pDS = l.nodesDauSach[iDS + pos]);
				Xoa_OutDS_29lines();
				ChooseItemTL(lDS,t, pDS);
				break;
			case KEY_F5:
				slSach = drawInputSLSach();
				pos = getPosByPDS(lDS, l.nodesDauSach[iDS + pos]);
				InputDMS(lDS.nodesDauSach[pos],slSach);
				ChooseItem_DMS(lDS.nodesDauSach[pos], tttrangDS, tongtrangDS);
				menuDS(lDS, pDS, t);
			case KEY_F6:
				pos = getPosByPDS(lDS, l.nodesDauSach[iDS + pos]);
				if (lDS.nodesDauSach[pos]->dms.n <= 0) {
					gotoxy(XTB, YTB);
					SetColor(RED);
					cout << "DAU SACH CHUA CO SACH !!!";
					Sleep(1000);
					Xoa_OutDS_29lines();
					clearNoti();
					setDefaultColor();
					Xoa_OutDS_29lines();

					goto loop;
				}
<<<<<<< HEAD
				
=======
>>>>>>> a4583d3bccbb7716aba1b22796c4e0dcedf1149a
				choose = ChooseItem_DMS(lDS.nodesDauSach[pos], tttrangDS, tongtrangDS);
				if (choose == -1) {
					Xoa_OutDS_29lines();
					menuDS(lDS, pDS, t);
					break;
				}
				dms = Search_DMS_Pos(lDS.nodesDauSach[pos]->dms.pHeadDMS, choose);
				drawInputDMS();
				SuaDanhMucSach(lDS.nodesDauSach[pos], dms);
				break;
			case KEY_LEFT:
				Xoa_OutDS_29lines();
				setHighLightColor();
				gotoxy(35, 36);
				cout << "" << setw(8) << setfill(char(196) )<< "";
				setDefaultColor();
				ChooseItemTL(lDS,t,pDS);
			case ESC:
				Xoa_OutDS_29lines();
				setHighLightColor();
				gotoxy(35, 36);
				cout << "" << setw(8) << setfill(char(196)) << "";
				setDefaultColor();
				ChooseItemTL(lDS, t, pDS);
				break;
			}
		}
		anConTro();
		SetColor(WHITE);
		gotoxy(35, 36);
		cout << tttrangDS << " / " << tongtrangDS;
		setDefaultColor();
	}
}

int ChooseItems_DS_MT(LIST_DauSach &lDS, Tree &t, pDauSach &pDS, string theLoai)
{
	LIST_DauSach l = getDSByTL(lDS, theLoai);
	NODE_DMS *dms;
	int slSach = 0;
	int pos = 0;
	int choose = 0;
	int kb_hit;
	int tttrang, tongtrang;
	tttrang = 1;
	tongtrang = (lDS.n / NUMBER_LINES) + 1;

loop:
	pos = 0;
	SetColor(BLACK);
	SetBGColor(YELLOW);
	gotoxy(xDisplayDS[1], yD + pos);
	cout << l.nodesDauSach[pos]->info.tenSach;
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
				SetColor(WHITE);
				SetBGColor(BLACK);
				gotoxy(xDisplayDS[1], yD + pos);
				cout << l.nodesDauSach[pos]->info.tenSach;
				setDefaultColor();
				//(pos > 0) ? pos-- : pos = l.n - 1;
				if (l.n <= NUMBER_LINES)
					(pos > 0) ? pos-- : pos = l.n - 1;
				else (pos > 0) ? pos-- : pos = NUMBER_LINES - 1;

				// to mau muc moi
				SetBGColor(YELLOW);
				SetColor(BLACK);
				gotoxy(xDisplayDS[1], yD + pos);
				cout << l.nodesDauSach[pos]->info.tenSach;
				setDefaultColor();
				break;

			case KEY_DOWN:
				// xoa muc truoc
				SetColor(WHITE);
				SetBGColor(BLACK);
				gotoxy(xDisplayDS[1], yD + pos);
				cout << l.nodesDauSach[pos]->info.tenSach;
				setDefaultColor();
				//(pos < l.n - 1) ? pos++ : pos = 0;
				if (l.n <= NUMBER_LINES)
					(pos < l.n - 1) ? pos++ : pos = 0;
				else (pos < NUMBER_LINES - 1) ? pos++ : pos = 0;

				// to mau muc moi
				SetBGColor(YELLOW);
				SetColor(BLACK);
				gotoxy(xDisplayDS[1], yD + pos);
				cout << l.nodesDauSach[pos]->info.tenSach;
				setDefaultColor();
				break;
			case ENTER:
				pos = getPosByPDS(lDS, l.nodesDauSach[pos]);
				return pos;
			
			case KEY_LEFT:
				Xoa_OutDS_29lines();
				ChooseItemTL_MT(lDS, t, pDS);
			case ESC:
				return -1;
			}
		}
		anConTro();
		SetColor(WHITE);
		gotoxy(45, 38);
		cout << "Trang " << tttrang << " / " << tongtrang;
		setDefaultColor();
	}
}

int ChooseItem_DMS_MT(pDauSach &pDS, int &tttrang, int tongtrang)
{
	NODE_DMS *p;
	int slSach = 0;
	int pos = 0;
	int kb_hit;
	int nDMS = pDS->dms.n;
	pos = 0;

	setHighLightColor();
	gotoxy(7, yDisplayDG + 2 + pos);
	p = Search_DMS_Pos(pDS->dms.pHeadDMS, pos);
	cout << p->data.maSach;

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
				gotoxy(7, yDisplayDG + 2 + pos);
				p = Search_DMS_Pos(pDS->dms.pHeadDMS, pos);
				cout << p->data.maSach;
				if (nDMS <= NUMBER_LINES)
					(pos > 0) ? pos-- : pos = nDMS - 1;
				else (pos > 0) ? pos-- : pos = NUMBER_LINES - 1;

				// to mau muc moi
				setHighLightColor();
				gotoxy(7, yDisplayDG + 2 + pos);
				p = Search_DMS_Pos(pDS->dms.pHeadDMS, pos);
				cout << p->data.maSach;
				setDefaultColor();
				break;

			case KEY_DOWN:

				// xoa muc truoc
				setDefaultColor();
				gotoxy(7, yDisplayDG + 2 + pos);
				p = Search_DMS_Pos(pDS->dms.pHeadDMS, pos);
				cout << p->data.maSach;
				if(nDMS <= NUMBER_LINES)
					(pos < nDMS-1) ? pos++ : pos = 0;
				else (pos < NUMBER_LINES - 1) ? pos++ : pos = 0;

				// to mau muc moi
				setHighLightColor();
				gotoxy(7, yDisplayDG + 2 + pos);
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
				gotoxy(7, yDisplayDG + 2 + pos);
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
				gotoxy(7, yDisplayDG + 2 + pos);
				p = Search_DMS_Pos(pDS->dms.pHeadDMS, pos);
				cout << p->data.maSach;
				break;
	
			case ENTER:
				/*if (pDS->dms.) {

				}*/
				return (pos == 0 && tttrang == 1) ? pos : pos + (tttrang - 1)* NUMBER_LINES;
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