#ifndef COLOR_HPP
#define COLOR_HPP

#include <cstdint>

struct Color {
    uint8_t b, g, r, a;
    Color() : r(0), g(0), b(0), a(255) {}
    // Color(uint32_t c) : r((c & 0x00FF0000) >> 16), g((c & 0x0000FF00) >> 8), b((c & 0x000000FF)), a((c & 0xFF000000) >> 24) {}
    Color(uint32_t c) : r((c & 0x00FF0000) >> 16), g((c & 0x0000FF00) >> 8), b((c & 0x000000FF)), a(255) {}
    Color(uint8_t r, uint8_t g, uint8_t b) : r(r), g(g), b(b), a(255) {}
    Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) : r(r), g(g), b(b), a(a) {}
};

// Comparing
bool operator == (const Color & first, const Color & second);

// Adding
Color operator + (const Color & first, const Color & second);
Color operator += (Color & first, const Color & second);

// Subtracting
Color operator - (const Color & first, const Color & second);
Color operator -= (Color & first, const Color & second);

// Multiplying
Color operator * (const Color & first, const float second);
Color operator *= (Color & first, const float second);
Color operator * (const float second, const Color & first);

// Dividing
Color operator / (const Color & first, const float second);
Color operator /= (Color & first, const float second);

#endif
