#include "MyDate.h"
#include "ThuVien.h"
#include <iostream>

using namespace std;

int main()
{
	ThuVien t;
	t.DocFile();
	//t.XuatDSSach();
	//t.ThemSach();
	//t.XoaSach();
	//t.SuaSach();
	//t.TimKiemSach();
	//t.XuatDSSach();

	t.XuatDSDocGia();
	//t.ThemDocGia();
	//t.XoaDocGia();
	//t.SuaDocGia();
	t.TimKiemDocGia();
	//t.XuatDSDocGia();
	system("pause");
	return 0;
}