#include "RespondFactory.h"




RespondFactory::RespondFactory(string enc):Factory()
{
    this->m_flag = true;
    this->m_encStr = enc;
}

RespondFactory::RespondFactory(RespondInfo* info):Factory()
{
    this->m_flag = false;
    this->m_info = info;
    
}

Codec* RespondFactory::createCodec()
{   
    Codec* c=NULL;
    
    if (m_flag)
    {
       c=new  RespondCodec(m_encStr);
    }
    else
    {
        c=new RespondCodec(m_info);
    }
    
    return c;
}

RespondFactory::~RespondFactory()
{

}
