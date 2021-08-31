#pragma once
#include "Hcn.h"
#include "Hinhtron.h"
#include "Moi.h"
#define D  30
class Ran
{
public:
	Hcn dau;
	Hinhtron ds[100];
	int them;
	int n;
	Ran();
	Ran(int mx, int my);
	void vehinh(CClientDC* pdc);
	void thietlap(int mx, int my);
	int chamdauran( Hinh* hinh);
	int chamthanran( Hinh* hinh);
	void dichuyenlen();
	void dichuyentrai();
	void dichuyenxuong();
	void dichuyenphai();
	void doicho();
	int anmoi(Moi moi);
	int dungthan();
};

