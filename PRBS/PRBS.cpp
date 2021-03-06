﻿#include "stdafx.h"
#include "HighPulse.h"
#include "LowPulse.h"
#include "plot.h"
#include <memory>
#include <thread>
#include <iostream>

int main()
{
   std::vector<std::shared_ptr<Waveform>> wave;

   //これがC++のポリモーフィズムだ!!!
   for(auto i = 0; i <= 2; ++i)
   {
      wave.push_back(std::static_pointer_cast<Waveform>(std::make_shared<LowPulse>()));
      wave.push_back(std::static_pointer_cast<Waveform>(std::make_shared<LowPulse>()));
      wave.push_back(std::static_pointer_cast<Waveform>(std::make_shared<LowPulse>()));
      wave.push_back(std::static_pointer_cast<Waveform>(std::make_shared<HighPulse>()));
      wave.push_back(std::static_pointer_cast<Waveform>(std::make_shared<HighPulse>()));
      wave.push_back(std::static_pointer_cast<Waveform>(std::make_shared<HighPulse>()));
      wave.push_back(std::static_pointer_cast<Waveform>(std::make_shared<HighPulse>()));
      wave.push_back(std::static_pointer_cast<Waveform>(std::make_shared<LowPulse>()));
      wave.push_back(std::static_pointer_cast<Waveform>(std::make_shared<HighPulse>()));
      wave.push_back(std::static_pointer_cast<Waveform>(std::make_shared<LowPulse>()));
      wave.push_back(std::static_pointer_cast<Waveform>(std::make_shared<HighPulse>()));
      wave.push_back(std::static_pointer_cast<Waveform>(std::make_shared<HighPulse>()));
      wave.push_back(std::static_pointer_cast<Waveform>(std::make_shared<LowPulse>()));
      wave.push_back(std::static_pointer_cast<Waveform>(std::make_shared<LowPulse>()));
      wave.push_back(std::static_pointer_cast<Waveform>(std::make_shared<HighPulse>()));
   }

   std::vector<double> y;
   for(auto itr = wave.begin(); itr != wave.end(); ++itr)
   {
      for(auto i = 0; i < (*itr)->get_plot_size(); ++i)
      {
         y.push_back((*itr)->getYplot(i));
      }
   }

   std::vector<double> t;
   for(auto itr = wave.begin(); itr != wave.end(); ++itr)
   {
      for(auto i = 0; i < (*itr)->get_plot_size(); ++i)
      {
         t.push_back( std::distance(wave.begin(), itr) * (*itr)->get_plot_sec() + i / (*itr)->get_plot_size() * (*itr)->get_plot_sec() );
      }
   }

   plot(t, y, "t[sec]", "Amplitude", "PRBS", "plot.plt", "command.bat");



   //相互相関を取る

   std::vector<double> y2;
   std::vector<double> t2;


   const auto START_COMPARE = -8;
   const auto FIN_COMPARE = 8;

   for(auto j = START_COMPARE; j <= FIN_COMPARE; ++j){
      auto wave_copy = wave;

      if(0 <= j)
      {
         for(auto i = j; i > 0; --i)
         {
            wave_copy.insert(wave_copy.begin(), wave_copy[wave_copy.size()-1]);
            wave_copy.pop_back();
         }
      }
      else
      {
         for(auto i = j; i < 0; ++i)
         {
            wave_copy.push_back(*wave_copy.begin());
            wave_copy.erase(wave_copy.begin());
         }
      }
      std::cout << wave_copy[0]->getYplot(0) << std::endl;
      auto sum = 0.0;
      auto itr = wave.begin();
      auto itr2 = wave_copy.begin();
      auto coxr = [&](int i){ return (*itr)->getYplot(i) * (*itr2)->getYplot(i); };

      while (itr != wave.end())
      {
         for(auto i = 0; i < (*itr)->get_plot_size(); ++i)
         {
            sum += coxr(i);
         }
         ++itr;
         ++itr2;
      }

      y2.push_back(sum);
      t2.push_back(j);
   }
   plot(t2, y2, "t[sec]", "Amplitude", "PRBS", "plot2.plt", "command2.bat");
   return 0;
}
