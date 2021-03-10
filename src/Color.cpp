#include "Color.hpp"

/*
 * Comparing
 */

bool operator == (const Color & first, const Color & second) {
    return first.r == second.r && first.g == second.g && first.b == second.b && first.a == second.a;
}

/*
 * Adding
 */

Color operator + (const Color & first, const Color & second) {
    return Color(first.r + second.r, first.g + second.g, first.b + second.b, first.a + second.a);
}

Color operator += (Color & first, const Color & second) {
    first.r += second.r;
    first.g += second.g;
    first.b += second.b;
    first.a += second.a;
    return first;
}

/*
 * Subtracting
 */

Color operator - (const Color & first, const Color & second) {
    return Color(first.r - second.r, first.g - second.g, first.b - second.b, first.a - second.a);
}

Color operator -= (Color & first, const Color & second) {
    first.r -= second.r;
    first.g -= second.g;
    first.b -= second.b;
    first.a -= second.a;
    return first;
}

/*
 * Multiplying
 */

Color operator * (const Color & first, const float second) {
    return Color(first.r * second, first.g * second, first.b * second, first.a * second);
}

Color operator *= (Color & first, const float second) {
    first.r *= second;
    first.g *= second;
    first.b *= second;
    first.a *= second;
    return first;
}

Color operator * (float second, const Color & first) {
    return first * second;
}

/*
 * Dividing
 */


Color operator / (const Color & first, const float second) {
    return Color(first.r / second, first.g / second, first.b / second, first.a / second);
}

Color operator /= (Color & first, const float second) {
    first.r /= second;
    first.g /= second;
    first.b /= second;
    first.a /= second;
    return first;
}
