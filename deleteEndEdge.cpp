#include "header.h"

void deleteEndEdge(vector<Point> &edges, vector<Point> &newEdge, int height, int width) {
  int i = 0;

  while (i < edges.size()) {
    if (edges[i].x == 0 || edges[i].y == 0) {
      i++;
      continue;
    }
    if (edges[i].x == width || edges[i].y == height) {
      i++;
      continue;
    }
    // ここに、画像の一番上、一番下の要素を消す処理を加える。
    newEdge.push_back(edges[i]);
    i++;
  }
    return;
}