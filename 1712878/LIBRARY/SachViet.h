#ifndef __SACH_VIET_H__
#define __SACH_VIET_H__

#include "Sach.h"
class SachViet :public Sach
{
public:
	virtual void Xuat();
	virtual int GetTienPhat();
	virtual string toString();
};

#endif // !__SACH_VIET_H__