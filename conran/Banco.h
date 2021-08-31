#pragma once
#include "Hcn.h"
#include "Ran.h"
#include "Moi.h"
class Banco
{
public:
	int diem;
	int dk;
	Ran ran;
	Hcn dv;
	Moi moi;
	int huong;
	Banco();
	void vehinh(CClientDC* pdc);
	void hienthimoi();
	void capnhathinh(CClientDC* pdc);
	void batdau();
	void ranchuyendong();
	int kiemtrabien();

};

