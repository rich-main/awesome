#if !defined(AFX_PRIORDLG_H__49E74608_9695_4981_836C_DDEAF50F8C8C__INCLUDED_)
#define AFX_PRIORDLG_H__49E74608_9695_4981_836C_DDEAF50F8C8C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PriorDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPriorDlg dialog

class CPriorDlg : public CDialog
{
// Construction
public:
	CSockLx& m_sock;
	void Refresh();
	CPriorDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPriorDlg)
	enum { IDD = IDD_PRIOR_DLG };
	CListCtrl	m_list;
	int		m_nPrior;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPriorDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPriorDlg)
	afx_msg void OnAdd();
	afx_msg void OnDel();
	afx_msg void OnMod();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRIORDLG_H__49E74608_9695_4981_836C_DDEAF50F8C8C__INCLUDED_)
