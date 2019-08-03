#pragma once
#include "DauSach.h"
#include "welcome.h"

char* toCharArray(string str);
char* ChuanHoaString(char* result);
string ChuanHoaString(string result);
void xoa(char* s, int vitrixoa);

void Input(int type, string &result, int &ordinal, bool &isSave, bool &isEscape);
void Input(int type, int &result, int &ordinal, bool &isSave, bool &isEscape);
int InputMaThe(int &maThe);