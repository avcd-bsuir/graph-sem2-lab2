// License: CC BY-NC-SA 4.0
/*
 * main.cpp
 *
 * This file should be used as a template file.
 *
 * Written by AlexeyFilich
 * 10 mar 2021
 */

#include <cmath>
#include <iostream>
#include <vector>

#include "Color.hpp"
#include "Engine.hpp"
// #include "MakeString.hpp"
#include "Mat3.hpp"
#include "primitives.hpp"
#include "utils.hpp"
#include "Vec3.hpp"

#define WIDTH 1280
#define HEIGHT 720

int main(int argc, char* args[]) {
    Engine engine("Template", WIDTH, HEIGHT, Color(0x0));

    float a = 250.0f, l = 150.0f;
    float t, x, y;

    while (!engine.shouldExit()) {
        SDL_Event event;
        while (engine.pollEvent(&event)) {
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.scancode) {
                    case SDL_SCANCODE_ESCAPE: engine.shutdown(); break;
                    default: log("Event", "SDL_KEYDOWN event processed"); break;
                }
            }
        }

        engine.clear();

        // Borders
        for (int x = 0; x < WIDTH; x++) engine.setPixel(x, HEIGHT / 2, Color(0, 255, 0));
        for (int y = 0; y < HEIGHT; y++) engine.setPixel(WIDTH / 2, y, Color(0, 255, 0));

        // Curve
        for (t = 0; t < 2 * 3.14159; t += 0.001) {
            x = (a * cos(t) * cos(t) + l * cos(t)) + WIDTH / 2;
            y = (a * cos(t) * sin(t) + l * sin(t)) + HEIGHT / 2;
            if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
                engine.setPixel((int)x, (int)y, Color(255, 0, 0));
        }

        engine.draw();
        SDL_Delay(16);
    }
    return 0;
}
