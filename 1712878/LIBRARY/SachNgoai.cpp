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
	cout << setw(10) << this->ISBN << endl;
}

void SachNgoai::SetDuLieu(vector<string> DL)
{
	Sach::SetDuLieu(DL);
	this->ISBN = DL[DL.size() - 1];
}

void SachNgoai::SuaSach()
{
	int choice;
	do
	{
		cout << "1. Sua toan bo\n2. Sua Ma Sach\n3. Sua Ten Sach\n";
		cout << "4. Sua Tac Gia\n5. Sua Nha Xuat Ban\n6. Sua gia\n7. Sua ISBN\n";
		cout << "Chon: ";
		cin >> choice;
	} while (choice < 1 || choice >7);

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
	case 7:
		cout << "ISBN moi: ";
		getline(cin >> ws, s);
		this->ISBN = s;
		break;
	}
}

int SachNgoai::GetTienPhat()
{
	return 20000;
}

SachNgoai::SachNgoai()
{
}


SachNgoai::~SachNgoai()
{
}
