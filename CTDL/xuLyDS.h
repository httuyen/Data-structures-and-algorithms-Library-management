#pragma once
#include "mylib.h"
#include "welcome.h"
#include "DauSach.h"
#include "RWDauSach.h"
#include "Date.h"
#include "GlobalVariable.h"
#include "Check_Input.h"
#include "XuLy.h"

void drawTable();
void showListTL(LIST_DauSach lds);
void drawEditDS(int x, int y);
void drawNoti(int x, int y);
void clearNoti();
void inputDS(LIST_DauSach &lds, pDauSach &pDS, bool isEdited);
void nhapISBN(string &ISBN, int &flag, bool &isSave, bool &isEsc);
void NhapTheLoaiSach(string &theLoai, int &flag, bool &isSave, bool &isEsc);
void NhapTenSach(string &tenSach, int &flag, bool &isSave, bool &isEsc);
void NhapTenTacGia(string &tacGia, int &flag, bool &isSave, bool &isEsc);
void nhapSoTrang(int &nTrang, int &flag, bool &isSave, bool &isEsc);
void NhapNamXuatBan(int &namXB, int &flag, bool &isSave, bool &isEsc);
void OutputDS_PerPage(LIST_DauSach list);
void Output_DS(dauSach ds, int viTri);
void XoaMotVung(int x, int y, int ndoc, int width);
void XoaMotDong(int width);
void Xoa1lineDS(int viTri);
void Xoa_OutDS_29lines();
void menuDS(LIST_DauSach &lds, pDauSach &pDS, Tree &t);
int ChooseItems_DS(LIST_DauSach &lDS, int &tttrang, int tongtrang,string theLoai);
int ChooseItemsTL(LIST_DauSach lds, int &tttrang, int tongtrang, int sizeTL);
void clearInput();