#ifndef __DOC_GIA_H__
#define __DOC_GIA_H__
#include <iostream>
#include <string>
#include <vector>
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
	void TimKiem(string s);
	void Sua(string s);
	~DocGia();
};

#endif // !__DOCGIA_H__