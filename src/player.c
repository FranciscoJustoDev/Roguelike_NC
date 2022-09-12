#include "player.h"

Player * playerSetup(){
	Player * newPlayer;
	newPlayer = malloc(sizeof(Player));

	newPlayer->pos.y = 7;
	newPlayer->pos.x = 7;
	newPlayer->health = 20;

	return newPlayer;
}

int handleInput(int input, Player * player){

	switch(input){
		case 'w':
		case 's':
		case 'a':
		case 'd':
			playerMovement(input, player);
			break;
		
		default:
			break;
	}

	return 0;
}

int playerMovement(int input, Player * player){

	int y;
	int x;

	switch (input){
		case 'w':
			y = player->scrpos.y - 1;
			x = player->scrpos.x;
			break;

		case 's':
			y = player->scrpos.y + 1;
			x = player->scrpos.x;
			break;

		case 'a':
			y = player->scrpos.y;
			x = player->scrpos.x - 1;
			break;

		case 'd':
			y = player->scrpos.y;
			x = player->scrpos.x + 1;
			break;

		default:
			break;
	}

	moveCheck(y, x, player, input);

	return 0;
}

int moveCheck(int y, int x, Player * player, int dir){

	switch (mvinch(y, x)){
		case '.':
			if(dir == 'w'){
				player->pos.y--;
			}else if(dir == 's'){
				player->pos.y++;
			}else if(dir == 'a'){
				player->pos.x--;
			}else if(dir == 'd'){
				player->pos.x++;
			}
			break;
		
		default:
			break;
	}

	return 0;
}