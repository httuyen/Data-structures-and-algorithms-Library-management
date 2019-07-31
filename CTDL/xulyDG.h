#pragma once
#include "mylib.h"
#include "welcome.h"
#include "RWDocGia.h"
#include "TempDG.h"

void drawTableDG(Tree &t);
void drawEditDG(int x, int y);

void DeleteLineTable_DG(int locate);
void ClearTable_DG();
void OutputDG_PerPage(Tree t, ListTempDG &l, int index);
void Output_DG(NODE_TREE* dg, int locate);
int Output_ListDG(Tree &t, ListTempDG &l, theDocGia &dg, int &tttrang);
void Menu_DocGia(Tree &t);
void InDocGia(Tree t);
