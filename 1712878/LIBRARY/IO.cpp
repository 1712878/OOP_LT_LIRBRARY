#include "IO.h"

void Menu()
{
	system("cls");
	cout << "0. Thoat\n";
	cout << "1. Sach\n";
	cout << "2. Doc Gia\n";
	cout << "3. Muon - Tra Sach\n";
	cout << "4. Liet Ke DS qua han\n";
}
int Chon()
{
	int chon;
	do
	{
		cout << "Moi ban chon: ";
		cin >> chon;
	} while (chon < 0 || chon > 4);
	return chon;
}
void XuLy(ThuVien &tv, int Lenh)
{
	switch (Lenh)
	{
	case 1:
		tv.XuLySach();
		break;
	case 2:
		tv.XuLyDocGia();
		break;
	case 3:
		tv.XuLyMuonTra();
		break;
	case 4:
		tv.XuLyQuaHan();
		break;
	}
}