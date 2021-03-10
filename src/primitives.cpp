#include "primitives.hpp"

void drawLine(Engine * engine, double x1, double y1, double x2, double y2, Color c1, Color c2) {
    double dots = std::sqrt(std::pow(x1 - x2, 2) + std::pow(y1 - y2, 2));
    for (double u = 0.0f; u < 1.0f; u += 1 / dots)
        engine->setPixel(std::round(lerp(x1, x2, u)), std::round(lerp(y1, y2, u)), lerp(c1, c2, u));
}

void drawLine(Engine * engine, double x1, double y1, double x2, double y2, Color c) {
    drawLine(engine, x1, y1, x2, y2, c, c);
}

void drawLine(Engine * engine, Vec3 first, Vec3 second, Color c1, Color c2) {
    drawLine(engine, first.x, first.y, second.x, second.y, c1, c2);
}

void drawLine(Engine * engine, Vec3 first, Vec3 second, Color c) {
    drawLine(engine, first.x, first.y, second.x, second.y, c, c);
}
