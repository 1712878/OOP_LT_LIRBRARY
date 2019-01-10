#include "SachViet.h"

void SachViet::Xuat()
{
	Sach::Xuat();
	cout << endl;
}

int SachViet::GetTienPhat()
{
	return pSachViet;
}

string SachViet::toString()
{
	return Sach::toString() + "\n";
}