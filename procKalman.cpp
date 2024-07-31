#include "header.h"
#include "Kalman.h"


void procKalman(vector<Point> &KLheads, vector<Point> heads){
    float dt = 0.1;
    Kalman::setIdentityMatrix();
    Kalman::setInitialMatrix(dt);
    for(int i = 0 ; i < heads.size() ; i++){
        Kalman::setY(heads[i]);
        Kalman::predicting();
        Kalman::updating();
        KLheads.push_back(Kalman::getY());
    }
    return;
}