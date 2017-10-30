#include "stdafx.h"
#include "TrueSinWave.h"


TrueSinWave::TrueSinWave()
{
   initialize();
}


TrueSinWave::~TrueSinWave()
{
}

void TrueSinWave::inputY()
{
   for(auto i = 0.0; i < 1.0/static_cast<double>(f0); i+=(1.0/fs))
   {
      y.push_back(std::sin(2.0*i*pi/static_cast<double>(f0)));//1秒間サンプリング周波数ずつ追加
   }
}
