#include "header.h"

void selectMultiEdge(vector<Point> &edges, vector<Point> &ttContours, int size, int num){
    int fPoint = 0;
    // int sPoint = 0;
    int i = 0;
    int former = 0;
    int latter = 0;
    vector< vector<Point> > edgeVectors(num);
    int vectorIndex = 0;
    vector<Point> LongestVec;
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
    int j = 0;
    while(vectorIndex < num && j < size){
        former = (fPoint+ j)%size;
        latter = (fPoint+ j + 1)%size;
        edgeVectors[vectorIndex].push_back(edges[former]);
        j++;
        if(norm(edges[former] - edges[latter])>2){
            vectorIndex++;
            j++;
            continue;
        }
    }
    // cout << "num = " << num << endl;
    // for(int l = 0 ; l < num ; l++){
    //     cout << edgeVectors[l] << endl;
    // }
    if(num == 1){
        ttContours = edgeVectors[0];
        return;
    }
    for(int k = 0 ; k < num - 1 ; k++){
        if(edgeVectors[k].size() > edgeVectors[k+1].size())
            LongestVec = edgeVectors[k];
        else
            LongestVec = edgeVectors[k+1];
    }
    ttContours = LongestVec;
    // cout << "end vector process = "<<ttContours << endl;
}