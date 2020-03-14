// Client_lvDlg.h : header file
//

#if !defined(AFX_CLIENT_LVDLG_H__82A7E529_55F0_4BE7_9D3F_DAC85C9FEF2E__INCLUDED_)
#define AFX_CLIENT_LVDLG_H__82A7E529_55F0_4BE7_9D3F_DAC85C9FEF2E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CClient_lvDlg dialog

class CClient_lvDlg : public CDialog
{
// Construction
public:
	CSockLx& m_sock;
	void Refresh();
	CClient_lvDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CClient_lvDlg)
	enum { IDD = IDD_WORK_DIALOG };
	CListCtrl	m_list;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClient_lvDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CClient_lvDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnProir();
	afx_msg void OnAdd();
	afx_msg void OnDel();
	afx_msg void OnMod();
	afx_msg void OnFind();
	afx_msg void OnPasswd();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIENT_LVDLG_H__82A7E529_55F0_4BE7_9D3F_DAC85C9FEF2E__INCLUDED_)
