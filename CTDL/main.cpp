#include "stdafx.h"
#include "DauSach.h"
#include "RWDauSach.h"
#include "RWDocGia.h"
#include "welcome.h"
#include "mylib.h"
#include "constant.h"
#include "xuLyDS.h"
using namespace std;


void menu(int lc, LIST_DauSach &lds, dauSach dauS, DMS dataDMS, LIST_DMS ldms, pDauSach &pDS);
void menuDG(int lc);
int main() {
	int flag = 1;
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
		case 1: {
			clrscr();
			int lc;
			gotoxy(5, 10); cout << "kiem thu nhap xuat doc gia";
			cout << "nhap lc: "; cin >> lc;
			menuDG(lc);
			break;
		}
			
		case 2:
			drawTable();
			break;
		case 3:
			break;
		case 4:
			//thoat chuong trinh
			exit(0);
			break;
		case 5: {
			clrscr();
			int lc;
			gotoxy(5, 10); cout << "kiem thu nhap xuat dau sach";
			cout << "nhap lc: "; cin >> lc;
			menu(lc, lds, dauS, dataDMS, ldms, pDS);
			break;
		}
			
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

void menuDG(int lc)
{
	switch (lc)
	{
	case 1: {
		MuonTra dataMT;
		ListMT lmt;
		theDocGia tDG;
		Tree t = NULL;
		int n;
		cout << "So luong doc gia: "; cin >> n;
		cin.ignore();
		for (int i = 0; i < n; i++) {
			cout << "Nhap vao Doc gia " + (i + 1) << endl;
			cout << "Ma the: "; cin >> tDG.maThe; cin.ignore();
			cout << "Ho: ";	getline(cin, tDG.ho);
			cout << "Ten: "; getline(cin, tDG.ten);
			cout << "Phai: "; getline(cin, tDG.phai);
			cout << "Trang thai: "; cin >> tDG.trangThai; cin.ignore();
			cout << "Cho doc gia muon sach?";
			//t = new NODE_TREE;
			//t->data.info = tDG;
			InsertDGtoTree(t, tDG);
			int YN; cin >> YN;
			if (YN == 1)
			{
				//initList_MT(lmt);
				//so luong sach
				int slSach = 0;
				cout << "Nhap vao so luong mt: "; cin >> slSach; cin.ignore();
				for (int j = 0; j < slSach; j++) {
					cout << "Ma sach: "; getline(cin, dataMT.maSach); cin.ignore();
					cout << "Ngay muon: ";  cin >> dataMT.ngayMuon.Ngay;
					cout << "Thang muon: ";  cin >> dataMT.ngayMuon.Thang;
					cout << "Nam muon: ";  cin >> dataMT.ngayMuon.Nam;
					cout << "Ngay tra: "; cin >> dataMT.ngayTra.Ngay;
					cout << "Thang tra: ";  cin >> dataMT.ngayTra.Thang;
					cout << "Nam tra: ";  cin >> dataMT.ngayTra.Nam;
					cout << "Trang thai: ";  cin >> dataMT.trangThai;
					AddHeadList_MT(t->data.listMT, dataMT);
				}
				//t->data.listMT.pHeadMT = lmt.pHeadMT;
			}
			//else if (YN == 2) {
				//lds.nodesDauSach[i]->dms.pHeadDMS = lds.nodesDauSach[i]->dms.pTailDMS = nullptr;
			//}
		}
		saveDG(t);

		break; }
	case 2: {
		MuonTra dataMT;
		ListMT lmt;
		theDocGia tDG;
		Tree t = NULL;
		loadDG(t);
		scanTreeDG(t);
		system("pause");
		break; }
	}
}
