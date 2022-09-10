#include "map.h"

Map * create_map(int row, int col){
	int y;
	int x;

	Map * newMap;
	newMap = malloc(sizeof(Map));
	newMap->size.y = row;
	newMap->size.x = col;
	
	newMap->map = malloc(sizeof(int *) * newMap->size.y);
	for(y = 0; y < newMap->size.y; y++){
		newMap->map[y] = malloc(sizeof(int) * newMap->size.x);
	}

	for(y = 0; y < newMap->size.y; y++){
		for(x = 0; x < newMap->size.x; x++){
			if(y == 0 || x == 0){
				newMap->map[y][x] = 1;
			} else if(y == (newMap->size.y - 1) || x == (newMap->size.x - 1)){
				newMap->map[y][x] = 1;
			} else{
				newMap->map[y][x] = 0;
			}
		}
	}

	return newMap;
}