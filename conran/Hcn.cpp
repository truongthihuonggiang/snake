#include "pch.h"
#include "Hcn.h"

Hcn::Hcn()
{
	x1 = 0;
	y1 = 0;
	x2 = 0;
	y2 = 0;
}

Hcn::Hcn(int mx1, int my1, int mx2, int my2)
{
	x1 = mx1;
	y1 = my1;
	x2 = mx2;
	y2 = my2;
}

void Hcn::vehinh(CClientDC* pdc)
{
	pdc->Rectangle(x1, y1, x2, y2);
}

int Hcn::kttronghinh(CPoint p)
{
	if (p.x > x1 && p.x <x2 && p.y > y1 && p.y < y2)
		return 1;
	else
		return 0;
}

void Hcn::setX1Y1(int mx1, int my1)
{
	x1 = mx1;
	y1 = my1;
}

void Hcn::setX2Y2(int mx2, int my2)
{
	x2 = mx2;
	y2 = my2;
}
