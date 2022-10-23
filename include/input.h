#ifndef INPUT_H
#define INPUT_H

#include "engine.h"

int handleInput(int input, Player * player, Window ** wins, Level * level);

int moveAction(Position dir, Player * player, Window ** wins, Level * level);
Position getDir(int input);
int doorAction(Position pos, Level * level, Window * logWin);

int inspectMode(Position playerScr, Window * win);

#endif