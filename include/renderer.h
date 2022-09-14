#ifndef RENDERER_H
#define RENDERER_H

#include "engine.h"

int drawInfoWindow(Window win, Player player);
int drawOptionsWindow(Window win, Player player);
int drawGameWindow(Map map, Player * player, Window GameWin);
int drawPlayer(Window gameWin, Position center, Position playerPos);

#endif