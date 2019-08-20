#include "stdafx.h"
#include "XuLy.h"

void xuLy(LIST_DauSach &lds, Tree &t)
{
	string listMenu[4] = { " QUAN LY DOC GIA ",
		" QUAN LY DAU SACH ",
		" QUAN LY MUON TRA ",
		" THOAT " };
	string listMenuDG[3] = { " CAP NHAT DOC GIA ",
		" DANH SACH DOC GIA ",
		" DANH SACH DOC GIA MUON SACH QUA HAN "};
	string listMenuS[3] = { " MUON SACH ",
		" TRA SACH ",
		" TOP 10 SACH DUOC MUON NHIEU NHAT " };
	int flag = 0;
	int lc = 0;
	dauSach dauS;
	DMS dataDMS;
	LIST_DMS ldms;
	pDauSach pDS;

	theDocGia dg;
	MuonTra dataMT;
	ListMT lmt;
	NODE_TREE* temp;

	while (true) {
		clrscr();
		welcomeConsole();
		menuFeature(4, 52, 20, flag, listMenu);
		switch (flag)
		{
		case 0: {
			break;
		}
		case 1: {
			int flagDG = 0;
			setHighLightColor();
			gotoxy(93, 21); cout << ">>";
			drawCell(95, 96, 20, 30);
			drawCell(136, 137, 20, 30);
			setDefaultColor();
			menuFeature(3, 96, 20, flagDG, listMenuDG);
			
				switch (flagDG)
				{
				case 0: 
					break;
				
				case 1: 
					Menu_DocGia(t);
					break;

				case 2:
					InDocGia(t);
					break;
				case 3:
					DanhSachQuaHan(t, lds);
					break;
				}
		
			break;
		}
		case 2:
			menuDS(lds, pDS, t);
			break;

		case 3: {
			int flagS = 0;
			setHighLightColor();
			gotoxy(93, 29); cout << ">>";
			drawCell(95, 96, 24, 34);
			drawCell(136, 137, 24, 34);
			setDefaultColor();
			menuFeature(3, 96, 24, flagS, listMenuS);
			switch (flagS)
			{
			case 0:
				break;

			case 1:
				MuonSach(t, lds);
				break;

			case 2:
				TraSach(t, lds);
				break;

			case 3:
				Top10Sach(lds);
				break;
			}
			break;
		}
		case 4:
			SaveDS(lds);
			saveDG(t);
			exit(0);
			break;
		case 5:
			clrscr();
			cout << "kiem thu nhap xuat dau sach";
			cout << "nhap lc: "; cin >> lc; cin.ignore();
			menu(lc, lds, dauS, dataDMS, ldms, pDS);
			break;

		case 6:
			loadDG(t);
			InDocGia(t);
			break;
		case 7:
			OpenFile(lds);
			loadDG(t);
			DanhSachQuaHan(t, lds);
			break;
		case 8:
			OpenFile(lds);
			Top10Sach(lds);
			break;
		case 9:
			loadDG(t);
			OpenFile(lds);
			//drawTable(lDS, pDS);
			MuonSach(t, lds);
			system("pause");
			break;
		case 10:
			//thoat chuong trinh
			//drawTableDG(t);
			loadDG(t);
			Menu_DocGia(t);
			break;
		default:
			break;
		}
	}
}

void menu(int lc, LIST_DauSach &lds, dauSach dauS, DMS dataDMS, LIST_DMS ldms, pDauSach &pDS) {
	switch (lc)
	{
	case 1:
		cout << "So luong dau sach: "; cin >> lds.n; cin.ignore();
		for (int i = 0; i < lds.n; i++) {
			cout << "nhap vao Dau sach " << i + 1 << endl;
			cout << "ISBN: ";
			cin.getline(dauS.ISBN, 7);
			//gets();
			cout << "Nam XB: ";	cin >> dauS.namXuatBan; cin.ignore();
			cout << "so trang: "; cin >> dauS.soTrang; cin.ignore();
			cout << "tac gia: ";  cin.getline(dauS.tacGia, 21);
			cout << "ten sach: "; cin.getline(dauS.tenSach, 21);
			cout << "the loai: "; cin.getline(dauS.theLoai, 21);
			initList_DMS(ldms);
			cout << "Ban co muon nhap danh muc sach cho dau sach nay khong?";
			lds.nodesDauSach[i] = new DauSach;
			lds.nodesDauSach[i]->info = dauS;
			int YN; cin >> YN; cin.ignore();
			if (YN == 1)
			{
				//initList_DMS(ldms);
				//so luong sach
				int slSach = 0;
				cout << "Nhap vao so luong dms: "; cin >> slSach; cin.ignore();
				lds.nodesDauSach[i]->dms.n = slSach;
				for (int j = 0; j < slSach; j++) {
					cout << "Nhap vao thong tin sach: " << j + 1 << endl;
					cout << "Ma sach: ";  cin.getline(dataDMS.maSach, 10);
					cout << "Trang thai: "; cin >> dataDMS.trangThai; cin.ignore();
					cout << "Vi tri: ";  cin.getline(dataDMS.viTri, 21);
					AddTailList_DMS(ldms, dataDMS);
				}
				lds.nodesDauSach[i]->dms.pHeadDMS = ldms.pHeadDMS;
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
		OpenFile(lds1);
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

//void menuDG(int lc, MuonTra dataMT)
//{
//	switch (lc)
//	{
//	case 1:
//		int n;
//		cout << "So luong doc gia: "; cin >> n; cin.ignore();
//		for (int i = 0; i < n; i++) {
//			cout << "Nhap vao Doc gia " << i + 1 << endl;
//			cout << "Ma the: "; cin >> t.maThe; cin.ignore();
//			cout << "Ho: ";	cin.getline(t.ho, 11);
//			cout << "Ten: "; cin.getline(t.ten, 11);
//			cout << "Phai: "; cin.getline(t.phai, 4);
//			cout << "Trang thai: "; cin >> t.trangThai; cin.ignore();
//			InsertDGtoTree(t, t);
//			temp = Find_DG(t, t.maThe);
//			cout << "Cho doc gia muon sach?";
//			int YN;
//			std::cin >> YN;
//			std::cin.ignore();
//			if (YN == 1)
//			{
//				int slSach = 0;
//				cout << "Nhap vao so luong mt: "; cin >> slSach; cin.ignore();
//				//t->data.listMT.n = slSach;
//				//ListMT lmt;
//				//initList_MT(temp->data.listMT);
//				for (int j = 0; j < slSach; j++) {
//					cout << "Ma sach: "; cin.getline(dataMT.maSach, 11);
//					cout << "Ngay muon: ";  cin >> dataMT.ngayMuon.Ngay; cin.ignore();
//					cout << "Thang muon: ";  cin >> dataMT.ngayMuon.Thang; cin.ignore();
//					cout << "Nam muon: ";  cin >> dataMT.ngayMuon.Nam; cin.ignore();
//					cout << "Ngay tra: "; cin >> dataMT.ngayTra.Ngay; cin.ignore();
//					cout << "Thang tra: ";  cin >> dataMT.ngayTra.Thang; cin.ignore();
//					cout << "Nam tra: ";  cin >> dataMT.ngayTra.Nam; cin.ignore();
//					cout << "Trang thai: ";  cin >> dataMT.trangThai; cin.ignore();
//					AddHeadList_MT(temp->data.listMT, dataMT);
//				}
//			}
//		}
//		saveDG(t);
//		break;
//	case 2:
//		/*loadDG(t);
//		scanTreeDG(t);
//		system("pause");*/
//		break;
//	}
//}
