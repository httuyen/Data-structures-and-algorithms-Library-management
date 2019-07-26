#include "stdafx.h"
#include "RWDauSach.h"
using namespace std;

//void OpenFile(LIST_DauSach &lds) {
//	FILE * f;
//	DauSach ds;
//	DMS dataDMS;
//	//pDauSach pDS;
//	if ((f = fopen("DauSach.txt", "rb")) == NULL)
//	{
//		cout << ("Loi mo file de doc"); return;
//	}
//	lds.n = 0;
//	while (fread(&ds, sizeof(DauSach), 1, f) != 0) {
//		//pDS = new DauSach;
//		lds.nodesDauSach[lds.n] = new DauSach;
//		*lds.nodesDauSach[lds.n] = ds;
//		//pDS->info = ds.info;
//		if (lds.nodesDauSach[lds.n]->dms.n < 0) {
//			lds.nodesDauSach[lds.n]->dms.pHeadDMS = lds.nodesDauSach[lds.n]->dms.pTailDMS = nullptr;
//		}
//		else {
//			int i = 0;
//			initList_DMS(lds.nodesDauSach[lds.n]->dms);
//			while (fread(&dataDMS, sizeof(DMS), 1, f) != 0) {
//				AddTailList_DMS(lds.nodesDauSach[lds.n]->dms, dataDMS);
//				i++;
//				if (lds.nodesDauSach[lds.n]->dms.n == i) break;
//			}
//		}	
//		lds.n++;
//	}
//	fclose(f);
//	cout<<("Da load xong danh sach vao bo nho");
//}
void OpenFile(LIST_DauSach &lds, pDauSach &pDS) {
	FILE * f;
	DauSach ds;
	DMS dataDMS;
	if ((f = fopen("DauSach.txt", "rb")) == NULL)
	{
		cout << ("Loi mo file de doc"); return;
	}
	lds.n = 0;
	while (fread(&ds, sizeof(DauSach), 1, f) != 0) {
		pDS = new DauSach;
		pDS->info = ds.info;
		pDS->dms.n = ds.dms.n;
		initList_DMS(pDS->dms);
		if (ds.dms.n < 0) {
			//lds.nodesDauSach[lds.n]->dms.pHeadDMS = lds.nodesDauSach[lds.n]->dms.pTailDMS = nullptr;
			pDS->dms.pHeadDMS = pDS->dms.pTailDMS = nullptr;
		}
		else {
			initList_DMS(pDS->dms);
			while (fread(&dataDMS, sizeof(DMS), 1, f) != 0) {
				AddTailList_DMS(pDS->dms, dataDMS);
				if (pDS->dms.n == ds.dms.n) break; //co ve khong can dong code nay
			}
		}
		Insert_DauSach(lds, pDS);
	}
	fclose(f);
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



