#include "stdafx.h"
#include "plot.h"
#include <iostream>

bool plot::printFile()
{
   std::cout << "plot[Info]:" << filename << "に書き込んでいます。" << std::endl;

   writing_file.open(filename, std::ios::out);
   try
   {
      if (!this->writing_file.is_open()) throw "指定したファイルが開けませんでした。";
      if (this->x.size() != this->y.size()) throw "std::vectorの変数のsizeが違います。";
      if (this->xlabel.empty()) throw "x軸ラベルが無記名です。";
      if (this->ylabel.empty()) throw "y軸ラベルが無記名です。";
      if (this->graph_title.empty()) throw "グラフタイトルが無記名です。";
      if (this->filename.empty()) throw "ファイル名が無記名です。";
   }
   catch(const char* Error)
   {
      std::cout << "plot[Error]:" << Error <<std::endl;
      return false;
   }

   //ヘッダーの作成
   writing_file << "# " << xlabel << " " << ylabel << " " << std::endl;

   for(auto i = 0; i < x.size(); ++i)
   {
      writing_file << x[i] << " " << y[i] << std::endl;
   }

   std::cout << "plot[Info]:" << filename << "に書き込みが終わりました。" << std::endl;
   return true;
}

bool plot::printCommandFile()
{
   std::cout << "plot[Info]:GNU Plot用のコマンドファイルを生成します。" << std::endl;
   std::cout << "plot[Info]:" << command_filename << "に書き込んでいます。" << std::endl;

   writing_command_file.open(command_filename, std::ios::out);
   try
   {
      if (!this->writing_command_file.is_open()) throw "指定したコマンドファイルが開けませんでした。";
      if (this->command_filename.empty()) throw "コマンドファイル名が無記名です。";
   }
   catch(const char*  Error)
   {
      std::cout << "plot[Error]:" << Error <<std::endl;
      return false;
   }

   writing_command_file << "set encoding utf8" << std::endl;
   writing_command_file << "set xl \""<< xlabel << "\"" << std::endl;
   writing_command_file << "set yl \""<< ylabel << "\"" << std::endl;
   writing_command_file << "set grid" << std::endl;
   writing_command_file << "set title \"" << graph_title << "\""  << std::endl;
   writing_command_file << "plot \"" << filename << "\" " << "with lp" << std::endl;

   std::cout << "plot[Info]:" << command_filename << "に書き込みが終わりました。" << std::endl;
   return true;
}

plot::plot(std::vector<double> x, std::vector<double> y, std::string xlabel, std::string ylabel, std::string graph_title, std::string filename, std::string command_filename = "command.bat") : x(x), y(y), xlabel(xlabel), ylabel(ylabel), graph_title(graph_title), filename(filename), command_filename(command_filename)
{
   try
   {
      if(!this->printFile()) throw "printFile()に失敗";
      if(!this->printCommandFile()) throw"printcommandFile()に失敗";

   }
   catch(const char*  Error)
   {
      std::cout << "plot[Error]:" << Error << std::endl;
      return;
   }

   std::cout << "plot[Info]:" << "全ての処理を終了" << std::endl;

   //コマンド用batをwgnuplotで開く
   //auto command = "\"C:\\\\Program Files (x86)\\gnuplot\\bin\\wgnuplot.exe\" -persist " + command_filename;
   //if (system(command.c_str())) std::cout << "plot[Error]:" << command.c_str() << " " << "GNU Plotが開けません。" << std::endl;

   return;
}

plot::~plot()
{
   return;
}
