#include "engine.h"

int init(){
	initscr();
	noecho();
	refresh();

	return 0;
}

Scene * setupScene(){

	Scene * newScene;
	newScene = malloc(sizeof(Scene));

	return newScene;
}

Window * createWindow(int y, int x, int height, int length){
	Window * newWindow;
	newWindow = malloc(sizeof(Window));

	newWindow->pos.y = y;
	newWindow->pos.x = x;
	newWindow->size.y = height;
	newWindow->size.x = length;

	return newWindow;
}

int updateLog(char * text, char ** log){

	int y;

	for(y = 0; y < 5; y++){
		log[y] = text;
	}

	return 0;
}

int printInfo(char * text, Window win){

	int n, y, x;
	n = 0;
	y = 1;
	x = 1;

	while(n < strlen(text)){
		
		mvprintw(win.pos.y + y, win.pos.x + x, "%c", text[n]);
		n++;

		if(x < win.size.x - 2){
			x++;
		}else{
			y++;
			x = 1;
		}
	}

	return 0;
}

char * getInfo(char img){

	switch(img){
		case PLAYER:
			return "Handsome!";
			break;

		case FLOOR:
			return "This is a floor tile.";
			break;

		case WALL:
			return "This is a wall. You'll have to go around.";
			break;

		case DOOR:
			return "It's a nice door.";
			break;

		default:
			break;
	}

	return "NOT DEFINED!";
}