#include "Game.h"

Game* game;

void wrapper()
{
	game->mainloop();
}

int main()
{
	game = new Game();
	game->run(wrapper);
	return 0;
}
