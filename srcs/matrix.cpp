#include "matrix.hpp"

// identity matrix
Matrix4f::Matrix4f() {
    for (int i = 0; i < 16; ++i)
        data[i] = 0.0f;
    data[0] = 1.0f;
    data[5] = 1.0f;
    data[10] = 1.0f;
    data[15] = 1.0f;
}

Matrix4f::Matrix4f(const Matrix4f& src) {
    for (int i = 0; i < 16; ++i)
        data[i] = src.data[i];
}

Matrix4f& Matrix4f::operator=(const Matrix4f& src) {
    if (this != &src) {
        for (int i = 0; i < 16; ++i)
            data[i] = src.data[i];
    }
    return *this;
}



void Matrix4f::print() const {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << data[i * 4 + j] << " ";
        }
        std::cout << std::endl;
    }
}