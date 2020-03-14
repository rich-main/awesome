// PassDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Client_lv.h"
#include "PassDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPassDlg dialog


CPassDlg::CPassDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPassDlg::IDD, pParent),m_sock(theApp.m_sock)
{
	//{{AFX_DATA_INIT(CPassDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPassDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPassDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPassDlg, CDialog)
	//{{AFX_MSG_MAP(CPassDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPassDlg message handlers
//GetDlgItemText(IDC_NAME,szName);
//
void CPassDlg::OnOK() 
{
	CString szConf;
	SPass pass;
	//�ضϵ�19��1���ַ�����β��
	GetDlgItemText(IDC_NEW,pass.sNew,sizeof(pass.sNew));
	if(!strlen(pass.sNew))
	{
		AfxMessageBox("�����벻��Ϊ�գ�");
		return;
	}
	GetDlgItemText(IDC_CONF,szConf);
	if(szConf != pass.sNew)
	{
		AfxMessageBox("������������ȷ�ϲ�һ�£�");
		return;
	}
	strcpy(pass.sName,theApp.m_admin.sName);
	strcpy(pass.sOld,theApp.m_admin.sPass);
	int nCmd = AD_CPASS;
	m_sock.Send(&nCmd,sizeof(nCmd));
	m_sock.Send(&pass,sizeof(pass));
	BOOL bRet = FALSE;
	m_sock.Receive(&bRet,sizeof(bRet));
	if(bRet)
	{
		strcpy(theApp.m_admin.sPass,pass.sNew);
		AfxMessageBox("�����޸ĳɹ���");
		CDialog::OnOK();
	}
	else
		AfxMessageBox("�����޸�ʧ�ܣ�");
}
