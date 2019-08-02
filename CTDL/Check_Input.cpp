#include "stdafx.h"
#include "Check_Input.h"

char* ChuanHoaString(char* result)
{
	for (int i = 0; i < strlen(result); i++)
		if (result[i] == ' '&& result[i + 1] == ' ')
		{
			xoa(result, i);
			i--;
		}
	if (result[0] == ' ')
		xoa(result, 0);
	if (result[strlen(result) - 1] == ' ')
		xoa(result, strlen(result) - 1);
	return result;
}

void xoa(char* s, int vitrixoa)
{
	int n = strlen(s);
	for (int i = vitrixoa; i < n; i++)
		s[i] = s[i + 1];
	s[n - 1] = '\0'; 
}

char* toCharArray(string str)
{
	char* c = new char(str.size() + 1);
	for (int i = 0; i < str.size() + 1; i++)
		c[i] = str[i];
	return c;
}

string ChuanHoaString(string result)
{
	for (size_t i = 1; i < result.length(); i++)
	{
		if (result[0] == ' ')
		{
			result.erase(0, 1);
			i--;
		}
		else if (result[i - 1] == ' ' && result[i] == ' ')
		{
			result.erase(i - 1, 1);
			i--;
		}
		else if (result[result.length() - 1] == ' ')
		{
			result.erase(result.length() - 1, 1);

		}
	}
	return result;
}

void Input(int type, string &result, int &ordinal, bool &isSave, bool &isEscape)
{
	setDefaultColor();
	// nhap HO DG
	if (type == 0) 
	{
		// bien dem so chu da duoc nhap vao cho result
		cout << result;
		int count = (int)result.length();
		int x, y;
		// bien co hieu
		int nSpace = 0;

		while (true)
		{
			x = wherex();
			y = wherey();
			while (_kbhit())
			{
				int kb_hit = _getch();
				// chi nhan chu thuong hoac  chu in hoa va dau cach
				// chi nhap ho toi da 10 ky tu.
				if (((kb_hit >= 65 && kb_hit <= 90) || (kb_hit >= 97 && kb_hit <= 122) || kb_hit == SPACE)
					&& count < MAX_HO && count >= 0)
				{
					// xoa dong thong bao
					gotoxy(xNOTI_DG + 2, yNOTI_DG + 2);
					cout << setw(42) << setfill(' ') << " ";
					gotoxy(x, y);

					if (nSpace == 1 && kb_hit == SPACE)
					{
						count++;
						cout << (char)kb_hit;
						result += (char)kb_hit;
						nSpace = 0;
					}
					else if (kb_hit != SPACE)
					{
						count++;
						kb_hit = toupper((char)kb_hit);
						cout << (char)kb_hit;
						result += (char)kb_hit;
						nSpace = 1;
					}

				}
				else if (kb_hit == 224)
				{
					kb_hit = _getch();
					if (kb_hit == KEY_UP)
					{
						ordinal = 3;
						return;
					}
					else
					{
						ordinal = 1;
						return;
					}
				}
				else if (kb_hit == ENTER)
				{
					ordinal = 1;
					return;
				}
				else if (kb_hit == BACKSPACE && count > 0)
				{
					cout << "\b" << " " << "\b";
					count--;
					result.erase(result.length() - 1, 1);
				}
				else if (kb_hit == 0)
				{
					kb_hit = _getch();
					if (kb_hit == KEY_F10)
					{
						isSave = true;
						return;
					}
				}
				else if (kb_hit == ESC)
				{
					isEscape = true;
					return;
				}
				else {
					gotoxy(xNOTI_DG + 2, yNOTI_DG + 2);
					cout << " TOI DA 10 KY TU, CHI LAY KY TU CHU !!!";
					gotoxy(x, y);
				}
			}

		}
	}

	// nhap TEN DG
	else if (type == 1)
	{
		// bien dem so chu da duoc nhap vao cho result
		cout << result;
		int count = (int)result.length();
		int x, y;
		while (true)
		{
			x = wherex();
			y = wherey();

			while (_kbhit())
			{
				int kb_hit = _getch();
				// chi nhan chu thuong hoac  chu in hoa. 
				// chi nhap ten toi da 7 ky tu, vi tu dai nhat tieng viet chi la 7.
				if (((kb_hit >= 65 && kb_hit <= 90) || (kb_hit >= 97 && kb_hit <= 122)) && count < MAX_TEN)
				{
					count++;

					// xoa dong thong bao
					gotoxy(xNOTI_DG + 2, yNOTI_DG + 2);
					cout << setw(42) << setfill(' ') << " ";
					gotoxy(x, y);

					// chuyen qua in hoa
					kb_hit = toupper((char)kb_hit);
					cout << (char)kb_hit;
					result += (char)kb_hit;
				}
				else if (kb_hit == 224)
				{
					kb_hit = _getch();
					if (kb_hit == KEY_UP)
					{
						ordinal = 0;
						return;
					}
					else
					{
						ordinal = 2;
						return;
					}
				}
				else if (kb_hit == ENTER)
				{
					ordinal = 2;
					return;
				}
				else if (kb_hit == BACKSPACE && count > 0)
				{
					cout << "\b" << " " << "\b";
					count--;
					result.erase(result.length() - 1, 1);

				}
				else if (kb_hit == 0)
				{
					kb_hit = _getch();
					if (kb_hit == KEY_F10)
					{
						isSave = true;
						return;
					}
				}
				else if (kb_hit == ESC)
				{
					isEscape = true;
					return;
				}
				else {
					gotoxy(xNOTI_DG + 2, yNOTI_DG + 2);
					cout << "TOI DA 10 KY TU, CHI LAY KY TU CHU !!!";
					gotoxy(x, y);
				}
			}
		}
	}

	// nhap PHAI
	else if (type == 2)
	{
	int count = 0;

	// giu lai vi tri ban dau 
	int x = wherex(), y = wherey();

	while (true)
	{
		while (_kbhit())
		{
			int kb_hit = _getch();
			if ((kb_hit == 48 || kb_hit == 49) && count < 1)
			{
				count++;
				result = to_string(kb_hit - 48);
				// xoa dong thong bao
				gotoxy(xNOTI_DG + 2, yNOTI_DG + 2);
				cout << setw(42) << setfill(' ') << " ";
				gotoxy(x, y);
				if (result == "0") {
					cout << result << ":  NU ";
					result = "NU";
				}
				else {
					cout << result << ":  NAM";
					result = "NAM";
				}
				//(result == "0") ? cout << result << ":  NU" : cout << result << ":  NAM";
			}
			else if (kb_hit == 224)
			{
				kb_hit = _getch();
				// cho nay xay ra hai truong hop
				if (kb_hit == KEY_UP)
				{
					ordinal = 1;
					return;
				}
				else
				{
					ordinal = 3;
					return;
				}
			}
			else if (kb_hit == ENTER)
			{

				ordinal = 3;
				return;

			}
			else if (kb_hit == BACKSPACE && count > 0)
			{
				gotoxy(x, y);
				result = "3";
				cout << " " << setw(15) << setfill(' ') << " ";
				count--;
				// chuyen ve vi tri ban dau.
				gotoxy(x, y);
			}
			else if (kb_hit == 0)
			{
				kb_hit = _getch();
				if (kb_hit == KEY_F10)
				{
					isSave = true;
					return;
				}
			}
			else if (kb_hit == ESC)
			{
				isEscape = true;
				return;
			}
			else {
				gotoxy(xNOTI_DG + 2, yNOTI_DG + 2);
				cout << "BAN HAY NHAP 0 HOAC 1,Backspace DE XOA !!!";
				gotoxy(x, y);
			}
		}
	}
	}
}

