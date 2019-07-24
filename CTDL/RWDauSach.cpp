#include "stdafx.h"
#include "RWDauSach.h"
using namespace std;

void OpenFile(LIST_DauSach &lds1) {
	FILE * f;
	DauSach ds;
	LIST_DMS ldms;
	DMS dataDMS;
	if ((f = fopen("DauSach.txt", "rb")) == NULL)
	{
		cout << ("Loi mo file de doc"); return;
	}
	lds1.n = 0;
	while (fread(&ds, sizeof(DauSach), 1, f) != 0) {
		lds1.nodesDauSach[lds1.n] = new DauSach;
		*lds1.nodesDauSach[lds1.n] = ds;
		if (lds1.nodesDauSach[lds1.n]->dms.n < 0) {
			lds1.nodesDauSach[lds1.n]->dms.pHeadDMS = lds1.nodesDauSach[lds1.n]->dms.pTailDMS = nullptr;
		}
		else {
			initList_DMS(ldms);
			int i = 0;
			while (fread(&dataDMS, sizeof(DMS), 1, f) != 0) {
				AddTailList_DMS(ldms, dataDMS);
				i++;
				if (lds1.nodesDauSach[lds1.n]->dms.n == i) break;
			}
		}
		lds1.nodesDauSach[lds1.n]->dms.pHeadDMS = ldms.pHeadDMS;
		lds1.n++;
	}
	fclose(f);
	cout<<("Da load xong danh sach vao bo nho");
}

void SaveDS(LIST_DauSach lds) {
	FILE * f;
	if ((f = fopen("DauSach.txt", "wb")) == NULL)
	{
		cout << ("Loi mo file de ghi"); return;
	}
	for (int i = 0; i < lds.n; i++){
		fwrite(lds.nodesDauSach[i], sizeof(DauSach), 1, f);
		for (NODE_DMS *p = lds.nodesDauSach[i]->dms.pHeadDMS; p != nullptr; p = p->pNext) {
			fwrite(p, sizeof(DMS), 1, f);
		}
	}
	fclose(f);
	cout << ("Da ghi xong danh sach vao file");
}



