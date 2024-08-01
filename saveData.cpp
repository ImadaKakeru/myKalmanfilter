#include "header.h"


void saveData(vector<double> &errorsNomal, vector<double> &errorsKalman, string Path){
    ofstream outFile;
    outFile.open(Path);
    outFile << "time,";
    outFile << "Normal,";
    outFile << "Kalman" << "\n";
    for(int i = 0 ; i < errorsNomal.size(); i++){
        outFile << i << ",";
        outFile << errorsNomal[i];
        outFile << ",";
        outFile << errorsKalman[i];
        outFile << "\n";
    }
    return;
}