#include "PhieuMuon.h"



PhieuMuon::PhieuMuon()
{
}

void PhieuMuon::Xuat()
{
	cout << this->CMND << "\t" << this->MaSach << "\t" << this->NgayMuon
		<< "\t" << this->NgayHetHan << "\t" << this->TinhTrang << endl;
}

void PhieuMuon::SetCMND(string cmnd)
{
	this->CMND = cmnd;
}

string PhieuMuon::GetCMND()
{
	return this->CMND;
}

void PhieuMuon::SetMaSach(string maSach)
{
	this->MaSach = maSach;
}

string PhieuMuon::GetMaSach()
{
	return this->MaSach;
}

void PhieuMuon::SetNgayMuon(MyDate ngayMuon)
{
	this->NgayMuon = ngayMuon;
}

MyDate PhieuMuon::GetNgayMuon()
{
	return this->NgayMuon;
}

void PhieuMuon::SetNgayHetHan(MyDate ngayHetHan)
{
	this->NgayHetHan = ngayHetHan;
}

MyDate PhieuMuon::GetNgayHetHan()
{
	return this->NgayHetHan;
}

void PhieuMuon::SetTinhTrang(bool tinhTrang)
{
	this->TinhTrang = tinhTrang;
}

bool PhieuMuon::GetTinhTrang()
{
	return this->TinhTrang;
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
	DocGia a;
	cout << "Thong tin nguoi muon: \n";
	a.TimKiem(CMND);
	a.Xuat();
	Sach b; 
	cout << "Thong tin sach muon: \n";
	b.Xuat();
	cout << "Ban duoc phep muon tu ngay: " << this->NgayMuon << "(" << this->NgayMuon.DayOfWeek() << "), den ngay: "
		<< this->NgayHetHan << "( " << this->NgayHetHan.DayOfWeek() << ")\n";
}

void PhieuMuon::TraPhieu()
{
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
