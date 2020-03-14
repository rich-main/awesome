// Manager.h: interface for the CManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MANAGER_H__4B0C4B59_70C8_445D_B245_619E1D67247F__INCLUDED_)
#define AFX_MANAGER_H__4B0C4B59_70C8_445D_B245_619E1D67247F__INCLUDED_
#include "Admin.h"
#include "Work.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CManager :public CAdmin,public CWork
{
public:
	static CManager m_man;
	BOOL OnReceive(CSockLx* pSocka);
	CManager();
	virtual ~CManager();

};

#endif // !defined(AFX_MANAGER_H__4B0C4B59_70C8_445D_B245_619E1D67247F__INCLUDED_)
