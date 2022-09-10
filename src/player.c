#include "player.h"

Player * playerSetup(){
	Player * newPlayer;
	newPlayer = malloc(sizeof(Player));

	newPlayer->pos.y = 97;
	newPlayer->pos.x = 60;
	newPlayer->health = 20;

	return newPlayer;
}