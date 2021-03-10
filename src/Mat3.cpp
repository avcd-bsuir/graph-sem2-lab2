#include "Mat3.hpp"

Mat3::Mat3() {
    this->data = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    // this->data[0][0] = 0; this->data[0][1] = 0; this->data[0][2] = 0;
    // this->data[1][0] = 0; this->data[1][1] = 0; this->data[1][2] = 0;
    // this->data[2][0] = 0; this->data[2][1] = 0; this->data[2][2] = 0;
}

Mat3::Mat3(std::array<double, 9> data) {
    this->data = data;
}

Mat3::Mat3(double a) {
    this->data = { a, a, a, a, a, a, a, a, a };
    // this->data[0][0] = a; this->data[0][1] = a; this->data[0][2] = a;
    // this->data[1][0] = a; this->data[1][1] = a; this->data[1][2] = a;
    // this->data[2][0] = a; this->data[2][1] = a; this->data[2][2] = a;
}

Mat3::Mat3(double a, double b, double c) {
    this->data = { a, 0, 0, 0, b, 0, 0, 0, c };
    // this->data[0][0] = a; this->data[0][1] = 0; this->data[0][2] = 0;
    // this->data[1][0] = 0; this->data[1][1] = b; this->data[1][2] = 0;
    // this->data[2][0] = 0; this->data[2][1] = 0; this->data[2][2] = c;
}

Mat3::Mat3(double a, double b, double c, double d, double e, double f, double g, double h, double i) {
    this->data = { a, b, c, d, e, f, g, h, i };
    // this->data[0][0] = a; this->data[0][1] = b; this->data[0][2] = c;
    // this->data[1][0] = d; this->data[1][1] = e; this->data[1][2] = f;
    // this->data[2][0] = g; this->data[2][1] = h; this->data[2][2] = i;
}

Mat3::~Mat3() {
}

double Mat3::determinant() {
    return this->data[0] * this->data[4] * this->data[8] +
           this->data[3] * this->data[7] * this->data[2] +
           this->data[1] * this->data[5] * this->data[6] -
           this->data[2] * this->data[4] * this->data[6] -
           this->data[1] * this->data[3] * this->data[8] -
           this->data[5] * this->data[7] * this->data[0];
}

/*
 * Comparing
 */

bool operator == (const Mat3 & first, const Mat3 & second) {
    return first.data == second.data;
}

/*
 * Adding
 */

Mat3 operator + (const Mat3 & first, const Mat3 & second) {
    std::array<double, 9> data;
    for (int i = 0; i < 9; i++)
        data[i] = first.data[i] + second.data[i];
    return Mat3(data);
}

Mat3 operator += (Mat3 & first, const Mat3 & second) {
    for (int i = 0; i < 9; i++)
        first.data[i] += second.data[i];
    return first;
}

/*
 * Subtracting
 */

Mat3 operator - (const Mat3 & first, const Mat3 & second) {
    std::array<double, 9> data;
    for (int i = 0; i < 9; i++)
        data[i] = first.data[i] - second.data[i];
    return Mat3(data);
}

Mat3 operator -= (Mat3 & first, const Mat3 & second) {
    for (int i = 0; i < 9; i++)
        first.data[i] -= second.data[i];
    return first;
}

/*
 * Multiplying
 */

Mat3 operator * (const Mat3 & first, const Mat3 & second) {
    std::array<double, 9> result;
    // for (int i = 0; i < 3; i++) {
    //     for (int j = 0; j < 3; j++) {
    //         result[i + j * 3] = 0.0f;
    //         for (int k = 0; k < 3; k++)
    //             result[i + j * 3] += second.data[i + k * 3] * first.data[k + j * 3];
    //     }
    // }
    result[0] = second.data[0] * first.data[0] + second.data[3] * first.data[1] + second.data[6] * first.data[2];
    result[1] = second.data[1] * first.data[0] + second.data[4] * first.data[1] + second.data[7] * first.data[2];
    result[2] = second.data[2] * first.data[0] + second.data[5] * first.data[1] + second.data[8] * first.data[2];
    result[3] = second.data[0] * first.data[3] + second.data[3] * first.data[4] + second.data[6] * first.data[5];
    result[4] = second.data[1] * first.data[3] + second.data[4] * first.data[4] + second.data[7] * first.data[5];
    result[5] = second.data[2] * first.data[3] + second.data[5] * first.data[4] + second.data[8] * first.data[5];
    result[6] = second.data[0] * first.data[6] + second.data[3] * first.data[7] + second.data[6] * first.data[8];
    result[7] = second.data[1] * first.data[6] + second.data[4] * first.data[7] + second.data[7] * first.data[8];
    result[8] = second.data[2] * first.data[6] + second.data[5] * first.data[7] + second.data[8] * first.data[8];
    return Mat3(result);
}

Mat3 operator *= (Mat3 & first, const Mat3 & second) {
    first = first * second;
    return first;
}

Vec3 operator * (const Mat3 & first, const Vec3 & second) {
    return Vec3(first.data[0] * second.x + first.data[1] * second.y + first.data[2] * second.z,
                first.data[3] * second.x + first.data[4] * second.y + first.data[5] * second.z,
                first.data[6] * second.x + first.data[7] * second.y + first.data[8] * second.z);
}

Vec3 operator * (const Vec3 & first, const Mat3 & second) {
    return Vec3(first.x * second.data[0] + first.y * second.data[3] + first.z * second.data[6],
                first.x * second.data[1] + first.y * second.data[4] + first.z * second.data[7],
                first.x * second.data[2] + first.y * second.data[5] + first.z * second.data[8]);
}

Mat3 operator * (const Mat3 & first, const float second) {
    std::array<double, 9> data;
    for (int i = 0; i < 9; i++)
        data[i] = first.data[i] * second;
    return Mat3(data);
}

Mat3 operator *= (Mat3 & first, const float second) {
    for (int i = 0; i < 9; i++)
        first.data[i] *= second;
    return first;
}

Mat3 operator * (float second, const Mat3 & first) {
    return first * second;
}

/*
 * Dividing
 */

Mat3 operator / (const Mat3 & first, const float second) {
    std::array<double, 9> data;
    for (int i = 0; i < 9; i++)
        data[i] = first.data[i] / second;
    return Mat3(data);
}

Mat3 operator /= (Mat3 & first, const float second) {
    for (int i = 0; i < 9; i++)
        first.data[i] /= second;
    return first;
}
