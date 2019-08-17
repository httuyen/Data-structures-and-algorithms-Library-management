#pragma once
#include<iostream>
#include<fstream>
#include<Windows.h>
#include<time.h>
#include<string>
#include<iomanip>
#include "mylib.h"
#include "Macro.h"
#include "Date.h"

using namespace std;
#define MaxNodes 10000
#define MAX_DAUSACH  100
typedef struct DanhMucSach
{
	char maSach[9] = "";
	int trangThai= 0;//0:cho muon dc//1:da cho muon//2:sach da thanh li
	char viTri[20] = "";
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
	char tenSach[20]="";
	int soTrang=0;
	char tacGia[20]="";
	int namXuatBan=0;
	char theLoai[20]="";
};
struct DauSach {
	dauSach info;
	LIST_DMS dms;
};
typedef struct DauSach* pDauSach;

/*struct Date
{
	int Ngay = 0;
	int Thang = 0;
	int Nam = 0;
};*/
struct MuonTra
{
	char maSach[10] = "";
	Date ngayMuon;
	Date ngayTra;
	int trangThai = 0;//0:dang muon//1:da tra//2:lam mat

	//string tenSach = "";
};

struct LIST_DauSach
{
	int n = -1;
	DauSach* nodesDauSach[MaxNodes];
	//pDauSach nodesDauSach[MaxNodes];
};


struct NODE_MT
{
	MuonTra data;
	struct NODE_MT *pNext;
	struct NODE_MT *pPrev;
};
struct ListMT
{
	int n = -1;
	NODE_MT *pHeadMT;
	NODE_MT *pTailMT;
};

struct theDocGia
{
	int maThe = 0;
	char ho[11] = "";
	char ten[11] = "";
	char phai[4] = "";//0:nu//1:nam
	int trangThai = 0;//trang thai the:0:bi khoa//1:hoat dong
};
//typedef struct theDocGia theDocGia;
struct TheDocGia
{
	theDocGia info;
	ListMT listMT;
};
typedef struct TheDocGia *pTheDocGia;

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
NODE_DMS* Search_DMS_Pos(NODE_DMS* dms, int pos);

char* getViTri(LIST_DauSach lDS, char* maSach);
NODE_DMS* getSachByMS(LIST_DauSach lDS, char* maSach);
DauSach* getSachByName(LIST_DauSach lDS, char* tenSach);

int Full_DauSach(LIST_DauSach  l);
void initListDS(LIST_DauSach &lds);
pDauSach searchTen_DS(LIST_DauSach lds, string theLoai);
int Insert_DauSach(LIST_DauSach &lds, pDauSach &pDS);

void initList_MT(ListMT &l);
void AddTailList_MT(ListMT &l, MuonTra data);
void AddHeadList_MT(ListMT &l, MuonTra data);
NODE_MT* GetNode_MT(MuonTra data);

int getTheLoai(LIST_DauSach lds, string listTL[]);

void InsertDGtoTree(Tree &t, theDocGia dg);
NODE_TREE* GetNode_DG(theDocGia dg);
void initTREE_DG(Tree &t);
NODE_TREE* Find_DG(Tree t, int maThe);
int countDG(Tree t);
void scanTreeDG(Tree t);

unsigned Random_MaThe(Tree t);
unsigned Random();
bool Check_MaThe(Tree t, unsigned maThe);
void Update_DG(Tree &t, theDocGia &dg, bool isEdited);
bool IsDeleted_DG(Tree &t, theDocGia dg);
NODE_TREE* FindMin(Tree t);
int SoSachDangMuon(ListMT lMT);
bool SearchISBN_DS(LIST_DauSach lds, string ISBN);
LIST_DauSach getDSByTL(LIST_DauSach &lds, string theLoai);
void QuicKsortTS(LIST_DauSach &lds, int left, int right);
void testDS(LIST_DauSach &lds, string theLoai);
void SwapTS(LIST_DauSach &a, LIST_DauSach &b);
void SwapNodeDS(DauSach* ds1, DauSach* ds2);
bool Check_DMS(NODE_DMS* nDMS);
int Empty_DauSach(LIST_DauSach l);
void DeleteDauSach(LIST_DauSach &lds, pDauSach pDS);
int getPosByPDS(LIST_DauSach lds, pDauSach pDS);