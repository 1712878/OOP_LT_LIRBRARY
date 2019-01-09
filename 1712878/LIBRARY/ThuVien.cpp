#include "ThuVien.h"

ThuVien::ThuVien()
{
}

void ThuVien::DocFile()
{
	fstream fp;
	string s;
	

	fp.open("..//FILE//Sach.csv", ios::in);
	getline(fp, s);
	while (!fp.eof())
	{
		Sach* a;
		vector <string> kq;
		getline(fp, s);
		TachToken(kq, s);
		if (kq.size() == 5)
			a = new SachViet;
		else
			a = new SachNgoai;
		a->SetDuLieu(kq);
		dsSach.push_back(a);
	}
	fp.close(); 

	fp.open("..//FILE//DocGia.csv", ios::in);
	getline(fp, s);
	DocGia dg;
	while (!fp.eof())
	{
		vector <string> kq;
		getline(fp, s);
		TachToken(kq, s);
		dg.SetDuLieu(kq);
		dsDocGia.push_back(dg);
	}
	fp.close();

	fp.open("..//FILE//PhieuMuon.csv", ios::in);
	getline(fp, s);
	PhieuMuon pm;
	while (!fp.eof())
	{
		vector <string> kq;
		getline(fp, s);
		TachToken(kq, s);
		pm.SetDuLieu(kq);
		dsPhieuMuon.push_back(pm);
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
}


void ThuVien::ThemSach()
{
	int choice;
	do
	{
		cout << "1. Sach Viet\n2. Sach ngoai\n";
		cin >> choice;
		cout << "Chon loai sach: ";
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
		cout << "Da xoa sach co ma " << s << endl;
		cout << "Dach sach Sach sau khi xoa: \n";
		dsSach.erase(dsSach.begin() + flag);
		XuatDSSach();
	}
}
void ThuVien::SuaSach()
{
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