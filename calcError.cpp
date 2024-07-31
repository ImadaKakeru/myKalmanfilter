#include "header.h"
#include "calcStatistics.h"

void calcError(vector<double> &errors, vector<Point> &heads, vector<Point> &groundTruth){

    int size = heads.size();
    for(int i = 0 ; i < size ; i++){
        // cout << "head[" << i <<"] = "<< heads[i] << endl;
        // cout << "groundTruth[" << i <<"] = "<< groundTruth[i] << endl;
        // cout << "error[" << i <<"] = "<< norm(heads[i] - groundTruth[i]) << endl;
        errors.push_back(norm(heads[i] - groundTruth[i]));
    }
    cout << "average Error = " << calcMean(errors)<< endl;
    cout << "stdDev Error = " << calcStdDev(errors, calcMean(errors))<< endl;
    return;
}