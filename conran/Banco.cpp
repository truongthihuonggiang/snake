#include "pch.h"
#include "Banco.h"
#include "Moi.h"
#define RONG 600
Banco::Banco()
{
	dk = 0;
	diem = 0;
	huong = 38;
	dv = Hcn(0, 0, RONG, RONG);
	ran = Ran(dv.x1 + D *10, dv.y1 + D * 10);
	moi = Moi();
}

void Banco::vehinh(CClientDC* pdc)
{
	CString strdiem;
	strdiem.Format(_T("Điểm:%d     "),diem);
	pdc->TextOutW(700, 50,strdiem);
	if (dk == 0)
	{
		CString strstart;
		strdiem.Format(_T("Bam phim space bat dau     "), diem);
		pdc->TextOutW((dv.x1 + dv.x2)/2, (dv.y1 + dv.y2) / 2, strdiem);
	}
	dv.vehinh(pdc);
	ran.vehinh(pdc);
	moi.vehinh(pdc);
}

void Banco::hienthimoi()
{
	Sleep(100);
	if (dk == 0)
		return;
		int h = 0;
		int mx = moi.x1;
		int my = moi.y1;
		while (mx == moi.x1 && my == moi.x2)
		{
			h = rand() % (RONG / D);
			mx = dv.x1 + h * D + D/4;
			h = rand() % (RONG / D);
			my = dv.y1 + h * D + D / 4;
		}
	
	
		while (ran.chamdauran(&moi) == 1 || ran.chamthanran(&moi) == 1)
		{
			h = rand() % (RONG / D);
			mx = dv.x1 + h * D + D / 4;
			h = rand() % (RONG / D);
			my = dv.y1 + h * D + D / 4;
			moi.setX1Y1(mx, my);
			moi.setX2Y2(mx + D / 2, my + D / 2);
		}
	
}

void Banco::capnhathinh(CClientDC* pdc)
{
	while (dk == 1)
	{
		vehinh(pdc);
		
		Sleep(40);
	}
	
}

void Banco::batdau()
{
	dk = 1;
	huong = 38;
	diem = 0;
	dv = Hcn(0, 0, RONG, RONG);
	ran = Ran(dv.x1 + D * 10, dv.y1 + D * 10);
	int h = rand() % (RONG / D);
	int mx = dv.x1 + h * D;
	h = rand() % (RONG / D);
	int my = dv.y1 + h * D;
	moi.setX1Y1(mx, my);
	moi.setX2Y2(mx + D / 2, my + D / 2);
	hienthimoi();
}

void Banco::ranchuyendong()
{
	while (dk == 1)
	{
		if (huong == 38)
		{
			//ran di len
			ran.dichuyenlen();
			
		}
		else
			if (huong == 37)
			{
				//ran di len
				ran.dichuyentrai();
			
			}
			else
				if (huong == 39)
				{
					ran.dichuyenphai();
					
				}
				else
					if (huong == 40)
					{
						ran.dichuyenxuong();
					}
		kiemtrabien();
		if (ran.anmoi(moi) == 1)
		{
			hienthimoi();
		
			diem++;
		}
		if (ran.dungthan() == 1)
		{
			dk = 0;
			//thong bao game ket thuc
		}
		Sleep(200);
	}
	
}

int Banco::kiemtrabien()
{
	//kiem tra tren
	if (ran.dau.y2 <= dv.y1)
	{
		ran.dau.y2 = dv.y2;
		ran.dau.y1 = dv.y2 - D;
		return 1;
	}
	//kiem tra trai
	if (ran.dau.x2 <= dv.x1)
	{
		ran.dau.x2 = dv.x2;
		ran.dau.x1 = dv.x2 - D;
		return 1;
	}
	//kiem tra phai
	if (ran.dau.x1 >= dv.x2)
	{
		ran.dau.x1 = dv.x1;
		ran.dau.x2 = dv.x1 + D;
		return 1;
	}
	//kiem tra phai
	if (ran.dau.y1 >= dv.y2)
	{
		ran.dau.y1 = dv.y1;
		ran.dau.y2 = dv.y1 + D;
		return 1;
	}
	return 0;
}
