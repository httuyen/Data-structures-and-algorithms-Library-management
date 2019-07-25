#include "stdafx.h"
#include "RWDocGia.h"
using namespace std;

void save(Tree t, FILE *f)
{
	fwrite(&t->data.info, sizeof(TheDocGia), 1, f);
	for (NODE_MT *p = t->data.listMT.pHeadMT ; p != nullptr; p = p->pNext) {
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