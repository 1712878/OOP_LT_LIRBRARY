#include "SachNgoai.h"


void SachNgoai::Nhap()
{
	Sach::Nhap();
	cout << "Ma ISBN: ";
	getline(cin>>ws, this->ISBN);
}

void SachNgoai::Xuat()
{
	Sach::Xuat();
	cout << "\t" << this->ISBN << endl;
}

void SachNgoai::SetDuLieu(vector<string> DL)
{
	Sach::SetDuLieu(DL);
	this->ISBN = DL[DL.size() - 1];
}

SachNgoai::SachNgoai()
{
}


SachNgoai::~SachNgoai()
{
}
