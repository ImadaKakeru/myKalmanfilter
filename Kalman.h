#ifndef KALMAN_H
#define KALMAN_H

#include <Eigen/Core>
#include <Eigen/Dense>
#include "header.h"
using namespace Eigen;


class Kalman{

public:
    static Point prePosition;
    // static Point Position;
    static Matrix<float, 4,4> I_4;
    static Matrix<float, 2,2> I_2;

    // 状態方程式における係数行列C
    static MatrixXf C;
    static MatrixXf C_t;

    // 離散化した状態方程式における係数行列Ad
    static MatrixXf Ad;
    static MatrixXf Ad_t;

    // 状態方程式のノイズ項、測定値のノイズ項、予測誤差のノイズ項
    static MatrixXf Q;
    static MatrixXf R;
    static MatrixXf G;

    //白色ノイズ項
    static MatrixXf w_k;

    // 状態変数
    static Vector4f Xt_1t_1;
    static Vector4f Xtt_1;
    static Vector4f Xtt;

    static MatrixXf S;
    static MatrixXf Kt;

    // 時刻t-1における誤差共分散行列
    static MatrixXf Pt_1t_1;
    // 時刻tにおける誤差共分散行列
    static MatrixXf Ptt;
    // 時刻t|t-1における誤差共分散行列の期待値
    static MatrixXf Ptt_1;   
    // 測定値および、その予測値
    static Vector2f Yt;
    static Vector2f Ytt_1;

    // 観測値Yを得る関数. 今回はx,yの位置を得るので、引数はPoint
    static void setY(Point loc);
    // フィルタリングした値を引き出す関数
    static Point getY(); 

    // 単位行列を設定する関数
    static void setIdentityMatrix();
    static void setInitialMatrix(float dt);

    //カルマンフィルタの更新ステップ
    static void updating();
    //カルマンフィルタの予測ステップ
    static void predicting();

    //次の時刻での処理に備える。
    static void prepare();
};

#endif // KALMAN_H