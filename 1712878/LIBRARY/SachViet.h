#ifndef __SACH_VIET_H__
#define __SACH_VIET_H__

#include "Sach.h"
class SachViet :public Sach
{
public:
	SachViet();
	virtual void Xuat();
	virtual string toString();
	~SachViet();
};

#endif // !__SACH_VIET_H__