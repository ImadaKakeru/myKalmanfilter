#include "Kalman.h"

// 静的メンバー変数の定義と初期化
// 静的メンバー変数の定義と初期化
Matrix<float, 4, 4> Kalman::I_4;
Matrix<float, 2, 2> Kalman::I_2;

MatrixXf Kalman::C(2, 4);
MatrixXf Kalman::C_t(4, 2);

MatrixXf Kalman::Ad(4, 4);
MatrixXf Kalman::Ad_t(4, 4);

MatrixXf Kalman::Q(4, 4);
MatrixXf Kalman::R(2, 2);
MatrixXf Kalman::G(4, 2);

MatrixXf Kalman::w_k(2, 2);

// 測定値および、その予測値
Vector2f Kalman::Yt;
Vector2f Kalman::Ytt_1;

// 時刻tにおける観測ノイズと予測値誤差の和を示す共分散行列
MatrixXf Kalman::S(2,2);
// 時刻tにおけるカルマンゲイン
MatrixXf Kalman::Kt(4,2);

// 時刻t-1における誤差共分散行列
MatrixXf Kalman::Pt_1t_1(4,4);
// 時刻tにおける誤差共分散行列
MatrixXf Kalman::Ptt(4,4);
// 時刻t|t-1における誤差共分散行列の期待値
MatrixXf Kalman::Ptt_1(4,4);

// 時刻t-1における状態変数の期待値
Vector4f Kalman::Xt_1t_1;
// 時刻t-1の情報を用いて予測した時刻tにおける状態変数
Vector4f Kalman::Xtt_1;
// 時刻tにおける状態変数の期待値
Vector4f Kalman::Xtt;

Point Kalman::getY(){
    Vector2f Y_hat = C * Xtt;
    Point tmp;
    tmp.x = Y_hat(0);
    tmp.y = Y_hat(1);

    return tmp;
}

void Kalman::setY(Point loc){
    Yt(0) = loc.x;
    Yt(1) = loc.y;
    return;
}

void Kalman::setIdentityMatrix(){
    I_4 = Matrix4f::Identity();
    I_2 = Matrix2f::Identity();
}

void Kalman::setInitialMatrix(double dt){
    Ad << 1,0,dt,0,
          0,1,0,dt,
          0,0,1,0,
          0,0,0,1;
    Ad_t = Ad.transpose();

    C << 1,0,0,0,
         0,1,0,0;   
    C_t = C.transpose();

    R << 1,0,
         0,1;
    
    w_k << 1,0,
           0,1;

    Q << 1,0,0,0,
         0,1,0,0,
         0,0,1,0,
         0,0,0,1;
    
    Pt_1t_1 << 1,0,0,0,
               0,1,0,0,
               0,0,1,0,
               0,0,0,1;

    // Yt_1t_1 << 320,240;
    Xt_1t_1 << 320,240,0,0;
}

void Kalman::updating(){
    // 予測誤差、観測後差の和の更新
    S = R + C * Ptt_1 * C_t; 

    // カルマンゲインの更新
    Kt = Ptt_1 * C_t * S.inverse();

    // 誤差共分散行列Pの更新
    Ptt = (I_4 - Kt * C) * Ptt_1;
    
    // 状態変数Xの更新
    Xtt = Xtt_1 + Kt * (Yt - Ytt_1);

    return;
}

void Kalman::predicting(){
    // 現在の時刻における状態の期待値
    Xtt_1 = Ad * Xt_1t_1;

    // 観測値の予測値
    Ytt_1 = C * Xtt_1;

    // 予測誤差の共分散行列
    Ptt_1 = Ad * Pt_1t_1 * Ad_t + Q;
    return;
}

void Kalman::prepare(){
    Xt_1t_1 = Xtt;
    Pt_1t_1 = Ptt;
    return;
}