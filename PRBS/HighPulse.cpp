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

   for(auto i = 0.0; i < 1.0/static_cast<double>(f0); i+=(1.0/fs))
   {

      y.push_back(1);//1秒間サンプリング周波数ずつ追加
   }
}
