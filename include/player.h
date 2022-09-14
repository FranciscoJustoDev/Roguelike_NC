#ifndef PLAYER_H
#define PLAYER_H

#include "engine.h"

Player * createPlayer();
int handleInput(int input, Player * player);
int playerMovement(int input, Player * player);
int moveCheck(int y, int x, Player * player, int dir);

#endif