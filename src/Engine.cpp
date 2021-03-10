#include "Engine.hpp"

Engine::Engine(std::string window_title, int width, int height, Color clear_color) : width(width), height(height), clear_color(clear_color), window(nullptr), renderer(nullptr), texture(nullptr), surface(nullptr), should_exit(false) {
    log("Engine", "Initializing SDL");
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        throwError("SDLInitError", SDL_GetError());

    log("Engine", "Creating window");
    this->window = SDL_CreateWindow(window_title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, this->width, this->height, SDL_WINDOW_SHOWN);
    if (this->window == NULL)
        throwError("SDLWindowInitError", SDL_GetError());

    log("Engine", "Creating renderer");
    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_SOFTWARE);
    if (!this->renderer)
        throwError("SDLRendererInitError", SDL_GetError());

    SDL_SetRenderDrawColor(this->renderer, clear_color.r, clear_color.g, clear_color.b, clear_color.a);

    log("Engine", "Creating surface");
    this->surface = SDL_CreateRGBSurface(0, this->width, this->height, 32, 0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);
    if (!this->surface)
        throwError("SDLSurfaceInitError", SDL_GetError());

    log("Engine", "Creating texture");
    this->texture = SDL_CreateTextureFromSurface(this->renderer, this->surface);
    if (!this->texture)
        throwError("SDLTextureInitError", SDL_GetError());
}

Engine::~Engine() {
    log("Engine", "Cleaning up");
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyTexture(this->texture);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

bool Engine::shouldExit() {
    return this->should_exit;
}

void Engine::shutdown() {
    this->should_exit = true;
}

bool Engine::pollEvent(SDL_Event * event) {
    if (SDL_PollEvent(&this->event) == 0)
        return false;
    if (this->event.type == SDL_QUIT) {
        this->should_exit = true;
        return false;
    }
    *event = this->event;
    return true;
}

void Engine::setPixel(int x, int y, Color pixel) {
    if (x < 0 || y < 0 || x >= this->width || y >= this->height)
        return;
        // throwError("OutOfRangeError", "Coordinates are out of range");
    ((Color *)surface->pixels)[x + y * surface->w] = pixel;
}

Color Engine::getPixel(int x, int y) {
    if (x < 0 || y < 0 || x >= this->width || y >= this->height)
        throwError("OutOfRangeError", "Coordinates are out of range");
    return ((Color *)surface->pixels)[x + y * surface->w];
}

void Engine::draw() {
    SDL_UpdateTexture(this->texture, NULL, this->surface->pixels, this->surface->pitch);
    SDL_RenderCopy(this->renderer, this->texture, NULL, NULL);
    SDL_RenderPresent(this->renderer);
}

void Engine::clear() {
    SDL_RenderClear(this->renderer);
    SDL_FillRect(this->surface, NULL, this->clear_color.a << 24 | this->clear_color.r << 16 | this->clear_color.g << 8 | this->clear_color.b);
}
