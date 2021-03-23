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

    double a = 250.0f, l = 150.0f;
    double t, x, y;
    int mouse_x, mouse_y;

    std::vector<Vec3> axes = { Vec3(-WIDTH, 0, 1), Vec3(WIDTH, 0, 1), Vec3(0, -HEIGHT, 1), Vec3(0, HEIGHT, 1) };

    std::vector<Vec3> curve;
    for (t = 0; t < 2 * 3.14159; t += 0.0001)
        curve.push_back(Vec3(a * cos(t) * cos(t) + l * cos(t), a * cos(t) * sin(t) + l * sin(t), 1));

    double angle = 0.0f;
    Mat3 S(1, 0, 0, 0, 1, 0, 0, 0, 1);
    Mat3 R(1, 0, 0, 0, 1, 0, 0, 0, 1);
    Mat3 T(1, 0, 0, 0, 1, 0, 0, 0, 1);

    while (!engine.shouldExit()) {
        SDL_Event event;
        while (engine.pollEvent(&event)) {
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.scancode) {
                    case SDL_SCANCODE_ESCAPE: engine.shutdown(); break;
                    case SDL_SCANCODE_Z:
                        angle += 0.01f;
                        R = Mat3(std::cos(angle), std::sin(angle), 0, -std::sin(angle), std::cos(angle), 0, 0, 0, 1);
                        break;
                    case SDL_SCANCODE_X:
                        angle -= 0.01f;
                        R = Mat3(std::cos(angle), std::sin(angle), 0, -std::sin(angle), std::cos(angle), 0, 0, 0, 1);
                        break;
                    case SDL_SCANCODE_LEFT:
                        S.data[0] -= 0.01f;
                        break;
                    case SDL_SCANCODE_RIGHT:
                        S.data[0] += 0.01f;
                        break;
                    case SDL_SCANCODE_UP:
                        S.data[4] -= 0.01f;
                        break;
                    case SDL_SCANCODE_DOWN:
                        S.data[4] += 0.01f;
                        break;
                    default: log("Event", "SDL_KEYDOWN event processed"); break;
                }
            }
        }

        engine.clear();

        SDL_GetMouseState(&mouse_x, &mouse_y);
        T.data[2] = mouse_x;
        T.data[5] = mouse_y;

        // Borders
        drawLine(&engine, 0, HEIGHT / 2, WIDTH, HEIGHT / 2, Color(0, 255, 0, 100));
        drawLine(&engine, WIDTH / 2, 0, WIDTH / 2, HEIGHT, Color(0, 255, 0, 100));

        drawLine(&engine, T * (S * (R * axes[0])), T * (S * (R * axes[1])), Color(0, 255, 0));
        // drawLine(&engine, S * (R * (T * axes[0])), S * (R * (T * axes[1])), Color(0, 255, 0));
        drawLine(&engine, T * (S * (R * axes[2])), T * (S * (R * axes[3])), Color(0, 255, 0));
        // drawLine(&engine, S * (R * (T * axes[2])), S * (R * (T * axes[3])), Color(0, 255, 0));

        // Curve
        for (int i = 0; i < curve.size(); i++) {
            Vec3 pixel = T * (S * (R * curve[i]));
            engine.setPixel(pixel.x, pixel.y, Color(255, 0, 0));
        }

        engine.draw();
        // SDL_Delay(16);
    }
    return 0;
}
