#include "header.h"

double calcAngle(Point &pt1, Point &pt2, Point &pt3) {
  // ポインタを使用してベクトルを計算
  int vec1x = pt1.x - pt2.x;
  int vec1y = pt1.y - pt2.y;

  int vec2x = pt3.x - pt2.x;
  int vec2y = pt3.y - pt2.y;

  double dotProduct = vec1x * vec2x + vec1y * vec2y;
  double length = sqrt(vec1x * vec1x + vec1y * vec1y) *
                  sqrt(vec2x * vec2x + vec2y * vec2y);

  double angle = acos(dotProduct / length);
  // std::cout << angle* 180.0 / CV_PI << std::endl;
  return angle * 180.0 / CV_PI;
}