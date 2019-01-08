#include "Sach.h"


Sach::Sach()
{
}

void Sach::Nhap()
{
	cout << "Ma Sach: ";
	getline(cin >> ws, this->MaSach);
	cout << "Ten Sach: ";
	getline(cin >> ws, this->TenSach);
	cout << "Tac Gia: ";
	getline(cin >> ws, this->TacGia);
	cout << "NhaXuatBan: ";
	getline(cin >> ws, this->NhaXuatBan);
	cout << "Gia: ";
	cin >> this->Gia;
}

void Sach::Xuat()
{
	cout << this->MaSach << "\t" << this->TenSach << "\t" << this->TacGia
		<< "\t" << this->NhaXuatBan << "\t" << this->Gia;
}

bool Sach::TimKiem(string ma)
{
	return this->MaSach == ma;
}

void Sach::Sua(string ma)
{
	cout << "Nhap thong tin can thay doi: ";
	string s;
	cout << "Ma Sach: "; 
	getline(cin >> ws, s);
	this->MaSach = s;
	cout << "Ten Sach: ";
	getline(cin >> ws, s);
	this->MaSach = s;
	cout << "Tac Gia: ";
	getline(cin >> ws, s);
	this->MaSach = s;
	cout << "NhaXuatBan: ";
	getline(cin >> ws, s);
	this->MaSach = s;
	cout << "Gia: ";
	float gia;
	cin >> gia;
	this->Gia = gia;
}


Sach::~Sach()
{
}
