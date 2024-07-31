#include "header.h"

void repairEdge(vector<Point> &edges, vector<Point> &newEdge) {
  int i = 0;
  int k = 0;
  int size = edges.size();
  //std::cout << "edge size = " << size << std::endl;

  // edge開始点の探索 i番目がエッジの端になる。
  while (i < size) {
    // printf("compare %d , %d\n", i, (i + 1)%size);
    if (norm(edges[i] - edges[(i + 1)%size]) > 2)
      break;
    i++;
  }

  while (k < size) {
    newEdge.push_back(edges[(i + k) % size]);
    k++;
  }
  return;
}