#include "header.h"

template <typename T>
double calcMean(std::vector<T> timeSeries){
    float sum=0;
    for(int i=0 ; i < timeSeries.size() ; i++){
        sum += timeSeries[i];
    }
    return (T)(sum/timeSeries.size());
}

template <typename T>
double calcStdDev(std::vector<T> timeSeries, T mean){
  double sumSquare=0;

  for (int i = 0; i < timeSeries.size(); i++) {
    sumSquare += (timeSeries[i] - mean) * (timeSeries[i] - mean);
  }

  double variance = sumSquare / (timeSeries.size() - 1);

  return std::sqrt(variance);
}