#pragma once
#include <iostream>
#include "Macro.h"
#include "DauSach.h"

using std::string;

struct TenHo
{
	string hoten;
	int MADG;
};

struct TempDG
{
	int index;
	int MADG;
};

struct NodeTempDG
{
	TempDG tl;
	struct NodeTempDG * pNext;
};


struct ListTempDG
{
	//so phan tu
	// int n;
	NodeTempDG *pHead;
	NodeTempDG *pTail;
};

// ..... khoi tao........
void initList_TempDG(ListTempDG &l);

//.......get node.........
NodeTempDG* GetNode_TempDG(int index, int MADG);

//...... add tail link list........
void AddTailList_TempDG(ListTempDG &l, int index, int MADG);

// function to find out middle element
NodeTempDG * Middle(NodeTempDG * start, NodeTempDG * last);

// Function for implementing the Binary Search on linked list
NodeTempDG * Search_TempDG(ListTempDG l, int index);

//............xoa list..................
void ClearAll_TempDG(ListTempDG &l);

void CreateList_TempDG(Tree t, ListTempDG &l, int &index);