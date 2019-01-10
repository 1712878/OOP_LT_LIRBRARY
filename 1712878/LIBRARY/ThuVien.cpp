#include "ThuVien.h"

void ThuVien::SetNgay(MyDate date)
{
	this->Ngay = date;
}

void ThuVien::DocFile()
{
	fstream fp;
	string s;
	
	fp.open("FILE//Sach.csv", ios::in);
	getline(fp, s);
	while (getline(fp, s))
	{
		Sach* a;
		vector <string> kq;
		TachToken(kq, s);
		if (kq.size() == 5)
			a = new SachViet;
		else
			a = new SachNgoai;
		a->SetDuLieu(kq);
		dsSach.push_back(a);
	}
	fp.close(); 

	fp.open("FILE//DocGia.csv", ios::in);
	getline(fp, s);
	DocGia docGia;
	while (getline(fp, s))
	{
		vector <string> kq;
		TachToken(kq, s);
		docGia.SetDuLieu(kq);
		dsDocGia.push_back(docGia);
	}
	fp.close();

	fp.open("FILE//PhieuMuon.csv", ios::in);
	getline(fp, s);
	PhieuMuon phieuMuon;
	while (getline(fp, s))
	{
		vector <string> kq;
		TachToken(kq, s);
		phieuMuon.SetDuLieu(kq);
		dsPhieuMuon.push_back(phieuMuon);
	}
	fp.close();
}

void ThuVien::XuatDSSach()
{
	cout << left << setw(5) << "STT" << setw(10) << "MA SACH" << setw(30) << "TEN SACH" << setw(20) << "TAC GIA"
		<< setw(20) << "NHA XUAT BAN" << setw(10) << "GIA" << setw(10) << "ISBN" << endl;
	int size = dsSach.size();
	for (int i = 0; i < size; i++)
	{
		cout << setw(5) << i + 1;
		dsSach[i]->Xuat();
	}
}

void ThuVien::XuatDSDocGia()
{
	cout << left << setw(5) << "STT" << setw(15) << "CMND" << setw(25) << "HO TEN" << setw(20) << "SDT"
		<< setw(20) << "NGHE NGHIEP" << setw(10) << "DIA CHI" << endl;
	int size = dsDocGia.size();
	for (int i = 0; i < size; i++)
	{
		cout << setw(5) << i + 1;
		dsDocGia[i].Xuat();
	}
}

void ThuVien::XuatDSPhieuMuon()
{
	cout << left << setw(5) << "STT" << setw(15) << "CMND" << setw(15) << "MASACH" << "\t" << "NGAYMUON"
		<< "\t" << "NGAYHH" << "\t\t" << "TINHTRANG" << endl;
	int size = dsPhieuMuon.size();
	for (int i = 0; i < size; i++)
	{
		cout << setw(5) << i + 1;
		dsPhieuMuon[i].Xuat();
	}
}

//1. Sach
void ThuVien::ThemSach()
{
	int choice;
	do
	{
		cout << "1. Sach Viet\n2. Sach ngoai\n";
		cout << "Chon loai sach: ";
		cin >> choice;
	} while (choice < 1 || choice >2);

	Sach* sach = NULL;
	switch (choice)
	{
	case 1:
		sach = new SachViet();
		break;
	case 2:
		sach = new SachNgoai();
		break;
	}
	sach->Nhap();
	dsSach.push_back(sach);
}

void ThuVien::XoaSach()
{
	int size = dsSach.size();
	if (size < 1) {
		cout << "Ban phai nhap danh sach sach truoc!\n";
		return;
	}
	string s;
	cout << "Nhap MaSach ban muon xoa: ";
	getline(cin >> ws, s);
	int flag = -1;
	for (int i = 0; i < size; i++)
	{
		if (dsSach[i]->GetMaSach() ==s)
		{
			flag = i; // Ma sach la duy nhat nen chi can tim kiem duoc la thoat!
			break;
		}
	}
	if (flag == -1)
		cout << "Khong tim thay ma sach nay!\n";
	else
	{ 
		dsSach.erase(dsSach.begin() + flag);
		cout << "Da xoa sach co ma " << s << endl;
	}
}

void ThuVien::SuaSach()
{
	int size = dsSach.size();
	if (size < 1) {
		cout << "Ban phai nhap danh sach sach truoc!\n";
		return;
	}
	string s;
	cout << "Nhap MaSach ban muon sua: ";
	getline(cin >> ws, s);
	int flag = -1;
	for (int i = 0; i < size; i++)
	{
		if (dsSach[i]->GetMaSach() == s)
		{
			flag = i; // Ma sach la duy nhat nen chi can tim kiem duoc la thoat!
			break;
		}
	}
	if (flag == -1)
		cout << "Khong tim thay ma sach nay!\n";
	else
	{
		dsSach[flag]->SuaSach();
	}
}

