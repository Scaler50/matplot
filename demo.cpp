#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include "matplot_lib/matplot.hpp"
#include <chrono>

int main(int argc, char** argv)
{
  // 1. create a plot object
  MatPlot matplot;
  // 2. configure params
  matplot.coordinate_auto = true;
  matplot.update_rate = 0.0000001;
  std::string name = "y";
  int n = 1000;
  // 3. create input (vector)
  std::vector<double> x, y, z, p;

  for(int i=0; i<n; i++) {
      // 4. push back signals into vector
      x.push_back(i*i);
      y.push_back(sin(2*M_PI*i/360.0));
      z.push_back(log(i));
      p.push_back(i);

      if (i % 10 == 0) {
        // 5. call plot function
        matplot.PlotDisplay(x, y, name);
      }
  }
  return 0;
}
