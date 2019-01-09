#ifndef __SACH_H__
#define __SACH_H__

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
class Sach
{
protected:
	string MaSach, TenSach, TacGia, NhaXuatBan;
	float Gia;
public:
	Sach();
	virtual void Nhap();
	virtual void Xuat();
	string GetMaSach();
	virtual void SetDuLieu(vector <string> DL)
	{
		int i = 0;
		this->MaSach = DL[i++];
		this->TenSach = DL[i++];
		this->TacGia = DL[i++];
		this->NhaXuatBan = DL[i++];
		this->Gia = atoi(DL[i].c_str());
	}
	bool TimKiem(string ma);
	void Sua(string ma);
	~Sach();
};

#endif // !__SACH_H__