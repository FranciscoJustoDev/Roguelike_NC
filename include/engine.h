#ifndef ENGINE_H
#define ENGINE_H

#include <ncurses.h>
#include <stdlib.h>

typedef struct Position{
	int y;
	int x;
} Position;

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

#include "map.h"
#include "renderer.h"
#include "player.h"

#endif