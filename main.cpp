#include "header.h"

int main(void){
    vector<Point> contours;
    Point head;
    int frameNum = 250;
    // image5:0~603
    // image5 頭が見えてる: 0~537
    vector<Mat> images;
    vector<Point> heads;
    vector<double> errors;
    vector<Point> groundTruth;
    // string groundTruthPath = "../groundTruth/groundTruth5.csv";
    cout << "getting images..." << endl;
    getImages(images, frameNum);

    cout << "detecting head coordinates..." << endl;
    detectHead(images, heads);

    cout << "reading groundTruth..." << endl;
    readGT(groundTruthPath, groundTruth);

    cout << "calculating position error..." << endl;
    calcError(errors, heads, groundTruth);
    return 0;
}