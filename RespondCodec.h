#pragma once
#include "Codec.h"
#include "Message.pb.h"
#include <iostream>
using namespace std;
struct RespondInfo
{
    int status;
    int seckeyId;
    string clientId;
    string serverId;
    string data;
};
class RespondCodec :
    public Codec
{
public:
    RespondCodec();
    RespondCodec(string encstr);
    RespondCodec(RespondInfo* info);
    void initMessage(string encstr);
    void initMessage(RespondInfo* info);
    string encodeMsg();
    void* decodeMsg();
    ~RespondCodec();
private:
    string m_encstr;
    RespondMsg m_msg;
};

