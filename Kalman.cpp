#include "Kalman.h"


// 状態方程式における係数行列C
Eigen::MatrixXf C(2,4);
Eigen::MatrixXf C_t(4,2);

// 離散化した状態方程式における係数行列Ad
Eigen::MatrixXf Ad(4,4);
Eigen::MatrixXf Ad_t(4,4);
// // 離散化した状態方程式における係数行列Bd
// Eigen::MatrixXf Bd(4,2);
// Eigen::Vector2f u;

// 状態方程式のノイズ項、測定値のノイズ項、予測誤差のノイズ項
Eigen::MatrixXf Q(4,4);
Eigen::MatrixXf R(2,2);
Eigen::MatrixXf P(4,4);
Eigen::MatrixXf G(4,2);

//白色ノイズ項
Eigen::MatrixXf w_k(2,2);

void Kalman(){
    return;
}
