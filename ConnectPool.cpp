#include "ConnectPool.h"
#include"winsock2.h"
ConnectPool::ConnectPool(int number)
{
	for (int i = 0; i < number; i++)
	{
		int fd = socket();
		connect();
		m_list.push(fd);
	}
}


int ConnectPool::getConnect()
{
	if (m_list.size() > 0)
	{
		int fd = m_list.front();
		m_list.pop();
		return fd;
	}
	return -1;
}

void ConnectPool::putConnect(int fd,bool isvalid)
{
	if (isvalid)
	{
		m_list.push(fd);
	}
	else
	{
		int fd = socket();
		m_list.push(fd);
	}
	
}
ConnectPool::~ConnectPool()
{
}
