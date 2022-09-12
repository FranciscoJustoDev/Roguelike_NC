#ifndef ENGINE_H
#define ENGINE_H

#include <ncurses.h>
#include <stdlib.h>

typedef struct Position{
	int y;
	int x;
} Position;

typedef struct Player{
	Position pos;
	Position scrpos;
	int health;
} Player;

typedef struct Window{
	Position pos;
	Position size;
} Window;

typedef struct Map{
    Position size;
    int ** map;
} Map;

/**
 * Initialize ncurses.
 */
int init();

Window * createWindow(int y, int x, int height, int length);

#include "player.h"
#include "map.h"
#include "renderer.h"

#endif