// Client_lvDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Client_lv.h"
#include "Client_lvDlg.h"
#include "PriorDlg.h"
#include "InputDlg.h"
#include "ModifyDlg.h"
#include "FindDlg.h"
#include "PassDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClient_lvDlg dialog

CClient_lvDlg::CClient_lvDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CClient_lvDlg::IDD, pParent),m_sock(theApp.m_sock)
{
	//{{AFX_DATA_INIT(CClient_lvDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CClient_lvDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CClient_lvDlg)
	DDX_Control(pDX, IDC_LIST, m_list);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CClient_lvDlg, CDialog)
	//{{AFX_MSG_MAP(CClient_lvDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_PROIR, OnProir)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_DEL, OnDel)
	ON_BN_CLICKED(IDC_MOD, OnMod)
	ON_BN_CLICKED(IDC_FIND, OnFind)
	ON_BN_CLICKED(IDC_PASSWD, OnPasswd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClient_lvDlg message handlers

BOOL CClient_lvDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	if(theApp.m_admin.nPrior)
		GetDlgItem(IDC_PROIR) ->ShowWindow(SW_HIDE);
	CString str ;
	GetWindowText(str);
	str += " ";
	str += theApp.m_admin.sName;
	str += "（";
	str += theApp.m_admin.nPrior?"普通":"高级";
	str += "）";
	SetWindowText(str);
	m_list.InsertColumn(0,"工号",0,100);
	m_list.InsertColumn(1,"姓名",0,100);
	m_list.InsertColumn(2,"工资",0,100);
	m_list.InsertColumn(3,"性别",0,100);
	m_list.InsertColumn(4,"入职",0,100);
	m_list.InsertColumn(5,"学历",0,100);
	m_list.InsertColumn(6,"外语",0,100);

	Refresh();
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CClient_lvDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CClient_lvDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CClient_lvDlg::OnProir() 
{
	if(theApp.m_admin.nPrior)
		return;
	CPriorDlg dlg;
	dlg.DoModal();
}

void CClient_lvDlg::Refresh()
{
	int nCmd = WK_BROW;
	m_sock.Send(&nCmd,sizeof(nCmd));
	int nCount = 0;
	m_sock.Receive(&nCount,sizeof(nCount));
	m_list.DeleteAllItems();
	int i = 0;
	CString str;
	SWork wk;
	while(i<nCount)
	{
		m_sock.Receive(&wk,sizeof(wk));
		str.Format("%d",wk.nNumb);
		m_list.InsertItem(i,str);
		m_list.SetItemText(i,1,wk.sName);
		str.Format("%0.2lf",wk.fSala);
		m_list.SetItemText(i,2,str);
		m_list.SetItemText(i,3,wk.time.Format("%Y年%m月%d日"));
		m_list.SetItemText(i,4,wk.sSex);
		m_list.SetItemText(i,5,wk.sEduc);
		m_list.SetItemText(i,6,wk.sLang);
		++i;
	}
}

void CClient_lvDlg::OnAdd() 
{
	CInputDlg dlg(this);
	dlg.DoModal();
}

void CClient_lvDlg::OnDel() 
{
	POSITION pos = m_list.GetFirstSelectedItemPosition();
}

void CClient_lvDlg::OnMod() 
{
	CModifyDlg dlg;
	
	if(dlg.DoModal() ==IDCANCEL)
		return;
	
}

void CClient_lvDlg::OnFind() 
{
	CFindDlg dlg;
	dlg.DoModal();
}

void CClient_lvDlg::OnPasswd() 
{
	CPassDlg dlg;
	dlg.DoModal();
}
