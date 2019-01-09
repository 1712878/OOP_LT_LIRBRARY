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

int Sach::GetTienPhat()
{
	return 10000;
}

string Sach::GetTenSach()
{
	return this->TenSach;
}

string Sach::GetTacGia()
{
	return this->TacGia;
}

string Sach::toString()
{
	return this->MaSach + "," + this->TenSach + "," +
		this->TacGia + "," + this->NhaXuatBan + "," + to_string(this->Gia);
}

void Sach::SuaSach()
{
	int choice;
	do
	{
		cout << "1. Sua toan bo\n2. Sua Ma Sach\n3. Sua Ten Sach\n";
		cout << "4. Sua Tac Gia\n5. Sua Nha Xuat Ban\n6. Sua gia\n";
		cout << "Chon: ";
		cin >> choice;
	} while (choice < 1 || choice >6);

	string s;
	switch (choice)
	{
	case 1:
		cout << "Nhap lai thong tin: \n";
		this->Nhap();
		break;
	case 2:
		cout << "Ma Sach moi: ";
		getline(cin >> ws, s);
		this->MaSach = s;
		break;
	case 3:
		cout << "Ten Sach moi: ";
		getline(cin >> ws, s);
		this->TenSach = s;
		break;
	case 4:
		cout << "Tac Gia moi: ";
		getline(cin >> ws, s);
		this->TacGia = s;
		break;
	case 5:
		cout << "Nha Xuat Ban moi: ";
		getline(cin >> ws, s);
		this->NhaXuatBan = s;
		break;
	case 6:
		cout << "Gia moi: ";
		float gia;
		cin >> gia;
		this->Gia = gia;
		break;
	}	
}

Sach::~Sach()
{
}
