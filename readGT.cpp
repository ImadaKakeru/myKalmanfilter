#include "header.h"

void readGT(string path, vector<Point> &groundTrtuth){
    ifstream inFile;
    inFile.open(path);
    if(!inFile){
        printf("cannnot open csv file\n");
        return;
    }
    string line;
    while(getline(inFile, line)){
        stringstream ss(line);
        string locX, locY;
        Point tmp;
        getline(ss,locX,',');
        getline(ss, locY, ',');

        tmp.x = stoi(locX);
        tmp.y = stoi(locY);

        groundTrtuth.push_back(tmp);
    }
    return;
}