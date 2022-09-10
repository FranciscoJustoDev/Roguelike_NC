#ifndef RENDERER_H
#define RENDERER_H

#include "engine.h"

int drawScreen(Map map, Position playerPos, Window GameWin);
int drawPlayer(Window gameWin, Position center, Position playerPos);

#endif