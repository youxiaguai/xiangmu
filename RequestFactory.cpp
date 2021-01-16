#include "RequestFactory.h"

RequestFactory::RequestFactory(string enc):Factory()
{
    m_flag = false;
    this->m_encstr = enc;
}

RequestFactory::RequestFactory(RequestInfo* info):Factory()
{
    m_flag = true;
    this->m_info = info;
}

Codec* RequestFactory::createCodec()
{
    Codec* codec = NULL;
    if (m_flag == true)
    {
        codec = new RequestCodec(m_info);
    }
    else
    {
        codec = new RequestCodec(m_encstr);
    }
    return codec;
}

RequestFactory::~RequestFactory()
{
}
