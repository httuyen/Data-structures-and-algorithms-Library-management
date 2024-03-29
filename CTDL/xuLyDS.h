#pragma once
#include "mylib.h"
#include "welcome.h"
#include "DauSach.h"
#include "RWDauSach.h"
#include "Date.h"
#include "GlobalVariable.h"
#include "Check_Input.h"
#include "XuLy.h"
#include "Macro.h"

void drawTable();
void drawTableDS();
int drawInputSLSach();
void InputDMS(pDauSach &pDS, int slSach);
void showListTL(string listTL[], int tttrangTL, int slTL);
void drawEditDS(int x, int y);
void drawNoti(int x, int y);
void drawInputDMS();
void clearNoti();
void clrscrTableDS();
void inputDS(LIST_DauSach &lds, pDauSach &pDS, bool isEdited);
void nhapISBN(string &ISBN, int &flag, bool &isSave, bool &isEsc);
void NhapTheLoaiSach(string &theLoai, int &flag, bool &isSave, bool &isEsc);
void NhapTenSach(string &tenSach, int &flag, bool &isSave, bool &isEsc);
void NhapTenTacGia(string &tacGia, int &flag, bool &isSave, bool &isEsc);
void nhapSoTrang(int &nTrang, int &flag, bool &isSave, bool &isEsc);
void NhapNamXuatBan(int &namXB, int &flag, bool &isSave, bool &isEsc);
void OutputDS_PerPage(LIST_DauSach &lDS, string theLoai, int tttrang);
void Output_DS(dauSach ds, int viTri);
void XoaMotVung(int x, int y, int ndoc, int width);
void clearInput();
void clearInputDMS();
void clearTheLoai(int sl);
void clearTL();
void XoaMotDong(int width);
void Xoa1lineDS(int viTri);
void Xoa_OutDS_29lines();
void menuDS(LIST_DauSach &lds, pDauSach &pDS, Tree &t);
int NhapSach(pDauSach &pDS);
int SuaDanhMucSach(pDauSach &pDS, NODE_DMS* dms);
void NhapTrangThaiSach(int &result, int &ordinal, bool &isSave, bool &isEscape, int a, int b);
void NhapViTri(string &result, int &ordinal, bool &isSave, bool &isEscape, int a, int b);
int ChooseItems_DS(LIST_DauSach &lDS, Tree &t, pDauSach &pDS, string theLoai);
int ChooseItemTL(LIST_DauSach &lDS,Tree &t,pDauSach &pDS);
int ChooseItemTL_MT(LIST_DauSach &lDS, Tree &t, pDauSach &pDS);
int ChooseItems_DS_MT(LIST_DauSach &lDS, Tree &t, pDauSach &pDS, string theLoai);
int ChooseItem_DMS_MT(pDauSach &pDS, int &tttrang, int tongtrang);
