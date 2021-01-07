#include "RespondCodec.h"

RespondCodec::RespondCodec()
{
}

RespondCodec::RespondCodec(string encstr)
{
	initMessage(encstr);
}

RespondCodec::RespondCodec(RespondInfo* info)
{
	initMessage(info);
}

void RespondCodec::initMessage(string encstr)
{
	m_encstr = encstr;
}

void RespondCodec::initMessage(RespondInfo* info)
{
	m_msg.set_status(info->status);
	m_msg.set_clientid(info->clientId);
	m_msg.set_seckeyid(info->seckeyId);
	m_msg.set_serverid(info->serverId);
	m_msg.set_data(info->data);
}

string RespondCodec::encodeMsg()
{
	string output;
	m_msg.SerializeToString(&output);//不能对类成员直接进行编码，不然回不去了
	return output;
}

void* RespondCodec::decodeMsg()
{
	m_msg.ParseFromString(m_encstr);
	return &m_msg;
}

RespondCodec::~RespondCodec()
{
}
