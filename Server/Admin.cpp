// Admin.cpp: implementation of the CAdmin class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Admin.h"
#include <iostream>
using namespace std;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CAdmin::CAdmin()
{

}

CAdmin::~CAdmin()
{

}
/*	SAdmin a;
	if(pSocka ->Receive(&a,sizeof(a)) != sizeof(a))
		return FALSE;
	CString szSQL ;
	szSQL.Format("SELECT f_prior FROM t_admin WHERE f_name='%s' AND f_pass='%s'",a.sName,a.sPass);
	
	if(!m_ado.Select(szSQL))
		return FALSE;

	//if(m_ado.GetRecordCount() == 0)
	int nRet = -1;
	if(!m_ado.IsEOF())
		m_ado.GetFieldByIndex(0,nRet);

	pSocka ->Send(&nRet,sizeof(nRet));	*/	
/*void Test(int i)
{

}
void Test(long i)
{
}*/

/*
	SAdmin a;
	if(pSocka ->Receive(&a,sizeof(a)) != sizeof(a))
		return FALSE;
	CString szSQL ;
	szSQL.Format("SELECT f_prior FROM t_admin WHERE f_name='%s' AND f_pass='%s'",a.sName,a.sPass);
	
	if(!m_ado.Select(szSQL))
		return FALSE;

	//if(m_ado.GetRecordCount() == 0)
	int nRet = -1;
	if(!m_ado.IsEOF())
		m_ado.GetFieldByIndex(0,nRet);

	pSocka ->Send(&nRet,sizeof(nRet));
*/
BOOL CAdmin::OnLogin(CSockLx *pSocka)
{
	SAdmin a;
	if(pSocka ->Receive(&a,sizeof(a)) != sizeof(a))
		return FALSE;


	CAdoLx::CProc *p = m_ado.CreateProc("p_login");
	p ->AddParam("v_name",a.sName);
	p ->AddParam("v_pass",a.sPass);
	p ->AddParam("v_ret",0L,adParamOutput);
	if(p ->Exec() < 0)
	{
		cout << (LPCSTR )p->GetLastError() << endl;
		return FALSE;
	}
	long lRet = 0;
	p ->GetValue("v_ret",lRet);
	pSocka ->Send(&lRet,sizeof(lRet));

//	theApp.m_nPrior = nPrior;
//	theApp.m_szName = szName;
	
	return TRUE;
	
}

BOOL CAdmin::OnBrowse(CSockLx *pSocka)
{
	if(!m_ado.Select("SELECT*FROM t_admin"))
		return FALSE;
	
	int nCount = m_ado.GetRecordCount();
	pSocka ->Send(&nCount,sizeof(nCount));
	SAdmin a;
	while(!m_ado.IsEOF())
	{
		m_ado.GetFieldByIndex(0,a.sName,sizeof(a.sName));
		m_ado.GetFieldByIndex(1,a.sPass,sizeof(a.sPass));
		m_ado.GetFieldByIndex(2,a.nPrior);
		pSocka ->Send(&a,sizeof(a));
		m_ado.MoveNext();
	}
	return TRUE;	
}
BOOL CAdmin::OnDel(CSockLx *pSocka)
{
	char sName[20];
	pSocka ->Receive(sName,sizeof(sName));
	int nRet = 0;
	if(stricmp(sName,"admin"))
	{
		
		CString szSQL;
		szSQL.Format("DELETE FROM t_admin WHERE f_name='%s'",sName);
		nRet = m_ado.ExecSQL(szSQL);
	}
	pSocka ->Send(&nRet,sizeof(nRet));
	return TRUE;
}

BOOL CAdmin::OnAdd(CSockLx *pSocka)
{
	SAdmin a;
	if(pSocka ->Receive(&a,sizeof(a)) != sizeof(a))
		return FALSE;
	CString szSQL;
	szSQL.Format("INSERT INTO t_admin VALUES('%s','%s',%d)",
		a.sName,a.sPass,a.nPrior);
	m_ado.ExecSQL(szSQL);
	return TRUE;
}

BOOL CAdmin::OnMod(CSockLx *pSocka)
{
	SAdmin a;
	if(pSocka ->Receive(&a,sizeof(a)) != sizeof(a))
		return FALSE;
	CString szSQL;
	szSQL.Format("UPDATE t_admin SET f_pass='%s',f_prior=%d WHERE f_name='%s'",
		a.sPass,a.nPrior,a.sName);
	BOOL nRet = TRUE;//4个字节
	if(m_ado.ExecSQL(szSQL)<0)
		nRet = FALSE;
	pSocka ->Send(&nRet,sizeof(nRet));
	return TRUE;
}

BOOL CAdmin::OnCPass(CSockLx* pSocka)
{
	SPass pass;
	if(pSocka ->Receive(&pass,sizeof(pass)) != sizeof(pass))
		return FALSE;
	CString szSQL;
	szSQL.Format("UPDATE t_admin SET f_pass='%s' WHERE f_name='%s' AND f_pass='%s'",
		pass.sNew,pass.sName,pass.sOld);
	BOOL nRet = TRUE;//4个字节
	if(m_ado.ExecSQL(szSQL)<=0)
		nRet = FALSE;
	pSocka ->Send(&nRet,sizeof(nRet));

	return TRUE;
}