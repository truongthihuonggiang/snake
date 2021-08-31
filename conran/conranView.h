
// conranView.h : interface of the CconranView class
//

#pragma once
#include "Banco.h"

class CconranView : public CView
{
protected: // create from serialization only
	CconranView() noexcept;
	DECLARE_DYNCREATE(CconranView)

// Attributes
public:
	CconranDoc* GetDocument() const;

// Operations
public:
	Banco banco;
	int kd = 0;
// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CconranView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	int batdau();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // debug version in conranView.cpp
inline CconranDoc* CconranView::GetDocument() const
   { return reinterpret_cast<CconranDoc*>(m_pDocument); }
#endif

