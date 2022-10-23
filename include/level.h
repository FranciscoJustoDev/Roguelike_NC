#ifndef LEVEL_H
#define LEVEL_H

#include "engine.h"

Level * setupLevel(char * level_name, Position * player);
Door * createDoor(int y, int x);

#endif