#include "PhieuMuon.h"

void PhieuMuon::Xuat()
{
	cout << left << setw(15) << this->CMND << setw(15) << this->MaSach << "\t" << this->NgayMuon
		<< "\t" << this->NgayHetHan << "\t"; 
	if (this->TinhTrang)
		cout << "Da tra\n";
	else
		cout << "Dang muon\n";
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

void PhieuMuon::SetDuLieu(vector<string> DL)
{
	int i = 0;
	this->CMND = DL[i++];
	this->MaSach = DL[i++];
	this->NgayMuon = DL[i++];
	this->NgayHetHan = DL[i++];
	this->TinhTrang = stoi(DL[i++]);
}

string PhieuMuon::toString()
{
	return this->CMND + "," + this->MaSach + "," + this->NgayMuon.toString() + "," +
		this->NgayHetHan.toString() + "," + to_string(this->TinhTrang) + "\n";
}