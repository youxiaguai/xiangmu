#include "TcpServer.h"

TcpServer::TcpServer()
{

}


TcpSocket* TcpServer::acceptConn(int timeout=10000)
{
	int len;

	int fd = accept(m_lfd, &address, &len);
	TcpSocket* tcp = new TcpSocket(fd);
	if (tcp != NULL)
	{
		return tcp;
	}
	return NULL;
}

int TcpServer::setListen(unsigned short port)
{
	int backlog;
	listen(port,backlog);
	return 0;
}



TcpServer::~TcpServer()
{
}
