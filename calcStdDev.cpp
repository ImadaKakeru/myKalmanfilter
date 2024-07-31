#include "header.h"

template <typename T>
double calcStdDev(std::vector<T> timeSeries, T mean){
  double sumSquare=0;

  for (int i = 0; i < timeSeries.size(); i++) {
    sumSquare += (timeSeries[i] - mean) * (timeSeries[i] - mean);
  }

  double variance = sumSquare / (timeSeries.size() - 1);

  return std::sqrt(variance);
}