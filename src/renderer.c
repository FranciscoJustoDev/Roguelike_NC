#include "renderer.h"

int drawInfoWindow(Window win, Player player){

	Position og;// window origin
	Position mx;// window max reachable index
	Position sz;// window size
	Position ctr;// window center
	int y;
	int x;
	og.y = win.pos.y;
	og.x = win.pos.x;
	mx.y = win.pos.y + win.size.y - 1;
	mx.x = win.pos.x + win.size.x - 1;
	sz.y = win.pos.y + win.size.y;
	sz.x = win.pos.x + win.size.x;
	ctr.y = win.pos.y + (win.size.y / 2);
	ctr.x = win.pos.x + (win.size.x / 2);

	for(y = og.y; y < sz.y; y++){
		for(x = og.x; x < sz.x; x++){
			if((y == og.y && x == og.x) || (y == mx.y && x == mx.x)){
				mvprintw(y, x, "/");
			}else if((y == og.y && x == mx.x) || (y == mx.y && x == og.x)){
				mvprintw(y, x, "\\");
			}else if((y == og.y || y == mx.y) && (x > og.x && x < mx.x)){
				mvprintw(y, x, "-");
			}else if((y > og.y && y < mx.y) && (x == og.x || x == mx.x)){
				mvprintw(y, x, "|");
			}
		}
	}

	mvprintw(og.y + 3, ctr.x - 2, "~HP~");
	mvprintw(og.y + 4, ctr.x - 1, "%d",player.health);
	mvprintw(og.y + 1, og.x + 1, "L");
	mvprintw(og.y + 2, og.x + 1, "y: %d", player.pos.y);
	mvprintw(og.y + 3, og.x + 1, "x: %d", player.pos.x);

	return 0;
}

int drawOptionsWindow(Window win, Player player){

	Position og;
	Position mx;
	Position sz;
	int y;
	int x;
	og.y = win.pos.y;
	og.x = win.pos.x;
	mx.y = win.pos.y + win.size.y - 1;
	mx.x = win.pos.x + win.size.x - 1;
	sz.y = win.pos.y + win.size.y;
	sz.x = win.pos.x + win.size.x;

	for(y = og.y; y < sz.y; y++){
		for(x = og.x; x < sz.x; x++){
			if((y == og.y && x == og.x) || (y == mx.y && x == mx.x)){
				mvprintw(y, x, "/");
			}else if((y == og.y && x == mx.x) || (y == mx.y && x == og.x)){
				mvprintw(y, x, "\\");
			}else if((y == og.y || y == mx.y) && (x > og.x && x < mx.x)){
				mvprintw(y, x, "-");
			}else if((y > og.y && y < mx.y) && (x == og.x || x == mx.x)){
				mvprintw(y, x, "|");
			}
		}
	}

	mvprintw(og.y + 1, og.x, "(|==========================|)");
	mvprintw(og.y + 2, og.x + 1, "  \"-_                  _-\"  ");
	mvprintw(og.y + 3, og.x + 1, "   \" -_              _-     ");
	mvprintw(og.y + 4, og.x + 1, "       -            -\'      ");
	mvprintw(og.y + 5, og.x + 1, "        -_        _-        ");
	mvprintw(og.y + 6, og.x + 1, "        \' -_    _-          ");
	mvprintw(og.y + 7, og.x + 1, "            -__- \"          ");
	mvprintw(og.y + 8, og.x + 1, "             ''             ");

	return 0;
}

int drawGameWindow(Map map, Player * player, Window win){

	Position offset;
	Position og;
	Position mx;
	Position sz;
	Position ctr;
	int y;
	int x;
	og.y = win.pos.y;
	og.x = win.pos.x;
	mx.y = win.pos.y + win.size.y - 1;
	mx.x = win.pos.x + win.size.x - 1;
	sz.y = win.pos.y + win.size.y;
	sz.x = win.pos.x + win.size.x;
	ctr.y = win.pos.y + (win.size.y / 2);
	ctr.x = win.pos.x + (win.size.x / 2);
	offset = getOffset(win, map, player);
	drawCamera(offset, win, map, player);

	for(y = og.y; y < sz.y; y++){
		for(x = og.x; x < sz.x; x++){
			/* top left / bottom right */
			if((y == og.y && x == og.x) || (y == mx.y && x == mx.x)){
				mvprintw(y, x, "/");
			}else if((y == og.y && x == mx.x) || (y == mx.y && x == og.x)){
				mvprintw(y, x, "\\");
			}else if((y == og.y || y == mx.y) && (x > og.x && x < sz.x)){
				mvprintw(y, x, "-");
			}else if((y > og.y && y < sz.y) && (x == og.x || x == mx.x)){
				mvprintw(y, x, "|");
			}
		}
	}

	mvprintw(ctr.y, og.x, "-");
	mvprintw(ctr.y, mx.x, "-");
	mvprintw(og.y, ctr.x, "|");
	mvprintw(mx.y, ctr.x, "|");
	mvprintw(og.y - 1, og.x + 1, "offset: y %d, x %d", offset);

	/* Draw Player */
	mvprintw(player->scrpos.y, player->scrpos.x, "@");
	move(player->scrpos.y, player->scrpos.x);

	return 0;
}

int drawCamera(Position offset, Window win, Map map, Player * player){

	int y, x;
	Position cameraPos = {win.pos.y + 1, win.pos.x + 1};
	Position cameraSize = {win.size.y - 2, win.size.x - 2};
	Position margin = {(win.size.y / 2) - 1, (win.size.x / 2) - 1};

	for(y = 0; y < cameraSize.y; y++){
		for(x = 0; x < cameraSize.x; x++){
			mvprintw(win.pos.y - 1, win.pos.x + 19 + y, "%d", y);
			switch(map.map[y + offset.y][x + offset.x]){
				case 0:
					mvprintw(y + cameraPos.y, x + cameraPos.x, ".");
					break;
				case 1:
					mvprintw(y + cameraPos.y, x + cameraPos.x, "#");
					break;
				
				default:
					mvprintw(y + cameraPos.y, x + cameraPos.x, " ");
					break;
			}
		}
	}

	return 0;
}

Position getOffset(Window win, Map map, Player * player){

	int y, x;
	Position offset;
	Position cameraPos = {win.pos.y + 1, win.pos.x + 1};
	Position cameraSize = {win.size.y - 2, win.size.x - 2};
	Position margin = {(win.size.y / 2) - 1, (win.size.x / 2) - 1};

	/* Y Axis */
	if(player->pos.y - margin.y < 0){
		offset.y = 0;
		player->scrpos.y = player->pos.y + cameraPos.y;
	}else if(player->pos.y + margin.y > (map.size.y - 1)){
		offset.y = map.size.y - cameraSize.y;
		player->scrpos.y = (cameraPos.y + cameraSize.y) - (map.size.y - player->pos.y);
	}else{
		offset.y = player->pos.y - margin.y;
		player->scrpos.y = cameraPos.y + margin.y;
	}

	/* X Axis */
	if(player->pos.x - margin.x < 0){
		offset.x = 0;
		player->scrpos.x = player->pos.x + cameraPos.x;
	}else if(player->pos.x + margin.x > (map.size.x - 1)){
		offset.x = map.size.x - cameraSize.x;
		player->scrpos.x = (cameraPos.x + cameraSize.x) - (map.size.x - player->pos.x);
	}else{
		offset.x = player->pos.x - margin.x;
		player->scrpos.x = cameraPos.x + margin.x;
	}

	return offset;
}