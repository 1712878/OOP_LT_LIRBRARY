#include "MyDate.h"
#include "ThuVien.h"
#include <iostream>

using namespace std;

int main()
{
	ThuVien t;
	t.DocFile();
	t.Xuat();
	PhieuMuon a;
	a.TaoPhieu();
	//a.TraPhieu();
	a.XuatPhieu();
	system("pause");
	return 0;
}