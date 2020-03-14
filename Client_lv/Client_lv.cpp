// Client_lv.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "Client_lv.h"
#include "Client_lvDlg.h"
#include "LoginDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClient_lvApp

BEGIN_MESSAGE_MAP(CClient_lvApp, CWinApp)
	//{{AFX_MSG_MAP(CClient_lvApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClient_lvApp construction

CClient_lvApp::CClient_lvApp()
{
	
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CClient_lvApp object

CClient_lvApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CClient_lvApp initialization

BOOL CClient_lvApp::InitInstance()
{
	if(!m_sock.Create())
	{
		AfxMessageBox("网络初始化失败！");
		return FALSE;
	}
	if(!m_sock.Connect("172.16.97.250",SERVER_PORT))
	{
		AfxMessageBox("连接服务器失败！");
		return FALSE;
	}
	CLoginDlg ldlg;
	if(IDCANCEL == ldlg.DoModal())
		return FALSE;
	CClient_lvDlg dlg;
	dlg.DoModal();
	return FALSE;
}
