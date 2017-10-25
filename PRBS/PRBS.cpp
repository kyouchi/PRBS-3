// PRBS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "HighPulse.h"
#include "LowPulse.h"
#include "plot.h"


int main()
{
   HighPulse h;
   LowPulse l;

   std::vector<Waveform> wave;
   //Copyコンストラクタを使う
   for(auto i = 0; i <= 2; ++i)
   {
      wave.push_back(l);
      wave.push_back(l);
      wave.push_back(l);
      wave.push_back(h);
      wave.push_back(h);
      wave.push_back(h);
      wave.push_back(h);
      wave.push_back(l);
      wave.push_back(h);
      wave.push_back(l);
      wave.push_back(h);
      wave.push_back(h);
      wave.push_back(l);
      wave.push_back(l);
      wave.push_back(h);
   }
   
   std::vector<double> y;
   std::vector<double> t;
   
   for(auto i = 0; i < wave.size(); ++i)
   {
      for(auto j = 0; j < wave[i].get_plot_size(); ++j)
      {
         y.push_back(wave[i].getYplot(j));
      }
   }

   for(double i = 0; i < wave.size() * wave[0].get_plot_size() * wave[0].get_plot_sec(); i+=wave[0].get_plot_sec())
   {
      t.push_back(i);
   }

   plot(t, y, "t[sec]", "Amplitude", "PRBS", "plot.dat", "command.bat");

   return 0;
}

