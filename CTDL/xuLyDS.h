#pragma once
#include "mylib.h"
#include "welcome.h"
#include "DauSach.h"
#include "RWDauSach.h"

void drawTable(LIST_DauSach &lds, pDauSach &pDS);
void showListDS(LIST_DauSach &lds, pDauSach &pDS);
void drawEditDS(int x, int y);
void drawNoti(int x, int y);