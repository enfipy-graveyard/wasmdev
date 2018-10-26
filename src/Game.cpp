#include "Game.h"

#if !__EMSCRIPTEN__
int usleep(unsigned);
#endif

Game::Game()
{
    m_rect.x = 0;
	m_rect.y = 0;
	m_rect.w = 60;
	m_rect.h = 60;
}

Game::~Game()
{

}

void Game::run(em_callback_func wrapper)
{
    init();
    emscripten_set_main_loop(wrapper, -1, 1);
    destroy();
}

void Game::init()
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(500, 350, 0, &m_window, &m_renderer);
}

void Game::mainloop()
{
    m_inputManager.update();
	input();
    update();
	draw();
}

void Game::update()
{
    if (m_inputManager.isKeyDown(SDLK_a)) 
    {
        m_rect.x -= 10;
    } 
    if (m_inputManager.isKeyDown(SDLK_d)) 
    {
        m_rect.x += 10;
    } 
    if (m_inputManager.isKeyDown(SDLK_w)) 
    {
        m_rect.y -= 10;
    } 
    if (m_inputManager.isKeyDown(SDLK_s))
    {
        m_rect.y += 10;
    }
    if (m_inputManager.isKeyDown(SDL_BUTTON_LEFT))
    {
        m_rect.x += 20;
    }
}

void Game::input()
{
    while (SDL_PollEvent(&m_event)) 
    {
        switch (m_event.type) 
        {
            case SDL_KEYDOWN:
                m_inputManager.pressKey(m_event.key.keysym.sym);
                break;
            case SDL_KEYUP:
                m_inputManager.releaseKey(m_event.key.keysym.sym);
                break;
            case SDL_MOUSEBUTTONDOWN:
                m_inputManager.pressKey(m_event.button.button);
                break;
            case SDL_MOUSEBUTTONUP:
                m_inputManager.releaseKey(m_event.button.button);
                break;
        }
    }
}

void Game::draw()
{
    SDL_SetRenderDrawColor(m_renderer, 64, 64, 64, 255);
	SDL_RenderClear(m_renderer);

	SDL_SetRenderDrawColor(m_renderer, 102, 0, 255, 255);
	SDL_RenderFillRect(m_renderer, &m_rect);

	SDL_RenderPresent(m_renderer);
}

void Game::destroy()
{
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}