void ThuVien::TimKiemSach()
{
	int size = dsSach.size();
	if (size < 1) {
		cout << "Ban phai nhap danh sach sach truoc!\n";
		return;
	}
	string s;
	cout << "Nhap MaSach or TenSach or TacGia or NhaXuatBan: ";
	getline(cin >> ws, s);
	int flag = 0;
	for (int i = 0; i < size; i++)
	{
		if (dsSach[i]->TimKiem(s))
		{
			flag++;
			if (flag == 1)
				cout << left << setw(10) << "MA SACH" << setw(30) << "TEN SACH" << setw(20) << "TAC GIA"
				<< setw(20) << "NHA XUAT BAN" << setw(10) << "GIA" << setw(10) << "ISBN" << endl;
			dsSach[i]->Xuat();
		}
	}
	if (flag == 0)
		cout << "Khong tim thay noi dung ban nhap!\n";
}

Sach* ThuVien::TimKiemSach(string maSach)
{
	Sach* sach = NULL;
	int size = dsSach.size();
	for (int i = 0; i < size; i++)
	{
		if (dsSach[i]->GetMaSach() == maSach)
		{
			sach = dsSach[i];
			break;
		}
	}
	return  sach;
}


//2. Doc Gia
void ThuVien::ThemDocGia()
{
	DocGia docGia;
	docGia.Nhap();
	dsDocGia.push_back(docGia);
}

void ThuVien::XoaDocGia()
{
	int size = dsDocGia.size();
	if (size < 1) {
		cout << "Ban phai nhap danh sach Doc Gia truoc!\n";
		return;
	}
	string s;
	cout << "Nhap CMND cua Doc Gia ban muon xoa: ";
	getline(cin >> ws, s);
	int flag = -1;
	for (int i = 0; i < size; i++)
	{
		if (dsDocGia[i].GetCMND() == s)
		{
			flag = i; //CMND la duy nhat nen chi can tim kiem duoc la thoat!
			break;
		}
	}
	if (flag == -1)
		cout << "Khong tim thay CMND nay!\n";
	else
	{
		dsDocGia.erase(dsDocGia.begin() + flag);
		cout << "Da xoa Doc Gia co CMND " << s << endl;
	}
}

void ThuVien::SuaDocGia()
{
	int size = dsDocGia.size();
	if (size < 1) {
		cout << "Ban phai nhap danh sach Doc Gia truoc!\n";
		return;
	}
	string s;
	cout << "Nhap CMND cua Doc Gia ban muon sua: ";
	getline(cin >> ws, s);
	int flag = -1;
	for (int i = 0; i < size; i++)
	{
		if (dsDocGia[i].GetCMND() == s)
		{
			flag = i; // CMND la duy nhat nen chi can tim kiem duoc la thoat!
			break;
		}
	}
	if (flag == -1)
		cout << "Khong tim thay ma CMND nay!\n";
	else
	{
		dsDocGia[flag].SuaDocGia();
	}
}

void ThuVien::TimKiemDocGia()
{
	int size = dsDocGia.size();
	if (size < 1) {
		cout << "Ban phai nhap danh sach Doc Gia truoc!\n";
		return;
	}
	string s;
	cout << "Nhap CMND or HoTen or SDT or NgheNghiep or DiaChi: ";
	getline(cin >> ws, s);
	int flag = 0;
	for (int i = 0; i < size; i++)
	{
		if (dsDocGia[i].TimKiem(s))
		{
			flag++;
			if (flag == 1)
				cout << left << setw(15) << "CMND" << setw(25) << "HO TEN" << setw(20) << "SDT"
				<< setw(20) << "NGHE NGHIEP" << setw(10) << "DIA CHI" << endl;
			dsDocGia[i].Xuat();
		}
	}
	if (flag == 0)
		cout << "Khong tim thay noi dung ban nhap!\n";
}

DocGia* ThuVien::TimKiemDocGia(string cmnd)
{
	DocGia* docGia = NULL;
	int size = dsDocGia.size();
	for (int i=0; i< size; i++)
	{
		if (dsDocGia[i].GetCMND() == cmnd)
		{
			docGia = &dsDocGia[i];
			break;
		}
	}
	return  docGia;
}

