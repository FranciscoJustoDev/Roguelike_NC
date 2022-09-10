#include "engine.h"

int init(){
	initscr();
	noecho();
	refresh();

	return 0;
}

Window * createWindow(int y, int x, int height, int length){
	Window * newWindow;
	newWindow = malloc(sizeof(Window));

	newWindow->pos.y = 2;
	newWindow->pos.x = 4;
	newWindow->size.y = height;
	newWindow->size.x = length;

	return newWindow;
}