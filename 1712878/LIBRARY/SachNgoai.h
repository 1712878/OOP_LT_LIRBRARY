#ifndef __SACH_NGOAI_H__
#define __SACH_NGOAI_H__

#include "Sach.h"
class SachNgoai : public Sach
{
private: 
	string ISBN;
public:
	virtual void Nhap();
	virtual void Xuat();
	virtual void SetDuLieu(vector <string> DL);
	virtual void SuaSach();
	virtual int GetTienPhat();
	virtual string toString();
};

#endif // !__SACH_NGOAI_H__