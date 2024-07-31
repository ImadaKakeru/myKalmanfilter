#include "header.h"
#include "Kalman.h"


void procKalman(vector<Point> &KLheads, vector<Point> heads){
    float dt = 0.1;
    Kalman::setIdentityMatrix();
    Kalman::setInitialMatrix(dt);
    Point position(0,0);
    for(int i = 0 ; i < heads.size() ; i++){
        Kalman::setY(heads[i]);
        Kalman::predicting();
        Kalman::updating();
        KLheads.push_back(Kalman::getY());
        cout << "observed Position = " << heads[i] << endl;
        cout << "filtered Position = " << Kalman::getY() << endl;
        Kalman::prepare();
    }
    return;
}