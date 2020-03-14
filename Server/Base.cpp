// Base.cpp: implementation of the CBase class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Base.h"
#include <iostream>
using namespace std;
#include <process.h>
#include "Manager.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBase::CBase()
{

}

CBase::~CBase()
{

}


void theProc(void* p)
{
	while(CManager::m_man.OnReceive((CSockLx*)p))
		;

}
//Oracle实例：
void CBase::Start()
{
	if(!m_ado.Connect(CAdoLx::DBT_ORACLE,"orcl","123456","work"))
	{
		cout << "连接数据库失败：" << (LPCSTR)m_ado.GetLastError() << endl;
		return;
	}
	if(!m_sock.Create(SERVER_PORT))
	{
		cout << "创建端口失败：" << WSAGetLastError() << endl;
		return;
	}
	cout << "服务器启动成功！" << endl;
	m_sock.Listen();
	CSockLx* pSocka = new CSockLx;
	char sIP[20];
	UINT nPort= 0;
	while(m_sock.Accept(*pSocka,sIP,&nPort))
	{
		_beginthread(theProc,0,pSocka);
		pSocka = new CSockLx;
	}
	
}