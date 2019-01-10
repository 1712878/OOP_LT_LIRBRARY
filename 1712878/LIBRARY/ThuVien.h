#ifndef __THU_VIEN_H__
#define __THU_VIEN_H__

#include "SachViet.h"
#include "SachNgoai.h"
#include "DocGia.h"
#include "PhieuMuon.h"
#include "MyDate.h"
#include <vector>
#include <fstream>

class ThuVien
{
private: 
	MyDate NgayHomNay;
	vector <Sach*> dsSach;
	vector <DocGia> dsDocGia;
	vector <PhieuMuon> dsPhieuMuon;
public:

	void SetNgayHomNay(MyDate date);
	void DocFile();
	void XuatDSSach();
	void XuatDSDocGia();
	void XuatDSPhieuMuon();

	void ThemSach();
	void XoaSach();
	void SuaSach();
	void TimKiemSach();
	Sach* TimKiemSach(string maSach);

	void ThemDocGia();
	void XoaDocGia();
	void SuaDocGia();
	void TimKiemDocGia();
	DocGia* TimKiemDocGia(string cmnd);

	void TaoPhieu();
	void TraPhieu();
	void XuatPhieu(PhieuMuon phieuMuon);

	void LietKeDSQuaHan();
	void XuatFile();
};
// 2 ham nay trong sach KTLT thay Thu
int GetToKen(string & token, string s, int &startPos);
int TachToken(vector<string>& arrToken, string s);

#endif // !__THUVIEN_H__