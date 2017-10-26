#pragma once
#include "Waveform.h"
class HighPulse :
   public Waveform
{
public:
   HighPulse();
   explicit HighPulse(const Waveform &obj) : Waveform(obj){};//CopyConstructor
   ~HighPulse();
   void inputY() override;
};

