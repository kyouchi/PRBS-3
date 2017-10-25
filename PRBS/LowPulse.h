#pragma once
#include "Waveform.h"
class LowPulse :
   public Waveform
{
public:
   LowPulse();
   ~LowPulse();
   void inputY() override;
};

