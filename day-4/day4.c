#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 16

static int Rolls = 0;

int ReadLine(char* buf){
	return 0;
}

int ReadFile(char* path){
	FILE* file;
	//char buffer[BUFFER_SIZE];
	//for (int _ = 0; _ < BUFFER_SIZE; _++){buffer[_] = 0;}
	
	file = fopen(path,"r");
	if(file == NULL){
		return -1;
	}

	int x = 0;
	int y = 0;

	//int _ind = 0;
	int _x = 0;
	while (!feof(file)){
		char c = fgetc(file);
		if(c == '\n'){
			//for (int _ = 0; _ < BUFFER_SIZE; _++){buffer[_] = 0;}
			//_ind = 0;
			_x = 0;
			y++;
		}else{
			_x++;
			if (_x > x){
				x = _x;
			}
			
			//buffer[_ind++] = c;
		}
	}

	fseek(file,0,SEEK_SET);
	int arr[y][x];
	for(int i = 0; i < y; i++){for(int j = 0; j < x; j++){arr[i][j] = 0;}}
	
	_x = 0;
	int _y = 0;
	while (!feof(file)){
		char c = fgetc(file);
		if(c == '\n'){
			_x = 0;
			_y++;
		}else{
			arr[_y][_x] = (c == '@')?('@'):('.');
			_x++;
		}
	}

	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++){
			printf("%c",arr[i][j]);
		}
		printf("\n");
	}
	
	

	fclose(file);
	return 0;
}

int main(void){
	ReadFile("ex.txt");
	printf("Rolls: %d\n", Rolls);
	return 0;
}