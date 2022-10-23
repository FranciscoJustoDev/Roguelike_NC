#include "engine.h"

int main(){
	init();

	int ch;
	Player * player;
	Window * gameWindow;
	Window * statsWindow;
	Window * logWindow;
	Level * level;
	Window ** windows;
	windows = malloc(sizeof(Window) * 3);

	gameWindow = createWindow(7, 6, 15, 47);
	statsWindow = createWindow(2, 6, 5, 47);
	logWindow = createWindow(2, 55, 20, 30);
	windows[0] = gameWindow;
	windows[1] = statsWindow;
	windows[2] = logWindow;

	player = createPlayer();
	level = setupLevel("test", &(player->pos));

	updateLog("You wake up in a poorly lit room.", level->log);
	drawGameWin(*(gameWindow), *(level), player);
	drawStatsWin(*(statsWindow), *(level), *(player));
	drawLogWin(*(logWindow), *(player), level->log);
	move(player->scrpos.y, player->scrpos.x);

	while((ch = getch()) != 'q'){
		handleInput(ch, player, windows, level);
		clear();
		drawGameWin(*(gameWindow), *(level), player);
		drawStatsWin(*(statsWindow), *(level), *(player));
		drawLogWin(*(logWindow), *(player), level->log);
		move(player->scrpos.y, player->scrpos.x);
	}

	endwin();
	return 0;
}