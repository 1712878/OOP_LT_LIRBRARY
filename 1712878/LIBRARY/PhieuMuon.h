#ifndef __PHIEU_MUON_H__
#define __PHIEU_MUON_H__

#include "MyDate.h"
#include "Sach.h"
#include "DocGia.h"
class PhieuMuon
{
private:
	string CMND, MaSach;
	MyDate NgayMuon, NgayHetHan, NgayTra;
	bool TinhTrang;
public:
	PhieuMuon();
	void Xuat();
	void TaoPhieu();
	void XuatPhieu();
	void TraPhieu();
	void SetDuLieu(vector <string> DL);
	~PhieuMuon();
};

#endif // !_PHIEU_MUON_H__