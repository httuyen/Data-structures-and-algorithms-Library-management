#pragma once
#include "mylib.h"
#include "xulyDS.h"

void drawNhapMaThe(int x, int y);
void drawInfoDG(int x, int y);
void drawListSachMuon();
void drawListSachMuon_FD();
void DrawTableDMS();

bool MatSach(ListMT lMT);
void MuonSach(Tree &t, LIST_DauSach &lDS);
int TacVuMuonSach(LIST_DauSach lDS, NODE_TREE* dg);

void TraSach(Tree &t, LIST_DauSach &lDS);

// kiem tra doc gia co muon sach nay khong
bool CheckTenSach_MT(LIST_DauSach lDS, ListMT lMT, string tenSach);

void ClearTable_SachMuon();
void ClearTable_SachMuon_FD();
void DeleteLineTable_SM_FD(int locate);
void OutputList_MT(ListMT listMT, LIST_DauSach lDS);
void Output_MT(NODE_MT * p, LIST_DauSach lDS, int locate);
int ChooseItem_MT(ListMT lMT);

void OutputDMS_PerPage(pDauSach pDS, int index);
void ClearTable_DMS();
void DeleteLineTable_DMS(int locate);
void Output_DMS(DMS dms, int locale);
int ChooseItem_DMS(pDauSach &pDS, int &tttrang, int tongtrang);
