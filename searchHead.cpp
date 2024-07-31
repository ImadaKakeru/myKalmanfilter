#include "header.h"

Point searchHead(vector<Point> edges, int d) {
  int i = 0;
  Point one, two, three;
  double angle = 70;
  Point loc;
  double ang;
  int size = edges.size();
  // int index = 0;
  Point center;
  center.x = Width/4;
  center.y = Height/4;
  //cout << "edge size = " << size << endl;
  //cout << "i+2 * d = " << i+2 *d << endl;
  while (i + 2 * d < size) {
    //std::cout << "angle = " << angle << std::endl;
    one = edges[i];
    two = edges[i + d];
    three = edges[i + 2 * d];

    ang = calcAngle(one, two, three);
    //std::cout << "( loc,ang )= " << two << "," << ang << std::endl;

    // result.at<uchar>(two.y,two.x) = (int)ang * 180.0 / CV_PI;
    if (ang < angle) {
      // if(norm(center - two) > 200)continue;
      // index = i+d;
      //std::cout << "ang = " << ang << std::endl;
      angle = ang;
      loc = two;

      // std::cout << "( loc,ang )= " << two << "," << ang << std::endl;
      // std::cout << "( one,three )= " << one << "," << three << std::endl;
    }
    i++;
  }
  //cout << "Ywah" << endl;
  // std::cout << "angle = " << angle << std::endl;
  // cout << loc << endl;
  return loc;
}