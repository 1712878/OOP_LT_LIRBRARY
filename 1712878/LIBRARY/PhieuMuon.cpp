#include "PhieuMuon.h"



PhieuMuon::PhieuMuon()
{
}

void PhieuMuon::Xuat()
{
	cout << this->CMND << "\t" << this->MaSach << "\t" << this->NgayMuon
		<< "\t" << this->NgayHetHan << "\t" << this->TinhTrang << endl;
}

void PhieuMuon::TaoPhieu()
{
	cout << "Nhap CMND: ";
	getline(cin >> ws, this->CMND);
	cout << "Nhap Ma Sach: ";
	getline(cin >> ws, this->MaSach);
	cout << "Nhap Ngay Muon: ";
	cin >> NgayMuon;
	NgayHetHan = NgayMuon + 7;
	TinhTrang = false;
}

void PhieuMuon::XuatPhieu()
{
	/*DocGia a;
	cout << "Thong tin nguoi muon: \n";
	a.Xuat();
	Sach b; 
	cout << "Thong tin sach muon: \n";
	b.Xuat();*/
	cout << "Ban duoc phep muon tu ngay: " << this->NgayMuon << "(" << this->NgayMuon.DayOfWeek() << "), den ngay: "
		<< this->NgayHetHan << "( " << this->NgayHetHan.DayOfWeek() << ")\n";
}

void PhieuMuon::TraPhieu()
{
	cout << "Nhap ngay tra sach: ";
	cin >> NgayTra;
	TinhTrang = true;
}

void PhieuMuon::SetDuLieu(vector<string> DL)
{
	int i = 0;
	this->CMND = DL[i++];
	this->MaSach = DL[i++];
	this->NgayMuon = DL[i++];
	this->NgayHetHan = DL[i++];
	this->TinhTrang = stoi(DL[i++]);
}

PhieuMuon::~PhieuMuon()
{
}
