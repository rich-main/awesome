// SockLx.h: interface for the CSockLx class.
//Author:吕鑫老师封装类 http://www.baojy.com
//////////////////////////////////////////////////////////////////////

#ifndef __SOCK_LX_H__
#define __SOCK_LX_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <winsock2.h>
class CSockLx  
{
protected:
	SOCKET m_hSocket;

public:
	BOOL Create( UINT nSocketPort = 0, int nSocketType = SOCK_STREAM 
		, LPCTSTR lpszSocketAddress = NULL );
	BOOL Accept( CSockLx& rConnectedSocket,  LPSTR szIP = NULL,UINT *nPort = NULL);
	BOOL Connect( LPCTSTR lpszHostAddress, UINT nHostPort );

	int SendTo( const void* lpBuf, int nBufLen, UINT nHostPort, LPCSTR lpszHostAddress = NULL, int nFlags = 0 );

	int ReceiveFrom( void* lpBuf, int nBufLen, char *rSocketAddress, UINT& rSocketPort, int nFlags = 0 );
	BOOL Listen( int nConnectionBacklog = 5 )
	{
		return !listen(m_hSocket,nConnectionBacklog);
	}
	int Send( const void* lpBuf, int nBufLen, int nFlags = 0 )
	{
		return send(m_hSocket, (LPCSTR)lpBuf, nBufLen, nFlags);
	}
	int Receive( void* lpBuf, int nBufLen, int nFlags = 0 )
	{
		return recv(m_hSocket, (LPSTR)lpBuf, nBufLen, nFlags);
	}

	void Close( )
	{
		closesocket(m_hSocket);
		m_hSocket = INVALID_SOCKET;
	}
	BOOL GetSockName( char*  rSocketAddress, UINT& rSocketPort );
	BOOL GetPeerName(  char* rPeerAddress, UINT& rPeerPort );
	BOOL Bind( UINT nSocketPort, LPCTSTR lpszSocketAddress = NULL );

	CSockLx();
	virtual ~CSockLx();
};

#endif //__SOCK_LX_H__
