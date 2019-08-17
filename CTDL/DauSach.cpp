#include "stdafx.h"
#include "DauSach.h"
#include "Check_Input.h"
#include "TempDG.h"

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

NODE_DMS* Search_DMS_Pos(NODE_DMS* dms, int pos)
{
	int count = -1;

	for (NODE_DMS* temp = dms; temp != NULL; temp = temp->pNext)
	{
		count++;
		if (pos == count)
		{
			return temp;
		}
	}
	return NULL;
}

NODE_DMS* getSachByMS(LIST_DauSach lDS, char* maSach)
{
	pDauSach temp = NULL;
	int i = 0;
	string maDS;

	while (maSach[i] != '_' && i < strlen(maSach))
	{
		maDS += maSach[i++];
	}

	for (int i = 0; i < lDS.n; i++)
	{
		temp = lDS.nodesDauSach[i];
		if (temp->info.ISBN == maDS);
		break;
	}

	for (NODE_DMS* p = temp->dms.pHeadDMS; p != NULL; p = p->pNext)
	{
		if ((string)p->data.maSach == maSach)
			return p;
	}
	return nullptr;
}

DauSach* getSachByName(LIST_DauSach lDS, char* tenSach)
{
	pDauSach temp = NULL;
	for (int i = 0; i <= lDS.n; i++)
	{
		temp = lDS.nodesDauSach[i];
		if ((string)temp->info.tenSach == (string)tenSach)
			return temp;
	}
	return NULL;
}

char* getViTri(LIST_DauSach lDS, char* maSach)
{
	pDauSach temp = NULL;
	int i = 0;
	string maDS;

	while (maSach[i] != '_' && i < strlen(maSach))
	{
		maDS += maSach[i++];
	}

	for (int i = 0; i < lDS.n; i++)
	{
		temp = lDS.nodesDauSach[i];
		if (temp->info.ISBN == maDS);
			break;
	}

	for (NODE_DMS* p = temp->dms.pHeadDMS ; p != NULL; p = p->pNext)
	{
		if ((string)p->data.maSach == maSach)
			return p->data.viTri;
	}
	return NULL;
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
		cout << countDG(t)<<endl;
		cout << "Ma the: " << t->data.info.maThe << endl;
		int nMT = t->data.listMT.n;
		cout <<"so luong sach mt:"<< nMT<<endl;
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
	hienConTro();
	int ordinal = 0;
	bool isSave = false;
	bool isEscape = false;

	string ho = "";
	string ten = "";
	string phai = "3";
	int ttthe = 3;
	int maThe;

	if (isEdited)
	{
		ho = dg.ho;
		ten = dg.ten;
		phai = dg.phai;
		ttthe = dg.trangThai;
		maThe = dg.maThe;
		gotoxy(xEDIT_DG + 17, yEDIT_DG + 2);
		cout << maThe << endl;
		gotoxy(xEDIT_DG + 17, yEDIT_DG + 5);
		cout << ho << endl;
		gotoxy(xEDIT_DG + 17, yEDIT_DG + 8);
		cout << ten << endl;
		gotoxy(xEDIT_DG + 17, yEDIT_DG + 11);
		(phai == "NU") ? cout << "0" << ":  NU" : cout << "1" << ":  NAM";
		gotoxy(xEDIT_DG + 17, yEDIT_DG + 14);
		(ttthe == 0) ? cout << ttthe << ":  KHOA" : cout << ttthe << ":  HOAT DONG";
	}

	if (!isEdited)
	{
		gotoxy(xEDIT_DG + 17, yEDIT_DG + 2);
		maThe = Random_MaThe(t);
		cout << maThe;
	}

	while (true) {
		switch (ordinal)
		{
			case 0: {
				gotoxy(xEDIT_DG + 17, yEDIT_DG + 5);
				Input(INPUT_HO, ho, ordinal, isSave, isEscape);
				break; 
			}
			case 1: {
				gotoxy(xEDIT_DG + 17, yEDIT_DG + 8);
				Input(INPUT_TEN, ten, ordinal, isSave, isEscape);
				break;
			}
			case 2: {
				gotoxy(xEDIT_DG + 17, yEDIT_DG + 11);
				Input(INPUT_PHAI, phai, ordinal, isSave, isEscape);
				break;
			}
			case 3: {
				gotoxy(xEDIT_DG + 17, yEDIT_DG + 14);
				Input(INPUT_TT, ttthe, ordinal, isSave, isEscape);
				break;
			}
		}

		if(isSave)
		{
			// cap nhat lai flag
			isSave = false;

			// check rong;
			if (ho.length() == 0)
			{
				gotoxy(xNOTI_DG + 2, yNOTI_DG + 2);
				cout << "(X) HO KHONG DUOC DE TRONG !!! ";

				// quay lai va dien vao truong du lieu do
				ordinal = 0;
				continue;
			}
			else if (ten.length() == 0)
			{
				gotoxy(xNOTI_DG + 2, yNOTI_DG + 2);
				cout << "(X) TEN KHONG DUOC DE TRONG !!! ";

				// quay lai va dien vao truong du lieu do
				ordinal = 1;
				continue;
			}
			else if (phai == "3")
			{
				gotoxy(xNOTI_DG + 2, yNOTI_DG + 2);
				cout << "(X) PHAI KHONG DUOC DE TRONG !!! ";

				// quay lai va dien vao truong du lieu do
				ordinal = 2;
				continue;
			}
			else if (ttthe == 3)
			{
				gotoxy(xNOTI_DG + 2, yNOTI_DG + 2);
				cout << "(X) T.THAI THE KHONG DUOC DE TRONG !!! ";
				
				ordinal = 3;
				continue;
			}
			dg.maThe = maThe;
			//dg.ho = toCharArray(ChuanHoaString(strHo));
			std::strncpy(dg.ho, toCharArray(ChuanHoaString(ho)), sizeof(theDocGia::ho));
			//dg.ten = ChuanHoaString(ten);
			std::strncpy(dg.ten, toCharArray(ChuanHoaString(ten)), sizeof(theDocGia::ten));
			//dg.phai = phai;
			std::strncpy(dg.phai, toCharArray(ChuanHoaString(phai)), sizeof(theDocGia::phai));
			dg.trangThai = ttthe;

			if (isEdited)
			{
				NODE_TREE* p;
				// ma doc gia khong doi
				p = Find_DG(t, maThe);
				p->data.info = dg;
			}
			else
			{
				InsertDGtoTree(t, dg);
			}

			// In dong thong bao .
			anConTro();
			gotoxy(xNOTI_DG + 2, yNOTI_DG + 2);
			cout << "          LUU THANH CONG !!! " <<endl;
			Sleep(800);
			return;
		}

		if (isEscape) return;
	}
}

