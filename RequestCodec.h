#pragma once
#include "Codec.h"
#include "Message.pb.h"
#include <iostream>
using namespace std;
struct RequestInfo
{
    int cmd;
    string clientId;
    string serverId;
    string sign;
    string data;

};
class RequestCodec :
    public Codec
{
    RequestCodec();
    RequestCodec(string encstr);
    RequestCodec(RequestInfo *info);
    void initMessage(string encstr);
    void initMessage(RequestInfo* info);
    string encodeMsg();
    void* decodeMsg();
    ~RequestCodec();
private:
    string m_encstr;
    RequestMsg m_msg;
};

