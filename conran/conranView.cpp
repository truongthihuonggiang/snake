
// conranView.cpp : implementation of the CconranView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "conran.h"
#endif

#include "conranDoc.h"
#include "conranView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CconranView

IMPLEMENT_DYNCREATE(CconranView, CView)

BEGIN_MESSAGE_MAP(CconranView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
END_MESSAGE_MAP()

// CconranView construction/destruction

CconranView::CconranView() noexcept
{
	// TODO: add construction code here
	banco = Banco();
	kd = 0;
}

CconranView::~CconranView()
{
}

BOOL CconranView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CconranView drawing

void CconranView::OnDraw(CDC* /*pDC*/)
{
	CconranDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	CClientDC pdc(this);
	
	banco.vehinh(&pdc);
}



void CconranView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CconranView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CconranView diagnostics

#ifdef _DEBUG
void CconranView::AssertValid() const
{
	CView::AssertValid();
}

void CconranView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CconranDoc* CconranView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CconranDoc)));
	return (CconranDoc*)m_pDocument;
}
#endif //_DEBUG


// CconranView message handlers

UINT capnhathinh(LPVOID pParam)
{
	int ran = 0;
	CconranView* cview = (CconranView*)pParam;
	CClientDC pdc(cview);
	cview->banco.capnhathinh(&pdc);
	return 0;
}
UINT ranchuyendong(LPVOID pParam)
{
	int ran = 0;
	CconranView* cview = (CconranView*)pParam;
	CClientDC pdc(cview);
	cview->banco.ranchuyendong();
	return 0;
}
int CconranView::batdau()
{
	// TODO: Add your implementation code here.
	banco.batdau();

	
	AfxBeginThread(capnhathinh, this, THREAD_PRIORITY_NORMAL, 0, 0, NULL);
	AfxBeginThread(ranchuyendong, this, THREAD_PRIORITY_NORMAL, 0, 0, NULL);
	return 0;
}


void CconranView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	kd = 1;
	if (nChar == 32 && banco.dk == 0)
	{
		batdau();
	}
	if (nChar >= 37 && nChar <=40  && banco.dk == 1)
	{
		banco.huong = nChar;
	}
	
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CconranView::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	kd = 0;
	CView::OnKeyUp(nChar, nRepCnt, nFlags);
}
