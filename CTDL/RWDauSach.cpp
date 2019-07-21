#include "stdafx.h"
#include "RWDauSach.h"
void SaveFile(dauSach ds, int n) {
	FILE * f;
	if ((f = fopen("DauSach.txt", "wb")) == NULL)
	{
		cout<<("Loi mo file de ghi"); return;
	}
	for (int i = 0; i < n; i++)
		fwrite(ds.ISBN, sizeof(ds), 1, f);
	fclose(f);
	cout<<("Da ghi xong danh sach vao file");
}
void OpenFile(LIST_DauSach &lds1) {
	FILE * f;
	DauSach ds;
	if ((f = fopen("DauSach.txt", "rb")) == NULL)
	{
		cout<<("Loi mo file de doc"); return;
	}
	lds1.n = 0;
	while (fread(&ds, sizeof(DauSach), 1, f) != 0) {
		lds1.nodesDauSach[lds1.n] = new DauSach;
		// file ch? này nè
		lds1.nodesDauSach[lds1.n]->info = ds.info;
		lds1.n++;
	}
	delete[] lds1.nodesDauSach;
	fclose(f);
	cout<<("Da load xong danh sach vao bo nho");

}
void SaveDS(LIST_DauSach lds) {
	FILE * f;
	if ((f = fopen("DauSach.txt", "wb")) == NULL)
	{
		cout << ("Loi mo file de ghi"); return;
	}
	for (int i = 0; i < lds.n; i++)
		fwrite(lds.nodesDauSach[i], sizeof(DauSach) , 1, f);
	fclose(f);
	cout << ("Da ghi xong danh sach vao file");
}
void SaveFileDauSach(LIST_DauSach lds) {
	fstream outFile;
	outFile.open("DauSach.txt", ios::out | ios::binary);
	if (outFile.is_open())
	{
		outFile << lds.n + 1 << endl;
		for (int i = 0; i <= lds.n; i++)
		{
			outFile << lds.nodesDauSach[i]->info.tenSach << endl;
			outFile << lds.nodesDauSach[i]->info.ISBN << endl;
			outFile << lds.nodesDauSach[i]->info.tacGia << endl;
			outFile << lds.nodesDauSach[i]->info.theLoai << endl;
			outFile << lds.nodesDauSach[i]->info.soTrang << endl;
			outFile << lds.nodesDauSach[i]->info.namXuatBan << endl;

			outFile << lds.nodesDauSach[i]->dms.n << endl;
			for (NODE_DMS* p = lds.nodesDauSach[i]->dms.pHeadDMS; p != NULL; p = p->pNext)
			{
				outFile << p->data.maSach << endl;
				outFile << p->data.trangThai << endl;
				outFile << p->data.viTri << endl;
			}
		}
	}
	else
	{
		cout << "KET NOI VOI FILE DauSach THAT BAI! ";
	}
	outFile.close();
}
void OpenFileDauSach(LIST_DauSach &lds) {
	fstream inFile;
	dauSach info;
	inFile.open("DauSach.txt", ios::in);
	DauSach *pDS;
	DMS dms;
	int sodausach, sosach;
	if (inFile.is_open())
	{
		string temp;
		inFile >> sodausach;
		getline(inFile, temp);

		for (int i = 0; i < sodausach; i++)
		{
			pDS = new DauSach;
			if (pDS == NULL) continue;

			// load thong tin vao bien tam.

			getline(inFile, info.tenSach);
			getline(inFile, info.tacGia);
			getline(inFile, info.theLoai);
			inFile >> info.ISBN;
			inFile >> info.soTrang;
			inFile >> info.namXuatBan;

			// load thong tin vao dau sach
			pDS->info = info;

			inFile >> sosach;
			getline(inFile, temp);
			initList_DMS(pDS->dms);
			for (int j = 0; j < sosach; j++)
			{
				getline(inFile, dms.maSach);
				inFile >> dms.trangThai;
				getline(inFile, temp);
				getline(inFile, dms.viTri);
				AddTailList_DMS(pDS->dms, dms);
			}
			Insert_DauSach(lds, pDS);
		}
	}
	else {
		cout << "KET NOI VOI FILE DocGia THAT BAI! ";
	}

	inFile.close();
}


