#pragma once
#include "mylib.h"
#include "xulyDS.h"

void drawNhapMaThe();
void drawInfoDG();
void drawListSachMuon();
void DrawTableDMS();

bool MatSach(ListMT lMT);
void MuonSach(Tree &t, LIST_DauSach &lDS);
int TacVuMuonSach(LIST_DauSach lDS, NODE_TREE* dg);

// kiem tra doc gia co muon sach nay khong
bool CheckTenSach_MT(LIST_DauSach lDS, ListMT lMT, string tenSach);