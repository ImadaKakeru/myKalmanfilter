#include "header.h"

void selectEdge(vector<Point> &edges, vector<Point> &ttContours, int size){
    int fPoint = 0, sPoint = 0;
    int i = 0,j = 0;
    int indexTmp1 = 0;
    int indexTmp2 = 0;
    int former = 0;
    int latter = 0;

    std::vector<cv::Point> tmp_1;
    std::vector<cv::Point> tmp_2;

    //std::cout << "edges = " << edges << std::endl;
    while(i < size){
        //途切れたポイントの検出
        if (cv::norm(edges[i] - edges[(i + 1)%size]) > 2){
            //printf("edgePoint[%d] = %d\n",i, edges[i]);
            i++;
            break;
        }
        i++;
    }
    // 配列1つ目の開始点を格納
    fPoint = i;
    //std::cout << "fPoint = " << fPoint << std::endl;
    while(j < size){
        former = (fPoint+ j)%size;
        latter = (fPoint+ j + 1)%size;
        //std::cout << "former , latter = " << former << "," << latter<<std::endl;
        tmp_1.push_back(edges[former]);
        indexTmp1++;
        j++;
        if (cv::norm(edges[former] - edges[latter])> 2) break;
    }
    sPoint = latter;
    //std::cout << "sPoint = " << sPoint << std::endl;
    while(j < size){
        tmp_2.push_back(edges[(sPoint+indexTmp2)%size]);
        indexTmp2++;
        j++;
    }
    // std::cout << "tmp_1" << std::endl;
    // std::cout << tmp_1 << std::endl;
    // std::cout << "tmp_2" << std::endl;
    // std::cout << tmp_2 << std::endl;

    ttContours = indexTmp1 > indexTmp2 ? tmp_1 : tmp_2;
    //std::cout << "ttContours = " << ttContours <<  std::endl;
}