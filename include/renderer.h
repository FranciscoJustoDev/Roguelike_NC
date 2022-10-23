#ifndef RENDERER_H
#define RENDERER_H

#include "engine.h"

int drawStatsWin(Window win, Level level, Player player);
int drawLogWin(Window win, Player player, char ** log);
int drawGameWin(Window win, Level level, Player * player);
int drawCamera(Window win, Level level, Position offset);
Position getOffset(Window win, Level level, Player * player);
int drawFrame(Window win);

#endif