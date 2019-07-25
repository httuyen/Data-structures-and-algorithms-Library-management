#pragma once
#include<iostream>
#include<fstream>
#include<Windows.h>
#include<time.h>
#include<conio.h>
#include<string>
#include<iomanip>
using namespace std;
#define MaxNodes 10000
#define MAX_DAUSACH  100

typedef struct DanhMucSach
{
	char maSach[6] = "";
	int trangThai= 0;//0:cho muon dc//1:da cho muon//2:sach da thanh li
	char viTri[6] = "";
}DMS;

struct NODE_DMS
{
	DMS data;
	struct NODE_DMS *pNext;
};
typedef struct listDMS
{
	int n = -1;
	NODE_DMS *pHeadDMS;
	NODE_DMS *pTailDMS;
}LIST_DMS;

///////////////////////
struct dauSach
{
	char ISBN[6] = "";
	char tenSach[6]="";
	int soTrang=0;
	char tacGia[6]="";
	int namXuatBan=0;
	char theLoai[6]="";
};
struct DauSach {
	dauSach info;
	LIST_DMS dms;
};
typedef struct DauSach* pDauSach;

struct Date
{
	int Ngay;
	int Thang;
	int Nam;
};
struct MuonTra
{
	string maSach;
	Date ngayMuon;
	Date ngayTra;
	int trangThai;//0:dang muon//1:da tra//2:lam mat

};

struct LIST_DauSach
{
	int n = -1;
	DauSach* nodesDauSach[MaxNodes];
	//pDauSach nodesDauSach[MaxNodes];
};


struct NODE_DOUBLELIST
{
	MuonTra data;
	struct NODE_DOUBLELIST *pNext;
	struct NODE_DOUBLELIST *pPrev;

};
struct DOUBLELIST
{
	NODE_DOUBLELIST *pHeadMT;
	NODE_DOUBLELIST *pTailMT;
};
struct TheDocGia
{
	int maThe;
	string ho;
	string ten;
	string phai;//0:nu//1:nam
	int trangThai;//trang thai the:0:bi khoa//1:hoat dong
	DOUBLELIST doubleList_MuonTra;
};
struct NODE_TREE
{
	TheDocGia data;
	NODE_TREE *pLeft;
	NODE_TREE *pRight;
};
typedef NODE_TREE *Tree;

void initList_DMS(LIST_DMS& l);
void AddTailList_DMS(LIST_DMS &l, DMS data);
NODE_DMS* GetNode_DMS(DMS DATA);
int Full_DauSach(LIST_DauSach  l);

void initListDS(LIST_DauSach &lds);
pDauSach searchTen_DS(LIST_DauSach lds, string theLoai);
int Insert_DauSach(LIST_DauSach &lds, pDauSach &pDS);