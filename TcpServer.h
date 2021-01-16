#pragma once
#include <iostream>
#include "TcpSocket.h"
#include"winsock2.h"
//#include <pthread.h>  
#include <stdio.h>

struct _SockePoolHandle
{
	int* fdArray;
	int* statusArray;//每条连接的状态，statusArray[0] =  1表示 链接有效 statusArray[0] =  0表示 链接无效
	int valid;//socket有效连接数目
	int nvalid;//socket无效连接数目
	int bounds;//socket连接池的容量

	char serverIp[128];
	int serverport;

	int connecttime;
	int sendtime;
	int revtime;
	int sTimeout;//没有连接时，等待时间
	
	// 判断连接池是否已经终止: 1-已经终止, 0-没有终止
	int terminated;
}SockePoolHandle;
//int sckCltPool_init(void** handle, SockePoolHandle *param)
//{
//	
//}
class TcpServer
{
public:
	TcpServer();
	~TcpServer();
	TcpSocket* acceptConn(int timeout=10000);
	int setListen(unsigned short port);
	
private:
	int m_lfd;//监听的文件描述符
	
};

