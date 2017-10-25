#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <complex>

class plot
{
private:
   std::ofstream writing_file;
   std::ofstream writing_command_file;

   std::vector<double> x;
   std::vector<double> y;
   std::string xlabel;
   std::string ylabel;
   std::string graph_title;
   std::string filename;
   std::string command_filename;

   bool printFile();
   bool printCommandFile();

public:
   plot(std::vector<double> x, std::vector<double> y, std::string xlabel, std::string ylabel, std::string graph_title, std::string Filename, std::string command_filename);
   ~plot();
};
