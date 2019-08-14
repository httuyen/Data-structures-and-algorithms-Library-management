#pragma once
#include "mylib.h"
#include "welcome.h"
#include "DauSach.h"
#include "RWDauSach.h"
#include "Date.h"
#include "GlobalVariable.h"
#include "Check_Input.h"
void drawTable(LIST_DauSach &lds, pDauSach &pDS);
void showListTL(LIST_DauSach &lds, pDauSach &pDS);
void drawEditDS(int x, int y);
void drawNoti(int x, int y);
void clearNoti();
void inputDS(LIST_DauSach &lds, bool isEdited);
void nhapISBN(string &ISBN, int &flag, bool &isSave, bool &isEsc);
void NhapTheLoaiSach(string &theLoai, int &flag, bool &isSave, bool &isEsc);
void NhapTenSach(string &tenSach, int &flag, bool &isSave, bool &isEsc);
void NhapTenTacGia(string &tacGia, int &flag, bool &isSave, bool &isEsc);
void nhapSoTrang(int &nTrang, int &flag, bool &isSave, bool &isEsc);
void NhapNamXuatBan(int &namXB, int &flag, bool &isSave, bool &isEsc);
<<<<<<< HEAD
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
=======

void Menu_DauSach(LIST_DauSach &lDS);
void OutputDS_PerPage(LIST_DauSach &lDS, int index);
void Output_DS(dauSach ds);
void XoaMotVung(int x, int y, int ndoc, int width);
void XoaMotDong(int width);
void Xoa1lineDS(int viTri);
void Xoa_OutDS_29lines();
>>>>>>> e1cb598b30d14bad7b92d0d64e77e0f4a744196d
