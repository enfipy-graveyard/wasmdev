#pragma once
#include <SDL2/SDL.h>
#include <emscripten.h>
#include <functional>

#include "InputManager.h"

class Game
{
public:
    Game();
    ~Game();
    void run(em_callback_func wrapper);
    void mainloop();
private:
    void init();
    void update();
    void input();
    void draw();
    void destroy();

    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    SDL_Event m_event;
    SDL_Rect m_rect;

    InputManager m_inputManager;
};
