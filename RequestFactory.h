#pragma once
#include "Codec.h"
#include "Factory.h"
#include "RequestCodec.h"
#include <iostream>

class RequestFactory :
    public Factory
{
public:
    RequestFactory(string enc);
    RequestFactory(RequestInfo* info);
    Codec* createCodec();
    ~RequestFactory();
    
    
private:
    bool m_flag;
    string m_encstr;
    RequestInfo* m_info;
};

