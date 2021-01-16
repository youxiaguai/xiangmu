#include <iostream>
#include <atomic>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include "RequestCodec.h"
#include "RespondCodec.h"
#include "TcpServer.h"
using namespace std;
string encodeMsg(Codec* codec)
{
	return codec->encodeMsg();
}
void* decodeMsg(Codec* codec)
{
	return codec->decodeMsg();
}
void* callback(void* arg)
{
	
}
int main()
{
	RequestInfo reqinfo;
	reqinfo.cmd = 9;
	reqinfo.clientId = "OnePiece";
	reqinfo.serverId = "Luffly";
	reqinfo.data = "柚夏怪";
	reqinfo.sign = "叶森迷路";
	RequestCodec req(&reqinfo);
	string reqmsg = encodeMsg(&req);
	RequestCodec req1(reqmsg);
	RequestMsg* reqMsg = (RequestMsg*)decodeMsg(&req1);
	cout << "cmd= " << reqMsg->cmdtype() << ", "
		<< "clientID= " << reqMsg->clientid() << ", "
		<< "serverID= " << reqMsg->serverid() << ", "
		<< "data= " << reqMsg->data() << ", "
		<< "sign= " << reqMsg->sign() << ", " << endl;

	//respondMsg
	RespondInfo resinfo;
	resinfo.status = 9;
	resinfo.clientId = "OnePiece";
	resinfo.serverId = "Luffly";
	resinfo.data = "柚夏怪";
	resinfo.seckeyId = 6;
	RespondCodec res(&resinfo);
	string resmsg = encodeMsg(&res);
	RespondCodec res1(resmsg);
	RespondMsg* resMsg = (RespondMsg*)decodeMsg(&res1);
	cout << "status= " << resMsg->status() << ", "
		<< "clientID= " << resMsg->clientid() << ", "
		<< "serverID= " << resMsg->serverid() << ", "
		<< "data= " << resMsg->data() << ", "
		<< "seckeyid= " << resMsg->seckeyid() << ", " << endl;
	return 0;

	//TcpServer使用
	TcpServer* server = new TcpServer;
	while (1)
	{
		TcpSocket *tcp=server->acceptConn();
		//创建子线程
		thread thread1(callback);
	}
	return 0;
}