NODE_TREE* FindMin(Tree t)
{
	while (t->pLeft != NULL) t = t->pLeft;
	return (t);
}

bool IsDeleted_DG(Tree &t, theDocGia dg)
{
	if (t == NULL)
		return false;
	else
	{
		if (dg.maThe > t->data.info.maThe)
			return IsDeleted_DG(t->pRight, dg);
		else if (dg.maThe < t->data.info.maThe)
			return IsDeleted_DG(t->pLeft, dg);
		else // Wohoo... I found you, Get ready to be deleted
		{
			//case 1: No child
			if (t->pLeft == NULL && t->pRight == NULL)
			{
				delete t; // dangling pointer
				t = NULL;
				//nDG--;
			}
			else if (t->pLeft == NULL)// case 2: One child
			{
				NODE_TREE* temp = t;
				t = t->pRight;
				delete temp;
				//nDG--;
			}
			else if (t->pRight == NULL)
			{
				NODE_TREE* temp = t;
				t = t->pLeft;
				delete temp;
				//nDG--;
			}// Case 3: 2 children
			else {
				NODE_TREE* temp = FindMin(t->pRight);

				// copy du lieu vao .
				t->data.info = temp->data.info;
				t->data.listMT = temp->data.listMT;
				return IsDeleted_DG(t->pRight, temp->data.info);
			}
			return true;
		}
	}
}


// so sach doc gia dang muon hoac lam mat
int SoSachDangMuon(ListMT lMT)
{
	int i = 0;
	for (NODE_MT * p = lMT.pHeadMT; p != NULL; p = p->pNext)
	{
		if (p->data.trangThai == 0 || p->data.trangThai == 2)
		{
			i++;
		}
	}
	return i;
}

bool SearchISBN_DS(LIST_DauSach lds, string ISBN)
{
	for (int i = 0; i <= lds.n; i++)
	{
		if (lds.nodesDauSach[i]->info.ISBN == ISBN)
			return true;
	}
	return false;
}

LIST_DauSach getDSByTL(LIST_DauSach &lds, string theLoai) {
	LIST_DauSach ldsTemp;
	ldsTemp.n = 0;
	for (int i = 0; i < lds.n; i++) {
		if (lds.nodesDauSach[i]->info.theLoai == theLoai) {
			ldsTemp.nodesDauSach[ldsTemp.n] = lds.nodesDauSach[i];
			ldsTemp.n++;
		}
	}
	return ldsTemp;
}
void QuicKsortTS(LIST_DauSach &lds, int left, int right) {
	//ldsTemp.nodesDauSach[1]
	dauSach key =  lds.nodesDauSach[(left + right) / 2]->info;
	dauSach tempDS;
	pDauSach pDSTemp = nullptr;
	
	int i = left, j = right;
	do {
		while (lds.nodesDauSach[i]->info.tenSach < key.tenSach)
			i++;
		while (lds.nodesDauSach[j]->info.tenSach > key.tenSach)
			j--;
		if (i <= j) {
			if (i < j) {
				SwapNodeDS(lds.nodesDauSach[i], lds.nodesDauSach[j]);
				/*tempDS = lds.nodesDauSach[i]->info;
				lds.nodesDauSach[i]->info = lds.nodesDauSach[j]->info;
				lds.nodesDauSach[j]->info = tempDS;

				pDSTemp->dms= lds.nodesDauSach[i]->dms;
				//pDSTemp->dms.pHeadDMS = lds.nodesDauSach[i]->dms.pHeadDMS;
				//pDSTemp->dms.pTailDMS = lds.nodesDauSach[i]->dms.pTailDMS;
				lds.nodesDauSach[i]->dms = lds.nodesDauSach[j]->dms;
				lds.nodesDauSach[j]->dms = pDSTemp->dms;*/
			}
			i++;
			j--;
		}
	} while (i <= j);
	if (left < j) QuicKsortTS(lds, left, j);
	if (right > i) QuicKsortTS(lds, i, right);
	delete[] pDSTemp;
}
void testDS(LIST_DauSach &lds, string theLoai) {
	LIST_DauSach ldsTemp = getDSByTL(lds, theLoai);
	QuicKsortTS(ldsTemp, 0, ldsTemp.n - 1);
}
void SwapTS(LIST_DauSach &a, LIST_DauSach &b) {
	LIST_DauSach temp;
	temp = a;
	a = b;
	b = temp;
}

void SwapNodeDS(DauSach* ds1, DauSach* ds2)
{
	DauSach temp = *ds1;
	*ds1 = *ds2;
	*ds2 = temp;
}