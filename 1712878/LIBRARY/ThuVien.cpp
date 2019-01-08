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
	DocGia a;
	while (!fp.eof())
	{
		vector <string> kq;
		getline(fp, s);
		TachToken(kq, s);
		a.SetDuLieu(kq);
		dsDocGia.push_back(a);
	}
	fp.close();

}

void ThuVien::Xuat()
{
	for (int i = 0; i < dsSach.size(); i++)
		dsSach[i]->Xuat();
	for (int i = 0; i < dsDocGia.size(); i++)
		dsDocGia[i].Xuat();
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