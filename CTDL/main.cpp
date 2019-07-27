#include "stdafx.h"
#include "DauSach.h"
#include "RWDauSach.h"
#include "RWDocGia.h"
#include "welcome.h"
#include "mylib.h"
#include "xuLyDS.h"
#include "constant.h"
using namespace std;

std::string listMenu[4] = { "QUAN LY DOC GIA",
"QUAN LY DAU SACH",
"QUAN LY SACH",
"THOAT" };


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
			cout << "nhap lc: "; cin >> lc; cin.ignore();
			menuDG(lc);
			break;
		}
			
		case 2:
			
			drawTable(lds,pDS);
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
			cout << "kiem thu nhap xuat dau sach";
			cout << "nhap lc: "; cin >> lc; cin.ignore();
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
		cout << "So luong dau sach: "; cin >> lds.n; cin.ignore();
		for (int i = 0; i < lds.n; i++) {
			cout << "nhap vao Dau sach "<<i+1<<endl;
			cout << "ISBN: ";
			cin.getline(dauS.ISBN, 7); cin.ignore();
			//gets();
			cout << "Nam XB: ";	cin >> dauS.namXuatBan; cin.ignore();
			cout << "so trang: "; cin >> dauS.soTrang; cin.ignore();
			cout << "tac gia: ";  cin.getline(dauS.tacGia,21);
			cout << "ten sach: "; cin.getline( dauS.tenSach,21);
			cout << "the loai: "; cin.getline( dauS.theLoai,21);
			cout << "Ban co muon nhap danh muc sach cho dau sach nay khong?";
			lds.nodesDauSach[i] = new DauSach;
			lds.nodesDauSach[i]->info = dauS;
			int YN; cin >> YN; cin.ignore();
			if (YN == 1)
			{
				initList_DMS(ldms);
				//so luong sach
				int slSach = 0;
				cout << "Nhap vao so luong dms: "; cin >> slSach; cin.ignore();
				lds.nodesDauSach[i]->dms.n = slSach;
				for (int j = 0; j < slSach; j++) {
					cout << "Nhap vao thong tin sach: "<< j+1 <<endl;
					cout << "Ma sach: ";  cin.getline(dataDMS.maSach,10);
					cout << "Trang thai: "; cin >> dataDMS.trangThai; cin.ignore();
					cout << "Vi tri: ";  cin.getline(dataDMS.viTri,21);
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
			cout << lds1.nodesDauSach[i]->info.ISBN << endl;
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
			cout << endl;
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
		NODE_TREE* temp;
		MuonTra dataMT;
		//ListMT lmt;
		theDocGia tDG;
		Tree t = NULL;
		int n;
		cout << "So luong doc gia: "; cin >> n; cin.ignore();		
		for (int i = 0; i < n; i++) {
			cout << "Nhap vao Doc gia "<<i+1 << endl;
			cout << "Ma the: "; cin >> tDG.maThe; cin.ignore();
			cout << "Ho: ";	cin.getline(tDG.ho,11);
			cout << "Ten: "; cin.getline(tDG.ten,11);
			cout << "Phai: "; cin.getline(tDG.phai,4);
			cout << "Trang thai: "; cin >> tDG.trangThai; cin.ignore();
			InsertDGtoTree(t, tDG);
			temp = Find_DG(t, tDG.maThe);
			cout << "Cho doc gia muon sach?";
			int YN; cin >> YN; cin.ignore();
			if (YN == 1)
			{
				int slSach = 0;
				cout << "Nhap vao so luong mt: "; cin >> slSach; cin.ignore();
				//t->data.listMT.n = slSach;
				//ListMT lmt;
				//initList_MT(temp->data.listMT);
				for (int j = 0; j < slSach; j++) {
					cout << "Ma sach: "; cin.getline(dataMT.maSach,11);
					cout << "Ngay muon: ";  cin >> dataMT.ngayMuon.Ngay; cin.ignore();
					cout << "Thang muon: ";  cin >> dataMT.ngayMuon.Thang; cin.ignore();
					cout << "Nam muon: ";  cin >> dataMT.ngayMuon.Nam; cin.ignore();
					cout << "Ngay tra: "; cin >> dataMT.ngayTra.Ngay; cin.ignore();
					cout << "Thang tra: ";  cin >> dataMT.ngayTra.Thang; cin.ignore();
					cout << "Nam tra: ";  cin >> dataMT.ngayTra.Nam; cin.ignore();
					cout << "Trang thai: ";  cin >> dataMT.trangThai; cin.ignore();
					AddHeadList_MT(temp->data.listMT, dataMT); 				
				}
				//t->data.listMT.pHeadMT = lmt.pHeadMT;
			}
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
