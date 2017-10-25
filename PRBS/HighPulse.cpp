#include "stdafx.h"
#include "HighPulse.h"


HighPulse::HighPulse()
{
   initialize();
}


HighPulse::~HighPulse()
{
}

void HighPulse::inputY()
{
   for(auto i = 0; i < 1/static_cast<double>(f0); i+=(1/fs))
   {
      y.push_back(1);//1•bŠÔƒTƒ“ƒvƒŠƒ“ƒOü”g”‚¸‚Â’Ç‰Á
   }
}
