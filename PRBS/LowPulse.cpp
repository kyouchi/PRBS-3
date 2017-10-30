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
   for(auto i = 0.0; i < 1.0/static_cast<double>(f0); i+=(1.0/fs))
   {
      y.push_back(-1);//1秒間サンプリング周波数ずつ追加
   }
}
