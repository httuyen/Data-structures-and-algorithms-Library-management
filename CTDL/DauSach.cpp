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
	if (l.pHeadMT == NULL) {
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
		for (int j = 0; j <= temp; j++) {
			if (lds.nodesDauSach[i]->info.theLoai == listTL[j]) {
				break;
			}
			else if (j == temp) {
				listTL[temp] = lds.nodesDauSach[i]->info.theLoai;
				temp++;
				break;
			}
		}
	}
}



NODE_TREE* GetNode_DG(theDocGia dg)
{
	NODE_TREE *p = new NODE_TREE;
	if (p == NULL) {
		return NULL;
	}
	// khoi tao danh muc sach trong node doc gia
	initList_MT(p->data.listMT);
	p->data.info = dg;
	p->pLeft = p->pRight = NULL;
	return (p);
}

void InsertDGtoTree(Tree &t, theDocGia dg)
{
	if (t == NULL) {
		t = GetNode_DG(dg);
		//++nDG;
	}
	else if (t->data.info.maThe > dg.maThe)
	{
		InsertDGtoTree(t->pLeft, dg);
	}
	else if (t->data.info.maThe < dg.maThe)
	{
		InsertDGtoTree(t->pRight, dg);
	}
}

void initTREE_DG(Tree &t)
{
	//nDG = 0;
	t = NULL;
}

NODE_TREE* Find_DG(Tree t, int maThe)
{
	while (t != NULL && t->data.info.maThe != maThe)
	{
		if (maThe < t->data.info.maThe)
		{
			t = t->pLeft;
		}
		else t = t->pRight;
	}
	return (t);
}

int countDG(Tree t)
{
	int c = 1;             // ban than node duoc dem la 1;
	if (t == NULL)
		return 0;
	else
	{
		c += countDG(t->pLeft);
		c += countDG(t->pRight);
		return c;
	}
}

void scanTreeDG(Tree t)
{ 
	if (t != NULL)
	{
		cout << countDG(t);
		cout << "Ho: " << t->data.info.ho << endl;
		int nMT = t->data.listMT.n;
		cout << nMT;
		if (nMT > 0) {
			for (NODE_MT *p = t->data.listMT.pHeadMT; p != NULL; p = p->pNext) {
				cout << "Ma sach: " << p->data.maSach << endl;
			}
		}
		scanTreeDG(t->pLeft);
		scanTreeDG(t->pRight);
	}
}

unsigned Random()
{
	srand((unsigned)time(0));
	int x;
	// bo ham rand() vao vong lap moi khong bi loi tang dan, hay giam dan.
	for (int i = 0; i < 500; i++)
	{
		x = rand();
	}
	return x;
}

unsigned Random_MaThe(Tree t)
{
	unsigned temp;
	do
	{
		temp = Random();
	} while (Check_MaThe(t, temp));  // check trung , neu trung thi random lai
	return temp;
}

bool Check_MaThe(Tree t, unsigned maThe)
{
	if (t == NULL) {
		return false;
	}
	else if (t->data.info.maThe == maThe)
	{
		return true;
	}
	else if (maThe < t->data.info.maThe)
	{
		return Check_MaThe(t->pLeft, maThe);
	}
	else
	{
		return Check_MaThe(t->pRight, maThe);
	}
}

void Update_DG(Tree &t, theDocGia &dg, bool isEdited)
{
	int ordinal = 0;
	bool isSave = false;
	bool isEscape = false;

	string ho = "";
	string ten = "";
	string phai = "";
	int ttthe = 3;
	int maThe;

	if (isEdited)
	{
		ho = dg.ho;
		ten = dg.ten;
		phai = dg.phai;
		ttthe = dg.trangThai;
		maThe = dg.maThe;
		//gotoxy((xDisplayDG[5] + 7 + nngang / 2), yDisplay + 3);
		cout << maThe << endl;
		//gotoxy((xDisplayDG[5] + 7 + nngang / 2), yDisplay + 5);
		cout << ho << endl;
		//gotoxy((xDisplayDG[5] + 7 + nngang / 2), yDisplay + 7);
		cout << ten << endl;
		//gotoxy((xDisplayDG[5] + 7 + nngang / 2), yDisplay + 9);
		cout << phai << endl;
		//gotoxy((xDisplayDG[5] + 7 + nngang / 2), yDisplay + 11);
		(ttthe == 0) ? cout << ttthe << ":  KHOA" : cout << ttthe << ":  HOAT DONG";
	}

	if (!isEdited)
	{
		//gotoxy((xDisplayDG[5] + 7 + nngang / 2), yDisplay + 3);
		maThe = Random_MaThe(t);
		cout << maThe;
	}

	while (true) {
		cout << "Ho: "; getline(cin, ho);
		cout << "Ten: "; getline(cin, ten);
		cout << "Phai: "; getline(cin, phai);
		cout << "Trang thai the: "; cin >> ttthe; cin.ignore();
		

	}

}