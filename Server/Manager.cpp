// Manager.cpp: implementation of the CManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Manager.h"
#include <iostream>
using namespace std;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CManager CManager::m_man;
CManager::CManager()
{

}

CManager::~CManager()
{

}
//协议解析函数
BOOL CManager::OnReceive(CSockLx *pSocka)
{
	int nCmd = 0;
	if(pSocka ->Receive(&nCmd,sizeof(nCmd))<=0)
		return FALSE;
	switch(nCmd)
	{
	case AD_LOGIN:
		return OnLogin(pSocka);
	case AD_BROW:
		return CAdmin::OnBrowse(pSocka);
	case AD_ADD:
		return CAdmin::OnAdd(pSocka);
	case AD_DEL:
		return CAdmin::OnDel(pSocka);
	case AD_MOD:
		return CAdmin::OnMod(pSocka);
	case AD_CPASS:
		return CAdmin::OnCPass(pSocka);//
	case WK_BROW:
		return CWork::OnBrowse(pSocka);
	case WK_ADD:
		return CWork::OnAdd(pSocka);

	}

	return FALSE;
}
