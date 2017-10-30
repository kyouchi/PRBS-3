#pragma once
#include "Waveform.h"
class ReverseSinWave :
   public Waveform
{
public:
   ReverseSinWave();
   explicit ReverseSinWave(const Waveform &obj) : Waveform(obj){};//CopyConstructor
   ~ReverseSinWave();
   void inputY() override;
};
