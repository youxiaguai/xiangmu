#pragma once
#include<queue>
class ConnectPool
{
public:
	ConnectPool(int number);
	~ConnectPool();
	int getConnect();//ȡ��һ������
	void putConnect(int fd,bool isvalid);//�Ż�һ������
private:
	std::queue<int>m_list;
};

