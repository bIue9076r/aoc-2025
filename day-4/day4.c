#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 16

static int Rolls = 0;

typedef struct tile_t_s {
	int isRoll;
	struct tile_t_s* up;
	struct tile_t_s* down;
	struct tile_t_s* left;
	struct tile_t_s* right;
	struct tile_t_s* up_left;
	struct tile_t_s* down_left;
	struct tile_t_s* up_right;
	struct tile_t_s* down_right;
} tile_t;

tile_t* newTile(int roll){
	tile_t* r = malloc(sizeof(tile_t));
	r->isRoll = roll;
	r->up = NULL;
	r->down = NULL;
	r->left = NULL;
	r->right = NULL;
	r->up_left = NULL;
	r->down_left = NULL;
	r->up_right = NULL;
	r->down_right = NULL;

	return r;
}

tile_t* ReadLine(char* buf, tile_t* last){
	tile_t* lt = last;
	tile_t* tmp = NULL;
	tile_t* new = NULL;
	while(*buf){
		if(lt == NULL){
			lt = newTile((*buf == '@')?(1):(0));
			buf++;
			continue;
		}
		
		tmp = lt;
		while (tmp->left != NULL){
			tmp = tmp->left;
		}

		new = 
		
		buf++;
	}
	printf("\n");
	
	return lt;
}

int ReadFile(char* path){
	FILE* file;
	tile_t* last = NULL;
	char buffer[BUFFER_SIZE];
	for (int _ = 0; _ < BUFFER_SIZE; _++){buffer[_] = 0;}
	
	file = fopen(path,"r");
	if(file == NULL){
		return -1;
	}

	int _ind = 0;
	while (!feof(file)){
		char c = fgetc(file);
		if(c == '\n'){
			last = ReadLine(buffer,last);
			for (int _ = 0; _ < BUFFER_SIZE; _++){buffer[_] = 0;}
			_ind = 0;
		}else{
			buffer[_ind++] = c;
		}
	}

	buffer[_ind - 1] = 0;
	ReadLine(buffer,last);
	for (int _ = 0; _ < BUFFER_SIZE; _++){buffer[_] = 0;}
	_ind = 0;

	fclose(file);
	return 0;
}

int main(void){
	ReadFile("ex.txt");
	printf("Rolls: %d\n", Rolls);
	return 0;
}