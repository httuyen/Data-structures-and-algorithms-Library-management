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
	for (int i = MIN_YEAR; i < date.Nam; i++)
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
	return (num1 - num2);
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

int ValidDate(Date date)
{
	// 2 la nam sai, 1 la thang sai, 0 la ngay sai
	if (date.Nam < MIN_YEAR || date.Nam > MAX_YEAR)
		return 2;
	if (date.Thang < MIN_MONTH || date.Thang > MAX_MONTH)
		return 1;
	if (date.Ngay < MIN_DAY || date.Ngay > MAX_DAY)
		return 0;
	if (date.Thang == 2)
	{
		if (namNhuan(date.Nam))
		{
			if (date.Ngay > 29)
				return 0;
		}
		else
		{
			if (date.Ngay > 28)
			{
				return 0;
			}
		}
	}
	if ((date.Thang == 4 || date.Thang == 6 || date.Thang == 9 || date.Thang == 11) && (date.Ngay > 30))
	{
		return 0;
	}
	return 3;
}