#include "IO.h"
#include "ThuVien.h"
#include <iostream>
using namespace std;

int main()
{
	MyDate date("14/1/2019");
	int Lenh;
	ThuVien tv;
	tv.SetNgay(date);
	tv.DocFile();
	do
	{
		Menu();
		Lenh = Chon();
		XuLy(tv, Lenh);
	} while (Lenh != 0);

	string s;
	cout << "Ban co muon luu lai cac thay doi (Y/N): ";
	getline(cin >> ws, s);
	if (s == "y" || s == "Y" || s == "YES" || s == "yes")
		tv.XuatFile();
	system("pause");
	return 0;
}