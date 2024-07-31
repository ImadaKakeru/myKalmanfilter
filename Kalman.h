#include <Eigen/Core>
#include <Eigen/Dense>

using namespace Eigen;

// 単位行列
Matrix<double ,4,4> I_4 = Matrix4d::Identity();
Matrix<double ,2,2> I_2 = Matrix2d::Identity();

class Kalman{

public:
    static Matrix<double, 4,4> I_4;
    static Matrix<double, 2,2> I_2;

    // 単位行列を設定する関数
    static void setIdentityMatrix(Matrix<double, 4,4> I_4, Matrix<double, 2,2> I_2);
};