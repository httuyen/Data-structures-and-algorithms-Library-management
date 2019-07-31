#include "stdafx.h"
#include "TempDG.h"

NodeTempDG * Search_TempDG(ListTempDG l, int index)
{
	//NodeTempDG* p;
	for (NodeTempDG* p = l.pHead; p != nullptr; p = p->pNext) 
		if (p->tl.index == index)
			return p;
	return nullptr;
}

void initList_TempDG(ListTempDG &l)
{
	l.pHead = l.pTail = nullptr;
}

NodeTempDG* GetNode_TempDG(int index, int MADG)
{
	NodeTempDG *p = new NodeTempDG;
	if (p == NULL) {
		return NULL;
	}
	p->tl.index = index;
	p->tl.MADG = MADG;
	p->pNext = NULL;
	return (p);
}

void AddTailList_TempDG(ListTempDG &l, int index, int MADG)
{
	// tao Node
	NodeTempDG *p = GetNode_TempDG(index, MADG);
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;

	}
}

void CreateList_TempDG(Tree t, ListTempDG &l, int &index)
{
	if (t == NULL)
		return;
	CreateList_TempDG(t->pLeft, l, index);
	AddTailList_TempDG(l, index++, t->data.info.maThe);
	CreateList_TempDG(t->pRight, l, index);
}

void ClearAll_TempDG(ListTempDG &l)
{
	NodeTempDG *p;
	while (l.pHead != NULL)
	{
		p = l.pHead;
		l.pHead = l.pHead->pNext;
		delete p;
	}
}