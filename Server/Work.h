// Work.h: interface for the CWork class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WORK_H__DF8EED7C_971D_4EBE_92D8_F1EBBC15277C__INCLUDED_)
#define AFX_WORK_H__DF8EED7C_971D_4EBE_92D8_F1EBBC15277C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Base.h"
class CWork : virtual public CBase
{
public:
	BOOL OnAdd(CSockLx* pSocka);
	BOOL OnBrowse(CSockLx* pSocka);
	CWork();
	virtual ~CWork();

};

#endif // !defined(AFX_WORK_H__DF8EED7C_971D_4EBE_92D8_F1EBBC15277C__INCLUDED_)
