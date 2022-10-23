#include "level.h"

Level * setupLevel(char * level_name, Position * player){

	FILE * fp;
	Level * newLevel;
	newLevel = malloc(sizeof(Level));
	char fname[64] = DIR_LEVEL;
	strcat(fname, level_name);
	strcat(fname, LEVEL_FILE_TYPE);

	fp = fopen(fname, "r");

	if(fp == NULL){
		perror("Error opening level file.\n");
		exit(EXIT_FAILURE);
	}

	char ch;
	char flag;
	int y, x, ndoors;
	y = 0;
	x = 0;
	ndoors = 0;
	flag = 0;
	fseek(fp, 0, SEEK_SET);

	while((ch = fgetc(fp)) != 'x'){
		if(ch == '\n'){
			y++;
			flag = '\n';
		}
		if(flag != '\n'){
			x++;
		}
		if(ch == DOOR){
			ndoors++;
		}
	}

	fclose(fp);

	newLevel->name = "Entrance Hall";
	newLevel->turn = 0;
	newLevel->size.y = y + 1;
	newLevel->size.x = x;
	newLevel->ndoor = ndoors;
	newLevel->door = malloc(sizeof(Door) * ndoors);
	newLevel->log = malloc(sizeof(char *) * 5);
	for(y = 0; y < 5; y++){
		newLevel->log[y] = malloc(sizeof(char) * 64);
	}

	newLevel->map = malloc(sizeof(char *) * newLevel->size.y);
	for(y = 0; y < newLevel->size.y; y++){
		newLevel->map[y] = malloc(sizeof(char) * newLevel->size.x);
	}

	fp = fopen(fname, "r");
	if(fp == NULL){
		perror("Error opening level file.\n");
		exit(EXIT_FAILURE);
	}

	y = 0;
	x = 0;
	ndoors = 0;

	fseek(fp, 0, SEEK_SET);
	while((ch = fgetc(fp)) != 'x'){
		if(flag != '\n'){
			x++;
		}else{
			flag = 0;
			x = 0;
		}
		if(ch == '\n'){
			y++;
			flag = '\n';
		}
		if(ch == 'P'){
			player->y = y;
			player->x = x;
		}
		if(ch == DOOR){
			newLevel->door[ndoors] = createDoor(y, x);
			ndoors++;
		}
		newLevel->map[y][x] = ch;
	}

	fclose(fp);

	return newLevel;
}

Door * createDoor(int y, int x){

	Door * newDoor;
	newDoor = malloc(sizeof(Door));
	newDoor->pos.y = y;
	newDoor->pos.x = x;
	newDoor->open = 0;
	newDoor->locked = 0;
	newDoor->hp = 20;

	return newDoor;
}