#include "stdafx.h"
#include "RWDocGia.h"
using namespace std;

void save(Tree t, FILE *f)
{
	fwrite(&t->data.info, sizeof(TheDocGia), 1, f);
	for (NODE_MT *p = t->data.listMT.pHeadMT; p != nullptr; p = p->pNext) {
		fwrite(p, sizeof(MuonTra), 1, f);
	}
}

void writeFileDG(Tree t, FILE *f)
{
	if (t != NULL)
	{
		save(t, f);
		writeFileDG(t->pLeft, f);
		writeFileDG(t->pRight, f);
	}
}

void saveDG(Tree t)
{
	FILE * f;
	if ((f = fopen("DocGia.txt", "wb")) == NULL)
	{
		cout << ("Loi mo file de ghi"); return;
	}
	writeFileDG(t, f);
	fclose(f);
	cout << ("Da ghi xong danh sach vao file");
}

void loadDG(Tree &t)
{
	initTREE_DG(t);
	FILE * f;
	NODE_TREE* pDG = NULL;
	theDocGia dg;
	MuonTra mt;
	if ((f = fopen("DocGia.txt", "rb")) == NULL)
	{
		cout << ("Loi mo file de doc"); return;
	}
	//lds.n = 0;
	while (fread(&dg, sizeof(theDocGia), 1, f) != 0) {
		InsertDGtoTree(t, dg);
		pDG = Find_DG(t, dg.maThe);
		while (fread(&mt, sizeof(MuonTra), 1, f) != 0) {
			AddHeadList_MT(pDG->data.listMT, mt);
			//if (pDS->dms.n == ds.dms.n) break;
		}

	}
	fclose(f);
}