#include "header.h"

void getImages(vector<Mat> &images, int frameNum){
    string number;
    string png = ".png";
    for(int i = 0; i < frameNum ; i++){
        // cout << "frame_number = "<< i << endl;
        number = to_string(i);
        Mat input = imread(inputPath+number + png,0);
        if(input.empty()){
            cout << "input is empty" << endl;
            return;
        }
        // imshow("window",input);
        // waitKey(0);
        images.push_back(input);
    }
    return;
}