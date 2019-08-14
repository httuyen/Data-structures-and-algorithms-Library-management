#pragma once
#include "DauSach.h"
#include "RWDauSach.h"
#include "RWDocGia.h"
#include "welcome.h"
#include "mylib.h"
#include "xuLyDS.h"
#include "xuLyDG.h"
#include "xuLyMT.h"

void xuLy(LIST_DauSach &lds, Tree &t);
void menu(int lc, LIST_DauSach &lds, dauSach dauS, DMS dataDMS, LIST_DMS ldms, pDauSach &pDS);
//void menuDG(int lc, MuonTra dataMT);