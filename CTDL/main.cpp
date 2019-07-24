#include "stdafx.h"
#include "DauSach.h"
#include "RWDauSach.h"
#include "welcome.h"
#include "mylib.h"
#include "constant.h"
#include "xuLyDS.h"
using namespace std;


void menu(int lc, LIST_DauSach &lds, dauSach dauS, DMS dataDMS, LIST_DMS ldms);
int main() {
	int flag = 5;
	welcomeConsole();
	//menuFeature(4, 52, 20, flag,listMenu);
	dauSach dauS;
	LIST_DauSach lds;
	DMS dataDMS;
	LIST_DMS ldms;
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
			menu(lc, lds, dauS,dataDMS,ldms);
			break;
		default:
			break;
		}	
	}
	system("pause");
	return 0;
}
void menu(int lc, LIST_DauSach &lds, dauSach dauS, DMS dataDMS, LIST_DMS ldms) {
	//pDauSach pDS = nullptr;
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
				initList_DMS(ldms);
				//so luong sach
				int slSach = 0;
				cout << "Nhap vao so luong dms: "; cin >> slSach;
				lds.nodesDauSach[i]->dms.n = slSach;
				for (int j = 0; j < slSach; j++) {
					cout << "Nhap vao thong tin sach: " + (j+1) <<endl;
					cout << "Ma sach: "; cin.ignore(); getline(cin, dataDMS.maSach);
					cout << "Trang thai: "; cin >> dataDMS.trangThai;
					cout << "Vi tri: "; cin.ignore(); getline(cin, dataDMS.viTri);
					AddTailList_DMS(ldms, dataDMS);
				}
				lds.nodesDauSach[i]->dms.pHeadDMS= ldms.pHeadDMS;
			}
		}
		SaveDS(lds);
		break;
	case 2:
		/*try {
			
		}
		catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}*/
		LIST_DauSach lds1;
		OpenFile(lds1);
		for (int i = 0; i < lds1.n; i++) {
			cout << puts(lds1.nodesDauSach[i]->info.ISBN) << endl;
			cout << lds1.nodesDauSach[i]->info.namXuatBan << endl;
			cout << lds1.nodesDauSach[i]->info.soTrang << endl;
			cout << lds1.nodesDauSach[i]->info.tacGia << endl;
			cout << lds1.nodesDauSach[i]->info.tenSach << endl;
			cout << lds1.nodesDauSach[i]->info.theLoai << endl;
			if (lds1.nodesDauSach[i]->dms.n > 0) {
				for (NODE_DMS *p = lds1.nodesDauSach[i]->dms.pHeadDMS; p != NULL; p = p->pNext) {
					cout << "Ma sach: " + p->data.maSach << endl;
					cout << "Trang thai: " + p->data.trangThai << endl;
					cout << "Vi tri: " + p->data.viTri << endl;
				}
			}
		}
		system("pause");
		break;
	}
}
