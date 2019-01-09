#include "SachViet.h"


SachViet::SachViet()
{
}

void SachViet::Xuat()
{
	Sach::Xuat();
	cout << endl;
}

string SachViet::toString()
{
	return Sach::toString() + "\n";
}


SachViet::~SachViet()
{
}
