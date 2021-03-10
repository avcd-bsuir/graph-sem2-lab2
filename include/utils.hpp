#ifndef UTILS_HPP
#define UTILS_HPP

#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

void log(std::string, std::string);

void throwError(std::string, std::string);

template<typename T>
inline T lerp(T a, T b, double u) {
    return (1.0f - u) * a + u * b;
}

#endif
