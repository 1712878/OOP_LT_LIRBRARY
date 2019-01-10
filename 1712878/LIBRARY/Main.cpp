#include "MyDate.h"
#include "ThuVien.h"
#include <iostream>

using namespace std;

int main()
{
	ThuVien t;
	t.DocFile();
	MyDate date("12/1/2019");
	//cout << "Nhap ngay hom nay(dd/mm/yyyy): ";
	//cin >> date;
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
	//t.TraPhieu();
	//t.XuatDSPhieuMuon();
	t.LietKeDSQuaHan();
	t.XuatFile();

	system("pause");
	return 0;
}