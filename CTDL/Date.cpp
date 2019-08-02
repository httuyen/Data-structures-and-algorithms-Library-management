#include "stdafx.h"
#include "Date.h"

bool namNhuan(int year)
{
	return (((year % 4 == 0) && (year % 100 != 0)) ||
		(year % 400 == 0));
}

int DateToNum(Date date)
{
	int kc1 = 0, kc2 = date.Ngay;
	for (int i = 2000; i < date.Nam; i++)
	{
		if (namNhuan(i))
			kc1 += 366;
		else kc1 += 365;
	}
	for (int i = 1; i < date.Thang; i++)
	{
		if (i == 2 && namNhuan(date.Nam)) 
			kc2 += 29;
		if (i == 2 && !namNhuan(date.Nam))
			kc2 += 28;
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
			kc2 += 31;
		if (i == 4 || i == 6 || i == 9 || i == 11)
			kc2 += 30;
	}
	return (kc1 + kc2);
}

int DateToDate(Date date1, Date date2)
{
	int num1 = DateToNum(date1);
	int num2 = DateToNum(date2);
	return abs(num1 - num2);
}

void Today(Date &date)
{
	tm today;
	time_t ltime;
	time(&ltime);
	// today = localtime( &ltime );
	localtime_s(&today, &ltime);
	date.Ngay = today.tm_mday;
	date.Thang = today.tm_mon + 1;
	date.Nam = today.tm_year + 1900;
}