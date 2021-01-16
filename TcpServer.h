#pragma once
#include <iostream>
#include "TcpSocket.h"
#include"winsock2.h"
//#include <pthread.h>  
#include <stdio.h>

struct _SockePoolHandle
{
	int* fdArray;
	int* statusArray;//ÿ�����ӵ�״̬��statusArray[0] =  1��ʾ ������Ч statusArray[0] =  0��ʾ ������Ч
	int valid;//socket��Ч������Ŀ
	int nvalid;//socket��Ч������Ŀ
	int bounds;//socket���ӳص�����

	char serverIp[128];
	int serverport;

	int connecttime;
	int sendtime;
	int revtime;
	int sTimeout;//û������ʱ���ȴ�ʱ��
	
	// �ж����ӳ��Ƿ��Ѿ���ֹ: 1-�Ѿ���ֹ, 0-û����ֹ
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
	int m_lfd;//�������ļ�������
	
};

