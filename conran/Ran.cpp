#include "pch.h"
#include "Ran.h"

Ran::Ran()
{
	thietlap(0, 0);
	
}

Ran::Ran(int mx, int my)
{
	thietlap(mx, my);

}

void Ran::vehinh(CClientDC* pdc)
{
	dau.vehinh(pdc);
	int i = 0;
	for (i = 0; i < n; i++)
		ds[i].vehinh(pdc);
}

void Ran::thietlap(int mx, int my)
{
	dau.x1 = mx;
	dau.y1 = my;
	dau.x2 = dau.x1 + D;
	dau.y2 = dau.y1 + D;
	n = 1;
	them = 0;
	ds[0].setX1Y1((dau.x1 ), dau.y2);
	ds[0].setX2Y2((dau.x2 ), dau.y2 + D);
}

int Ran::chamdauran( Hinh* hinh)
{
	if (dau.chamhinh(hinh))
		return 1;
	else
		return 0;
}

int Ran::chamthanran( Hinh* hinh)
{
	
	for (int i = 0; i < n; i++)
	{
		if (ds[i].chamhinh(hinh) == 1)
			return 1;
	}
	return 0;
}

void Ran::dichuyenlen()
{
	doicho();
	dau.dichlen(D);
}

void Ran::dichuyentrai()
{
	doicho();
	dau.dichtrai(D);
}

void Ran::dichuyenxuong()
{
	doicho();
	dau.dichxuong(D);
}

void Ran::dichuyenphai()
{
	doicho();
	dau.dichphai(D);
}

void Ran::doicho()
{
	if (them == 1 && n < 100)
	{
		n++;
		them = 0;
	}
	
	for (int i = n-1; i >=0; i--)
	{
		ds[i].x1 = ds[i - 1].x1;
		ds[i].y1 = ds[i - 1].y1;
		ds[i].x2 = ds[i - 1].x2;
		ds[i].y2 = ds[i - 1].y2;
		ds[i].capnhattam();
	}
	ds[0].x1 = dau.x1;
	ds[0].x2 = dau.x2;
	ds[0].y1 = dau.y1;
	ds[0].y2 = dau.y2;
	ds[0].capnhattam();
}

int Ran::anmoi(Moi moi)
{
	if (dau.chamhinh(&moi) == 1)
	{
		them = 1;
		return 1;
	}
	else
		return 0;
}

int Ran::dungthan()
{
	int mx = (dau.x1 + dau.x2) / 2;
	int my = (dau.y1 + dau.y2) / 2;
	CPoint p = CPoint(mx, my);
	for (int i = 1; i < n; i++)
	{
		if (ds[i].kttronghinh(p) == 1)
			return 1;
	}
	return 0;
}