void Input(int type, int &result, int &ordinal, bool &isSave, bool &isEscape)
{
	// nhap TRANG THAI
	if (type == 3)
	{
		int count = 0;

		// giu lai vi tri ban dau 
		int x = wherex(), y = wherey();

		while (true)
		{
			while (_kbhit())
			{
				int kb_hit = _getch();
				if ((kb_hit == 48 || kb_hit == 49) && count < 1)
				{
					count++;
					result = kb_hit - 48;
					// xoa dong thong bao
					gotoxy(xNOTI_DG + 2, yNOTI_DG + 2);
					cout << setw(42) << setfill(' ') << " ";
					gotoxy(x, y);
					(result == 0) ? cout << result << ":  KHOA     " : cout << result << ":  HOAT DONG";
				}
				else if (kb_hit == 224)
				{
					kb_hit = _getch();
					// cho nay xay ra hai truong hop
					if (kb_hit == KEY_UP)
					{
						ordinal = 2;
						return;
					}
					else
					{
						ordinal = 0;
						return;
					}
				}
				else if (kb_hit == ENTER)
				{

					ordinal = 0;
					return;

				}
				else if (kb_hit == BACKSPACE && count > 0)
				{
					gotoxy(x, y);
					result = 3;
					cout << " " << setw(15) << setfill(' ') << " ";
					count--;
					// chuyen ve vi tri ban dau.
					gotoxy(x, y);
				}
				else if (kb_hit == 0)
				{
					kb_hit = _getch();
					if (kb_hit == KEY_F10)
					{
						isSave = true;
						return;
					}
				}
				else if (kb_hit == ESC)
				{
					isEscape = true;
					return;
				}
				else {
					gotoxy(xNOTI_DG + 2, yNOTI_DG + 2);
					cout << "BAN HAY NHAP 0 HOAC 1,Backspace DE XOA !!!";
					gotoxy(x, y);
				}
			}
		}
	}
}
