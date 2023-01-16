#include <Eigen/Dense>
#include <iostream>
#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <string>

using EigenRowMajMatrixXd = Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic,Eigen::RowMajor>;

void fill(Eigen::Ref<EigenRowMajMatrixXd> matrix, double value) {
    std::cout << "C++ code: executing fill()" << std::endl;
    for (int r = 0; r < matrix.rows(); r++) {
        for (int c = 0; c < matrix.cols(); c++) {
            std::cout << "C++ code: modifying " << matrix(r, c) << " to " << std::to_string(value) << std::endl; 
            matrix(r, c) = value;
        }
    }
}

int add(int i, int j) {
    const int result = i + j;
    const std::string strFunctionSignature = "add(" + std::to_string(i) + "," + std::to_string(j) + ")";
    const std::string strResult = "=" + std::to_string(result);
    std::cout << "C++ code: executing " << strFunctionSignature << strResult << std::endl;
    return result;
}

PYBIND11_MODULE(example_functions, module) {
    module.def("add", &add, "A function that adds two numbers");
    module.def("fill", &fill, "Set every value of a matrix to a given value");
}
