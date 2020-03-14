// PriorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Client_lv.h"
#include "PriorDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPriorDlg dialog


CPriorDlg::CPriorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPriorDlg::IDD, pParent),m_sock(theApp.m_sock)
{
	//{{AFX_DATA_INIT(CPriorDlg)
	m_nPrior = 1;
	//}}AFX_DATA_INIT
}


void CPriorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPriorDlg)
	DDX_Control(pDX, IDC_LIST, m_list);
	DDX_CBIndex(pDX, IDC_PRIOR, m_nPrior);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPriorDlg, CDialog)
	//{{AFX_MSG_MAP(CPriorDlg)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_DEL, OnDel)
	ON_BN_CLICKED(IDC_MOD, OnMod)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPriorDlg message handlers

void CPriorDlg::OnAdd() 
{
	SAdmin a;
	
	GetDlgItemText(IDC_NAME,a.sName,sizeof(a.sName));
	if(strlen(a.sName) == 0)
	{
		AfxMessageBox("帐户名不能为空！");
		GetDlgItem(IDC_NAME) ->SetFocus();
		return;
	}
	GetDlgItemText(IDC_PASS,a.sPass,sizeof(a.sPass));
	UpdateData();
	a.nPrior = m_nPrior;
	int nCmd = AD_ADD;
	m_sock.Send(&nCmd,sizeof(nCmd));
	m_sock.Send(&a,sizeof(a));
	Refresh();
}

void CPriorDlg::OnDel() 
{
	POSITION pos = m_list.GetFirstSelectedItemPosition();
	if(!pos)
	{
		AfxMessageBox("请选中一行再删除！");
		return;
	}
	int nSel = m_list.GetNextSelectedItem(pos);
	CString str = m_list.GetItemText(nSel,0);
	if(IDNO==AfxMessageBox("确认要删除 " + str + " 吗？",MB_YESNO))
		return;
	int nCmd = AD_DEL;
	m_sock.Send(&nCmd,sizeof(nCmd));
	m_sock.Send(str,str.GetLength()+1);
	int nRet = 0;
	m_sock.Receive(&nRet,sizeof(nRet)); //阻止TCP数据粘连
	if(nRet <= 0)
		AfxMessageBox("删除失败");
	else
		Refresh();

	
}

void CPriorDlg::OnMod() 
{
	POSITION pos = m_list.GetFirstSelectedItemPosition();
	if(!pos)
	{
		AfxMessageBox("请选中一行再删除！");
		return;
	}
	int nSel = m_list.GetNextSelectedItem(pos);
	SAdmin a;
	m_list.GetItemText(nSel,0,a.sName,sizeof(a.sName));
	GetDlgItemText(IDC_PASS,a.sPass,sizeof(a.sPass));
	UpdateData();
	a.nPrior = m_nPrior;
	int nCmd = AD_MOD;
	m_sock.Send(&nCmd,sizeof(nCmd));
	m_sock.Send(&a,sizeof(a));
	BOOL bRet = FALSE;
	m_sock.Receive(&bRet,sizeof(bRet));
	if(bRet)
		Refresh();
	else
		AfxMessageBox("修改记录失败！");

}

BOOL CPriorDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_list.InsertColumn(0,"账号",0,100);
	m_list.InsertColumn(1,"密码",0,100);
	m_list.InsertColumn(2,"权限",0,100);
	Refresh();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CPriorDlg::Refresh()
{
	int nCmd = AD_BROW;
	m_sock.Send(&nCmd,sizeof(nCmd));
	int nCount = 0,i=0;
	SAdmin a;
	m_list.DeleteAllItems();
	m_sock.Receive(&nCount,sizeof(nCount));
	while(i<nCount)
	{
		theApp.m_sock.Receive(&a,sizeof(a));
		m_list.InsertItem(i,a.sName);
		m_list.SetItemText(i,1,a.sPass);
		m_list.SetItemText(i,2,a.nPrior?"普通":"高级");
		++i;
	}
}
