// Base.h: interface for the CBase class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BASE_H__8781143C_73A1_416E_ADED_0E3DE8FD7FDA__INCLUDED_)
#define AFX_BASE_H__8781143C_73A1_416E_ADED_0E3DE8FD7FDA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "AdoLx.h"	// Added by ClassView
#include "SockLx.h"	// Added by ClassView

class CBase  
{
	CSockLx m_sock;
public:
	CAdoLx m_ado;
	void Start();

	CBase();
	virtual ~CBase();

};

#endif // !defined(AFX_BASE_H__8781143C_73A1_416E_ADED_0E3DE8FD7FDA__INCLUDED_)
