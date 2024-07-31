#include "header.h"


void detectHead(vector<Mat> images, vector<Point> &heads){
    Point head;
    vector<Point> contours;
    // cout << "image vector size = " << images.size() << endl;
    for(int i = 0 ; i < images.size() ; i++){
        // cout << "frame_number = "<< i << endl;
        Mat rszImg(Size(Width/4, Height/4), CV_8UC1, Scalar(255));
        Mat gradient;
        resize(images[i], rszImg, rszImg.size(),0, 0,INTER_LINEAR);
        GaussianBlur(rszImg, rszImg, Size(5,5), 5, 5, 4);
        threshold(rszImg, gradient, 150, 255, THRESH_BINARY);
        bitwise_not(gradient,gradient);
        // imshow("window", gradient);
        // waitKey(0);
        getContour(gradient, contours);

        head = searchHead(contours, 30);
        // head = contours[index];
        head.x *= 4;
        head.y *= 4 ;
        heads.push_back(head);
        contours.clear();
        // cout << "head = " << head << endl;
    }
    return;
}