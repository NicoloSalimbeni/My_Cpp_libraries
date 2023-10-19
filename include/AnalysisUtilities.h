// Copyright 2023 nicolò salimbeni
#ifndef AnalysisUtilities_h
#define AnalysisUtilities_h

/*
  This class contains general functions and object than can be usefull
  in any data analysis.
*/

#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class AnalysisUtilities
{
  public:
  AnalysisUtilities();
  ~AnalysisUtilities();

  // not tamplate methods (commented in the .cpp file)
  static void ProgressBar(float progress, std::string title, int present_bar, int total_bars);

  // template methods
  template <class T>
  static std::vector<T> LoadVector(const std::string &filename, int columnNumber)
  {
    /*
    arguments explanation: filename is a string with the file name you want to load
                           columnNumber is the column number you want to load in the vector counting from 1

    This function takes a file.txt in input with some columns, select a specific column and load it inside
    a vector<T>. It allows comments in the .txt file with the # char at the beginning of the line
    */
    std::ifstream file(filename);
    if (!file)
    {
      std::cerr << "Failed to open the file." << std::endl;
      exit(EXIT_FAILURE);
    }

    std::vector<std::vector<T>> columns; // Vector to store columns
    std::string                 line;
    int                         numColumns = 0;
    while (std::getline(file, line))
    {
      if (line.empty() || line[0] == '#')
      {
        continue; // Skip empty lines and lines starting with "#"
      }

      std::istringstream iss(line);
      std::vector<T>     row;
      T                  value;
      while (iss >> value)
      {
        row.push_back(value);
      }

      if (numColumns == 0)
      {
        numColumns = row.size();
      }
      else if (row.size() != numColumns)
      {
        std::cerr << "Error: Inconsistent number of columns." << std::endl;
        file.close();
        exit(EXIT_FAILURE);
      }

      columns.push_back(row);
    }

    file.close();

    if (columnNumber - 1 >= numColumns || columnNumber < 1)
    {
      std::cerr << "Error: Column number " << columnNumber << " out of range." << std::endl;
      exit(EXIT_FAILURE);
    }

    std::vector<T> columnVector;
    for (const auto &row : columns)
    {
      columnVector.push_back(row[columnNumber - 1]);
    }

    return columnVector;
  }

  // template functions must be declared and defined in the same file
  // put all of them below here
  template <class T>
  static void Reorder(T *v, int n, const std::string order = "ascending")
  {
    // order a vector, array, whatever with ascending or descending order
    T tmp;
    if (order == "ascending")
    {
      for (int i = 0; i < n; i++)
      {
        for (int j = i; j < n; j++)
        {
          if (v[j] < v[i])
          {
            tmp  = v[i];
            v[i] = v[j];
            v[j] = tmp;
          }
        }
      }
    }

    if (order == "descending")
    {
      for (int i = 0; i < n; i++)
      {
        for (int j = i; j < n; j++)
        {
          if (v[j] > v[i])
          {
            tmp  = v[i];
            v[i] = v[j];
            v[j] = tmp;
          }
        }
      }
    }
  }

  template <class T>
  static double Mean(const T &v, int n)
  {
    // compute the mean value of a list v
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
      sum += v[i];
    }
    return sum / n;
  }

  template <class T>
  static double Rms(const T &v, int n)
  {
    // compute the RMS value of a list v
    double mean = Mean(v, n);
    double sum  = 0;
    for (int i = 0; i < n; i++)
    {
      sum += std::pow(v[i] - mean, 2);
    }

    // pay attenction to the n-1 at the denominator
    return std::sqrt(sum / (n - 1));
  }

  template <class T>
  static double FindMax(const T &v, int n)
  {
    double max = -10e10;
    for (int i = 0; i < n; i++)
    {
      double tmp = v[i];
      if (tmp > max)
      {
        max = tmp;
      }
    }

    return max;
  }

  template <class T>
  static double FindMin(const T &v, int n)
  {
    double min = 10e10;
    for (int i = 0; i < n; i++)
    {
      double tmp = v[i];
      if (tmp < min)
      {
        min = tmp;
      }
    }

    return min;
  }
};

#endif
