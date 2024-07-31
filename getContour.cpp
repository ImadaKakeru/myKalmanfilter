#include "header.h"

void getContour(Mat gradient, vector<Point> &rinnkaku){
    vector<vector<Point>> contours;
    vector<Point> tContours;
    // Mat result = cv::Mat::zeros(gradient.size(), CV_8UC3);
    findContours(gradient, contours, cv::RETR_EXTERNAL,
                     cv::CHAIN_APPROX_NONE);
                         int MaxCon = 0;
    int curCon;
    int CeleIndex;
    for (int j = 0; j < contours.size(); j++) {
        curCon = contours[j].size();
        if (MaxCon < curCon) {
            MaxCon = curCon;
            CeleIndex = j;
        }
    }
    // imwrite(outPath, result);

    deleteEndEdge(contours[CeleIndex], tContours, gradient.rows - 1,
        gradient.cols - 1);
    fillEdge(tContours, rinnkaku);
    // Mat result;
    // Mat result = Mat::zeros(gradient.size(),CV_8UC3);
    // for (int k = 0; k < rinnkaku.size(); ++k) {
    //     int x = rinnkaku[k].x;
    //     int y = rinnkaku[k].y;
    //     result.at<Vec3b>(y, x) = Vec3b(255, 255, 255); // BGRの順で色を指定
    // }
    // imwrite(outPath, result);
    // cout << rinnkaku << endl;
    return;
}