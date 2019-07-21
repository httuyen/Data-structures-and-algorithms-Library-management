#include "stdafx.h"
#include "DauSach.h"
#include "RWDauSach.h"
#include "welcome.h"
#include "mylib.h"
using namespace std;


void menu(int lc, LIST_DauSach &lds, dauSach dauS);
int main() {
	welcomeConsole();
	menuFeature(4, 52, 20);
	dauSach dauS;
	LIST_DauSach lds;
	int lc = 0;
	while (true) {
		SetColor(YELLOW);
		/*gotoxy(5, 10);cout << "kiem thu nhap xuat dau sach";
		cout << "nhap lc: "; cin >> lc;*/
		menu(lc, lds, dauS);
	}
	system("pause");
	return 0;
}
void menu(int lc, LIST_DauSach &lds, dauSach dauS) {
	switch (lc)
	{
	case 1:
		cout << "So luong dau sach: "; cin >> lds.n;
		cin.ignore();
		for (int i = 0; i < lds.n; i++) {

			cout << "ISBN: ";
			gets_s(dauS.ISBN);
			cout << "Nam XB: ";	cin >> dauS.namXuatBan;
			cout << "so trang: "; cin >> dauS.soTrang;
			cout << "tac gia: "; cin.ignore(); getline(cin, dauS.tacGia);
			cout << "ten sach: "; getline(cin, dauS.tenSach);
			cout << "the loai: "; getline(cin, dauS.theLoai);

			lds.nodesDauSach[i] = new DauSach;
			lds.nodesDauSach[i]->info = dauS;
			lds.nodesDauSach[i]->dms.pHeadDMS = lds.nodesDauSach[i]->dms.pHeadDMS = nullptr;
			//cout << "/////////////////////////////////////////////////////////////\n";
			//cout << puts(dauS.ISBN);
			//cout << dauS.namXuatBan << endl;
			//cout << dauS.soTrang << endl;
			//cout << dauS.tacGia << endl;
			//cout << dauS.tenSach << endl;
			//cout << dauS.theLoai << endl;
		}
		SaveDS(lds);
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
