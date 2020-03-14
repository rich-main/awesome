// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__B6BDFB00_ABEB_41CC_A9F7_6710E85038C2__INCLUDED_)
#define AFX_STDAFX_H__B6BDFB00_ABEB_41CC_A9F7_6710E85038C2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <afx.h>
#include <afxdisp.h>
//DBA 美工 200人 DBA 200人

enum {SERVER_PORT=8822};

enum {
AD_LOGIN=0x1234, //协议号：传入数据：传出数据:
AD_ADD,
AD_DEL,
AD_MOD,
AD_BROW,
AD_CPASS,

WK_BROW=0x2000,
WK_ADD,
WK_DEL,
WK_MOD,
};

struct SPass
{
char sName[20];
char sOld[20];
char sNew[20];
};

struct SAdmin
{
char sName[20];
char sPass[20];
int nPrior;
};

struct SWork
{
	int nNumb;
	char sName[20];
	double fSala;
	COleDateTime time;//12个 DATA time; 8个字节
	char sSex[8];
	char sEduc[16];
	char sLang[16];
};

// TODO: reference additional headers your program requires here

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__B6BDFB00_ABEB_41CC_A9F7_6710E85038C2__INCLUDED_)
