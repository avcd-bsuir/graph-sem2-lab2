#ifndef MAT3_HPP
#define MAT3_HPP

#include <array>

#include "Vec3.hpp"

class Mat3 {
    private:
    public:
        std::array<double, 9> data;

        Mat3();
        Mat3(std::array<double, 9>);
        Mat3(double);
        Mat3(double, double, double);
        Mat3(double, double, double, double, double, double, double, double, double);
        ~Mat3();

        double determinant();
};

// Comapring
bool operator == (const Mat3 & first, const Mat3 & second);

// Adding
Mat3 operator + (const Mat3 & first, const Mat3 & second);
Mat3 operator += (Mat3 & first, const Mat3 & second);

// Subtracting
Mat3 operator - (const Mat3 & first, const Mat3 & second);
Mat3 operator -= (Mat3 & first, const Mat3 & second);

// Multiplying
Mat3 operator * (const Mat3 & first, const Mat3 & second);
Mat3 operator *= (Mat3 & first, const Mat3 & second);
Vec3 operator * (const Mat3 & first, const Vec3 & second);
Vec3 operator * (const Vec3 & first, const Mat3 & second);

Mat3 operator * (const Mat3 & first, const float second);
Mat3 operator *= (Mat3 & first, const float second);
Mat3 operator * (const float second, const Mat3 & first);

// Dividing
Mat3 operator / (const Mat3 & first, const float second);
Mat3 operator /= (Mat3 & first, const float second);

#endif
