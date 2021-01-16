#pragma once
#include<queue>
class ConnectPool
{
public:
	ConnectPool(int number);
	~ConnectPool();
	int getConnect();//取出一个连接
	void putConnect(int fd,bool isvalid);//放回一个连接
private:
	std::queue<int>m_list;
};

