// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__4FA081F1_E2A0_44BF_A3F4_2A9357AD970C__INCLUDED_)
#define AFX_STDAFX_H__4FA081F1_E2A0_44BF_A3F4_2A9357AD970C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT
enum {SERVER_PORT=8822};

enum {
AD_LOGIN=0x1234, //Э��ţ��������ݣ���������:
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
char sName[20];//�˻���
char sOld[20];//������
char sNew[20];//������
};

struct SAdmin
{
char sName[20];
char sPass[20];
int nPrior;//0����߼� 1��ͨ
};
struct SWork
{
	int nNumb;
	char sName[20];
	double fSala;
	COleDateTime time;//12�� DATA time; 8���ֽ�
	char sSex[8];
	char sEduc[16];
	char sLang[16];
};
#include "Client_lv.h"
extern CClient_lvApp theApp;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__4FA081F1_E2A0_44BF_A3F4_2A9357AD970C__INCLUDED_)
