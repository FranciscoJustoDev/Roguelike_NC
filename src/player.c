#include "player.h"

Player * createPlayer(){
	Player * newPlayer;
	newPlayer = malloc(sizeof(Player));

	newPlayer->pos.y = 7;
	newPlayer->pos.x = 7;
	newPlayer->health = 20;

	return newPlayer;
}