// Client_lv.h : main header file for the CLIENT_LV application
//

#if !defined(AFX_CLIENT_LV_H__B470F54A_A08D_419D_9AA6_63F8905473C2__INCLUDED_)
#define AFX_CLIENT_LV_H__B470F54A_A08D_419D_9AA6_63F8905473C2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include "SockLx.h"	// Added by ClassView

/////////////////////////////////////////////////////////////////////////////
// CClient_lvApp:
// See Client_lv.cpp for the implementation of this class
//

class CClient_lvApp : public CWinApp
{
public:
	SAdmin m_admin;

	CSockLx m_sock;
	CClient_lvApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClient_lvApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CClient_lvApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIENT_LV_H__B470F54A_A08D_419D_9AA6_63F8905473C2__INCLUDED_)
