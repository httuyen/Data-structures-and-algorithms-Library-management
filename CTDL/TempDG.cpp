#include "stdafx.h"
#include "TempDG.h"

NodeTempDG * Search_TempDG(ListTempDG l, int index)
{
	//NodeTempDG* p;
	for (NodeTempDG* p = l.pHead; p != nullptr; p = p->pNext) 
		if (p->tl.index == index)
			return p;
	return nullptr;
}

void initList_TempDG(ListTempDG &l)
{
	l.pHead = l.pTail = nullptr;
}

NodeTempDG* GetNode_TempDG(int index, int MADG)
{
	NodeTempDG *p = new NodeTempDG;
	if (p == NULL) {
		return NULL;
	}
	p->tl.index = index;
	p->tl.MADG = MADG;
	p->pNext = NULL;
	return (p);
}

void AddTailList_TempDG(ListTempDG &l, int index, int MADG)
{
	// tao Node
	NodeTempDG *p = GetNode_TempDG(index, MADG);
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;

	}
}

void CreateList_TempDG(Tree t, ListTempDG &l, int &index)
{
	if (t != NULL) 
	{
		CreateList_TempDG(t->pLeft, l, index);
		AddTailList_TempDG(l, index++, t->data.info.maThe);
		CreateList_TempDG(t->pRight, l, index);
	}
		//return;
	
}

void ClearAll_TempDG(ListTempDG &l)
{
	NodeTempDG *p;
	while (l.pHead != NULL)
	{
		p = l.pHead;
		l.pHead = l.pHead->pNext;
		delete p;
	}
}

string Get_TenHo(theDocGia dg)
{
	int i = 0;
	string token;
	token = dg.ten;
	while (dg.ho[i] != ' ' && i<strlen(dg.ho))
	{
		token += dg.ho[i++];
	}
	return token;
}

void Create_ArrTenHo(Tree t, TenHo* arr, int &index)
{
	if (t == NULL)
		return;
	Create_ArrTenHo(t->pLeft, arr, index); 
	arr[index].hoten = Get_TenHo(t->data.info);
	arr[index++].MADG = t->data.info.maThe;
	Create_ArrTenHo(t->pRight, arr, index);
}

void Swap_TenHo(TenHo &a, TenHo &b)
{
	TenHo temp;
	temp = a;
	a = b;
	b = temp;
}

void QuicKsort_ARRTenHo(TenHo *th, int left, int right)
{
	TenHo key = th[(left + right) / 2];
	int i = left, j = right;
	do {
		while (th[i].hoten < key.hoten)
			i++;
		while (th[j].hoten > key.hoten)
			j--;
		if (i <= j) {
			if (i < j) Swap_TenHo(th[i], th[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (left < j) QuicKsort_ARRTenHo(th, left, j);
	if (right > i) QuicKsort_ARRTenHo(th, i, right);
}

void Sort_QuaHan(QuaHan *ArrQuaHan, int left, int right)
{
	QuaHan temp;
	int i = left;
	int j = right;
	//Lay phan tu giua cua day can sap thu tu lam moc
	QuaHan x = ArrQuaHan[(left + right) / 2];
	do
	{  
		while (ArrQuaHan[i].sachQuaHan.soNgayQuaHan > x.sachQuaHan.soNgayQuaHan)
			i++; // tim phan tu dau tien co gia tri nho hon hay bang x
		while (ArrQuaHan[j].sachQuaHan.soNgayQuaHan < x.sachQuaHan.soNgayQuaHan)
			j--;   // tim phan tu dau tien co gia tri lon hon hay bang x

		if (i <= j)   // Hoan vi
		{
			temp = ArrQuaHan[i];
			ArrQuaHan[i] = ArrQuaHan[j];
			ArrQuaHan[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);

	if (left < j) 	
		Sort_QuaHan(ArrQuaHan, left, j);
	if (i < right)   	
		Sort_QuaHan(ArrQuaHan, i, right);
}

string getTenSach(char* maSach, LIST_DauSach lDS)
{
	int i = 0;
	string maDS;
	while (maSach[i] != '_' && i < strlen(maSach))
	{
		maDS += maSach[i++];
	}
	for (int j = 0; j < lDS.n; j++)
	{
		if(lDS.nodesDauSach[j]->info.ISBN == maDS)
			return lDS.nodesDauSach[j]->info.tenSach;
	}
	return NULL;
}

int SoNgayMuon_Max(ListMT lMT)
{
	int max = 0;
	int ngay;
	Date today;
	Today(today);
	for (NODE_MT * p = lMT.pHeadMT; p != NULL; p = p->pNext)
	{
		if ((p->data.trangThai == 0) || (p->data.trangThai == 2))
		{
			ngay = DateToDate(p->data.ngayMuon, today);
			if (max < ngay)
			{
				max = ngay;
			}
		}
	}
	return max;

}

SachQuaHan TimSachQuaHan(ListMT lMT, LIST_DauSach lDS)
{
	SachQuaHan sQH;
	//LIST_DauSach lDS;
	int max = 0;
	int ngay;
	Date today;
	Today(today);
	for (NODE_MT * p = lMT.pHeadMT; p != NULL; p = p->pNext)
	{
		if ((p->data.trangThai == 0) || (p->data.trangThai == 2))
		{
			ngay = DateToDate(p->data.ngayMuon, today);
			if (max < ngay)
			{
				max = ngay;
				sQH.maSach = p->data.maSach;
				sQH.ngayMuon = p->data.ngayMuon;
				sQH.soNgayQuaHan = max - 7; // qua han 7 ngay
				//sQH.tenSach = p->data.tenSach;
				//sQH.tenSach = getTenSach(p->data.maSach, lDS);
				sQH.tenSach = "hoa";
			}
		}
	}
	return sQH;

}

// tong so sach cua dau sach dang duoc muon
int soSachMuon(LIST_DMS dms)
{
	int dem = 0;
	NODE_DMS *temp = NULL;
	for (temp = dms.pHeadDMS; temp != NULL; temp = temp->pNext)
	{
		//  tinh ca sach da muon va da muon nhung lam mat.
		if (temp->data.trangThai == 1 || temp->data.trangThai == 2)
		{
			dem++;
		}
	}
	return dem;
}

void Sort_Top10(TopSach *top10, int left, int right)
{
	TopSach temp;
	int i = left;
	int j = right;

	int x = top10[(left + right) / 2].sosachmuon;

	do
	{
		while (top10[i].sosachmuon > x)
			i++;
		while (top10[j].sosachmuon < x)
			j--; 

		if (i <= j)   // Hoan vi
		{
			temp = top10[i];
			top10[i] = top10[j];
			top10[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);

	if (left < j) 
		Sort_Top10(top10, left, j);
	if (i < right)   
		Sort_Top10(top10, i, right);
}