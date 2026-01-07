#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>

class Matrix4f {
    private:
        float data[16];

    public:
        Matrix4f();
        Matrix4f(const Matrix4f& src);
	    // ~Matrix4f();
	    Matrix4f&	operator=(const Matrix4f& src);

        Matrix4f operator*(const Matrix4f& rhs) const;

        void print() const;

};

#endif // MATRIX_HPP