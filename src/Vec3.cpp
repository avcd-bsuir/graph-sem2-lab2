#include "Vec3.hpp"

Vec3::Vec3() : x(0), y(0), z(0) {
}

Vec3::Vec3(double x, double y, double z) : x(x), y(y), z(z) {
}

Vec3::~Vec3() {
}

double Vec3::magnitude() {
    return std::sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

Vec3 Vec3::normalized() {
    // Will crash if magnitude is 0
    return *this / this->magnitude();
}

/*
 * Comparing
 */

bool operator == (const Vec3 & first, const Vec3 & second) {
    return first.x == second.x && first.y == second.y && first.z == second.z;
}

/*
 * Adding
 */

Vec3 operator + (const Vec3 & first, const Vec3 & second) {
    return Vec3(first.x + second.x, first.y + second.y, first.z + second.z);
}

Vec3 operator += (Vec3 & first, const Vec3 & second) {
    first.x += second.x;
    first.y += second.y;
    first.z += second.z;
    return first;
}

/*
 * Subtracting
 */

Vec3 operator - (const Vec3 & first, const Vec3 & second) {
    return Vec3(first.x - second.x, first.y - second.y, first.z - second.z);
}

Vec3 operator -= (Vec3 & first, const Vec3 & second) {
    first.x -= second.x;
    first.y -= second.y;
    first.z -= second.z;
    return first;
}

/*
 * Multiplying
 */

Vec3 operator * (const Vec3 & first, const float second) {
    return Vec3(first.x * second, first.y * second, first.z * second);
}

Vec3 operator *= (Vec3 & first, const float second) {
    first.x *= second;
    first.y *= second;
    first.z *= second;
    return first;
}

Vec3 operator * (float second, const Vec3 & first) {
    return first * second;
}

/*
 * Dividing
 */

Vec3 operator / (const Vec3 & first, const float second) {
    return Vec3(first.x / second, first.y / second, first.z / second);
}

Vec3 operator /= (Vec3 & first, const float second) {
    first.x /= second;
    first.y /= second;
    first.z /= second;
    return first;
}

/*
 * Other
 */

double dot(Vec3 first, Vec3 second) {
    return first.x * second.x + first.y * second.y + first.z * second.z;
}

Vec3 cross(Vec3 first, Vec3 second) {
    return Vec3(first.y * second.z - first.z * second.y,
                first.z * second.x - first.x * second.z,
                first.x * second.y - first.y * second.x);
}

double distance(Vec3 first, Vec3 second) {
    return std::sqrt(std::pow(first.x - second.x, 2) + std::pow(first.y - second.y, 2) + std::pow(first.z - second.z, 2));
}

bool lineIntersection(Vec3 a1, Vec3 a2, Vec3 b1, Vec3 b2, Vec3 & pos) {
    double d = (a2.x - a1.x) * (b1.y - b2.y) - (b1.x - b2.x) * (a2.y - a1.y);
    if (d == 0)
        return false;
    double t = ((b1.x - a1.x) * (b1.y - b2.y) - (b1.x - b2.x) * (b1.y - a1.y)) / d,
           u = ((a2.x - a1.x) * (b1.y - a1.y) - (b1.x - a1.x) * (a2.y - a1.y)) / d;
    pos = lerp(a1, a2, t);
    if (u < 0 || u > 1 || t < 0 || t > 1) return false;
    return true;
}
