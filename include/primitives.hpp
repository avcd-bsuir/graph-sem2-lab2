#ifndef PRIMITIVES_HPP
#define PRIMITIVES_HPP

#include "Color.hpp"
#include "Engine.hpp"
#include "utils.hpp"
#include "Vec3.hpp"

void drawLine(Engine *, double, double, double, double, Color, Color);
void drawLine(Engine *, double, double, double, double, Color);
void drawLine(Engine *, Vec3, Vec3, Color, Color);
void drawLine(Engine *, Vec3, Vec3, Color);

#endif
