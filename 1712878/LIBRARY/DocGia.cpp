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

string DocGia::GetCMND()
{
	return this->CMND;
}

void DocGia::SuaDocGia()
{
	int choice;
	do
	{
		cout << "1. Sua toan bo\n2. Sua CMND\n3. Sua Ho Ten\n";
		cout << "4. Sua SDT\n5. Sua Nghe Nghiep\n6. Sua Dia Chi\n";
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
		cout << "CMND moi: ";
		getline(cin >> ws, s);
		this->CMND = s;
		break;
	case 3:
		cout << "Ho Ten moi: ";
		getline(cin >> ws, s);
		this->HoTen = s;
		break;
	case 4:
		cout << "SDT moi: ";
		getline(cin >> ws, s);
		this->SDT = s;
		break;
	case 5:
		cout << "Nghe Nghiep moi: ";
		getline(cin >> ws, s);
		this->NgheNghiep = s;
		break;
	case 6:
		cout << "Dia Chi moi: ";
		getline(cin >> ws, s);
		this->DiaChi = s;
		break;
	}
}

bool DocGia::TimKiem(string s)
{
	return (this->CMND == s || this->HoTen == s || this->SDT == s
		|| this->NgheNghiep == s || this->DiaChi == s);
}

DocGia::~DocGia()
{
}
