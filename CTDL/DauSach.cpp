#include "stdafx.h"
#include "DauSach.h"

void initList_DMS(LIST_DMS &l)
{
	l.n = 0;
	l.pHeadDMS = l.pTailDMS = NULL;
}
void AddTailList_DMS(LIST_DMS &l, DMS data)
{
	// tao Node
	NODE_DMS *p = GetNode_DMS(data);
	if (l.pHeadDMS == NULL) {
		l.pHeadDMS = l.pTailDMS = p;
	}
	else
	{
		l.pTailDMS->pNext = p;
		l.pTailDMS = p;
	}
	l.n++;
}
int Insert_DauSach(LIST_DauSach &l, DauSach* &pDS)
{
	if (Full_DauSach(l))
	{
		return 0;
	}
	l.nodesDauSach[++l.n] = pDS;
	return 1;
}
NODE_DMS* GetNode_DMS(DMS DATA)
{
	NODE_DMS *p = new NODE_DMS;
	if (p == NULL) {
		return NULL;
	}
	p->data = DATA;
	p->pNext = NULL;
	return (p);
}
int Full_DauSach(LIST_DauSach  l)
{
	return l.n == MAX_DAUSACH;
}
void initDS(dauSach &ds) {
	ds.ISBN[6] = {};
	ds.namXuatBan = NULL;
	ds.soTrang = NULL;
	ds.tacGia = "";
	ds.tenSach = "";
	ds.theLoai = "";
}

