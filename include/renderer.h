#ifndef RENDERER_H
#define RENDERER_H

#include "engine.h"

int drawGameWindow(Map map, Player * player, Window GameWin);
int drawPlayer(Window gameWin, Position center, Position playerPos);

#endif