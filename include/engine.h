#ifndef ENGINE_H
#define ENGINE_H

#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DIR_LEVEL "levels/"
#define LEVEL_FILE_TYPE ".txt"

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

typedef struct Level{
	char * name;
	int turn;
    char ** map;
	Position size;
} Level;

typedef struct Scene{
	/*
		Holds every element of scene.
	*/
} Scene;

/**
 * Initialize ncurses.
 */
int init();

Window * createWindow(int y, int x, int height, int length);
Scene * setupScene();

#include "sprites.h"
#include "input.h"
#include "player.h"
#include "level.h"
#include "renderer.h"

#endif