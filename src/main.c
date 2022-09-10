#include "engine.h"

int main(){
	init();

	int ch;
	Player * player;
	Window * gameWindow;
	Map * map;

	gameWindow = createWindow(2, 4, 15, 15);
	player = playerSetup();
	map = create_map(100, 100);

	drawScreen(*(map), player->pos, *(gameWindow));

	while((ch = getch()) != 'q'){
		drawScreen(*(map), player->pos, *(gameWindow));
	}

	endwin();
	return 0;
}