//3. Phieu Muon
void ThuVien::TaoPhieu()
{
	PhieuMuon phieuMuon;
	string s;
	DocGia* docGia;
	Sach* sach;
	do
	{
		cout << "Nhap CMND: ";
		cin >> s;
		docGia = TimKiemDocGia(s);
		if (docGia != NULL)
			break;
		else
			cout << "CMND chua dang ki doc gia, vui long nhap lai.";
	} while (1);
	phieuMuon.SetCMND(s);

	do
	{
		cout << "Nhap Ma Sach: ";
		cin >> s;
		sach = TimKiemSach(s);
		if (sach != NULL)
			break;
		else
			cout << "Ma Sach khong ton tai, vui long nhap lai.";
	} while (1);
	phieuMuon.SetMaSach(s);
	phieuMuon.SetNgayMuon(this->Ngay);
	phieuMuon.SetNgayHetHan(this->Ngay + 7);
	phieuMuon.SetTinhTrang(false);
	dsPhieuMuon.push_back(phieuMuon);
	cout << "\nTao phieu muon thanh cong!\n";
	XuatPhieu(phieuMuon);
}

void ThuVien::TraPhieu()
{
	string s;
	cout << "Nhap CMND: ";
	getline(cin >> ws, s);
	PhieuMuon phieuMuon;
	for (int i = 0; i < dsPhieuMuon.size(); i++)
	{
		if (dsPhieuMuon[i].GetCMND() == s)
		{
			phieuMuon = dsPhieuMuon[i];
			phieuMuon.SetTinhTrang(true);
			XuatPhieu(phieuMuon);
		}
	}
}

void ThuVien::XuatPhieu(PhieuMuon phieuMuon)
{
	DocGia* docGia = TimKiemDocGia(phieuMuon.GetCMND());
	Sach* sach = TimKiemSach(phieuMuon.GetMaSach());
	cout << "\n-----------PHIEU MUON - TRA SACH--------------\n";
	cout << "\n==> Thong tin Doc Gia <==\n";
	cout << "CMND:     " << docGia->GetCMND() << endl;
	cout << "Ho Ten:   " << docGia->GetHoTen() << endl;
	cout << "SDT:      " << docGia->GetSDT() << endl;
	cout << "\n==> Thong tin Sach    <==\n";
	cout << "Ma Sach:  " << sach->GetMaSach() << endl;
	cout << "Ten Sach: " << sach->GetTenSach() << endl;
	cout << "Tac Gia:  " << sach->GetTacGia() << endl;
	cout << "\n==> Thong muon - tra  <==\n";
	cout << "Ngay muon:    " << phieuMuon.GetNgayMuon() << endl;
	cout << "Ngay het han: " << phieuMuon.GetNgayHetHan() << endl;
	cout << "Tinh trang:   ";
	if (phieuMuon.GetTinhTrang() == false)
		cout << "Dang muon\n";
	else
	{
		cout << "Da tra ngay " << this->Ngay << endl;
		int nDay = this->Ngay - phieuMuon.GetNgayHetHan();
		cout << "*** Ghi chu: ";
		if (nDay > 0)
		{
			int TienPhat = sach->GetTienPhat();
			cout << "so tien phat " << nDay << "(ngay) * " << TienPhat << "/ngay = " << nDay * TienPhat << endl;
		}
		else
			cout << "tra dung han\n";
	}
}

// 4. DS qua han
void ThuVien::LietKeDSQuaHan()
{
	int n = 0;
	int size = dsPhieuMuon.size();
	for (int i = 0; i < size; i++)
	{
		if (dsPhieuMuon[i].GetTinhTrang() == false)
		{
			int nDay = this->Ngay - dsPhieuMuon[i].GetNgayHetHan();
			if (nDay > 0)
			{
				n++;
				DocGia* docGia = TimKiemDocGia(dsPhieuMuon[i].GetCMND());
				Sach* sach = TimKiemSach(dsPhieuMuon[i].GetMaSach());
				if (n == 1)
				{
					cout << left << setw(5) << "STT" << setw(25) << "HOTEN" << setw(15) << "SDT"
						<< setw(25) << "TENSACH" << setw(23) << "TACGIA"
						<< setw(5) << "NGAY" << setw(13) << "TIEN/NGAY" << setw(15) << "TONG" << endl;
				}
				cout << left << setw(5) << n << setw(25) << docGia->GetHoTen() << setw(15) << docGia->GetSDT()
					<< setw(25) << sach->GetTenSach() << setw(25) << sach->GetTacGia()
					<< setw(5) << nDay << setw(10) << sach->GetTienPhat() << setw(15) << nDay*sach->GetTienPhat() << endl;
			}
		}
	}
}

