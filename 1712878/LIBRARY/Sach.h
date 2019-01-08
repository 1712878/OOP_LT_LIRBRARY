#ifndef __SACH_H__
#define __SACH_H__

#include <iostream>
#include <string>
using namespace std;
class Sach
{
protected:
	string MaSach, TenSach, TacGia, NhaXuatBan;
	float Gia;
public:
	Sach();
	void Nhap();
	void Xuat();
	bool TimSach(string ma);
	void SuaSach(string ma);
	~Sach();
};

#endif // !__SACH_H__