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
	cout << left <<setw(10)<< this->MaSach << setw(30) << this->TenSach << setw(20) << this->TacGia
		<< setw(20) << this->NhaXuatBan << setw(10) << this->Gia;
}

string Sach::GetMaSach()
{
	return this->MaSach;
}

bool Sach::TimKiem(string s)
{
	return (this->MaSach == s || this->TenSach == s|| this->TacGia == s|| this->NhaXuatBan == s);
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
