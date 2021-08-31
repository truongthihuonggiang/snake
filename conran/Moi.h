#pragma once
#include "Hinhtron.h"
class Moi :
    public Hinhtron
{
public:
    Moi() :Hinhtron() {
    
    };
    Moi(int mx1, int my1, int mx2, int my2) :Hinhtron( mx1, my1,  mx2,  my2) {

    }
    void vehinh(CClientDC* pdc)
    {
        CBrush* b = new CBrush(RGB(0, 0, 0));
        CBrush* ob;
        ob = pdc->SelectObject(b);
        Hinhtron::vehinh(pdc);
        pdc->SelectObject(ob);
    }
};

