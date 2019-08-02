#pragma once
#include <iostream>
#include <Windows.h>
#include <ctime>
//#include <cstdlib>
#include <iomanip>
#include <math.h>
#include <conio.h>
#include <string>
#include <fstream>
#include <Shellapi.h>
#include <stdio.h>
#include<thread>
#pragma comment(lib, "winmm.lib")

#define BLACK			0
#define DARKBLUE		1
#define DARKGREEN		2
#define DARKBEIGE		3
#define DARKRED			4
#define DARKPURPLE		5
#define DARKYELLOW		6
#define GREY			7
#define DARKGREY		8
#define BLUE			9
#define GREEN			10
#define BEIGE			11
#define RED				12
#define PURPLE			13
#define YELLOW			14
#define WHITE			15
#define BRIGHTBLUE_ondarkblue 11
//
#define UP				72
#define DOWN			80
#define LEFT			75
#define RIGHT			77
#define UP_Redefine		1
#define DOWN_Redefine	3
#define LEFT_Redefine	5
#define RIGHT_Redefine	7
//#define DELETE			83
#define DELETE_Redefine	9
#define ENTER			13
#define ESCAPE			27
#define BACKSPACE		8
#define SPACE			32
#define F2 60
#define F3 61
#define F4 62
#define F5 63
#define F6 64
#define F7 65
#define F8 66
#define F9 67
#define F2_Redefine 130
#define F3_Redefine 131
#define F4_Redefine 132
#define F5_Redefine 133
#define F6_Redefine 134
#define F7_Redefine 135
#define F8_Redefine 136
#define F9_Redefine 137
#define CONTROL_D 4
#define CONTROL_L 12
#define CONTROL_Z 26
//
#define Tcross		char(-62)
#define Tleft		char(63)
#define Tright		char(-76)
#define Tinvert		char(-63)
#define CROSS		char(-59)
#define VERTICAL	char(-60)
#define HORIZONTAL	char(-77)
#define UPPERLEFT	char(-38)
#define UPPERRIGHT	char(-65)
#define BOTTOMLEFT	char(-64)
#define BOTTOMRIGHT char(-39)
#define SQUARE		char(219)
void ResizeConsole(int width, int height);
bool deleteFile1(char* directory_path);
void openFile(char* fileName);
void strcpy_s2(char* destination_string, int Size, char* source_string);
void strcat_s2(char* destination_string, char* source_string);
int wherex(void);
void gotoxy(short int x, short int y);
int wherey(void);
void textColor(int textColor, int BackColor);
void anConTro();
void hienConTro();
void veNetNgang(int xStart, int xEnd, int y);
void veNetDoc(int yStart, int yString, int x);
void xoaNetNgang(int xStart, int xEnd, int y);
void xoaNetDoc(int yStart, int yString, int x);
void drawCell(int xStartPoint, int xEndPoint, int yStartPoint, int yEndPoint, int Mode = 1, char* side = NULL);
void joinCell(int xStartPoint, int xEndPoint, int yStartPoint, int yEndPoint, int Mode = 1, char* side = NULL);
void deleteCell(int xStartPoint, int xEndPoint, int yStartPoint, int yEndPoint, char* side = NULL);
void drawRow(int xStartPoint, int yStartPoint, int xWidth, int yWidth, int Amount, int Mode = 1, char side = NULL);
void deleteRow(int xStartPoint, int yStartPoint, int xWidth, int yWidth, int Amount, int Mode = 1, char side = NULL);
void drawColumn(int xStartPoint, int yStartPoint, int xWidth, int yWidth, int Amount, int Mode = 1, char side = NULL);
void deleteColumn(int xStartPoint, int yStartPoint, int xWidth, int yWidth, int Amount, int Mode = 1, char side = NULL);
double lamTronSauDauPhay(double Number, int amount);
template<class Type>
bool randomArray(Type* array, int sizeofArray, int leftLimit, int rightLimit);
template<class Type>
bool selectionSort(Type* array, int sizeofArray, int leftLimit, int rightLimit, bool increase);
template<class Type>
bool numberToString(Type number, char* String, int SizeOfString);
template<class Type>
bool stringToNumber(char* String, Type& number);
void SetColor(WORD color);
void SetBGColor(WORD color);
void clrscr();
void cls(HANDLE hConsole);
