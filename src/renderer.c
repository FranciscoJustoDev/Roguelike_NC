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

	Position winCenter;
	Position offset;
	Position og;
	Position mx;
	Position sz;
	Position ctr;
	int y;
	int x;
	winCenter.y = win.size.y / 2;
	winCenter.x = win.size.x / 2;
	og.y = win.pos.y;
	og.x = win.pos.x;
	mx.y = win.pos.y + win.size.y - 1;
	mx.x = win.pos.x + win.size.x - 1;
	sz.y = win.pos.y + win.size.y;
	sz.x = win.pos.x + win.size.x;
	ctr.y = win.pos.y + (win.size.y / 2);
	ctr.x = win.pos.x + (win.size.x / 2);

	/* Find map offset and update player screen position */
	if(player->pos.y - winCenter.y <= 0){
		offset.y = 0;
		player->scrpos.y = player->pos.y + og.y;
	}else if(player->pos.y + winCenter.y >= (map.size.y - 1)){
		offset.y = (map.size.y - 1) - (win.size.y - 1);
		player->scrpos.y = mx.y - ((map.size.y - 1) - player->pos.y);
	}else{
		offset.y = player->pos.y - winCenter.y;
		player->scrpos.y = ctr.y;
	}

	if(player->pos.x - winCenter.x <= 0){
		offset.x = 0;
		player->scrpos.x = player->pos.x + og.x;
	}else if(player->pos.x + winCenter.x >= (map.size.x - 1)){
		offset.x = (map.size.x - 1) - (win.size.x - 1);
		player->scrpos.x = mx.x - ((map.size.x - 1) - player->pos.x);
	}else{
		offset.x = player->pos.x - winCenter.x;
		player->scrpos.x = ctr.x;
	}

	/* Draw Game Window */
	for(y = 0; y < win.size.y; y++){
		for(x = 0; x < win.size.x; x++){
				switch(map.map[y + offset.y][x + offset.x]){
					case 0:
						mvprintw(y + og.y, x + og.x, ".");
						break;
					case 1:
						mvprintw(y + og.y, x + og.x, "#");
						break;
					
					default:
						mvprintw(y + og.y, x + og.x, " ");
						break;
				}
		}
	}

	/* Window Frame */
	for(y = og.y - 1; y <= sz.y; y++){
		for(x = og.x - 1; x <= sz.x; x++){
			if((y == og.y - 1 && x == og.x - 1) || (y == sz.y && x == sz.x)){
				mvprintw(y, x, "/");
			}else if((y == og.y - 1 && x == sz.x) || (y == sz.y && x == og.x - 1)){
				mvprintw(y, x, "\\");
			}else if((y == og.y - 1 || y == sz.y) && (x > og.x - 1 && x < sz.x)){
				mvprintw(y, x, "-");
			}else if((y > og.y - 1 && y < sz.y) && (x == og.x - 1 || x == sz.x)){
				mvprintw(y, x, "|");
			}
		}
	}
	mvprintw(og.y - 1, ctr.x, "|");
	mvprintw(sz.y, ctr.x, "|");
	mvprintw(ctr.y, sz.x, "-");
	mvprintw(ctr.y, og.x - 1, "-");

	/* Draw Player */
	mvprintw(player->scrpos.y, player->scrpos.x, "@");
	move(player->scrpos.y, player->scrpos.x);

	return 0;
}