// Copyright 2023 nicolò salimbeni andrea de vita
#include "../include/AnalysisUtilities.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

void AnalysisUtilities::ProgressBar(float progress, std::string title, int present_bar = 1, int total_bars = 1)
{
  /*
  arguments explenation: progress as a fraction, ex. 0.3 will be 30% ecc..
                         present bar is an integer
                         total bar is the total number of progress bars in the software

  This function print on screen a progress bar like:

  [1/3] title [==========               ]38%

  */

  // to make is faster print only if the % is an integer
  if (100 * progress - (int)(progress * 100) != 0)
  {
    return;
  }

  int barWidth = 70;
  std::cout << "Total (" << present_bar << "/" << total_bars << ") ";
  std::cout << std::setw(30) << title << " [";
  int pos = barWidth * progress;
  for (int i = 0; i < barWidth; ++i)
  {
    if (i < pos)
      std::cout << "=";
    else if (i == pos)
      std::cout << ">";
    else
      std::cout << " ";
  }
  std::cout << "] " << int(progress * 100.0) << " %\r";
  if (progress == 1)
    std::cout << std::endl;
  std::cout.flush();
}
