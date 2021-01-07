#include "RequestCodec.h"

#include <iostream>

RequestCodec::RequestCodec()
{
	
}
RequestCodec::RequestCodec(std::string encstr)
{
	initMessage(encstr);
}
RequestCodec::RequestCodec(RequestInfo* info)
{
	initMessage(info);
}
void RequestCodec::initMessage(std::string encstr)
{
	m_encstr = encstr;
}
void RequestCodec::initMessage(RequestInfo* info)
{
	m_msg.set_cmdtype(info->cmd);
	m_msg.set_clientid(info->clientId);
	m_msg.set_serverid(info->serverId);
	m_msg.set_data(info->data);
	m_msg.set_sign(info->sign);
}

string RequestCodec::encodeMsg()
{
	string output;
	 m_msg.SerializeToString(&output);
	 return output;
}

void* RequestCodec::decodeMsg()
{
	m_msg.ParseFromString(m_encstr);
	return &m_msg;
}

RequestCodec::~RequestCodec()
{
}