void ThuVien::XuatFile()
{
	fstream fp;
	{
		fp.open("FILE//Sach.csv", ios::out);
		fp << "MA SACH,TEN SACH,TAC GIA,NXB,GIA SACH,ISBN\n";
		for (auto a : dsSach)
			fp << a->toString();
		fp.close();
	}
	
	{
		fp.open("FILE//DocGia.csv", ios::out);
		fp << "CMND,HO TEN,SDT,NGHE NGHIEP,DIA CHI\n";
		for (auto a : dsDocGia)
			fp << a.toString();
		fp.close();
	}

	{
		fp.open("FILE//PhieuMuon.csv", ios::out);
		fp << "CMND,MA SACH,NGAY MUON,NGAY HH,TINH TRANG\n";
		for (auto a : dsPhieuMuon)
			fp << a.toString();
		fp.close();
	}
}

//5. XuLy
void ThuVien::XuLySach()
{
	system("cls");
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
	} while (chon < 1 || chon > 5);
	switch (chon) {
	case 1:
		XuatDSSach();
		break;
	case 2:
		ThemSach();
		break;
	case 3:
		XoaSach();
		break;
	case 4:
		SuaSach();
		break;
	case 5:
		TimKiemSach();
		break;
	}
	char ch;
	cout << "Nhan phim 'y' de tiep tuc, phim bat ki de tro ve Menu chinh: ";
	cin >> ch;
	if (ch == 'y' || ch =='Y')
	{
		XuLySach();
	}
}

void ThuVien::XuLyDocGia()
{
	system("cls");
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
	} while (chon < 1 || chon > 4);
	switch (chon) {
	case 1:
		XuatDSDocGia();
		break;
	case 2:
		ThemDocGia();
		break;
	case 3:
		XoaDocGia();
		break;
	case 4:
		SuaDocGia();
		break;
	case 5:
		TimKiemDocGia();
		break;
	}
	char ch;
	cout << "Nhan phim 'y' de tiep tuc, phim bat ki de tro ve Menu chinh: ";
	cin >> ch;
	if (ch == 'y' || ch == 'Y')
	{
		XuLyDocGia();
	}
}

void ThuVien::XuLyMuonTra()
{
	system("cls");
	cout << "1. Xem DS Phieu Muon\n";
	cout << "2. Tao Phieu Muon Sach\n";
	cout << "3. Tra Phieu Muon Sach\n";
	int chon;
	do
	{
		cout << "Moi chon: ";
		cin >> chon;
	} while (chon < 1 || chon > 3);
	switch (chon) {
	case 1:
		XuatDSPhieuMuon();
		break;
	case 2:
		TaoPhieu();
		break;
	case 3:
		TraPhieu();
		break;
	}
	char ch;
	cout << "Nhan phim 'y' de tiep tuc, phim bat ki de tro ve Menu chinh: ";
	cin >> ch;
	if (ch == 'y' || ch == 'Y')
	{
		XuLyMuonTra();
	}
}

void ThuVien::XuLyQuaHan()
{
	system("cls");
	cout << "1. Xem DS Qua Han\n";
	cout << "2. Thay Doi Ngay Can Xet\n";
	int chon;
	do
	{
		cout << "Moi chon: ";
		cin >> chon;
	} while (chon < 1 || chon > 2);
	switch (chon) {
	case 1:
		cout << "Danh sach qua han ngay " << this->Ngay << " la: \n";
		LietKeDSQuaHan();
		break;
	case 2:
		MyDate date;
		cout << "Nhap ngay can xet(dd/mm/yyyy): ";
		cin >> date;
		SetNgay(date);
		cout << "Thay doi ngay thanh cong! ";
		break;
	}
	char ch;
	cout << "Nhan phim 'y' de tiep tuc, phim bat ki de tro ve Menu chinh: ";
	cin >> ch;
	if (ch == 'y' || ch == 'Y')
	{
		XuLyQuaHan();
	}
}

// 2 ham nay trong sach KTLT thay Thu
int GetToKen(string & token, string s, int &startPos)
{
	string sep = ",";
	int fromPos, toPos, length = s.length(), nTokenLength = 0;
	token = "";
	fromPos = s.find_first_not_of(sep, startPos);
	if (fromPos == string::npos)
		return nTokenLength;
	toPos = s.find_first_of(sep, fromPos);
	if (toPos == string::npos)
		toPos = length;
	nTokenLength = toPos - fromPos;
	token = s.substr(fromPos, nTokenLength);
	startPos = toPos;
	return nTokenLength;
}
int TachToken(vector<string>& arrToken, string s)
{
	string token;
	int nTokens = 0, startPos = 0;
	while (GetToKen(token, s, startPos) > 0)
	{
		arrToken.push_back(token);
		nTokens++;
	}
	return nTokens;
}