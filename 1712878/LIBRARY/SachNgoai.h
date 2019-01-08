#ifndef __SACH_NGOAI_H__
#define __SACH_NGOAI_H__

#include "Sach.h"
class SachNgoai : public Sach
{
private: 
	string ISBN;
public:
	void Nhap();
	void Xuat();
	virtual void SetDuLieu(vector <string> DL);
	SachNgoai();
	~SachNgoai();
};

#endif // !__SACH_NGOAI_H__