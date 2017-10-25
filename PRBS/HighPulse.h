#pragma once
#include "Waveform.h"
class HighPulse :
   public Waveform
{
public:
   HighPulse();
   ~HighPulse();
   void inputY() override;
};

