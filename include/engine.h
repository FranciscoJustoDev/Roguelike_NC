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

typedef struct Door{
	Position pos;
	int hp;
	int open;
	int locked;
} Door;

typedef struct Level{
	char * name;
	int turn;
    char ** map;
	Position size;
	Door ** door;
	int ndoor;
	char ** log;
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
int updateLog(char * text, char ** log);
char * getInfo(char img);
int printInfo(char * text, Window win);

#include "sprites.h"
#include "input.h"
#include "player.h"
#include "level.h"
#include "renderer.h"

#endif