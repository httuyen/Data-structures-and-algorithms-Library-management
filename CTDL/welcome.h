#pragma once
#include "mylib.h"
#include <iostream>
#include <string>
#define windowWeight 1300
#define windowHeight 700
using namespace std;

void welcomeConsole();
void menuFeature();
void drawFrame();
void menuFeature(int slFeature, int xStart, int yStart, int &flag, std::string listMenu[]);
int selection(int &flag, std::string listMenu[], int slFeature, int xStart, int yStart);
int index(string listMenu[], int i);
void setDefaultColor();
void setHighLightColor();
void clearHighLight(int &flag, std::string listMenu[], int slFeature, int xStart, int yStartText, int keypress);