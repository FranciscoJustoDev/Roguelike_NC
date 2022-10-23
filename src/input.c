#include "input.h"

int handleInput(int input, Player *player, Window **wins, Level *level){

	switch (input){
		case 'w':
		case 's':
		case 'a':
		case 'd':
			moveAction(getDir(input), player, wins, level);
			break;

		case 'i':
			inspectMode(player->scrpos, wins[0]);
			break;

		case '.':
			level->turn++;
			break;

		default:
			break;
	}

	return 0;
}

int moveAction(Position dir, Player * player, Window ** wins, Level * level){

	Position objPos = {player->pos.y + dir.y, player->pos.x + dir.x};

	switch(mvinch(player->scrpos.y + dir.y, player->scrpos.x + dir.x)){
		case FLOOR:
			player->scrpos.y += dir.y;
			player->scrpos.x += dir.x;
			player->pos.y += dir.y;
			player->pos.x += dir.x;
			level->turn += 1;
			break;
		
		case DOOR:
			doorAction(objPos, level, wins[2]);
			break;
		
		default:
			break;
	}

	return 0;
}

Position getDir(int input){

	Position dir = {0, 0};
	switch (input){
		case 'w':
			dir.y--;
			break;
		case 's':
			dir.y++;
			break;
		case 'a':
			dir.x--;
			break;
		case 'd':
			dir.x++;
			break;
		default:
			break;
	}

	return dir;
}

int doorAction(Position pos, Level * level, Window * logWin){

	Door * door;
	char ch;
	int i, y, x;
	y = pos.y;
	x = pos.x;

	for(i = 0; i < level->ndoor; i++){
		if(y == level->door[i]->pos.y && x == level->door[i]->pos.x){
			door = level->door[i];
		}
	}
	if(door->locked == 1){
		updateLog("The door is locked! Smash it down? y/n", level->log);
		while((ch = getch()) == 'y' && door->hp > 0){
			door->hp -= 5;
		}
	}else{
		door->open = 1;
		level->map[y][x] = FLOOR;
		updateLog("You open the door.", level->log);
	}
	return 0;
}

int inspectMode(Position playerScr, Window * win){

	int ch;
	char img;
	Window infoBox = {0, 0, 7, 24};
	Position pos = playerScr;

	do{

		switch(ch){
			case 'w':
				if(pos.y > win->pos.y + 1)
				{
					img = mvinch(pos.y - 1, pos.x);
					pos.y--;
				}
				break;

			case 's':
				if(pos.y < win->size.y - 2 + win->pos.y)
				{
					img = mvinch(pos.y + 1, pos.x);
					pos.y++;
				}
				break;

			case 'a':
				if(pos.x > win->pos.x + 1)
				{
					img = mvinch(pos.y, pos.x - 1);
					pos.x--;
				}
				break;

			case 'd':
				if(pos.x < win->size.x - 2 + win->pos.x)
				{
					img = mvinch(pos.y, pos.x + 1);
					pos.x++;
				}
				break;

			default:
				break;
		}

		drawFrame(infoBox);
		img = mvinch(pos.y, pos.x);
		printInfo(getInfo(img), infoBox);
		move(pos.y, pos.x);

	}while((ch = getch()) != 'q');

	return 0;
}