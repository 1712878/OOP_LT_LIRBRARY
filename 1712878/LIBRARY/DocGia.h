#ifndef __DOC_GIA_H__
#define __DOC_GIA_H__
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class DocGia
{
private:
	string CMND, HoTen, SDT, NgheNghiep, DiaChi;
public:
	DocGia();
	void Nhap();
	void Xuat();
	void SetDuLieu(vector <string> DL);
	string GetCMND();
	void SuaDocGia();
	bool TimKiem(string s);
	string GetHoTen();
	string GetSDT();
	string toString();
	~DocGia();
};

#endif // !__DOCGIA_H__