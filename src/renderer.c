#include "renderer.h"

int drawStatsWin(Window win, Level level, Player player){

	drawFrame(win);

	mvprintw(win.pos.y + 1, win.pos.x + 1, "HP: %d", player.health);
	mvprintw(win.pos.y + 2, win.pos.x + 1, "%s", level.name);
	mvprintw(win.pos.y + 3, win.pos.x + 1, "%d", level.turn);

	return 0;
}

int drawLogWin(Window win, Player player, char ** log){

	drawFrame(win);

	// mvprintw(og.y + 1, og.x, "(|==========================|)");
	// mvprintw(og.y + 2, og.x + 1, "  \"-_                  _-\"  ");
	// mvprintw(og.y + 3, og.x + 1, "   \" -_              _-     ");
	// mvprintw(og.y + 4, og.x + 1, "       -            -\'      ");
	// mvprintw(og.y + 5, og.x + 1, "        -_        _-        ");
	// mvprintw(og.y + 6, og.x + 1, "        \' -_    _-          ");
	// mvprintw(og.y + 7, og.x + 1, "            -__- \"          ");
	// mvprintw(og.y + 8, og.x + 1, "             ''             ");

	printInfo(log[0], win);

	return 0;
}

int drawGameWin(Window win, Level level, Player * player){

	Position offset;
	drawFrame(win);

	offset = getOffset(win, level, player);
	drawCamera(win, level, offset);

	mvprintw(win.pos.y + win.size.y / 2, win.pos.x, "-");
	mvprintw(win.pos.y + win.size.y / 2, win.pos.x + win.size.x - 1, "-");
	mvprintw(win.pos.y, win.pos.x + win.size.x / 2, "|");
	mvprintw(win.pos.y + win.size.y - 1, win.pos.x + win.size.x / 2, "|");

	/* Draw Player */
	mvprintw(player->scrpos.y, player->scrpos.x, "@");
	move(player->scrpos.y, player->scrpos.x);

	return 0;
}

int drawCamera(Window win, Level level, Position offset){

	int ch;
	int y, x;
	Position cameraPos = {win.pos.y + 1, win.pos.x + 1};
	Position cameraSize = {win.size.y - 2, win.size.x - 2};
	Position margin = {(win.size.y / 2) - 1, (win.size.x / 2) - 1};

	for(y = 0; y < cameraSize.y; y++){
		for(x = 0; x < cameraSize.x; x++){
			switch(level.map[y + offset.y][x + offset.x]){
				case '#':
					mvprintw(y + cameraPos.y, x + cameraPos.x, "#");
					break;

				case '.':
					mvprintw(y + cameraPos.y, x + cameraPos.x, ".");
					break;
				
				case '+':
					mvprintw(y + cameraPos.y, x + cameraPos.x, "+");
					break;
				
				default:
					mvprintw(y + cameraPos.y, x + cameraPos.x, ".");
					break;
			}
		}
	}

	return 0;
}

Position getOffset(Window win, Level level, Player * player){

	int y, x;
	Position offset;
	Position cameraPos = {win.pos.y + 1, win.pos.x + 1};
	Position cameraSize = {win.size.y - 2, win.size.x - 2};
	Position margin = {(win.size.y / 2) - 1, (win.size.x / 2) - 1};

	/* Y Axis */
	if(player->pos.y - margin.y < 0){
		offset.y = 0;
		player->scrpos.y = player->pos.y + cameraPos.y;
	}else if(player->pos.y + margin.y > (level.size.y - 1)){
		offset.y = level.size.y - cameraSize.y;
		player->scrpos.y = (cameraPos.y + cameraSize.y) - (level.size.y - player->pos.y);
	}else{
		offset.y = player->pos.y - margin.y;
		player->scrpos.y = cameraPos.y + margin.y;
	}

	/* X Axis */
	if(player->pos.x - margin.x < 0){
		offset.x = 0;
		player->scrpos.x = player->pos.x + cameraPos.x;
	}else if(player->pos.x + margin.x > (level.size.x - 1)){
		offset.x = level.size.x - cameraSize.x;
		player->scrpos.x = (cameraPos.x + cameraSize.x) - (level.size.x - player->pos.x);
	}else{
		offset.x = player->pos.x - margin.x;
		player->scrpos.x = cameraPos.x + margin.x;
	}

	return offset;
}

int drawFrame(Window win){

	Position og;
	Position mx;
	Position sz;
	Position ctr;
	og.y = win.pos.y;
	og.x = win.pos.x;
	mx.y = win.pos.y + win.size.y - 1;
	mx.x = win.pos.x + win.size.x - 1;
	sz.y = win.pos.y + win.size.y;
	sz.x = win.pos.x + win.size.x;
	ctr.y = win.pos.y + (win.size.y / 2);
	ctr.x = win.pos.x + (win.size.x / 2);
	
	int y, x;

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
			}else{
				mvprintw(y, x, " ");
			}
		}
	}

	return 0;
}