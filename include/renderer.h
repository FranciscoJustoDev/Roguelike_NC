#ifndef RENDERER_H
#define RENDERER_H

#include "engine.h"

int drawInfoWindow(Window win, Player player);
int drawOptionsWindow(Window win, Player player);
int drawGameWindow(Map map, Player * player, Window GameWin);
int drawCamera(Position offset, Window win, Map map, Player * player);
Position getOffset(Window win, Map map, Player * player);

#endif