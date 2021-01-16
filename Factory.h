#pragma once
#include "Codec.h"
using namespace std;

class Factory
{
public:
	Factory();
	virtual Codec* createCodec();

	virtual ~Factory();
	

	

};

