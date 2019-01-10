#include "IO.h"

void XuLy(ThuVien &tv)
{
	system("cls");
	cout << "0. Thoat\n";
	cout << "1. Sach\n";
	cout << "2. Doc Gia\n";
	cout << "3. Muon - Tra Sach\n";
	cout << "4. Liet Ke DS qua han\n";
	int chon;
	do
	{
		cout << "Moi ban chon: ";
		cin >> chon;
	} while (chon < 0 || chon > 4);

	switch (chon)
	{
	case 0:
		break;
	case 1:
		XuLySach(tv);
		break;
	case 2:
		XuLyDocGia(tv);
		break;
	case 3:
		XuLyMuonTra(tv);
		break;
	case 4:
		XuLyQuaHan(tv);
		break;
	}
}

void XuLySach(ThuVien &tv)
{
	system("cls");
	cout << "0. Back\n";
	cout << "1. Xem DS Sach\n";
	cout << "2. Them Sach\n";
	cout << "3. Xoa Sach theo MaSach\n";
	cout << "4. Sua Sach theo MaSach\n";
	cout << "5. Tim Kiem Sach\n";

	int chon;
	do
	{
		cout << "Moi chon: ";
		cin >> chon;
	} while (chon < 0 || chon > 5);
	switch (chon) {
	case 0:
		XuLy(tv);
		break;
	case 1:
		system("cls");
		tv.XuatDSSach();
		break;
	case 2:
		system("cls");
		tv.ThemSach();
		break;
	case 3:
		system("cls");
		tv.XoaSach();
		break;
	case 4:
		system("cls");
		tv.SuaSach();
		break;
	case 5:
		system("cls");
		tv.TimKiemSach();
		break;
	}

	char ch;
	cout << "\nNhan phim 'y' de tiep tuc, phim bat ki de tro ve Menu chinh: ";
	cin >> ch;
	if (ch == 'y' || ch == 'Y')
		XuLySach(tv);
	else
		XuLy(tv);
}

void XuLyDocGia(ThuVien &tv)
{
	system("cls");
	cout << "0. Back\n";
	cout << "1. Xem DS Doc Gia\n";
	cout << "2. Them Doc Gia\n";
	cout << "3. Xoa Doc Gia theo CMND\n";
	cout << "4. Sua Doc Gia theo CMND\n";
	cout << "5. Tim Doc Gia\n";

	int chon;
	do
	{
		cout << "Moi chon: ";
		cin >> chon;
	} while (chon < 0 || chon > 5);
	switch (chon) {
	case 0:
		XuLy(tv);
		break; 
	case 1:
		system("cls");
		tv.XuatDSDocGia();
		break;
	case 2:
		system("cls");
		tv.ThemDocGia();
		break;
	case 3:
		system("cls");
		tv.XoaDocGia();
		break;
	case 4:
		system("cls");
		tv.SuaDocGia();
		break;
	case 5:
		system("cls");
		tv.TimKiemDocGia();
		break;
	}

	char ch;
	cout << "\nNhan phim 'y' de tiep tuc, phim bat ki de tro ve Menu chinh: ";
	cin >> ch;
	if (ch == 'y' || ch == 'Y')
		XuLyDocGia(tv);
	else
		XuLy(tv);
}

void XuLyMuonTra(ThuVien &tv)
{
	system("cls");
	cout << "0. Back\n";
	cout << "1. Xem Danh Sach Phieu Muon\n";
	cout << "2. Tao Phieu Muon Sach Bang CMND Va MaSach\n";
	cout << "3. Tra Phieu Muon Sach Bang CMND\n";

	int chon;
	do
	{
		cout << "Moi chon: ";
		cin >> chon;
	} while (chon < 0 || chon > 3);
	switch (chon) {
	case 0:
		XuLy(tv);
		break;
	case 1:
		system("cls");
		tv.XuatDSPhieuMuon();
		break;
	case 2:
		system("cls");
		tv.TaoPhieu();
		break;
	case 3:
		system("cls");
		tv.TraPhieu();
		break;
	}

	char ch;
	cout << "\nNhan phim 'y' de tiep tuc, phim bat ki de tro ve Menu chinh: ";
	cin >> ch;
	if (ch == 'y' || ch == 'Y')
		XuLyMuonTra(tv);
	else
		XuLy(tv);
}

void XuLyQuaHan(ThuVien &tv)
{
	system("cls");
	cout << "0. Back\n";
	cout << "1. Xem DS Qua Han\n";
	cout << "2. Thay Doi Ngay Can Xet\n";

	int chon;
	do
	{
		cout << "Moi chon: ";
		cin >> chon;
	} while (chon < 0 || chon > 2);
	switch (chon) {
	case 0:
		XuLy(tv);
		break;
	case 1:
		system("cls");
		tv.LietKeDSQuaHan();
		break;
	case 2:
		system("cls");
		MyDate date;
		cout << "Nhap ngay can xet(dd/mm/yyyy): ";
		cin >> date;
		tv.SetNgay(date);
		cout << "Thay doi ngay thanh cong! ";
		break;
	}

	char ch;
	cout << "Nhan phim 'y' de tiep tuc, phim bat ki de tro ve Menu chinh: ";
	cin >> ch;
	if (ch == 'y' || ch == 'Y')
		XuLyQuaHan(tv);
	else
		XuLy(tv);
}