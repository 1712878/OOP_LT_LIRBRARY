#ifndef __PHIEU_MUON_H__
#define __PHIEU_MUON_H__

#include "MyDate.h"
#include "Sach.h"
#include "DocGia.h"
class PhieuMuon
{
private:
	string CMND, MaSach;
	MyDate NgayMuon, NgayHetHan;
	bool TinhTrang;
public:
	void Xuat();
	void SetCMND(string cmnd);
	string GetCMND();
	void SetMaSach(string maSach);
	string GetMaSach();
	void SetNgayMuon(MyDate ngayMuon);
	MyDate GetNgayMuon();
	void SetNgayHetHan(MyDate ngayHetHan);
	MyDate GetNgayHetHan();
	void SetTinhTrang(bool tinhTrang);
	bool GetTinhTrang();
	void SetDuLieu(vector <string> DL);
	string toString();
};

#endif // !_PHIEU_MUON_H__