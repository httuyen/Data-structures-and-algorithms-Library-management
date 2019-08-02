#pragma once
#include "mylib.h"
#include "welcome.h"
#include "RWDocGia.h"
#include "TempDG.h"

void drawTableDG();
void drawEditDG(int x, int y);
void drawNotiDG(int x, int y);
void drawTableTop10();

int ChooseItems(Tree &t, ListTempDG &l, int tttrang, int tongtrang);
void DeleteLineTable_DG(int locate);
void ClearTable_DG();
void OutputDG_PerPage(Tree t, ListTempDG &l, int index);
void OutputDG_PerPage_STH(Tree t, TenHo *arr, int index);
void Output_DG(NODE_TREE* dg, int locate);
int Output_ListDG(Tree &t, ListTempDG &l, theDocGia &dg, int &tttrang);
void ListDG_Sort_MDG(Tree &t, ListTempDG &l, int &tttrang);
void ListDG_Sort_TenHo(Tree t, TenHo *arr);
void Menu_DocGia(Tree &t);
void InDocGia(Tree t);
void DanhSachQuaHan(Tree t, LIST_DauSach lDS);
void Top10Sach(LIST_DauSach lDS);
