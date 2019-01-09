#include "DocGia.h"



DocGia::DocGia()
{
}

void DocGia::Nhap()
{
	cout << "CMND: ";
	getline(cin >> ws, this->CMND);
	cout << "Ho Ten: ";
	getline(cin >> ws, this->HoTen);
	cout << "SDT: ";
	getline(cin >> ws, this->SDT);
	cout << "Nghe Nghiep: ";
	getline(cin >> ws, this->NgheNghiep);
	cout << "Dia Chi: ";
	getline(cin >> ws, this->DiaChi);
}

void DocGia::Xuat()
{
	cout << left << setw(15) << this->CMND << setw(25) << this->HoTen << setw(20) << this->SDT
		<< setw(20) << this->NgheNghiep << setw(10) << this->DiaChi << endl;
}

void DocGia::SetDuLieu(vector<string> DL)
{
	int i = 0;
	this->CMND = DL[i++];
	this->HoTen = DL[i++];
	this->SDT = DL[i++];
	this->NgheNghiep = DL[i++];
	this->DiaChi = DL[i++];
}

void DocGia::TimKiem(string s)
{
}

void DocGia::Sua(string s)
{
}


DocGia::~DocGia()
{
}
