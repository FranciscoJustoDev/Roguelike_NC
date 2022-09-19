#include "engine.h"

int main(){
	init();

	int ch;
	Player * player;
	Window * gameWindow;
	Window * statsWindow;
	Window * infoWindow;
	Level * level;
	Window ** windows;
	windows = malloc(sizeof(Window) * 3);

	gameWindow = createWindow(7, 6, 15, 47);
	statsWindow = createWindow(2, 55, 20, 30);
	infoWindow = createWindow(2, 6, 5, 47);
	windows[0] = gameWindow;
	windows[1] = statsWindow;
	windows[2] = infoWindow;

	player = createPlayer();
	level = setupLevel("test", &(player->pos));

	drawGameWin(*(gameWindow), *(level), player);
	drawStatsWin(*(statsWindow), *(player));
	drawInfoWin(*(infoWindow), *(level));
	move(player->scrpos.y, player->scrpos.x);

	while((ch = getch()) != 'q'){
		handleInput(ch, player, windows, level);
		clear();
		drawGameWin(*(gameWindow), *(level), player);
		drawStatsWin(*(statsWindow), *(player));
		drawInfoWin(*(infoWindow), *(level));
		move(player->scrpos.y, player->scrpos.x);
	}

	endwin();
	return 0;
}