// SockLx.cpp: implementation of the CSockLx class.
//Author:吕鑫老师封装类 http://www.baojy.com
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SockLx.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
#pragma comment(lib,"ws2_32.lib")
CSockLx::CSockLx()
{
	static int i = 0;
	if(!i)
	{	i=1;
		WSADATA wd;
		WSAStartup(0x0202,&wd);
	}
	m_hSocket = INVALID_SOCKET;
}

CSockLx::~CSockLx()
{
	Close();
}
//#define s_addr  S_un.S_addr
BOOL CSockLx::Bind( UINT nSocketPort, LPCTSTR lpszSocketAddress  )
{
	sockaddr_in sa={AF_INET,htons(nSocketPort)};
	if(lpszSocketAddress)
		sa.sin_addr.s_addr = inet_addr(lpszSocketAddress);
	return !bind(m_hSocket,(sockaddr*)&sa,sizeof(sa));
}

BOOL CSockLx::Create( UINT nSocketPort, int nSocketType , LPCTSTR lpszSocketAddress  )
{
	m_hSocket = socket(AF_INET,nSocketType,0);
	if(INVALID_SOCKET==m_hSocket)
		return FALSE;
	return Bind(nSocketPort,lpszSocketAddress);
}

BOOL CSockLx::Accept( CSockLx& rConnectedSocket,  LPSTR szIP ,UINT *nPort )
{
	sockaddr_in sa ;  
	int len = sizeof(sa);
	rConnectedSocket.m_hSocket = accept(m_hSocket,(sockaddr*)&sa,&len);

	if(INVALID_SOCKET == rConnectedSocket.m_hSocket )
		return FALSE;
	if(szIP)
		strcpy(szIP,inet_ntoa(sa.sin_addr));
	if(nPort)
		*nPort = htons(sa.sin_port);
	return TRUE;
}
BOOL CSockLx::Connect( LPCTSTR lpszHostAddress, UINT nHostPort )
{
	sockaddr_in sa={AF_INET,htons(nHostPort)};
	sa.sin_addr.s_addr = inet_addr(lpszHostAddress);
	return !connect(m_hSocket,(sockaddr*)&sa,sizeof(sa));
}

int CSockLx::SendTo( const void* lpBuf, int nBufLen, UINT nHostPort,
					LPCSTR lpszHostAddress , int nFlags )
{
	sockaddr_in sa={AF_INET,htons(nHostPort)};
	sa.sin_addr.s_addr = inet_addr(lpszHostAddress);

	return sendto(m_hSocket,(const char*)lpBuf,nBufLen,0,(sockaddr*)&sa,sizeof(sa));
}

BOOL CSockLx::GetSockName( char*  rSocketAddress, UINT& rSocketPort )
{
	sockaddr_in sa ;  
	int len = sizeof(sa);
	if(getsockname(m_hSocket,(sockaddr*)&sa,&len))
		return FALSE;

	rSocketPort = htons(sa.sin_port);
	strcpy(rSocketAddress,inet_ntoa(sa.sin_addr));
	return TRUE;
}
BOOL CSockLx::GetPeerName(  char* rPeerAddress, UINT& rPeerPort )
{
	sockaddr_in sa ;  
	int len = sizeof(sa);
	if(getpeername(m_hSocket,(sockaddr*)&sa,&len))
		return FALSE;

	rPeerPort = htons(sa.sin_port);
	strcpy(rPeerAddress,inet_ntoa(sa.sin_addr));
	return TRUE;
}
