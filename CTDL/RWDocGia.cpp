#include "stdafx.h"
#include "RWDocGia.h"
using namespace std;

void save(Tree t, FILE *f)
{
	fwrite(&t->data.info, sizeof(TheDocGia), 1, f);
	for (NODE_MT *p = t->data.listMT.pHeadMT; p != NULL; p = p->pNext) {
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
	NODE_TREE* pDG = nullptr;
	TheDocGia dg;
	MuonTra mt;
	if ((f = fopen("DocGia.txt", "rb")) == NULL)
	{
		cout << ("Loi mo file de doc"); return;
	}
	//lds.n = 0;
	while (fread(&dg, sizeof(TheDocGia), 1, f) != 0) {
		InsertDGtoTree(t, dg.info);
		pDG = Find_DG(t, dg.info.maThe);
		if (dg.listMT.n <= 0) {
			pDG->data.listMT.pHeadMT = pDG->data.listMT.pHeadMT = nullptr;
		}
		else {
			while (fread(&mt, sizeof(MuonTra), 1, f) != 0) {
				AddHeadList_MT(pDG->data.listMT, mt);
				if (pDG->data.listMT.n == dg.listMT.n) break;
			}
		}
	}
	fclose(f);
}