#pragma once
#include <iostream>
class TcpSocket
{
	TcpSocket();
	TcpSocket(int connfd);
	~TcpSocket();
	int connectToHost(std::string ip, unsigned short port, int timeout);
	void diskConnect();
	int sendMsg(std::string data, int timeout = 10000);
	std::string recvMsg(int timeout);
private:
	int m_socket;
};

