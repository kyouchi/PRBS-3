#include "stdafx.h"
#include "LowPulse.h"


LowPulse::LowPulse()
{
   initialize();
}


LowPulse::~LowPulse()
{
}

void LowPulse::inputY()
{
   for(auto i = 0; i < 1/static_cast<double>(f0); i+=(1/fs))
   {
      y.push_back(-1);//1•bŠÔƒTƒ“ƒvƒŠƒ“ƒOü”g”‚¸‚Â’Ç‰Á
   }
}
