#include "ThuVien.h"

ThuVien::ThuVien()
{
}

void ThuVien::SetNgayHomNay(MyDate date)
{
	this->NgayHomNay = date;
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
	cout << left << setw(10) << "MA SACH" << setw(30) << "TEN SACH" << setw(20) << "TAC GIA"
		<< setw(20) << "NHA XUAT BAN" << setw(10) << "GIA" << setw(10) << "ISBN" << endl;
	for (int i = 0; i < dsSach.size(); i++)
		dsSach[i]->Xuat();
}

void ThuVien::XuatDSDocGia()
{
	cout << left << setw(15) << "CMND" << setw(25) << "HO TEN" << setw(20) << "SDT"
		<< setw(20) << "NGHE NGHIEP" << setw(10) << "DIA CHI" << endl;
	for (int i = 0; i < dsDocGia.size(); i++)
		dsDocGia[i].Xuat();
}

void ThuVien::XuatDSPhieuMuon()
{
	for (auto a : dsPhieuMuon)
		a.Xuat();
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

DocGia* ThuVien::TimDocGiaBangCMND(string cmnd)
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

Sach* ThuVien::TimSachBangMaSach(string maSach)
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
		docGia = TimDocGiaBangCMND(s);
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
		sach = TimSachBangMaSach(s);
		if (sach != NULL)
			break;
		else
			cout << "Ma Sach khong ton tai, vui long nhap lai.";
	} while (1);
	phieuMuon.SetMaSach(s);
	phieuMuon.SetNgayMuon(this->NgayHomNay);
	phieuMuon.SetNgayHetHan(this->NgayHomNay + 7);
	phieuMuon.SetTinhTrang(false);
	dsPhieuMuon.push_back(phieuMuon);
	cout << "\nTao phieu muon thanh cong!\n";
	XuatPhieu(phieuMuon);
}

void ThuVien::XuatPhieu(PhieuMuon phieuMuon)
{
	DocGia* docGia = TimDocGiaBangCMND(phieuMuon.GetCMND());
	Sach* sach = TimSachBangMaSach(phieuMuon.GetMaSach());
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
		cout << "Da tra ngay " << this->NgayHomNay << endl;
		int nDay = this->NgayHomNay - phieuMuon.GetNgayHetHan();
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

void ThuVien::LietKeDSQuaHan()
{
	int n = 0;
	for (int i = 0; i < dsPhieuMuon.size(); i++)
	{
		if (dsPhieuMuon[i].GetTinhTrang() == false)
		{
			int nDay = this->NgayHomNay - dsPhieuMuon[i].GetNgayHetHan();
			if (nDay > 0)
			{
				n++;
				DocGia* docGia = TimDocGiaBangCMND(dsPhieuMuon[i].GetCMND());
				Sach* sach = TimSachBangMaSach(dsPhieuMuon[i].GetMaSach());
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
		fp << "CMND,Ho Ten,SDT,NGHE NGHIEP,DIA CHI\n";
		for (auto a : dsDocGia)
			fp << a.toString();
		fp.close();
	}

	{
		fp.open("FILE//PhieuMuon.csv", ios::out);
		fp << "CMND,Ho Ten,SDT,NGHE NGHIEP,DIA CHI\n";
		for (auto a : dsPhieuMuon)
			fp << a.toString();
		fp.close();
	}
}

ThuVien::~ThuVien()
{
}
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