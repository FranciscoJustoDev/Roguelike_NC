#ifndef INPUT_H
#define INPUT_H

#include "engine.h"

int handleInput(int input, Player * player, Window ** windows, Level * level);

int moveAction(Position dir, Player * player, int * t);
Position getDir(int input);

int inspectMode(Position playerScr, Window ** win);
char * getInfo(char img);
int printInfo(char * text, Window win);

#endif