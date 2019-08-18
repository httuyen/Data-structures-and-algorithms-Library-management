#include "stdafx.h"
#include "XuLy.h"

int main() {
	LIST_DauSach lds;
	Tree t;
	OpenFile(lds);
	loadDG(t);
	xuLy(lds, t);
	return 0;
}
