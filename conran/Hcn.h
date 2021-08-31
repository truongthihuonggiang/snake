#pragma once
#include "Hinh.h"
class Hcn :
    public Hinh
{
public:
    Hcn();
    Hcn(int mx1, int my1, int mx2, int my2);
    void vehinh(CClientDC* pdc);
    int kttronghinh(CPoint p);
    void setX1Y1(int mx1, int my1);
    void setX2Y2(int mx2, int my2);
};

