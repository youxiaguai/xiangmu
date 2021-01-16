#include "TcpSocket.h"
#include"winsock2.h"

TcpSocket::TcpSocket()
{
	int fd = socket(AF_INET,SOCK_STREAM,0);
	m_socket = fd;
}
TcpSocket::TcpSocket(int connfd)
{
	m_socket = connfd;
}
int TcpSocket::connectToHost(std::string ip, unsigned short port, int timeout)
{
	//connect(m_socket,);
	return 0;
}

void TcpSocket::diskConnect()
{
}

int TcpSocket::sendMsg(std::string data, int timeout)
{
	return 0;
}

std::string TcpSocket::recvMsg(int timeout)
{
	return std::string();
}
TcpSocket::~TcpSocket()
{
}