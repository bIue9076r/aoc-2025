#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 16
#define PART_2

static int Rolls = 0;

int ReadArr(int y, int x, int arr[y][x]){
	ReadArr_top:;
	int delta = 0;
	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++){
			if (!arr[i][j]){
				continue;
			}
			
			int isUp = ((i - 1) >= 0);
			int isDown = ((i + 1) < y);
			int isLeft = ((j - 1) >= 0);
			int isRight = ((j + 1) < x);

			int up = 0; // i - 1
			int down = 0; // i + 1
			int left = 0; // j - 1
			int right = 0; // j + 1
			int up_left = 0; // i - 1 & j - 1
			int down_left = 0; // i + 1 & j - 1
			int up_right = 0; // i - 1 & j + 1
			int down_right = 0; // i + 1 & j + 1
			if(isUp){
				up = arr[i - 1][j];
				if (isLeft){
					up_left = arr[i - 1][j - 1];
				}
				
				if(isRight){
					up_right = arr[i - 1][j + 1];
				}
			}

			if (isDown){
				down = arr[i + 1][j];
				if (isLeft){
					down_left = arr[i + 1][j - 1];
				}
				
				if(isRight){
					down_right = arr[i + 1][j + 1];
				}
			}

			if(isLeft){
				left = arr[i][j - 1];
			}

			if(isRight){
				right = arr[i][j + 1];
			}

			int res = up + down + left + right + up_left + down_left + up_right + down_right;
			if(res < 4){
				Rolls++;
				#ifdef PART_2
				arr[i][j] = 0;
				delta++;
				#endif
			}
		}
	}
	#ifdef PART_2
	if(delta){
		goto ReadArr_top;
	}
	#endif
	
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

	int x = 1;
	int y = 1;

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
			if (c == '@' || c == '.'){
				_x++;
				if (_x > x){
					x = _x;
				}

				//buffer[_ind++] = c;
			}
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
			if (c == '@' || c == '.'){
				arr[_y][_x] = (c == '@')?(1):(0);
				_x++;
			}
		}
	}

	ReadArr(y,x,arr);

	fclose(file);
	return 0;
}

int main(void){
	ReadFile("ex.txt");
	printf("Rolls: %d\n", Rolls);

	Rolls = 0;
	ReadFile("data.txt");
	printf("Rolls: %d\n", Rolls);
	return 0;
}