// Admin.h: interface for the CAdmin class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADMIN_H__F6605FE7_E828_4F4E_843C_58247C934133__INCLUDED_)
#define AFX_ADMIN_H__F6605FE7_E828_4F4E_843C_58247C934133__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Base.h"
class CAdmin  : virtual public CBase
{
public:
	BOOL OnMod(CSockLx*pSocka);
	BOOL OnAdd(CSockLx* pSocka);
	BOOL OnDel(CSockLx* pSocka);
	BOOL OnBrowse(CSockLx* pSocka);
	BOOL OnLogin(CSockLx* pSocka);
	BOOL OnCPass(CSockLx* pSocka);
	CAdmin();
	virtual ~CAdmin();

};

#endif // !defined(AFX_ADMIN_H__F6605FE7_E828_4F4E_843C_58247C934133__INCLUDED_)
