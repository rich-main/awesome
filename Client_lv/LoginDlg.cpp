// LoginDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Client_lv.h"
#include "LoginDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg dialog


CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLoginDlg::IDD, pParent),m_sock(	theApp.m_sock)
{
	//{{AFX_DATA_INIT(CLoginDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLoginDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialog)
	//{{AFX_MSG_MAP(CLoginDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg message handlers
//协议=命令+数据
void CLoginDlg::OnOK() 
{
	SAdmin a;
	GetDlgItemText(IDC_NAME,a.sName,sizeof(a.sName));
	GetDlgItemText(IDC_PASS,a.sPass,sizeof(a.sPass));
	int nCmd = AD_LOGIN;
	m_sock.Send(&nCmd,sizeof(nCmd));
	m_sock.Send(&a,sizeof(a));

	int nRet = 0;
	m_sock.Receive(&nRet,sizeof(nRet));
	if(nRet < 0)
	{
		AfxMessageBox("账户或密码错误，请重新输入！");
		return;
	}
	theApp.m_admin = a;
	theApp.m_admin.nPrior = nRet;

	CDialog::OnOK();
}
