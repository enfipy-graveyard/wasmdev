#include <SDL.h>
#include <emscripten.h>

SDL_Window *window;
SDL_Renderer *renderer;
int i = 0;

void mainloop()
{
	// red background
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderClear(renderer);

	// moving blue rectangle
	SDL_Rect r;
	r.x = i % 500;
	r.y = 50;
	r.w = 50;
	r.h = 50;
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderFillRect(renderer, &r);

	SDL_RenderPresent(renderer);
    i++;
}

int main(int argc, char *argv[])
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(500, 250, 0, &window, &renderer);
	
	// call the function repeatedly
	const int simulate_infinite_loop = 1;
	// call the function as fast as the browser wants to render (typically 60fps)
	const int fps = -1;
	emscripten_set_main_loop(mainloop, fps, simulate_infinite_loop);

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}