#include "renderer.h"

int drawScreen(Map map, Position playerPos, Window gameWin){
	
	Position center;
	Position offset;
	Position playerDraw;
	center.y = gameWin.size.y / 2;
	center.x = gameWin.size.x / 2;
	int y;
	int x;

	/* Lock map if window view escapes map array */
	if(playerPos.y - center.y < 0 || playerPos.x - center.x < 0){
		if(playerPos.y - center.y < 0){
			offset.y = 0;
		}else{
			offset.y = playerPos.y - center.y;
		}
		if(playerPos.x - center.x < 0){
			offset.x = 0;
		}else{
			offset.x = playerPos.x - center.x;
		}
	}else if(playerPos.y + center.y >= map.size.y || playerPos.x + center.x >= map.size.x){
		if(playerPos.y + center.y >= map.size.y){
			offset.y = map.size.y - gameWin.size.y;
		}else{
			offset.y = playerPos.y - center.y;
		}
		if(playerPos.x + center.x >= map.size.x){
			offset.x = map.size.x - gameWin.size.x;
		}else{
			offset.x = playerPos.x - center.x;
		}
	}

	for(y = 0; y < gameWin.size.y; y++){
		for(x = 0; x < gameWin.size.x; x++){
			switch(map.map[y + offset.y][x + offset.x]){
				case 0:
					mvprintw(y + gameWin.pos.y, x + gameWin.pos.x, ".");
					break;
				case 1:
					mvprintw(y + gameWin.pos.y, x + gameWin.pos.x, "#");
					break;
				
				default:
					mvprintw(y + gameWin.pos.y, x + gameWin.pos.x, " ");
					break;
			}
		}
	}

	/* Draw Player */
	if(offset.y == 0 || offset.x == 0){
		if(offset.y == 0){
			playerDraw.y = playerPos.y + gameWin.pos.y;
		}else{
			playerDraw.y = gameWin.pos.y + center.y;
		}
		if(offset.x == 0){
			playerDraw.x = playerPos.x + gameWin.pos.x;
		}else{
			playerDraw.x = gameWin.pos.x + center.x;
		}
	}else if(offset.y == map.size.y - gameWin.size.y || offset.x == map.size.x - gameWin.size.x){
		if(offset.y == map.size.y - gameWin.size.y){
			playerDraw.y = (gameWin.pos.y + gameWin.size.y) - (map.size.y - playerPos.y) - 1;
		}else{
			playerDraw.y = gameWin.pos.y + center.y;
		}
		if(offset.x == map.size.x - gameWin.size.x){
			playerDraw.x = (gameWin.pos.x + gameWin.size.x) - (map.size.x - playerPos.x) - 1;
		}else{
			playerDraw.x = gameWin.pos.x + center.x;
		}
	}

	mvprintw(playerDraw.y, playerDraw.x, "@");
	move(playerDraw.y, playerDraw.x);

	return 0;
}