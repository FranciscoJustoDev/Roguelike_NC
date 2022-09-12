#include "renderer.h"

int drawGameWindow(Map map, Player * player, Window gameWin){
	
	clear();
	Position winCenter;
	Position mapOffset;

	/* center == 7 */
	winCenter.y = gameWin.size.y / 2;
	winCenter.x = gameWin.size.x / 2;

	/* Find draw_offset for map and player */
	if(player->pos.y - winCenter.y <= 0){
		mapOffset.y = 0;
		player->scrpos.y = player->pos.y + gameWin.pos.y;
	}else if(player->pos.y + winCenter.y >= (map.size.y - 1)){
		mapOffset.y = (map.size.y - 1) - (gameWin.size.y - 1);
		player->scrpos.y = (gameWin.pos.y + (gameWin.size.y - 1)) - ((map.size.y - 1) - player->pos.y);
	}else{
		mapOffset.y = player->pos.y - winCenter.y;
		player->scrpos.y = gameWin.pos.y + winCenter.y;
	}

	if(player->pos.x - winCenter.x <= 0){
		mapOffset.x = 0;
		player->scrpos.x = player->pos.x + gameWin.pos.x;
	}else if(player->pos.x + winCenter.x >= (map.size.x - 1)){
		mapOffset.x = (map.size.x - 1) - (gameWin.size.x - 1);
		player->scrpos.x = (gameWin.pos.x + (gameWin.size.x - 1)) - ((map.size.x - 1) - player->pos.x);
	}else{
		mapOffset.x = player->pos.x - winCenter.x;
		player->scrpos.x = gameWin.pos.x + winCenter.x;
	}

	/* Draw Game Window */
	int y;
	int x;

	for(y = 0; y < gameWin.size.y; y++){
		for(x = 0; x < gameWin.size.x; x++){
			
			switch(map.map[y + mapOffset.y][x + mapOffset.x]){
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
	mvprintw(player->scrpos.y, player->scrpos.x, "@");
	move(player->scrpos.y, player->scrpos.x);

	return 0;
}