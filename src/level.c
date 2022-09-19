#include "level.h"

Level * setupLevel(char * level_name, Position * player){

	char fname[64] = DIR_LEVEL;
	strcat(fname, level_name);
	strcat(fname, LEVEL_FILE_TYPE);

	FILE * fp;

	fp = fopen(fname, "r");

	if(fp == NULL){
		perror("Error opening level file.\n");
		exit(EXIT_FAILURE);
	}

	char ch;
	char flag;
	int y, x;
	y = 1;
	x = 0;
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
	}

	fclose(fp);

	Level * newLevel;
	newLevel = malloc(sizeof(Level));
	newLevel->name = "Entrance Hall";
	newLevel->turn = 0;
	newLevel->size.y = y;
	newLevel->size.x = x;

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

	fseek(fp, 0, SEEK_SET);
	while((ch = fgetc(fp)) != 'x'){
		if(flag != '\n'){
			x++;
		}else{
			flag = 0;
			x = 0;
		}
		if(ch == 'P'){
			player->y = y;
			player->x = x;
		}
		if(ch == '\n'){
			y++;
			flag = '\n';
		}
		newLevel->map[y][x] = ch;
	}

	fclose(fp);

	return newLevel;
}