#ifndef RENDERER_H
#define RENDERER_H

#include "engine.h"

int drawInfoWin(Window win, Level level);
int drawStatsWin(Window win, Player player);
int drawGameWin(Window win, Level level, Player * player);
int drawCamera(Window win, Level level, Position offset);
Position getOffset(Window win, Level level, Player * player);
int drawFrame(Window win);

#endif