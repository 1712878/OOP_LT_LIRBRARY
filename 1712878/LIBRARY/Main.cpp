#include "MyDate.h"
#include "ThuVien.h"
#include <iostream>

using namespace std;

int main()
{
	ThuVien t;
	t.DocFile();
	MyDate date;
	cout << "Nhap ngay hom nay(dd/mm/yyyy): ";
	cin >> date;
	t.SetNgayHomNay(date);
	t.XuatDSSach();
	//t.ThemSach();
	//t.XoaSach();
	//t.SuaSach();
	//t.TimKiemSach();
	//t.XuatDSSach();

	t.XuatDSDocGia();
	//t.ThemDocGia();
	//t.XoaDocGia();
	//t.SuaDocGia();
	//t.TimKiemDocGia();
	//t.XuatDSDocGia();
	t.XuatDSPhieuMuon();
	t.TraPhieu();
	//t.XuatDSPhieuMuon();
	system("pause");
	return 0;
}