
// multithreadView.h: CmultithreadView 클래스의 인터페이스
//

#pragma once
struct SData {
	int array[5];
	int max;
	HWND NotifyWindow;
};
SData data;
class CmultithreadView : public CView
{
protected: // serialization에서만 만들어집니다.
	CmultithreadView() noexcept;
	DECLARE_DYNCREATE(CmultithreadView)

// 특성입니다.
public:
	CmultithreadDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CmultithreadView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileFindmax();
	void OnMaxFound(WPARAM wParam, LPARAM lParam);
};

#ifndef _DEBUG  // multithreadView.cpp의 디버그 버전
inline CmultithreadDoc* CmultithreadView::GetDocument() const
   { return reinterpret_cast<CmultithreadDoc*>(m_pDocument); }
#endif

