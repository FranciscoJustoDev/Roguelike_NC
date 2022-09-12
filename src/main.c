#include "engine.h"

int main(){
	init();

	int ch;
	Player * player;
	Window * gameWindow;
	Window * optionsWindow;
	Map * map;

	gameWindow = createWindow(2, 4, 20, 46);
	optionsWindow = createWindow(2, 55, 20, 30);
	player = playerSetup();
	map = create_map(100, 100);

	drawGameWindow(*(map), player, *(gameWindow));
	drawOptionsWindow(*(optionsWindow), *(player));
	move(player->scrpos.y, player->scrpos.x);

	while((ch = getch()) != 'q'){
		handleInput(ch, player);
		clear();
		drawGameWindow(*(map), player, *(gameWindow));
		drawOptionsWindow(*(optionsWindow), *(player));
		move(player->scrpos.y, player->scrpos.x);
	}

	endwin();
	return 0;
}