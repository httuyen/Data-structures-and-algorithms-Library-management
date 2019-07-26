#include "stdafx.h"
#include "DauSach.h"

void initList_DMS(LIST_DMS &l)
{
	l.n = 0;
	l.pHeadDMS = l.pTailDMS = nullptr;
}
void AddTailList_DMS(LIST_DMS &l, DMS data)
{
	// tao Node
	NODE_DMS *p = GetNode_DMS(data);
	if (l.pHeadDMS == nullptr) {
		l.pHeadDMS = l.pTailDMS = p;
	}
	else
	{
		l.pTailDMS->pNext = p;
		l.pTailDMS = p;
	}
	l.n++;
}

NODE_DMS* GetNode_DMS(DMS DATA)
{
	NODE_DMS *p = new NODE_DMS;
	if (p == nullptr) {
		return nullptr;
	}
	p->data = DATA;
	p->pNext = nullptr;
	return (p);
}

void initList_MT(ListMT &l)
{
	l.n = 0;
	l.pHeadMT = l.pTailMT = NULL;
}

void AddTailList_MT(ListMT &l, MuonTra data)
{
	NODE_MT *p = GetNode_MT(data);
	if (l.pHeadMT == nullptr) {
		l.pHeadMT = l.pTailMT = p;
	}
	else {
		l.pTailMT->pNext = p;
		p->pPrev = l.pTailMT;
		l.pTailMT = p;
	}
	l.n++;
}

void AddHeadList_MT(ListMT &l, MuonTra data)
{
	NODE_MT *p = GetNode_MT(data);
	if (l.pHeadMT == NULL) {
		l.pHeadMT = l.pTailMT = p;
	}
	else
	{
		p->pNext = l.pHeadMT;
		l.pHeadMT->pPrev = p;
		l.pHeadMT = p;
	}
	++l.n;
}

NODE_MT* GetNode_MT(MuonTra data)
{
	NODE_MT *p = new NODE_MT;
	if (p == nullptr) {
		return nullptr;
	}
	p->data = data;
	p->pNext = p->pPrev = nullptr;
	return (p);
}

int Full_DauSach(LIST_DauSach  l)
{
	return l.n == MAX_DAUSACH;
}

void initListDS(LIST_DauSach &lds) {
	
	lds.n = 0;
	initList_DMS(lds.nodesDauSach[0]->dms);
	lds.nodesDauSach[0]->dms.pHeadDMS = lds.nodesDauSach[0]->dms.pTailDMS = nullptr;
}
pDauSach searchTen_DS(LIST_DauSach lds, string theLoai){
	pDauSach temp = NULL;
	for (int i = 0; i <= lds.n; i++)
	{
		temp = lds.nodesDauSach[i];
		if (temp->info.tenSach == theLoai)
			return temp;
	}
	return NULL;
}
int Insert_DauSach(LIST_DauSach &lds, pDauSach &pDS)
{
	if (Full_DauSach(lds))
	{
		return 0;
	}
	lds.nodesDauSach[lds.n++] = pDS;
	return 1;
}
void getTheLoai(LIST_DauSach lds, string listTL[]) {
	int temp = 0;
	for (int i = 0; i < lds.n; i++) {
		for (int j = 0;j<=temp; j++) {
			if (lds.nodesDauSach[i]->info.theLoai == listTL[j]) {
				break;
			}
			else if(j==temp) {
				listTL[temp] = lds.nodesDauSach[i]->info.theLoai;
				temp++;
				break;
			}
		}
	}

}