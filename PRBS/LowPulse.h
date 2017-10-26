#pragma once
#include "Waveform.h"
class LowPulse :
   public Waveform
{
public:
   LowPulse();
   explicit LowPulse(const Waveform &obj) : Waveform(obj){};//CopyConstructor
   ~LowPulse();
   void inputY() override;
};

