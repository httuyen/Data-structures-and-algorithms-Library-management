#include "stdafx.h"
#include "DauSach.h"
#include "RWDauSach.h"
#include "welcome.h"
#include "mylib.h"
#include "constant.h"
#include "xuLyDS.h"
using namespace std;


void menu(int lc, LIST_DauSach &lds, dauSach dauS, DMS dataDMS, LIST_DMS ldms, pDauSach &pDS);
int main() {
	int flag = 5;
	welcomeConsole();
	//menuFeature(4, 52, 20, flag,listMenu);
	dauSach dauS;
	LIST_DauSach lds;
	DMS dataDMS;
	LIST_DMS ldms;
	pDauSach pDS;
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
			menu(lc, lds, dauS,dataDMS,ldms,pDS);
			break;
		default:
			break;
		}	
	}
	system("pause");
	return 0;
}
void menu(int lc, LIST_DauSach &lds, dauSach dauS, DMS dataDMS, LIST_DMS ldms,pDauSach &pDS) {
	//pDauSach pDS = nullptr;
	switch (lc)
	{
	case 1:
		cout << "So luong dau sach: "; cin >> lds.n;
		cin.ignore();
		for (int i = 0; i < lds.n; i++) {
			cout << "Nhap vao Dau sach " + (i+1)<<endl;
			cout << "ISBN: ";
			cin.getline(dauS.ISBN, 6);
			cout << "Nam XB: ";	cin >> dauS.namXuatBan;
			cout << "so trang: "; cin >> dauS.soTrang; cin.ignore();
			cout << "tac gia: ";  cin.getline(dauS.tacGia,6);
			cout << "ten sach: "; cin.getline( dauS.tenSach,6);
			cout << "the loai: "; cin.getline( dauS.theLoai,6);
			cout << "Ban co muon nhap danh muc sach cho dau sach nay khong?";
			lds.nodesDauSach[i] = new DauSach;
			lds.nodesDauSach[i]->info = dauS;
			int YN; cin >> YN;
			if (YN == 1)
			{
				initList_DMS(ldms);
				//so luong sach
				int slSach = 0;
				cout << "Nhap vao so luong dms: "; cin >> slSach; cin.ignore();
				lds.nodesDauSach[i]->dms.n = slSach;
				for (int j = 0; j < slSach; j++) {
					cout << "Nhap vao thong tin sach: " + (j+1) <<endl;
					cout << "Ma sach: ";  cin.getline(dataDMS.maSach,6);
					cout << "Trang thai: "; cin >> dataDMS.trangThai; cin.ignore();
					cout << "Vi tri: ";  cin.getline(dataDMS.viTri,6);
					AddTailList_DMS(ldms, dataDMS);
				}
				lds.nodesDauSach[i]->dms.pHeadDMS= ldms.pHeadDMS;
			}
			else if (YN == 2) {
				lds.nodesDauSach[i]->dms.pHeadDMS = lds.nodesDauSach[i]->dms.pTailDMS = nullptr;
			}
		}
		SaveDS(lds);
		
		break;
	case 2:
		//initListDS(lds);
		LIST_DauSach lds1;
		OpenFile(lds1,pDS);
		for (int i = 0; i < lds1.n; i++) {
			cout << puts(lds1.nodesDauSach[i]->info.ISBN) << endl;
			cout << lds1.nodesDauSach[i]->info.namXuatBan << endl;
			cout << lds1.nodesDauSach[i]->info.soTrang << endl;
			cout << lds1.nodesDauSach[i]->info.tacGia << endl;
			cout << lds1.nodesDauSach[i]->info.tenSach << endl;
			cout << lds1.nodesDauSach[i]->info.theLoai << endl;
			if (lds1.nodesDauSach[i]->dms.n > 0) {
				for (NODE_DMS *p = lds1.nodesDauSach[i]->dms.pHeadDMS; p != NULL; p = p->pNext) {
					cout << "Ma sach: " << p->data.maSach << endl;
					cout << "Trang thai: " << p->data.trangThai << endl;
					cout << "Vi tri: " << p->data.viTri << endl;
				}
			}
		}
		system("pause");
		break;
	}
}
