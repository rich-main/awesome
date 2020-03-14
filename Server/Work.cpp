// Work.cpp: implementation of the CWork class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Work.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CWork::CWork()
{

}

CWork::~CWork()
{

}

BOOL CWork::OnBrowse(CSockLx *pSocka)
{
	if(!m_ado.Select("SELECT*FROM t_work"))
		return FALSE;

	int nCount = m_ado.GetRecordCount();
	pSocka ->Send(&nCount,sizeof(nCount));
	SWork wk;
	while(!m_ado.IsEOF())
	{
		m_ado.GetFieldByIndex(0,wk.nNumb);
		m_ado.GetFieldByIndex(1,wk.sName,sizeof(wk.sName));
		m_ado.GetFieldByIndex(2,wk.fSala);
		m_ado.GetFieldByIndex(3,wk.time);
		m_ado.GetFieldByIndex(4,wk.sSex,sizeof(wk.sSex));
		m_ado.GetFieldByIndex(5,wk.sEduc,sizeof(wk.sEduc));
		m_ado.GetFieldByIndex(6,wk.sLang,sizeof(wk.sLang));
		pSocka ->Send(&wk,sizeof(wk));
		m_ado.MoveNext();
	}	
	return TRUE;
}

BOOL CWork::OnAdd(CSockLx *pSocka)
{
	SWork wk;
	if(sizeof(wk) != pSocka ->Receive(&wk,sizeof(wk)))
		return FALSE;
	CString szSQL;
	szSQL.Format("INSERT INTO t_work VALUES(%d,'%s',%0.3lf,to_date('%s','YYYY-MM-DD'),'%s','%s','%s')",
		wk.nNumb,wk.sName,wk.fSala,wk.time.Format("%Y-%m-%d"),wk.sSex,wk.sEduc,wk.sLang);
	m_ado.ExecSQL(szSQL);

	return TRUE;
}
