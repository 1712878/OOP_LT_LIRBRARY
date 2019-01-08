#include "PhieuMuon.h"



PhieuMuon::PhieuMuon()
{
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



PhieuMuon::~PhieuMuon()
{
}
