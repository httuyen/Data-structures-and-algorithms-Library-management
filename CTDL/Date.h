#pragma once
#include <time.h>
#include <iostream>
#include "mylib.h"
#include "Macro.h"

struct Date
{
	int Ngay = 0;
	int Thang = 0;
	int Nam = 0;
};

// kt nam nhuan
bool namNhuan(int year);

// khoang cach tu moc 1/1/2000
int DateToNum(Date date);

// khoang cach giua 2 ngay
int DateToDate(Date date1, Date date2);

// lay ngay hien tai
void Today(Date &date);

// kiem tra ngay hop le
int ValidDate(Date date);