#pragma once
#include <iostream>
#include "Macro.h"
#include "DauSach.h"

using std::string;

struct TenHo
{
	string hoten;
	int MADG;
};

struct TempDG
{
	int index;
	int MADG;
};

struct NodeTempDG
{
	TempDG tl;
	struct NodeTempDG * pNext;
};


struct ListTempDG
{
	NodeTempDG *pHead;
	NodeTempDG *pTail;
};

struct SachQuaHan
{
	string maSach = "";
	string tenSach = "";
	Date ngayMuon;
	int soNgayQuaHan = 0;
};

struct QuaHan
{
	TenHo docGia;
	SachQuaHan sachQuaHan;
};

struct  TopSach
{
	string tensach;
	int sosachmuon;
};

// ..... khoi tao........
void initList_TempDG(ListTempDG &l);

//.......get node.........
NodeTempDG* GetNode_TempDG(int index, int MADG);

//...... add tail link list........
void AddTailList_TempDG(ListTempDG &l, int index, int MADG);

// Function for implementing the Binary Search on linked list
NodeTempDG * Search_TempDG(ListTempDG l, int index);

//............xoa list..................
void ClearAll_TempDG(ListTempDG &l);

void CreateList_TempDG(Tree t, ListTempDG &l, int &index);
string Get_TenHo(theDocGia dg);
void Create_ArrTenHo(Tree t, TenHo* arr, int &index);
void Swap_TenHo(TenHo &a, TenHo &b);
void QuicKsort_ARRTenHo(TenHo *th, int left, int right);

void Sort_QuaHan(QuaHan *ArrQuaHan, int left, int right);
int SoNgayMuon_Max(ListMT lMT);
SachQuaHan TimSachQuaHan(ListMT lMT, LIST_DauSach lDS);
string getTenSach(char* maSach, LIST_DauSach lDS);

int soSachMuon(LIST_DMS dms);
void Sort_Top10(TopSach *top10, int left, int right);