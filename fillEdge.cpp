#include "header.h"

void fillEdge(vector<Point> &edges, vector<Point> &ttContours){
    int size = edges.size();
    int i = 0;
    int num = 0;
    while(i < size){
        if (norm(edges[i] - edges[(i + 1)%size]) > 2){
            num++;
            //std::cout << "edge Point = " << edges[i] << std::endl;
        }
        i++;
    }
    // cout << "num = " << num << endl;
    // numに輪郭が途切れている箇所の数が格納される。この数分、輪郭を分割したい。
    // cout << edges << endl;
    // cout << "edge size = " << size << endl;
    //std::cout << "num = " << num << std::endl;
    // if(num == 1)repairEdge(edges,ttContours);
    // else selectEdge(edges, ttContours, size);
    // auto start = chrono::system_clock::now();
    selectMultiEdge(edges, ttContours, size, num);
    // auto end = chrono::system_clock::now();
    // auto dur = end - start;        // 要した時間を計算
    // auto microsec = chrono::duration_cast<chrono::microseconds>(dur).count();
    // cout << "process time = " << (float)microsec/1000 << "msec" << endl;
    // cout << "true contours = " << ttContours << endl; 
    return;
}