#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <SDL2/SDL.h>

#include "Color.hpp"
#include "utils.hpp"

class Engine {
    private:
        int width, height;
        bool should_exit;

        SDL_Event event;

        SDL_Renderer * renderer;
        SDL_Surface * surface;
        SDL_Texture * texture;
        SDL_Window * window;
        Color clear_color;
    public:
        Engine(std::string, int, int, Color);
        ~Engine();

        bool shouldExit();
        void shutdown();

        bool pollEvent(SDL_Event *);

        void setPixel(int, int, Color);
        Color getPixel(int, int);

        void draw();
        void clear();
};

#endif
