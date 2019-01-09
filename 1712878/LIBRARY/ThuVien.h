#ifndef __THU_VIEN_H__
#define __THU_VIEN_H__

#include "Sach.h"
#include "SachViet.h"
#include "SachNgoai.h"
#include "DocGia.h"
#include "PhieuMuon.h"
#include <vector>
#include <fstream>

class ThuVien
{
private: 
	vector <Sach*> dsSach;
	vector <DocGia> dsDocGia;
	vector <PhieuMuon> dsPhieuMuon;
public:
	ThuVien();
	void DocFile();
	void XuatDSSach();
	void XuatDSDocGia();
	void XuatDSPhieuMuon();
	void ThemSach();
	void XoaSach();
	void SuaSach();
	void TimKiemSach();
	void ThemDocGia();
	void XoaDocGia();
	void SuaDocGia();
	void TimKiemDocGia();
	~ThuVien();
};
int GetToKen(string & token, string s, int &startPos);
int TachToken(vector<string>& arrToken, string s);
#endif // !__THUVIEN_H__