#ifndef __SACH_H__
#define __SACH_H__

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
#define pSachViet 10000
#define pSachNgoai 20000

class Sach
{
protected:
	string MaSach, TenSach, TacGia, NhaXuatBan;
	float Gia;
public:
	virtual void Nhap();
	virtual void Xuat();
	virtual void SetDuLieu(vector <string> DL);
	string GetMaSach();
	virtual void SuaSach();
	bool TimKiem(string s);
	virtual int GetTienPhat() = 0;
	string GetTenSach();
	string GetTacGia();
	virtual string toString();
};

#endif // !__SACH_H__