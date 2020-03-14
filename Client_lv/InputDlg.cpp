// InputDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Client_lv.h"
#include "InputDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInputDlg dialog


CInputDlg::CInputDlg(CClient_lvDlg* pDlg /*=NULL*/)
	: CDialog(CInputDlg::IDD),m_sock(theApp.m_sock)
{
	m_pDlg = pDlg;
	//{{AFX_DATA_INIT(CInputDlg)
	m_date = COleDateTime::GetCurrentTime();
	m_bEngl = FALSE;
	m_bJapn = FALSE;
	m_bKrea = FALSE;
	m_nNumb = 0;
	m_bRuss = FALSE;
	m_fSala = 0.0;
	m_nSex = -1;
	m_szName = _T("");
	m_szEduc = _T("");
	//}}AFX_DATA_INIT
}


void CInputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CInputDlg)
	DDX_DateTimeCtrl(pDX, IDC_DATE, m_date);
	DDX_Check(pDX, IDC_ENGL, m_bEngl);
	DDX_Check(pDX, IDC_JAPN, m_bJapn);
	DDX_Check(pDX, IDC_KREA, m_bKrea);
	DDX_Text(pDX, IDC_NUMB, m_nNumb);
	DDX_Check(pDX, IDC_RUSS, m_bRuss);
	DDX_Text(pDX, IDC_SALA, m_fSala);
	DDX_Radio(pDX, IDC_SEX, m_nSex);
	DDX_Text(pDX, IDC_NAME, m_szName);
	DDX_CBString(pDX, IDC_EDUC, m_szEduc);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CInputDlg, CDialog)
	//{{AFX_MSG_MAP(CInputDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInputDlg message handlers

void CInputDlg::OnOK() 
{
	SWork wk;
	
	UpdateData();
	wk.nNumb = m_nNumb;
	strcpy(wk.sName,m_szName);
	wk.fSala = m_fSala;
	wk.time = m_date;
	strcpy(wk.sSex,m_nSex?"Å®":"ÄÐ");
	strcpy(wk.sEduc,m_szEduc);
	strcpy(wk.sLang,"Ó¢");
	int nCmd = WK_ADD;
	m_sock.Send(&nCmd,sizeof(nCmd));
	m_sock.Send(&wk,sizeof(wk));

	m_pDlg ->Refresh();
	//CDialog::OnOK();
}
