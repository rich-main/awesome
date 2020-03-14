#if !defined(AFX_INPUTDLG_H__E6F7785F_609A_4938_A280_86F584492C4D__INCLUDED_)
#define AFX_INPUTDLG_H__E6F7785F_609A_4938_A280_86F584492C4D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// InputDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CInputDlg dialog
#include "Client_lvDlg.h"
class CInputDlg : public CDialog
{
	CClient_lvDlg *m_pDlg;
public:
	CSockLx& m_sock;
	CInputDlg(CClient_lvDlg* pDlg);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CInputDlg)
	enum { IDD = IDD_INPUT_DLG };
	COleDateTime	m_date;
	BOOL	m_bEngl;
	BOOL	m_bJapn;
	BOOL	m_bKrea;
	UINT	m_nNumb;
	BOOL	m_bRuss;
	double	m_fSala;
	int		m_nSex;
	CString	m_szName;
	CString	m_szEduc;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInputDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CInputDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INPUTDLG_H__E6F7785F_609A_4938_A280_86F584492C4D__INCLUDED_)
