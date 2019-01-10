#include "IO.h"
#include "ThuVien.h"

int main()
{
	MyDate date;
	cout << "Khong tat ngang chuong trinh se mat du lieu!!\n";
	cout << "Nhap vao ngay hom nay(dd/mm/yyyy): ";
	cin >> date;
	ThuVien tv;
	tv.SetNgay(date);
	tv.DocFile();

	int lc = 0;
	do {
		lc = XuLy(tv);
	} while (lc != 0);

	string s;
	cout << "Ban co muon luu lai cac thay doi (Y/N): ";
	getline(cin >> ws, s);
	if (s == "Y" || s == "y" || s == "YES" || s == "yes")
		tv.XuatFile();

	system("pause");
	return 0;
}