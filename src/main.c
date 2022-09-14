#include "engine.h"

int main(){
	init();

	int ch;
	Player * player;
	Window * gameWindow;
	Window * optionsWindow;
	Window * infoWindow;
	Map * map;

	/*
		Both player screen pos variable and
		map edge "free movement"
		REQUIRE game win size (y,x) to be an ODD int num
	*/
	gameWindow = createWindow(8, 6, 13, 45);
	optionsWindow = createWindow(2, 55, 20, 30);
	infoWindow = createWindow(2, 5, 5, 47);

	map = create_map(50, 50);
	player = createPlayer();

	drawGameWindow(*(map), player, *(gameWindow));
	drawOptionsWindow(*(optionsWindow), *(player));
	drawInfoWindow(*(infoWindow), *(player));
	move(player->scrpos.y, player->scrpos.x);

	while((ch = getch()) != 'q'){
		handleInput(ch, player);
		clear();
		drawGameWindow(*(map), player, *(gameWindow));
		drawOptionsWindow(*(optionsWindow), *(player));
		drawInfoWindow(*(infoWindow), *(player));
		move(player->scrpos.y, player->scrpos.x);
	}

	endwin();
	return 0;
}