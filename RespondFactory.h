#pragma once
#include "Factory.h"
#include "RespondCodec.h"
class RespondFactory :
    public Factory
{
public:
   // RespondFactory();
    RespondFactory(string enc);
    RespondFactory(RespondInfo* info);
    Codec* createCodec();
    ~RespondFactory();
    

    
private:
    bool m_flag;
    string m_encStr;
    RespondInfo* m_info;
};

