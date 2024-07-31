#include "header.h"

template <typename T>

double calcMean(std::vector<T> timeSeries){
    float sum=0;
    for(int i=0 ; i < timeSeries.size() ; i++){
        sum += timeSeries[i];
    }
    return (T)(sum/timeSeries.size());
}