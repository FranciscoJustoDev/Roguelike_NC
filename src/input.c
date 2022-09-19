#include "input.h"

int handleInput(int input, Player *player, Window **win, Level *level)
{

	switch (input){
		case 'w':
		case 's':
		case 'a':
		case 'd':
			moveAction(getDir(input), player, &(level->turn));
			break;

		case 'i':
			inspectMode(player->scrpos, win);
			break;

		case '.':
			level->turn++;
			break;

		default:
			break;
	}

	return 0;
}

int moveAction(Position dir, Player * player, int *t){

	switch(mvinch(player->scrpos.y + dir.y, player->scrpos.x + dir.x)){
		case FLOOR:
			player->scrpos.y += dir.y;
			player->scrpos.x += dir.x;
			player->pos.y += dir.y;
			player->pos.x += dir.x;
			*t += 1;
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

int inspectMode(Position playerScr, Window **win){

	int ch;
	char img;
	Window infoBox = {0, 0, 7, 24};
	Position pos = playerScr;

	do{

		switch(ch){
			case 'w':
				if(pos.y > win[0]->pos.y + 1)
				{
					img = mvinch(pos.y - 1, pos.x);
					pos.y--;
				}
				break;

			case 's':
				if(pos.y < win[0]->size.y - 2 + win[0]->pos.y)
				{
					img = mvinch(pos.y + 1, pos.x);
					pos.y++;
				}
				break;

			case 'a':
				if(pos.x > win[0]->pos.x + 1)
				{
					img = mvinch(pos.y, pos.x - 1);
					pos.x--;
				}
				break;

			case 'd':
				if(pos.x < win[0]->size.x - 2 + win[0]->pos.x)
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

int printInfo(char * text, Window win){

	int n, y, x;
	n = 0;
	y = 1;
	x = 1;

	while(n < strlen(text)){
		
		mvprintw(win.pos.y + y, win.pos.x + x, "%c", text[n]);
		
		if(x < win.size.x - 3){
			x++;
		}else{
			y++;
			x = 1;
		}
		n++;
	}

	return 0;
}

char * getInfo(char img){

	switch(img){
		case PLAYER:
			return "Handsome!";
			break;

		case FLOOR:
			return "This is a floor tile.";
			break;

		case WALL:
			return "This is a wall. You'll have to go around.";
			break;

		case DOOR:
			return "It's a nice door.";
			break;

		default:
			break;
	}

	return "NOT DEFINED!";
}