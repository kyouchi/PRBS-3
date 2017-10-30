#pragma once
#include "Waveform.h"
class TrueSinWave :
   public Waveform
{
public:
   TrueSinWave();
   explicit TrueSinWave(const Waveform &obj) : Waveform(obj){};//CopyConstructor
   ~TrueSinWave();
   void inputY() override;
};
