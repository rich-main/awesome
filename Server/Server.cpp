// Server.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Manager.h"
//Socket+Database

int main(int argc, char* argv[])
{
	CManager::m_man.Start();
	return 0;
}
