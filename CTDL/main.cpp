#include "stdafx.h"
#include "DauSach.h"
#include "RWDauSach.h"
#include "welcome.h"
#include "mylib.h"
#include "constant.h"
#include "xuLyDS.h"
using namespace std;


void menu(int lc, LIST_DauSach &lds, dauSach dauS);
int main() {
	int flag = 5;
	welcomeConsole();
	//menuFeature(4, 52, 20, flag,listMenu);
	dauSach dauS;
	LIST_DauSach lds;

	//vong lap cua chuong trinh
	while (true) {
		switch (flag)
		{
		case 1:
			break;
		case 2:
			drawTable();
			break;
		case 3:
			break;
		case 4:
			//thoat chuong trinh
			exit(0);
			break;
		case 5:
			clrscr();
			int lc;
			gotoxy(5, 10); cout << "kiem thu nhap xuat dau sach";
			cout << "nhap lc: "; cin >> lc;
			menu(lc, lds, dauS);
			break;
		default:
			break;
		}	
	}
	system("pause");
	return 0;
}
void menu(int lc, LIST_DauSach &lds, dauSach dauS) {
	pDauSach pDS = nullptr;
	switch (lc)
	{
	case 1:
		cout << "So luong dau sach: "; cin >> lds.n;
		cin.ignore();
		for (int i = 0; i < lds.n; i++) {
			cout << "Nhap vao Dau sach " + (i+1)<<endl;
			cout << "ISBN: ";
			gets_s(dauS.ISBN);
			cout << "Nam XB: ";	cin >> dauS.namXuatBan;
			cout << "so trang: "; cin >> dauS.soTrang;
			cout << "tac gia: "; cin.ignore(); getline(cin, dauS.tacGia);
			cout << "ten sach: "; getline(cin, dauS.tenSach);
			cout << "the loai: "; getline(cin, dauS.theLoai);
			cout << "Ban co muon nhap danh muc sach cho dau sach nay khong?";
			lds.nodesDauSach[i] = new DauSach;
			lds.nodesDauSach[i]->info = dauS;
			int YN; cin >> YN;
			if (YN == 1)
			{
				//NODE_DMS *p = lds.nodesDauSach[i]->dms.pHeadDMS;
				int slSach = 0;
				//so luong sach
				cout << "Nhap vao so luong dms: "; cin >> slSach;
				lds.nodesDauSach[i]->dms.n = slSach;
				DMS dataDMS;
				LIST_DMS ldms;
				for (int j = 0; j < slSach; j++) {
					cout << "Nhap vao thong tin sach: " + (j+1) <<endl;
					cout << "Ma sach: "; cin.ignore(); getline(cin, dataDMS.maSach);
					cout << "Trang thai: "; cin >> dataDMS.trangThai;
					cout << "Vi tri: "; cin.ignore(); getline(cin, dataDMS.viTri);
					AddTailList_DMS(ldms, dataDMS);
				}
				pDS->dms = ldms;
			}

			/*lds.nodesDauSach[i]->dms.pHeadDMS = nullptr;
			lds.nodesDauSach[i]->dms.pTailDMS = nullptr;*/
			//cout << "/////////////////////////////////////////////////////////////\n";
			//cout << puts(dauS.ISBN);
			//cout << dauS.namXuatBan << endl;
			//cout << dauS.soTrang << endl;
			//cout << dauS.tacGia << endl;
			//cout << dauS.tenSach << endl;
			//cout << dauS.theLoai << endl;
		}
		SaveDS(lds);
		delete pDS;
		break;
	case 2:
		OpenFile(lds);
		for (int i = 0; i < lds.n; i++) {
			cout << puts(lds.nodesDauSach[i]->info.ISBN);
			cout << lds.nodesDauSach[i]->info.namXuatBan << endl;
			cout << lds.nodesDauSach[i]->info.soTrang << endl;
			cout << lds.nodesDauSach[i]->info.tacGia << endl;
			cout << lds.nodesDauSach[i]->info.tenSach << endl;
			cout << lds.nodesDauSach[i]->info.theLoai << endl;
		}
		break;
	default: break;
	}
}
