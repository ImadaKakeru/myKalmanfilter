#include <iostream>
#include <time.h>
#include <cmath>
#include <fstream>
#include <string>
#include <stdio.h>

#define float16_t opencv_broken_float16_t
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#undef float16_t

using namespace cv;
using namespace std;

#define Width 640
#define Height 480
#define inputPath "../../dataSet/image4/img"
#define groundTruthPath "../groundTruth/groundTruth4.csv"
#define outputPath "./errorCSV/error4.csv"
double calcAngle(Point &pt1, Point &pt2, Point &pt3);
Point searchHead(vector<Point> edges, int d);
void selectEdge(vector<Point> &edges, vector<Point> &ttContours, int size);
void fillEdge(vector<Point> &edges, vector<Point> &ttContours);
void getContour(Mat gradient, vector<Point> &rinnkaku);
void deleteEndEdge(vector<Point> &edges, vector<Point> &newEdge, int height, int width);
void repairEdge(vector<Point> &edges, vector<Point> &newEdge);
void readGT(string path, vector<Point> &groundTrtuth);
void getImages(vector<Mat> &images, int frameNum);
void detectHead(vector<Mat> images, vector<Point> &heads);
void calcError(vector<double> &errors, vector<Point> &heads, vector<Point> &groundTruth);
void readGT(string path, vector<Point> &groundTrtuth);
void selectMultiEdge(vector<Point> &edges, vector<Point> &ttContours, int size, int num);
void procKalman(vector<Point> &KLheads, vector<Point> heads);
void saveData(vector<double> &errorsNomal, vector<double> &errorsKalman, string Path);