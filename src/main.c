#include "engine.h"

int main(){
	init();

	int ch;
	Player * player;
	Window * gameWindow;
	Map * map;

	gameWindow = createWindow(2, 4, 15, 15);
	player = playerSetup();
	map = create_map(30, 30);

	drawGameWindow(*(map), player, *(gameWindow));
	mvprintw(0, 0, "Player x = %d", player->pos.x);
	mvprintw(1, 0, "Player y = %d", player->pos.y);
	move(player->scrpos.y, player->scrpos.x);

	while((ch = getch()) != 'q'){
		handleInput(ch, player);
		drawGameWindow(*(map), player, *(gameWindow));
		mvprintw(0, 0, "Player x = %d", player->pos.x);
		mvprintw(1, 0, "Player y = %d", player->pos.y);
		move(player->scrpos.y, player->scrpos.x);
	}

	endwin();
	return 0;
}