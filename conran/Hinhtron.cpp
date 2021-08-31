#include "pch.h"
#include "Hinhtron.h"

Hinhtron::Hinhtron()
{
    x1 = 0;
    x2 = 0;
    y1 = 0;
    y2 = 0;
    r = 0;
    o.x = 0;
    o.y = 0;
}

Hinhtron::Hinhtron(int mx1, int my1, int mx2, int my2)
{
    x1 = mx1;
    y1 = my1;
    x2 = mx2;
    y2 = my2;
    o.x = (x1 + x2) / 2;
    o.y = (y1 + y2) / 2;
    if (x2 - x1 < y2 - y1 && x2 > x1 && y2 > y1)
    {
        r = (x2 - x1) / 2;
    }
    if (x2 - x1 >= y2 - y1 && x2 > x1 && y2 > y1)
    {
        r = (y2 - y1) / 2;
    }

}

void Hinhtron::setX1Y1(int mx1, int my1)
{
    x1 = mx1;
    y1 = my1;
    o.x = (x1 + x2) / 2;
    o.y = (y1 + y2) / 2;
    if (x2 - x1 < y2 - y1 && x2 > x1 && y2 > y1)
    {
        r = (x2 - x1) / 2;
    }
    if (x2 - x1 >= y2 - y1 && x2 > x1 && y2 > y1)
    {
        r = (y2 - y1) / 2;
    }
}

void Hinhtron::setX2Y2(int mx2, int my2)
{
    x2 = mx2;
    y2 = my2;
    o.x = (x1 + x2) / 2;
    o.y = (y1 + y2) / 2;
    if (x2 - x1 < y2 - y1 && x2 > x1 && y2 > y1)
    {
        r = (x2 - x1) / 2;
    }
    if (x2 - x1 >= y2 - y1 && x2 > x1 && y2 > y1)
    {
        r = (y2 - y1) / 2;
    }
}

void Hinhtron::vehinh(CClientDC* pdc)
{
   
    pdc->Ellipse(o.x - r, o.y - r, o.x + r, o.y + r);
}

void Hinhtron::dichxuong(int d)
{
    Hinh::dichxuong(d);
    capnhattam();
}

void Hinhtron::dichlen(int d)
{
    Hinh::dichlen(d);
    capnhattam();
}

void Hinhtron::dichtrai(int d)
{
    Hinh::dichtrai(d);
    capnhattam();
}

void Hinhtron::dichphai(int d)
{
    Hinh::dichphai(d);
    capnhattam();
}

void Hinhtron::capnhattam()
{
    o.x = (x1 + x2) / 2;
    o.y = (y1 + y2) / 2;
    if (x2 - x1 < y2 - y1 && x2 > x1 && y2 > y1)
    {
        r = (x2 - x1) / 2;
    }
    if (x2 - x1 >= y2 - y1 && x2 > x1 && y2 > y1)
    {
        r = (y2 - y1) / 2;
    }
}

int Hinhtron::kttronghinh(CPoint p)
{
    float kc = sqrt((p.x - o.x) * (p.x - o.x) + (p.y - o.y) * (p.y - o.y));
    if (kc < r)
        return 1;
    else
        return 0;
}
