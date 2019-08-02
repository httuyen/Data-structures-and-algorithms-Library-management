#pragma once
#include "mylib.h"
#include "welcome.h"
#include "DauSach.h"
#include "RWDauSach.h"

void drawTable(LIST_DauSach &lds, pDauSach &pDS);
void showListDS(LIST_DauSach &lds, pDauSach &pDS);
void drawEditDS(int x, int y);
void drawNoti(int x, int y);
void clearNoti();
void inputDS(int x, int y, LIST_DauSach &lds);
void nhapISBN(string &ISBN, int &flag, bool &isSave, bool &isEsc);
void NhapTheLoaiSach(string &theLoai, int &flag, bool &isSave, bool &isEsc);
void NhapTenSach(string &tenSach, int &flag, bool &isSave, bool &isEsc);
void NhapTenTacGia(string &tacGia, int &flag, bool &isSave, bool &isEsc);
void nhapSoTrang(int &nTrang, int &flag, bool &isSave, bool &isEsc);
void NhapNamXuatBan(int &namXB, int &flag, bool &isSave, bool &isEsc);