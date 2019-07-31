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
