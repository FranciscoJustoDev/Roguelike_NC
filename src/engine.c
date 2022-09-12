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

	newWindow->pos.y = y;
	newWindow->pos.x = x;
	newWindow->size.y = height;
	newWindow->size.x = length;

	return newWindow;
}