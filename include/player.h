#ifndef PLAYER_H
#define PLAYER_H

#include "engine.h"

typedef struct Player{
	Position pos;
	int health;
} Player;

Player * playerSetup();

#endif